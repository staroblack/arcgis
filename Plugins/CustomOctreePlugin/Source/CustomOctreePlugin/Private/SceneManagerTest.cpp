// Fill out your copyright notice in the Description page of Project Settings.

#include "SceneManagerTest.h"
#include "RenderGraphBuilder.h"
#include "Interfaces/IPluginManager.h"
#include "MyShaders/Public/MyShaders.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

inline FVector glm2FVec(const glm::vec3& p) {
	return FVector(p.x, p.y, p.z);
}

inline FVector3f glm2FVec3f(const glm::vec3& p) {
	return FVector3f(p.x, p.y, p.z);
}

LineGenerator::LineGenerator() {
	stepDivider = 60;
	transform = glm::vec3(0.15f, 0.5f, 0.09f);
	rotation = glm::vec3(0, 0, 0);
	scale = 0.31f;
	spawnCount = 20;
	collideForce = 1;
	lineThickness = 0.5;

	spawnType = SpawnType::LINE;

	for (int i = 0; i < 100; i++)
	{
		double r1 = ((double)rand() / (RAND_MAX + 1.0) * 2) - 1;
		double r2 = ((double)rand() / (RAND_MAX + 1.0) * 2) - 1;
		double r3 = ((double)rand() / (RAND_MAX + 1.0) * 2) - 1;
		randomValue.push_back(glm::vec3(r1, r2, r3));
	}
}

FStreamLineParameters::FStreamLineParameters() {
	lines.Empty();
}

FStreamLineParameters::FStreamLineParameters(std::vector<glm::vec4>& point, int index_length, int chunklist_length, CustomOctree& octree) {
	points.SetNum(point.size());

	for (int32 i = 0; i < point.size(); ++i)
	{
		points[i] = FVector4f(point[i].x, point[i].y, point[i].z, point[i].w);
	}
	pathLine.Empty();
	lines.Empty();

	collideForce = 1;
	dt = 0.033f;
	maxLength = 1000;
	indexLength = index_length;
	chunkListLength = chunklist_length;
	chunkSize = glm2FVec3f(glm::vec3(octree.GetChunkSize()));
	minPos = glm2FVec3f(octree.GetMin());
	maxPos = glm2FVec3f(octree.GetMax());
	spacing = glm2FVec3f(octree.GetSampledSpacing());
	totalLevel = octree.GetTotalLevel();

	visibleLength = 10.0f;
	invisibleLength = 2.5f;
	animateTime = 1;

	hack = false;
}

FIsosurfaceParameters::FIsosurfaceParameters() {}

FIsosurfaceParameters::FIsosurfaceParameters(int index_length, int chunklist_length, float threshold, FMatrix camViewProj, CustomOctree& octree) {
	isosurfacePoint.Empty();
	outputPos.Empty();

	indexLength = index_length;
	chunkListLength = chunklist_length;

	viewProj = FMatrix44f(camViewProj);
	model = FMatrix44f();
	model.SetIdentity();

	chunkSize = glm2FVec3f(glm::vec3(octree.GetChunkSize()));
	minPos = glm2FVec3f(octree.GetMin());
	maxPos = glm2FVec3f(octree.GetMax());
	spacing = glm2FVec3f(octree.GetSampledSpacing());
	totalLevel = octree.GetTotalLevel();

	isovalue = threshold;
}

// Sets default values
ASceneManagerTest::ASceneManagerTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	randomComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Random Component"));
	randomComponent->SetupAttachment(RootComponent);

	lineComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatcher"));

	planePMC = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("planePMC"), false);
	isosurfacePMC = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("isosurfacePMC"), false);
	isosurfacePMC2 = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("isosurfacePMC2"), false);

	isosurfaceParams = FIsosurfaceParameters();
	streamLineParams = FStreamLineParameters();
}

// Called when the game starts or when spawned
void ASceneManagerTest::BeginPlay()
{
	Super::BeginPlay();

	//Testing SetupInfo
	/*FString FilePath = FPaths::Combine(FPaths::ProjectPluginsDir(), "CustomOctreePlugin/Source/CustomOctreePlugin/101data2_collection/gridinfo.bin");

	_octree.SetupInfo(FilePath, 1);

	fileValueList.clear();
	fileIndexList.clear();
	baseFileValueList.clear();
	baseFileIndexList.clear();

	octreeLODList.clear();
	octreeLODList.push_back(1);
	octreeLODList.push_back(2);
	octreeLODList.push_back(4);
	octreeLODList.push_back(8);
	octreeLODList.push_back(16);
	octreeLODList.push_back(32);
	octreeLODList.push_back(64);*/

	//for (auto& ol : octreeLODList) ol = pow(ol, 2);
}

void ASceneManagerTest::BeginDestroy()
{
	Super::BeginDestroy();
}

