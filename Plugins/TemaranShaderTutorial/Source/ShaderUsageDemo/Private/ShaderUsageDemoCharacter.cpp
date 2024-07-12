// @Author	Fredrik Lindh [Temaran] (temaran@gmail.com) {https://github.com/Temaran}
///////////////////////////////////////////////////////////////////////////////////////

#include "ShaderUsageDemoCharacter.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "ProceduralMeshComponent.h"
#include "BatchedElements.h"
#include <fstream>

static TAutoConsoleVariable<int32> CVarDemoPerformCPUCheck(TEXT("demo.PerformCPUCheck"), 0, TEXT("If this is set to 1, we will perform CPU side checking of our GPU output to help verify there are no errors."), ECVF_Default);

AShaderUsageDemoCharacter::AShaderUsageDemoCharacter()
{
	//GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	GetCapsuleComponent()->InitCapsuleSize(55.f, 192.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	//Mesh1P->SetOnlyOwnerSee(true);
	////Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	//Mesh1P->bCastDynamicShadow = false;
	//Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	//Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	//FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	//FP_Gun->SetOnlyOwnerSee(true);
	//FP_Gun->bCastDynamicShadow = false;
	//FP_Gun->CastShadow = false;
	//FP_Gun->SetupAttachment(RootComponent);

	//FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	//FP_MuzzleLocation->SetupAttachment(FP_Gun);
	//FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	line = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatcher"));;
}

void AShaderUsageDemoCharacter::BeginPlay()
{
	Super::BeginPlay();
	//FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("GripPoint"));

	//ReadData(index_tbo, status_tbo, vel_tbo, pre_tbo);
	//CreateTextures(index_tbo, status_tbo, vel_tbo, pre_tbo);
	
	//FShaderDeclarationDemoModule::Get().BeginRendering(IndexTex, StatusTex, VelTex, PreTex, line);
}

void AShaderUsageDemoCharacter::BeginDestroy()
{
	FShaderDeclarationDemoModule::Get().EndRendering();
	Super::BeginDestroy();
}

void AShaderUsageDemoCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TotalTimeSecs += DeltaSeconds;
	float ComputeShaderBlendScalar = 0.0f;

	// Do axis logic here since we cannot use input bindings in a plugin...
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if(PlayerController)
	{ 
		//if (PlayerController->IsInputKeyDown(EKeys::W) && PlayerController->IsInputKeyDown(EKeys::LeftShift)) { AddMovementInput(GetActorUpVector(), -10.0f); }
		//if (PlayerController->IsInputKeyDown(EKeys::S) && PlayerController->IsInputKeyDown(EKeys::LeftShift)) { AddMovementInput(GetActorUpVector(), 10.0f); }
		if (PlayerController->IsInputKeyDown(EKeys::W)) { AddMovementInput(GetActorForwardVector(), 100.0f); }
		if (PlayerController->IsInputKeyDown(EKeys::S)) { AddMovementInput(GetActorForwardVector(), -100.0f); }
		if (PlayerController->IsInputKeyDown(EKeys::A)) { AddMovementInput(GetActorRightVector(), -100.0f); }
		if (PlayerController->IsInputKeyDown(EKeys::D)) { AddMovementInput(GetActorRightVector(), 100.0f); }
	}
	
	EndColorBuildup = FMath::Clamp(EndColorBuildup + DeltaSeconds * EndColorBuildupDirection, 0.0f, 1.0f);
	if (EndColorBuildup >= 1.0 || EndColorBuildup <= 0) 
	{
		EndColorBuildupDirection *= -1;
	}
		
	ComputeShaderBlend = FMath::Clamp(ComputeShaderBlend + ComputeShaderBlendScalar * DeltaSeconds, 0.0f, 1.0f);

	FShaderUsageExampleParameters InputParameters(RenderTarget);
	{
		InputParameters.SimulationState = ComputeShaderSimulationSpeed * TotalTimeSecs;
		InputParameters.ComputeShaderBlend = ComputeShaderBlend;
		InputParameters.StartColor = StartColor;
		InputParameters.EndColor = FColor(EndColorBuildup * 255, 0, 0, 255);
	}

	ProcessSummationRequests(InputParameters);

	// If doing this for realsies, you should avoid doing this every frame unless you have to of course.
	// We set it every frame here since we're updating the end color and simulation state. Boop.
	FShaderDeclarationDemoModule::Get().UpdateParameters(InputParameters);
}

