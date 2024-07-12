// @Author	Fredrik Lindh [Temaran] (temaran@gmail.com) {https://github.com/Temaran}
///////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Components/LineBatchComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "ShaderDeclarationDemoModule.h"

#include "ShaderUsageDemoCharacter.generated.h"


class UInputComponent;

UCLASS()
class AShaderUsageDemoCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector GunOffset;

	/************************************************************************/
	/* Plugin Shader Demo variables!                                        */
	/************************************************************************/
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShaderDemo)
	FColor StartColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShaderDemo)
	float ComputeShaderSimulationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShaderDemo)
	UMaterialInterface* MaterialToApplyToClickedObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShaderDemo)
	class UTextureRenderTarget2D* RenderTarget;

	UTexture2D* IndexTex;
	UTexture2D* StatusTex;
	UTexture2D* VelTex;
	UTexture2D* PreTex;

	ULineBatchComponent* line;

public:
	AShaderUsageDemoCharacter();
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	TMap<int32, TArray<int32>> SummationRequests;
	int32 NextRequestId = 0;
	int32 SuccessfulReduceSummations = 0;
	float EndColorBuildup;
	float EndColorBuildupDirection;
	float ComputeShaderBlend;
	float TotalTimeSecs;

	void OnFire();
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

private:
	void ProcessSummationRequests(FShaderUsageExampleParameters& InputParameters);

	void ReadData(std::vector<int>& index_tbo_data, std::vector<int>& status_tbo_data, std::vector<FVector3f>& vel_tbo_data, std::vector<float>& pre_tbo_data);

	void CreateTextures(const std::vector<int>& index_tbo_data, const std::vector<int>& status_tbo_data, const std::vector<FVector3f>& vel_tbo_data, const std::vector<float>& pre_tbo_data);
	std::vector<int> index_tbo;
	std::vector<int> status_tbo;
	std::vector<FVector3f> vel_tbo;
	std::vector<float> pre_tbo;
};