// Called every frame
void ASceneManagerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!drawing)
		return;

	float frustumEquation[24];
	// test camera for voricity isosurface
	glm::mat4 cameraViewProj = glm::mat4(
		glm::vec4(-1.2182, 1.21388, 0.532041, 0.506088),
		glm::vec4(-1.06213, -1.57212, -0.545959, -0.519327),
		glm::vec4(-0.0920113, 2.07645, -0.723917, -0.688604),
		glm::vec4(2.24047, 0.186117, 1.99532, 2.09311)
	);

	//FMatrix camViewProjMat;
	FMatrix Matrix = GetCameraViewProj();
	FString MatrixString = FString::Printf(TEXT("Matrix: [%f, %f, %f, %f], [%f, %f, %f, %f], [%f, %f, %f, %f], [%f, %f, %f, %f]"),
		Matrix.M[0][0], Matrix.M[0][1], Matrix.M[0][2], Matrix.M[0][3],
		Matrix.M[1][0], Matrix.M[1][1], Matrix.M[1][2], Matrix.M[1][3],
		Matrix.M[2][0], Matrix.M[2][1], Matrix.M[2][2], Matrix.M[2][3],
		Matrix.M[3][0], Matrix.M[3][1], Matrix.M[3][2], Matrix.M[3][3]);

	//UE_LOG(LogTemp, Log, TEXT("%s"), *MatrixString);

	for (int32 Row = 0; Row < 4; ++Row)
	{
		for (int32 Col = 0; Col < 4; ++Col)
		{
			// Note: FMatrix is column based, glm::mat4 is row based, need to switch // orignal was commented
			cameraViewProj[Col][Row] = Matrix.M[Col][Row];
		}
	}

	extract_planes_from_projmat(cameraViewProj, frustumEquation);

	//vector<CustomChunk*> chunkList // orignal was commented
	chunkList.clear();
	fileValueList.clear();
	fileIndexList.clear();

	this->dataFolder = wstring((wchar_t*)TCHAR_TO_UTF16(*FPaths::ProjectPluginsDir())) + L"CustomOctreePlugin/Source/CustomOctreePlugin/101data2_collection/101data2";

	for (int i = 0; i <= _octree.GetTotalLevel(); i++) {
		ifstream* in1 = new ifstream, * in2 = new ifstream;
		wstring loadpath;
		if (_octree.GetTotalFrame() == 1)
			loadpath = this->dataFolder + L"/Level" + to_wstring(i) + L"_compressed.bin";
		else
			loadpath = this->dataFolder + to_wstring(nowFrame) + L"/Level" + to_wstring(i) + L"_compressed.bin";
		in1->open(loadpath, ios_base::in | ios_base::binary);
		fileValueList.push_back(in1);

		if (_octree.GetTotalFrame() == 1)
			loadpath = this->dataFolder + L"/Level" + to_wstring(i) + L"_index.bin";
		else
			loadpath = this->dataFolder + to_wstring(nowFrame) + L"/Level" + to_wstring(i) + L"_index.bin";
		in2->open(loadpath, ios_base::in | ios_base::binary);
		fileIndexList.push_back(in2);
	}

	baseFileValueList.clear();
	baseFileIndexList.clear();

	for (int i = 0; i <= _octree.GetTotalLevel(); i++) {
		ifstream* in1 = new ifstream, * in2 = new ifstream;
		wstring loadpath;
		if (_octree.GetTotalFrame() == 1)
			loadpath = this->dataFolder + L"/Level" + to_wstring(i) + L"_compressed.bin";
		else
			loadpath = this->dataFolder + to_wstring(nowFrame - ((nowFrame - 1) % timeBase)) + L"/Level" + to_wstring(i) + L"_compressed.bin";
		in1->open(loadpath, ios_base::in | ios_base::binary);
		baseFileValueList.push_back(in1);

		if (_octree.GetTotalFrame() == 1)
			loadpath = this->dataFolder + L"/Level" + to_wstring(i) + L"_index.bin";
		else
			loadpath = this->dataFolder + to_wstring(nowFrame - ((nowFrame - 1) % timeBase)) + L"/Level" + to_wstring(i) + L"_index.bin";
		in2->open(loadpath, ios_base::in | ios_base::binary);
		baseFileIndexList.push_back(in2);

	}

	loadChunkCount = 0;
	GetChunkInFrustum(_octree.GetRoot(), chunkList, frustumEquation);

	//UE_LOG(LogTemp, Log, TEXT("Loaded %d chunks."), loadChunkCount);
	//FVector playerPos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//UE_LOG(LogTemp, Log, TEXT("playerPos %f, %f %f"), playerPos.X, playerPos.Y, playerPos.Z);

	DrawCube(glm2FVec(_octree.GetMin()), glm2FVec(_octree.GetMax()));

	UpdateTexBuffer();

	planePMC->ClearAllMeshSections();
	isosurfacePMC->ClearAllMeshSections();
	isosurfacePMC2->ClearAllMeshSections();
	switch (drawType) {
	case 1:
		UpdateStreamLine(false);
		DrawStreamLines();
		break;
	case 2:
		UpdateStreamLine(true);
		DrawStreamLines();
		break;
	case 3:
		UpdatePlane();
		DrawPlane();
		break;
	case 4:
		UpdateIsosurface();
		DrawVorticity();
		break;
	case 5:
		UpdateIsosurface();
		DrawQCritirea();
		break;
	default:
		break;
	}

}