void AShaderUsageDemoCharacter::ProcessSummationRequests(FShaderUsageExampleParameters& InputParameters)
{
	// Let's check our previous requests.
	TMap<int32, FIntegerSummationResult> LatestResults;
	FShaderDeclarationDemoModule::Get().GetCompletedSummationRequests(LatestResults);
	for (auto& [RequestId, Result] : LatestResults)
	{
		check(SummationRequests.Contains(RequestId));

		if (CVarDemoPerformCPUCheck.GetValueOnGameThread())
		{
			// Let's sum this manually on the CPU, and see if it checks out :)
			TArray<int32> OriginalData = SummationRequests[RequestId];
			int32 ReduceSum = 0;
			for (int32 Entry : OriginalData)
			{
				ReduceSum += Entry;
			}

			static uint32 TotalAddedInts = 0;
			static uint32 CheckCounter = 0;
			TotalAddedInts += OriginalData.Num();
			CheckCounter += OriginalData.Num();

			if (ReduceSum == Result.Result)
			{
				if (CheckCounter >= 10000)
				{
					CheckCounter = 0;
					UE_LOG(LogTemp, Log, TEXT("New total added int count: %u"), TotalAddedInts);
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("The summation CS isn't working correctly? CPU: %i  GPU: %i"), ReduceSum, Result.Result);
			}
		}

		// We're done with this one!
		SummationRequests.Remove(RequestId);
	}

	// If we have shaders that only work in certain shader models we can avoid using them by checking our supported feature level.
	if (GetWorld() && GetWorld()->Scene && GetWorld()->Scene->GetFeatureLevel() >= ERHIFeatureLevel::SM6)
	{
		// Let's make some new summation requests!
		const int32 NrNewRequests = FMath::RandRange(1, 10);
		for (int32 RequestIdx = 0; RequestIdx < NrNewRequests; RequestIdx++)
		{
			const int32 RequestId = NextRequestId++;

			TArray<int32> IntegersToSum;
			const int32 RandomNumberOfIntegers = FMath::RandRange(1, 5000);
			for (int32 IntIdx = 0; IntIdx < RandomNumberOfIntegers; IntIdx++)
			{
				IntegersToSum.Add(FMath::RandRange(0, 10000));
			}

			// Store the request locally so we can refer back to it later, as well as copy them to the input params.
			SummationRequests.Add(RequestId, IntegersToSum);
			InputParameters.IntegerSummationRequests.Add(RequestId, MoveTemp(IntegersToSum));
		}
	}
}