//Editing LoadChunkDataFromFile Function
void ASceneManagerTest::LoadChunkDataFromFile(CustomChunk* _Chunk, int _chunkListIndex) {
	if (DrawRedDot)
		DrawDebugPoint(GetWorld(), glm2FVec(_Chunk->center) * MyScale * 100.0f + Center, 5, FColor::Red, false, 0.1f);

	try {
		++loadChunkCount;
		Frame& fc = _octree.GetFrameCollection()[nowFrame - 1];
		//設定Tree中的當個Chunk對應ChunkList的Index,Chunk.dataIndex代表該Chunk在該Level中的Index(DFS)
		fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].chunkListIndex = _chunkListIndex;
		//更新該Chunk的所有parent的狀態為True
		CustomChunk* cc = _Chunk;
		while (1) {
			fc.levelFile[cc->level].chunk[cc->dataIndex].hasChildInChunkList = true;
			if (cc->parent != nullptr)
				cc = cc->parent;
			else
				break;
		}

		fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].points.resize(_octree.GetChunkPointCount());

		if (fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].chunkAge == 0 || !ENABLE_CACHE) {
			Frame& cachedFrame = _octree.GetCachedFrame();
			istream* fil = fileIndexList[_Chunk->level], * fvl = fileValueList[_Chunk->level];

			if (!fil || !fvl || !fil->good() || !fvl->good())
				return;

			int startIndex;
			fil->seekg(_Chunk->dataIndex * sizeof(int), ios::beg);
			fil->read((char*)&startIndex, sizeof(int));

			bool skipReading = false;
			if (startIndex == -1) {
				if (nowFrame - ((nowFrame - 1) % timeBase) != nowFrame
					&& cachedFrame.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].chunkAge != 0) {//Cached,Skip Reading
					fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].points
						= cachedFrame.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].points;
					skipReading = true;
				}
				if (!skipReading) {
					fil = baseFileIndexList[_Chunk->level];
					fil->seekg(_Chunk->dataIndex * sizeof(int), ios::beg);
					fil->read((char*)&startIndex, sizeof(int));
					fvl = baseFileValueList[_Chunk->level];
				}
			}

			if (!skipReading) {
				actuallyReadChunkCount++;
				fvl->seekg(startIndex, ios::beg);

				int sizeVelValues;
				int sizePreValues;
				vector<glm::vec3> velValues;
				vector<float> preValues;

				vector<unsigned char> velIndexes;
				velIndexes.resize(_octree.GetChunkPointCount());
				vector<unsigned char> preIndexes;
				preIndexes.resize(_octree.GetChunkPointCount());

				fvl->read((char*)&sizeVelValues, sizeof(sizeVelValues));
				velValues.resize(sizeVelValues);
				fvl->read((char*)&sizePreValues, sizeof(sizePreValues));
				preValues.resize(sizePreValues);
				fvl->read((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
				fvl->read((char*)preValues.data(), sizeof(float) * sizePreValues);
				fvl->read((char*)velIndexes.data(), sizeof(unsigned char) * velIndexes.size());
				fvl->read((char*)preIndexes.data(), sizeof(unsigned char) * preIndexes.size());

				for (int i = 0; i < _octree.GetChunkPointCount(); i++) {
					fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].points[i].SetXYZVel(velValues[velIndexes[i]]);
					fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].points[i].SetPressure(preValues[preIndexes[i]]);
				}
			}
		}
		if (ENABLE_CACHE)
			fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].chunkAge = 1;

	}
	catch (exception e)
	{
		cout << "Load Chunk Data From File Error! Cause: " << e.what() << endl;
		UE_LOG(LogTemp, Log, TEXT("Load Chunk Data From File Error!"));
		return;
	}
}

bool ASceneManagerTest::ClipFrustum(CustomChunk* _Chunk, float frustumEquation[24])
{
	float scaleSize = MyScale * 100.0f;
	glm::dvec4 _min = glm::dvec4(_Chunk->min[0], _Chunk->min[1], _Chunk->min[2], 1) * double(scaleSize) + glm::dvec4(Center.X, Center.Y, Center.Z, 1);
	glm::dvec4 _max = glm::dvec4(_Chunk->max[0], _Chunk->max[1], _Chunk->max[2], 1) * double(scaleSize) + glm::dvec4(Center.X, Center.Y, Center.Z, 1);

	// check box outside/inside of frustum
	for (int i = 0; i < 6; i++)
	{
		glm::dvec4 v(frustumEquation[i * 4 + 0], frustumEquation[i * 4 + 1], frustumEquation[i * 4 + 2], frustumEquation[i * 4 + 3]);
		if (dot(v, glm::dvec4(_min[0], _min[1], _min[2], 1.0)) > 0.0) continue;
		if (dot(v, glm::dvec4(_min[0], _min[1], _max[2], 1.0)) > 0.0) continue;
		if (dot(v, glm::dvec4(_min[0], _max[1], _min[2], 1.0)) > 0.0) continue;
		if (dot(v, glm::dvec4(_min[0], _max[1], _max[2], 1.0)) > 0.0) continue;
		if (dot(v, glm::dvec4(_max[0], _min[1], _min[2], 1.0)) > 0.0) continue;
		if (dot(v, glm::dvec4(_max[0], _min[1], _max[2], 1.0)) > 0.0) continue;
		if (dot(v, glm::dvec4(_max[0], _max[1], _min[2], 1.0)) > 0.0) continue;
		if (dot(v, glm::dvec4(_max[0], _max[1], _max[2], 1.0)) > 0.0) continue;
		return false;
	}
	return true;
}

//Editing GetChunkInFrustum Function
void ASceneManagerTest::GetChunkInFrustum(CustomChunk* _Chunk, vector<CustomChunk*>& _chunkList, float frustumEquation[24]) {
	if (_Chunk->child.size() == 0) {
		chunkList.push_back(_Chunk);
		LoadChunkDataFromFile(_Chunk, chunkList.size() - 1);
	}
	else {
		float scaleSize = 100.0f * MyScale;
		for (int i = 0; i < 8; i++) {
			if (ClipFrustum(_Chunk->child[i], frustumEquation)) {
				FVector Loc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
				FVector distVec = Loc - (glm2FVec(_Chunk->child[i]->center) * scaleSize + Center);
				//UE_LOG(LogTemp, Log, TEXT("distVec[%i]: %f, %f, %f"), i, distVec.X, distVec.Y, distVec.Z);

				if (distVec.Length() < octreeLODList[_octree.GetTotalLevel() - _Chunk->level] * baseViewDistance) {
					GetChunkInFrustum(_Chunk->child[i], _chunkList, frustumEquation);
				}
				else {
					chunkList.push_back(_Chunk->child[i]);
					LoadChunkDataFromFile(_Chunk->child[i], chunkList.size() - 1);
				}
			}
		}
	}
}

double ASceneManagerTest::dot(const glm::dvec4& vec1, const glm::dvec4& vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}

void ASceneManagerTest::extract_planes_from_projmat(glm::mat4& mat, float frustumEquation[24])
{
	for (int i = 4; i--; ) frustumEquation[i] = (mat[i][3] + mat[i][0]);
	for (int i = 4; i--; ) frustumEquation[i + 4] = (mat[i][3] - mat[i][0]);
	for (int i = 4; i--; ) frustumEquation[i + 8] = (mat[i][3] + mat[i][1]);
	for (int i = 4; i--; ) frustumEquation[i + 12] = (mat[i][3] - mat[i][1]);
	for (int i = 4; i--; ) frustumEquation[i + 16] = (mat[i][3] + mat[i][2]);
	for (int i = 4; i--; ) frustumEquation[i + 20] = (mat[i][3] - mat[i][2]);
}

FMatrix ASceneManagerTest::GetCameraViewProj() {
	ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if (LocalPlayer != nullptr && LocalPlayer->ViewportClient != nullptr && LocalPlayer->ViewportClient->Viewport)
	{
		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			LocalPlayer->ViewportClient->Viewport,
			GetWorld()->Scene,
			LocalPlayer->ViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(true));

		FVector ViewLocation;
		FRotator ViewRotation;
		FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, LocalPlayer->ViewportClient->Viewport);
		if (SceneView != nullptr)
		{
			return SceneView->ViewMatrices.GetViewProjectionMatrix();
		}
	}
	return FMatrix();
}

void ASceneManagerTest::DrawCube(FVector min, FVector max) {
	const vector<int> rotateArr = { 0b00, 0b01, 0b11, 0b10 };
	for (int i = 0; i < 4; ++i) {
		int index = rotateArr[i];
		FVector base((index & 1) ? min.X : max.X, (index & 2) ? min.Y : max.Y, min.Z);
		FVector target(base.X, base.Y, max.Z);
		float scaleSize = 100.0f * MyScale;
		//DrawDebugLine(GetWorld(), base, target, FColor::Cyan, false, 1, 0, 10);
		DrawDebugLine(GetWorld(), base * scaleSize + Center, target * scaleSize + Center, FColor::Cyan, false, 1, 0, 5 * MyScale);

		int index2 = rotateArr[(i + 1) & 3];
		target = FVector((index2 & 1) ? min.X : max.X, (index2 & 2) ? min.Y : max.Y, min.Z);
		//DrawDebugLine(GetWorld(), base, target, FColor::Cyan, false, 1, 0, 10);
		DrawDebugLine(GetWorld(), base * scaleSize + Center, target * scaleSize + Center, FColor::Cyan, false, 1, 0, 5 * MyScale);

		base.Z = target.Z = max.Z;
		//DrawDebugLine(GetWorld(), base, target, FColor::Cyan, false, 1, 0, 10);
		DrawDebugLine(GetWorld(), base * scaleSize + Center, target * scaleSize + Center, FColor::Cyan, false, 1, 0, 5 * MyScale);
	}
}

void ASceneManagerTest::UpdateTexBuffer()
{
	try {
		index_tbo_data.clear();
		status_tbo_data.clear();
		vel_tbo_data.clear();
		pre_tbo_data.clear();

		Frame& fc = _octree.GetFrameCollection()[nowFrame - 1];
		CustomChunk* _Chunk = _octree.GetRoot();

		if (fc.levelFile[0].chunk[0].hasChildInChunkList == false) {//填Root的G，有節點
			index_tbo_data.push_back(-10);
			status_tbo_data.push_back(0);
			return;
		}
		else {
			if (fc.levelFile[0].chunk[0].chunkListIndex == -1 && _Chunk->child.size() != 0) {

				index_tbo_data.push_back(1);
				status_tbo_data.push_back(1);
				int startIndex = index_tbo_data.size();
				for (int i = 0; i < 8; i++) {
					index_tbo_data.push_back(-2);
					status_tbo_data.push_back(-2);
				}
				for (int i = 0; i < 8; i++) {
					FillIndexTex_Recursive(_Chunk->child[i], fc, startIndex + i);
				}
			}
			else {
				index_tbo_data.push_back(fc.levelFile[0].chunk[0].chunkListIndex);
				status_tbo_data.push_back(2);
			}
		}


		int cpc = _octree.GetChunkPointCount();
		vel_tbo_data.resize(chunkList.size() * 3 * cpc);
		pre_tbo_data.resize(chunkList.size() * cpc);
		glm::vec3 vel;
		for (int i = 0; i < chunkList.size(); i++) {
			vector<CustomPointData>& cp = fc.levelFile[chunkList[i]->level].chunk[chunkList[i]->dataIndex].points;
			for (int j = 0; j < cpc; j++) {
				vel = cp[j].GetVel();
				vel_tbo_data[(i * cpc + j) * 3 + 0] = vel.x;
				vel_tbo_data[(i * cpc + j) * 3 + 1] = vel.y;
				vel_tbo_data[(i * cpc + j) * 3 + 2] = vel.z;
				pre_tbo_data[(i * cpc + j)] = cp[j].GetPressure();
			}
		}
	}
	catch (exception e)
	{
		cout << "Update Tex Buffer Error! Cause: " << e.what() << endl;
		return;
	}
}