void AShaderUsageDemoCharacter::OnFire()
{
	// Try to set a texture to the object we hit!
	FHitResult HitResult;
	FVector StartLocation = FirstPersonCameraComponent->GetComponentLocation();
	FRotator Direction = FirstPersonCameraComponent->GetComponentRotation();
	FVector EndLocation = StartLocation + Direction.Vector() * 10000;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, QueryParams))
	{
		AActor* HitActor = HitResult.GetActor();

		if (HitActor)
		{
			TArray<UStaticMeshComponent*> StaticMeshComponents = TArray<UStaticMeshComponent*>();
			HitActor->GetComponents<UStaticMeshComponent>(StaticMeshComponents);
			// try to catch procedrual mesh
			/*TArray<UProceduralMeshComponent*> ProceduralMeshComponents = TArray<UProceduralMeshComponent*>();
			HitActor->GetComponents<UProceduralMeshComponent>(ProceduralMeshComponents);*/

			/*for (int32 i = 0; i < StaticMeshComponents.Num(); i++) 
			{
				UStaticMeshComponent* CurrentStaticMeshPtr = StaticMeshComponents[i];
				CurrentStaticMeshPtr->SetMaterial(0, MaterialToApplyToClickedObject);
				UMaterialInstanceDynamic* MID =	CurrentStaticMeshPtr->CreateAndSetMaterialInstanceDynamic(0);
				MID->SetTextureParameterValue("InputTexture", (UTexture*)RenderTarget);
			}*/

			/*for (int32 i = 0; i < ProceduralMeshComponents.Num(); i++)
			{
				UProceduralMeshComponent* CurrentProceduralMeshPtr = ProceduralMeshComponents[i];
				for (int32 j = 0; j < CurrentProceduralMeshPtr->GetNumSections(); j++) {
					CurrentProceduralMeshPtr->SetMaterial(j, MaterialToApplyToClickedObject);
					UMaterialInstanceDynamic* MID = CurrentProceduralMeshPtr->CreateAndSetMaterialInstanceDynamic(j);
					MID->SetTextureParameterValue("IndexTex", (UTexture*)IndexTex);
					MID->SetTextureParameterValue("StatusTex", (UTexture*)StatusTex);
					MID->SetTextureParameterValue("VelTex", (UTexture*)VelTex);
					MID->SetTextureParameterValue("PreTex", (UTexture*)PreTex);
					MID->SetScalarParameterValue("index_tex_size", IndexTex->GetSizeX());
					MID->SetScalarParameterValue("vel_tex_size", VelTex->GetSizeX());
					MID->SetScalarParameterValue("index_length", index_tbo.size());
				}
			}*/
		}
	}

	if (FireSound)
	{
		//UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	/*UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
	if (AnimInstance && FireAnimation)
	{
		AnimInstance->Montage_Play(FireAnimation, 1.f);
	}*/
}

void AShaderUsageDemoCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Pressed, this, &AShaderUsageDemoCharacter::Jump);
	PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Released, this, &AShaderUsageDemoCharacter::StopJumping);
	PlayerInputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this, &AShaderUsageDemoCharacter::OnFire);

	PlayerInputComponent->BindAxisKey(EKeys::MouseX, this, &AShaderUsageDemoCharacter::TurnAtRate);
	PlayerInputComponent->BindAxisKey(EKeys::MouseY, this, &AShaderUsageDemoCharacter::LookUpAtRate);	
}

void AShaderUsageDemoCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AShaderUsageDemoCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(-Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AShaderUsageDemoCharacter::ReadData(std::vector<int>& index_tbo_data, std::vector<int>& status_tbo_data, std::vector<FVector3f>& vel_tbo_data, std::vector<float>& pre_tbo_data) {
	std::ifstream in;

	// init dir
	FString pluginDir = FPaths::Combine(FPaths::ProjectPluginsDir(), "TemaranShaderTutorial");
	FString testDataDir = FPaths::Combine(pluginDir, "TestData");

	// c++ 11 lambdas function was not supported template
	auto OpenIntFile = [&in, &testDataDir](const FString& dataPath, std::vector<int>& buf) {
		buf.clear();
		in.open(std::string(TCHAR_TO_UTF8(*dataPath)), std::fstream::in);
		std::string temp;
		std::stringstream ss;
		int t;
		while (in >> temp) {
			ss << temp;
			ss >> t;
			buf.push_back(t);
			temp.clear();
			ss.clear();
		}
		in.close();
		return;
		};

	auto OpenFloatFile = [&testDataDir, &in](const FString& dataPath, std::vector<float>& buf) {
		buf.clear();
		in.open(std::string(TCHAR_TO_UTF8(*dataPath)), std::fstream::in);
		std::string temp;
		std::stringstream ss;
		float t;
		while (in >> temp) {
			ss << temp;
			ss >> t;
			buf.push_back(t);
			temp.clear();
			ss.clear();
		}
		in.close();
		};

	auto OpenVec3File = [&testDataDir, &in](const FString& dataPath, std::vector<FVector3f>& buf) {
		buf.clear();
		in.open(std::string(TCHAR_TO_UTF8(*dataPath)), std::fstream::in);
		std::string temp;
		std::stringstream ss;
		FVector3f t;
		while (in >> temp) {
			ss << temp;
			ss >> t[0];

			in >> temp;
			ss << temp;
			ss >> t[1];

			in >> temp;
			ss << temp;
			ss >> t[2];
			buf.push_back(t);
			temp.clear();
			ss.clear();
		}
		in.close();
		};

	OpenIntFile(FPaths::Combine(testDataDir, "index_tbo.txt"), index_tbo_data);
	OpenIntFile(FPaths::Combine(testDataDir, "status_tbo.txt"), status_tbo_data);
	OpenVec3File(FPaths::Combine(testDataDir, "vel_tbo.txt"), vel_tbo_data);
	OpenFloatFile(FPaths::Combine(testDataDir, "pre_tbo.txt"), pre_tbo_data);
}

void AShaderUsageDemoCharacter::CreateTextures(const std::vector<int>& index_tbo_data, const std::vector<int>& status_tbo_data, const std::vector<FVector3f>& vel_tbo_data, const std::vector<float>& pre_tbo_data) {
	float IndexSizeSqrt = powf(index_tbo_data.size(), 0.5);
	float StatusSizeSqrt = powf(status_tbo_data.size(), 0.5);
	float VelSizeSqrt = powf(vel_tbo_data.size(), 0.5);
	float PreSizeSqrt = powf(pre_tbo_data.size(), 0.5);

	int IndexSize = ceil(IndexSizeSqrt);
	int StatusSize = ceil(StatusSizeSqrt);
	int VelSize = ceil(VelSizeSqrt);
	int PreSize = ceil(PreSizeSqrt);
	IndexTex = UTexture2D::CreateTransient(IndexSize, IndexSize, PF_FloatRGBA); // PF_B8G8R8A8
	StatusTex = UTexture2D::CreateTransient(StatusSize, StatusSize, PF_FloatRGBA); // PF_B8G8R8A8
	VelTex = UTexture2D::CreateTransient(VelSize, VelSize, PF_FloatRGBA); // PF_B8G8R8A8
	PreTex = UTexture2D::CreateTransient(PreSize, PreSize, PF_FloatRGBA); // PF_B8G8R8A8

	TextureMipGenSettings IndexOldMipSetting, StatusOldMipSetting, VelOldMipSetting, PreOldMipSetting;
	IndexOldMipSetting = IndexTex->MipGenSettings;
	StatusOldMipSetting = StatusTex->MipGenSettings;
	VelOldMipSetting = VelTex->MipGenSettings;
	PreOldMipSetting = PreTex->MipGenSettings;
	IndexTex->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	StatusTex->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	VelTex->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	PreTex->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	IndexTex->UpdateResource();
	StatusTex->UpdateResource();
	VelTex->UpdateResource();
	PreTex->UpdateResource();

	// IndexTex write data
	FFloat16* Ptr0 = (FFloat16*)IndexTex->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write
	
	for (int i = 0; i < IndexTex->GetSizeY(); i++) {
		for (int j = 0; j < IndexTex->GetSizeX(); j++) {
			int32 index = j + i * IndexTex->GetSizeX();
			int32 Idx = 4 * index;
			int16 val;
			if (index < index_tbo_data.size()) {
				val = FFloat16(index_tbo_data[index]);
				Ptr0[Idx + 0] = val; // real R
				Ptr0[Idx + 1] = 0; // real G
				Ptr0[Idx + 2] = 0; // real B
				Ptr0[Idx + 3] = 1; // A
			}
			else {
				Ptr0[Idx + 0] = 0; // real R
				Ptr0[Idx + 1] = 0; // real G
				Ptr0[Idx + 2] = 0; // real B
				Ptr0[Idx + 3] = 0; // A
			}
		}
	}

	IndexTex->PlatformData->Mips[0].BulkData.Unlock();

	// StatusTex write data
	FFloat16* Ptr1 = (FFloat16*)StatusTex->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write

	// run through every pixel
	for (int i = 0; i < StatusTex->GetSizeY(); i++) {
		for (int j = 0; j < StatusTex->GetSizeX(); j++) {
			int32 index = j + i * StatusTex->GetSizeX();
			int32 Idx = 4 * index;
			FFloat16 val;
			if (index < status_tbo_data.size()) {
				val = FFloat16(status_tbo_data[index]);
				Ptr1[Idx + 0] = val; // real R
				Ptr1[Idx + 1] = 0; // real G
				Ptr1[Idx + 2] = 0; // real B
				Ptr1[Idx + 3] = 1; // A
			}
			else {
				Ptr1[Idx + 0] = 0; // real R
				Ptr1[Idx + 1] = 0; // real G
				Ptr1[Idx + 2] = 0; // real B
				Ptr1[Idx + 3] = 0; // A
			}
		}
	}

	StatusTex->PlatformData->Mips[0].BulkData.Unlock();

	// VelTex write data
	FFloat16* Ptr2 = (FFloat16*)VelTex->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write

	// run through every pixel
	for (int i = 0; i < VelTex->GetSizeY(); i++) {
		for (int j = 0; j < VelTex->GetSizeX(); j++) {
			int32 index = j + i * VelTex->GetSizeX();
			int32 Idx = 4 * index;
			FVector3f val;
			if (index < vel_tbo_data.size()) {
				val = vel_tbo_data[index];
				Ptr2[Idx + 0] = FFloat16(val.X); // real R
				Ptr2[Idx + 1] = FFloat16(val.Y); // real G
				Ptr2[Idx + 2] = FFloat16(val.Z); // real B
				Ptr2[Idx + 3] = 1; // A
			}
			else {
				Ptr2[Idx + 0] = 0; // real R
				Ptr2[Idx + 1] = 0; // real G
				Ptr2[Idx + 2] = 0; // real B
				Ptr2[Idx + 3] = 0; // A
			}
		}
	}

	VelTex->PlatformData->Mips[0].BulkData.Unlock();

	// PreTex write data
	FFloat16* Ptr3 = (FFloat16*)PreTex->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write

	// run through every pixel
	for (int i = 0; i < PreTex->GetSizeY(); i++) {
		for (int j = 0; j < PreTex->GetSizeX(); j++) {
			int32 index = j + i * PreTex->GetSizeX();
			int32 Idx = 4 * index;
			FFloat16 val;
			if (index < pre_tbo_data.size()) {
				val = FFloat16(pre_tbo_data[index]);
				Ptr3[Idx + 0] = val; // real R
				Ptr3[Idx + 1] = 0; // real G
				Ptr3[Idx + 2] = 0; // real B
				Ptr3[Idx + 3] = 1; // A
			}
			else {
				Ptr3[Idx + 0] = 0; // real R
				Ptr3[Idx + 1] = 0; // real G
				Ptr3[Idx + 2] = 0; // real B
				Ptr3[Idx + 3] = 0; // A
			}
		}
	}

	PreTex->PlatformData->Mips[0].BulkData.Unlock();

	IndexTex->MipGenSettings = IndexOldMipSetting;
	StatusTex->MipGenSettings = StatusOldMipSetting;
	VelTex->MipGenSettings = VelOldMipSetting;
	PreTex->MipGenSettings = PreOldMipSetting;
	IndexTex->UpdateResource();
	StatusTex->UpdateResource();
	VelTex->UpdateResource();
	PreTex->UpdateResource();
}