void ASceneManagerTest::FillIndexTex_Recursive(CustomChunk* _Chunk, Frame& fc, int tbo_index) {
	//G:0的話代表自己和子節點都沒有被載入，1的話代表有某個子節點被載入，2的話代表這個節點有被載入
	//R在G為0的情況無效，在G為1的情況代表下個需要Trace的Index，在G為2的情況代表該Chunk在ChunkList中的Index
	//自己和子節點都沒有載入，R無效，在G填0，Return
	Chunk& c = fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex];
	if (c.hasChildInChunkList == false) {
		index_tbo_data[tbo_index] = -3;
		status_tbo_data[tbo_index] = 0;
	}
	//自己或子節點有載入
	else {
		//子節點有人載入，往下Load，R填子節點Index，G填1
		if (c.chunkListIndex == -1 && _Chunk->child.size() != 0) {

			int startIndex = index_tbo_data.size();
			index_tbo_data[tbo_index] = startIndex;
			status_tbo_data[tbo_index] = 1;

			for (int i = 0; i < 8; i++) {
				index_tbo_data.push_back(-4);
				status_tbo_data.push_back(-4);
			}

			for (int i = 0; i < 8; i++) {
				FillIndexTex_Recursive(_Chunk->child[i], fc, startIndex + i);
			}
		}
		//自己有載入，R直接填chunkListIndex，G填2
		else {
			index_tbo_data[tbo_index] = c.chunkListIndex;
			status_tbo_data[tbo_index] = 2;
		}
	}
}

void ASceneManagerTest::CreateTextures() {
	float IndexSizeSqrt = powf(index_tbo_data.size(), 0.5);
	float StatusSizeSqrt = powf(status_tbo_data.size(), 0.5);
	float VelSizeSqrt = powf(vel_tbo_data.size() / 3, 0.5);
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
	FFloat16* Ptr0 = (FFloat16*)IndexTex->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write

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

	IndexTex->GetPlatformData()->Mips[0].BulkData.Unlock();

	// StatusTex write data
	FFloat16* Ptr1 = (FFloat16*)StatusTex->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write

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

	StatusTex->GetPlatformData()->Mips[0].BulkData.Unlock();

	// VelTex write data
	FFloat16* Ptr2 = (FFloat16*)VelTex->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write

	// run through every pixel
	for (int i = 0; i < VelTex->GetSizeY(); i++) {
		for (int j = 0; j < VelTex->GetSizeX(); j++) {
			int32 index = j + i * VelTex->GetSizeX();
			int32 Idx = 4 * index;
			FFloat16 val;
			if (index < vel_tbo_data.size()) {
				for (int k = 0; k < 3; k++) {
					val = vel_tbo_data[index * 3 + k];
					Ptr2[Idx + k] = val; // real R
				}
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

	VelTex->GetPlatformData()->Mips[0].BulkData.Unlock();

	// PreTex write data
	FFloat16* Ptr3 = (FFloat16*)PreTex->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE); // this can do read and write

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

	PreTex->GetPlatformData()->Mips[0].BulkData.Unlock();

	IndexTex->MipGenSettings = IndexOldMipSetting;
	StatusTex->MipGenSettings = StatusOldMipSetting;
	VelTex->MipGenSettings = VelOldMipSetting;
	PreTex->MipGenSettings = PreOldMipSetting;
	IndexTex->UpdateResource();
	StatusTex->UpdateResource();
	VelTex->UpdateResource();
	PreTex->UpdateResource();
}

void ASceneManagerTest::UpdatePlane() {
	//cout << "Chunk count: " << chunkList.size() << endl;

	glm::vec3 dist = _octree.GetMax() - _octree.GetMin();
	int offsetAxis;
	int planeA, planeB;
	if (this->selectedAxis == 0) {
		offsetAxis = 0;
		planeA = 1;
		planeB = 2;
	}
	else if (this->selectedAxis == 1) {
		offsetAxis = 1;
		planeA = 0;
		planeB = 2;
	}
	else if (this->selectedAxis == 2) {
		offsetAxis = 2;
		planeA = 0;
		planeB = 1;
	}


	glm::vec3 lb, rb, lt, rt;
	glm::vec3 startPos = _octree.GetMin();
	startPos[offsetAxis] = startPos[offsetAxis] + dist[offsetAxis] * this->planeOffset;

	lb = rb = lt = rt = startPos;
	rb[planeA] = startPos[planeA] + dist[planeA];
	lt[planeB] = startPos[planeB] + dist[planeB];
	rt[planeA] = startPos[planeA] + dist[planeA];
	rt[planeB] = startPos[planeB] + dist[planeB];

	/*float points[] = {
		lb[0],lb[1],lb[2],
		rb[0],rb[1],rb[2],
		rt[0],rt[1],rt[2],
		lt[0],lt[1],lt[2],
	};*/

	float scaleSize = 100.0f * MyScale;
	TArray<FVector> points;
	points.Add(glm2FVec(lb) * scaleSize + Center);
	points.Add(glm2FVec(rb) * scaleSize + Center);
	points.Add(glm2FVec(rt) * scaleSize + Center);
	points.Add(glm2FVec(lt) * scaleSize + Center);

	TArray<int> indexs{
		0,2,1,
		0,3,2,
		0,1,2,
		0,2,3
	};

	TArray<FVector2D> UV0;
	TArray<FLinearColor> Colors;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector> Normals;

	UV0.Init(FVector2D(0, 0), points.Num());
	Colors.Init(FLinearColor(1, 0, 0, 0.3), points.Num());
	Tangents.Init(FProcMeshTangent(1, 0, 0), points.Num());
	Normals.Init(FVector(0, 0, 1), points.Num());

	planePMC->ClearAllMeshSections();
	planePMC->CreateMeshSection_LinearColor(0, points, indexs, Normals, UV0, Colors, Tangents, false);
}

void ASceneManagerTest::DrawPlane() {
	CreateTextures();

	isosurfacePMC->ClearAllMeshSections();
	isosurfacePMC2->ClearAllMeshSections();

	for (int32 j = 0; j < planePMC->GetNumSections(); j++) {
		planePMC->SetMaterial(j, MaterialToApplyToClickedObject);
		UMaterialInstanceDynamic* MID = planePMC->CreateAndSetMaterialInstanceDynamic(j);
		MID->SetTextureParameterValue("IndexTex", (UTexture*)IndexTex);
		MID->SetTextureParameterValue("StatusTex", (UTexture*)StatusTex);
		MID->SetTextureParameterValue("VelTex", (UTexture*)VelTex);
		MID->SetTextureParameterValue("PreTex", (UTexture*)PreTex);

		MID->SetScalarParameterValue("index_tex_size", IndexTex->GetSizeX());
		MID->SetScalarParameterValue("vel_tex_size", VelTex->GetSizeX());

		MID->SetScalarParameterValue("index_length", index_tbo_data.size());
		MID->SetScalarParameterValue("chunklist_length", chunkList.size());

		MID->SetVectorParameterValue("chunkSize", glm2FVec(glm::vec3(_octree.GetChunkSize())));
		MID->SetVectorParameterValue("minPos", glm2FVec(_octree.GetMin()));
		MID->SetVectorParameterValue("maxPos", glm2FVec(_octree.GetMax()));
		MID->SetVectorParameterValue("spacing", glm2FVec(_octree.GetSampledSpacing()));
		MID->SetScalarParameterValue("totalLevel", _octree.GetTotalLevel());

		MID->SetScalarParameterValue("renderingMode", planeDrawType);
		if (planeDrawType == 0) {
			MID->SetScalarParameterValue("minValue", 0.0f);
			MID->SetScalarParameterValue("maxValue", _octree.GetMaxXVel());
		}
		else if (planeDrawType == 1) {
			MID->SetScalarParameterValue("minValue", 0.0f);
			MID->SetScalarParameterValue("maxValue", _octree.GetMaxYVel());
		}
		else if (planeDrawType == 2) {
			MID->SetScalarParameterValue("minValue", 0.0f);
			MID->SetScalarParameterValue("maxValue", _octree.GetMaxZVel());
		}
		else if (planeDrawType == 3) {
			MID->SetScalarParameterValue("minValue", _octree.GetMinPressure());
			MID->SetScalarParameterValue("maxValue", _octree.GetMaxPressure());
		}
		else if (planeDrawType == 4) {
			MID->SetScalarParameterValue("minValue", 0.0f);
			MID->SetScalarParameterValue("maxValue", _octree.GetMaxMagnitude());
		}

		MID->SetScalarParameterValue("scale", MyScale * 100.f);
		MID->SetVectorParameterValue("center", Center);
	}
}

void ASceneManagerTest::UpdateStreamLine(bool isDynamic) {
	std::vector<glm::vec4> points;
	points.resize(lineGenerator.spawnCount);
	UpdateSpawnPointPositions(points);

	streamLineParams = FStreamLineParameters(points, index_tbo_data.size(), chunkList.size(), _octree);
	streamLineParams.stepDivider = lineGenerator.stepDivider;
	streamLineParams.lineThickness = lineGenerator.lineThickness;
	streamLineParams.maxMag = 0.033f / streamLineParams.stepDivider * _octree.GetMaxMagnitude();

	streamLineParams.visibleLength = visibleLength;
	streamLineParams.invisibleLength = invisibleLength;
	streamLineParams.animateTime = animateTime;
	streamLineParams.hack = hack;
	streamLineParams.center = Center;
	streamLineParams.myScale = MyScale;

	if (isDynamic)
		FMyShaders::GetDynamicStreamLine(index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, streamLineParams);
	else
		FMyShaders::GetSteadyStreamLine(index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, streamLineParams);
}

void ASceneManagerTest::DrawStreamLines() {
	FlushRenderingCommands();

	lineComponent->Flush();
	lineComponent->DrawLines(streamLineParams.lines);

	if (clock() - lastAnimate > (double)CLOCKS_PER_SEC / 33.3333) {
		if (first) { animateTime = visibleLength + invisibleLength - 1; first = 0; }
		lastAnimate = clock();
		animateTime -= animateSpeed;
		if (animateTime < 0)
			animateTime = visibleLength + invisibleLength - 1;
	}
}

void ASceneManagerTest::UpdateSpawnPointPositions(std::vector<glm::vec4>& points) {
	glm::mat4 rotatemat(1.0f);
	rotatemat = glm::rotate(rotatemat, glm::radians(lineGenerator.rotation[0]), glm::vec3(1, 0, 0));
	rotatemat = glm::rotate(rotatemat, glm::radians(lineGenerator.rotation[1]), glm::vec3(0, 1, 0));
	rotatemat = glm::rotate(rotatemat, glm::radians(lineGenerator.rotation[2]), glm::vec3(0, 0, 1));

	int sideCount = sqrt(lineGenerator.spawnCount);
	glm::vec3 unitPos(0, -1, -1);
	float bias = 2.f / (float)(sideCount - 1);

	switch (lineGenerator.spawnType)
	{
	case SpawnType::SPHERE:
		for (int i = 0; i < lineGenerator.spawnCount; i++)
		{
			glm::vec3 dist = _octree.GetMax() - _octree.GetMin();
			glm::vec3 startPos = _octree.GetMin();

			glm::vec4 pos = glm::vec4(startPos + dist * lineGenerator.transform +
				glm::vec3(glm::vec4(lineGenerator.randomValue[i] * lineGenerator.scale, 1) * rotatemat), 0);
			points[i] = pos;
		}
		break;
	case SpawnType::SQUARE:
		for (int i = 0; i < sideCount; i++)
		{
			for (int j = 0; j < sideCount; j++) {
				glm::vec3 dist = _octree.GetMax() - _octree.GetMin();
				glm::vec3 startPos = _octree.GetMin();

				glm::vec4 pos = glm::vec4(startPos + dist * lineGenerator.transform +
					glm::vec3(glm::vec4(unitPos * lineGenerator.scale, 1) * rotatemat), 0);
				points[i * sideCount + j] = pos;
				unitPos[1] += bias;
			}
			unitPos[2] += bias;
			unitPos[1] = -1;
		}
		break;
	case SpawnType::LINE:
		unitPos = glm::vec3(0, -1, 0);
		bias = 2.f / (float)(lineGenerator.spawnCount - 1);
		for (int i = 0; i < lineGenerator.spawnCount; i++) {
			glm::vec3 dist = _octree.GetMax() - _octree.GetMin();
			glm::vec3 startPos = _octree.GetMin();

			glm::vec3 apply = glm::vec3(glm::vec4(unitPos * lineGenerator.scale, 1) * rotatemat);
			glm::vec4 pos = glm::vec4(startPos + dist * lineGenerator.transform +
				apply, 0);
			/*glm::vec4 pos = glm::vec4(startPos + dist * lineGenerator.transform +
				glm::vec3(glm::vec4(unitPos * lineGenerator.scale, 1) * rotatemat), 0);*/
			points[i] = pos;
			unitPos[1] += bias;
		}
		break;
	}
}

void ASceneManagerTest::DrawVorticity() {
	planePMC->ClearAllMeshSections();
	isosurfacePMC2->ClearAllMeshSections();

	UpdateIsosurface();

	isosurfaceParams = FIsosurfaceParameters(index_tbo_data.size(), chunkList.size(), vorticityThreshold, GetCameraViewProj(), _octree);
	isosurfaceParams.minIsovalue = 0;
	isosurfaceParams.maxIsovalue = 0;
	isosurfaceParams.isQCritirea = 0;
	isosurfaceParams.myScale = MyScale;
	isosurfaceParams.center = Center;

	FMyShaders::GetIsosufacePos(isosurfacePointList, index_tbo_data, status_tbo_data, vel_tbo_data, isosurfaceParams);

	FlushRenderingCommands();

	TArray<FVector2D> UV0;
	TArray<FLinearColor> Colors;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector> Normals;

	UV0.Init(FVector2D(0, 0), isosurfaceParams.outputPos.Num());
	Colors.Init(FLinearColor(1, 0, 0, 1), isosurfaceParams.outputPos.Num());
	Tangents.Init(FProcMeshTangent(1, 0, 0), isosurfaceParams.outputPos.Num());
	Normals.Init(FVector(0, 0, 1), isosurfaceParams.outputPos.Num());

	isosurfacePMC->ClearAllMeshSections();
	isosurfacePMC->CreateMeshSection_LinearColor(0, isosurfaceParams.outputPos, isosurfaceParams.OutTris, Normals, UV0, Colors, Tangents, false);
}

void ASceneManagerTest::DrawQCritirea() {
	UpdateIsosurface();

	isosurfaceParams = FIsosurfaceParameters(index_tbo_data.size(), chunkList.size(), QCritireaThreshold1, GetCameraViewProj(), _octree);
	isosurfaceParams.minIsovalue = _octree.GetMinQCritirea();
	isosurfaceParams.maxIsovalue = _octree.GetMaxQCritirea();
	isosurfaceParams.isQCritirea = 1;
	isosurfaceParams.myScale = MyScale;
	isosurfaceParams.center = Center;

	FMyShaders::GetIsosufacePos(isosurfacePointList, index_tbo_data, status_tbo_data, vel_tbo_data, isosurfaceParams);

	FlushRenderingCommands();

	TArray<FVector2D> UV0;
	TArray<FLinearColor> Colors;
	TArray<FProcMeshTangent> Tangents;
	TArray<FVector> Normals;

	UV0.Init(FVector2D(0, 0), isosurfaceParams.outputPos.Num());
	Colors.Init(FLinearColor(1, 0, 0, 1), isosurfaceParams.outputPos.Num());
	Tangents.Init(FProcMeshTangent(1, 0, 0), isosurfaceParams.outputPos.Num());
	Normals.Init(FVector(0, 0, 1), isosurfaceParams.outputPos.Num());

	isosurfacePMC->ClearAllMeshSections();
	isosurfacePMC->CreateMeshSection_LinearColor(0, isosurfaceParams.outputPos, isosurfaceParams.OutTris, Normals, UV0, Colors, Tangents, false);

	isosurfaceParams.isovalue = QCritireaThreshold2;

	FMyShaders::GetIsosufacePos(isosurfacePointList, index_tbo_data, status_tbo_data, vel_tbo_data, isosurfaceParams);

	FlushRenderingCommands();

	UV0.Init(FVector2D(0, 0), isosurfaceParams.outputPos.Num());
	Colors.Init(FLinearColor(1, 0, 0, 1), isosurfaceParams.outputPos.Num());
	Tangents.Init(FProcMeshTangent(1, 0, 0), isosurfaceParams.outputPos.Num());
	Normals.Init(FVector(0, 0, 1), isosurfaceParams.outputPos.Num());

	isosurfacePMC2->ClearAllMeshSections();
	isosurfacePMC2->CreateMeshSection_LinearColor(0, isosurfaceParams.outputPos, isosurfaceParams.OutTris, Normals, UV0, Colors, Tangents, false);
}

void ASceneManagerTest::UpdateIsosurface() {
	isosurfacePointList.clear();
	isosurfaceIndexList.clear();

	for (int i = 0; i < chunkList.size(); i++)
	{
		glm::vec3 min; //cv::Vec3f min;
		min = chunkList[i]->min + (_octree.GetSampledSpacing() / 2.f * (float)pow(2, _octree.GetTotalLevel() - chunkList[i]->level));

		glm::vec3 p = min; //cv::Vec3f p = min;
		for (int l = 0; l < _octree.GetChunkSize()[2]; l++)
		{
			for (int k = 0; k < _octree.GetChunkSize()[1]; k++)
			{
				for (int j = 0; j < _octree.GetChunkSize()[0]; j++)
				{
					float isosurfacePoint[] =
					{
						p[0], p[1], p[2]
					};
					isosurfacePointList.insert(isosurfacePointList.end(), std::begin(isosurfacePoint), std::end(isosurfacePoint));

					isosurfaceIndexList.push_back(isosurfaceIndexList.size());
					p[0] += _octree.GetSampledSpacing()[0] * pow(2, _octree.GetTotalLevel() - chunkList[i]->level);
				}
				p[0] = min[0];
				p[1] += _octree.GetSampledSpacing()[1] * pow(2, _octree.GetTotalLevel() - chunkList[i]->level);
			}
			p[1] = min[1];
			p[2] += _octree.GetSampledSpacing()[2] * pow(2, _octree.GetTotalLevel() - chunkList[i]->level);
		}
	}
}

void ASceneManagerTest::UpdateCenter(FVector InCenter) {
	Center = InCenter;
}

void ASceneManagerTest::UpdateScale(float InScale) {
	MyScale = InScale;
}

void ASceneManagerTest::SetDrawType(int DrawType) {
	this->drawType = DrawType;
}

void ASceneManagerTest::SetStepDivider(int stepDivider) {
	lineGenerator.stepDivider = stepDivider;
}

void ASceneManagerTest::SetSpawnCount(int spawnCount) {
	if (lineGenerator.spawnType == SpawnType::SQUARE)
		lineGenerator.spawnCount = spawnCount < 20 ? 4 : pow(spawnCount / 10, 2);
	else
		lineGenerator.spawnCount = spawnCount;
}

void ASceneManagerTest::SetSpawnRange(float spawnRange) {
	lineGenerator.scale = spawnRange;
}

void ASceneManagerTest::SetXPos(float xPos) {
	lineGenerator.transform.x = xPos;
}

void ASceneManagerTest::SetYPos(float yPos) {
	lineGenerator.transform.y = yPos;
}

void ASceneManagerTest::SetZPos(float zPos) {
	lineGenerator.transform.z = zPos;
}

void ASceneManagerTest::SetXRot(float xRot) {
	lineGenerator.rotation.x = xRot;
}

void ASceneManagerTest::SetYRot(float yRot) {
	lineGenerator.rotation.y = yRot;
}

void ASceneManagerTest::SetZRot(float zRot) {
	lineGenerator.rotation.z = zRot;
}

void ASceneManagerTest::SetLineThickness(float lineThickness) {
	lineGenerator.lineThickness = lineThickness;
}

void ASceneManagerTest::SetSpawnType(int spawnType) {
	if (spawnType == 0) {
		lineGenerator.spawnType = SpawnType::SPHERE;
	}
	else if (spawnType == 1) {
		lineGenerator.spawnType = SpawnType::SQUARE;
		lineGenerator.spawnCount = lineGenerator.spawnCount < 20 ? 4 : pow(lineGenerator.spawnCount / 10, 2);
	}
	else if (spawnType == 2) {
		lineGenerator.spawnType = SpawnType::LINE;
	}
}

void ASceneManagerTest::SetVisibleLength(float VisibleLength) {
	this->visibleLength = VisibleLength;
}

void ASceneManagerTest::SetInvisibleLength(float InvisibleLength) {
	this->invisibleLength = InvisibleLength;
}

void ASceneManagerTest::SetAnimateSpeed(float AnimateSpeed) {
	this->animateSpeed = AnimateSpeed;
}

void ASceneManagerTest::SetSelectedAxis(int SelectedAxis) {
	this->selectedAxis = SelectedAxis;
}

void ASceneManagerTest::SetPlaneOffset(float PlaneOffset) {
	this->planeOffset = PlaneOffset;
}

void ASceneManagerTest::SetPlaneDrawType(int PlaneDrawType) {
	this->planeDrawType = PlaneDrawType;
}

void ASceneManagerTest::SetVoricityValue(float voricityValue) {
	this->vorticityThreshold = voricityValue;
}

void ASceneManagerTest::SetQCritirea1Value(float QCritirea1Value) {
	this->QCritireaThreshold1 = QCritirea1Value;
}

void ASceneManagerTest::SetQCritirea2Value(float QCritirea2Value) {
	this->QCritireaThreshold2 = QCritirea2Value;
}

void ASceneManagerTest::Hack() {
	hack = !hack;
}

void ASceneManagerTest::SetData(FString FileName, FVector InCenter, float InScale) {
	//FString FilePath = FPaths::Combine(FPaths::ProjectPluginsDir(), "CustomOctreePlugin/Source/CustomOctreePlugin/101data2_collection/gridinfo.bin");
	FString FilePath = FPaths::Combine(FPaths::ProjectDir(), "testpak/", FileName, "/gridinfo.bin");

	_octree.SetupInfo(FilePath, 1);

	fileValueList.clear();
	fileIndexList.clear();
	baseFileValueList.clear();
	baseFileIndexList.clear();

	octreeLODList.clear();
	octreeLODList.push_back(1);
	octreeLODList.push_back(2);
	octreeLODList.push_back(4);
	octreeLODList.push_back(8);
	octreeLODList.push_back(16);
	octreeLODList.push_back(32);
	octreeLODList.push_back(64);

	Center = InCenter;
	MyScale = InScale;

	drawing = true;
}

void ASceneManagerTest::ClearData() {
	_octree.CleanUpChunkStructure();

	fileValueList.clear();
	fileIndexList.clear();
	baseFileValueList.clear();
	baseFileIndexList.clear();

	octreeLODList.clear();

	Center = FVector(0, 0, 0);
	MyScale = 0.f;

	drawing = false;
}