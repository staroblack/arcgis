// Fill out your copyright notice in the Description page of Project Settings.

#include "SceneManagerTest.h"
#include "RenderGraphBuilder.h"
#include "Interfaces/IPluginManager.h"
#include "MyShaders/Public/MyShaders.h"

inline FVector glm2FVec(const glm::vec3& p) {
	return FVector(p.x, p.y, p.z);
}

inline FVector3f glm2FVec3f(const glm::vec3& p) {
	return FVector3f(p.x, p.y, p.z);
}

LineGenerator::LineGenerator() {
	//transform = glm::vec3(0.3f, 0.5f, 0.05f);
	//transform = glm::vec3(20.f, 50.f, 9.f);
	transform = glm::vec3(0.2f, 0.5f, 0.09f);
	rotation = glm::vec3(0, 0, 0);
	scale = 0.3f;
	//scale = 4000.0f;
	spawnCount = 10;
}

FSteadyStreamParameters::FSteadyStreamParameters() {
	lines.Empty();
}

FSteadyStreamParameters::FSteadyStreamParameters(std::vector<glm::vec4>& point, int index_length, int chunklist_length, CustomOctree& octree) {
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
	stepDivider = 2;
	indexLength = index_length;
	chunkListLength = chunklist_length;
	chunkSize = glm2FVec3f(glm::vec3(octree.GetChunkSize()));
	minPos = glm2FVec3f(octree.GetMin());
	maxPos = glm2FVec3f(octree.GetMax());
	spacing = glm2FVec3f(octree.GetSampledSpacing());
	totalLevel = octree.GetTotalLevel();
	maxMag = 0.033f / stepDivider * octree.GetMaxMagnitude();
}

FDynamicStreamParameters::FDynamicStreamParameters() {
	lines.Empty();
}

FDynamicStreamParameters::FDynamicStreamParameters(std::vector<glm::vec4>& point, int index_length, int chunklist_length, CustomOctree& octree) {
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
	stepDivider = 53;
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

	maxMag = 0.033f / stepDivider * octree.GetMaxMagnitude();
}
// Sets default values
ASceneManagerTest::ASceneManagerTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	randomComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Random Component"));
	randomComponent->SetupAttachment(RootComponent);

	lineComponent = CreateDefaultSubobject<ULineBatchComponent>(TEXT("LineBatcher"));;

	steadyStreamParams = FSteadyStreamParameters();
	dynamicStreamParams = FDynamicStreamParameters();
}

// Called when the game starts or when spawned
void ASceneManagerTest::BeginPlay()
{
	Super::BeginPlay();

	//Testing SetupInfo
	//FString FilePath = FPaths::Combine(FPaths::ProjectPluginsDir(), "CustomOctreePlugin/Source/CustomOctreePlugin/uniform_1f_collection/gridinfo.bin");
	FString FilePath = FPaths::Combine(FPaths::ProjectPluginsDir(), "CustomOctreePlugin/Source/CustomOctreePlugin/101data2_collection/gridinfo.bin");

	_octree.SetupInfo(FilePath, 1);
	int totalLevel = _octree.GetTotalLevel();
	UE_LOG(LogTemp, Log, TEXT("totalLevel is %d"), totalLevel);

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
}

void ASceneManagerTest::BeginDestroy()
{
	Super::BeginDestroy();
}

// Called every frame
void ASceneManagerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float frustumEquation[24];
	//glm::mat4 cameraViewProj = cameraProj * cameraView; // original was commented
	glm::mat4 cameraViewProj = glm::mat4(
		glm::vec4(-0.806148f, 1.50818f, 0.726391f, 0.690957f),
		glm::vec4(-1.39081f, -0.54731f, -0.498509f, -0.474192f),
		glm::vec4(0.190708f, 2.38381f, -0.573619f, -0.545638f),
		glm::vec4(0.0669274f, -0.2095f, 0.481997f, 0.653607f)
	);

	FMatrix camViewProjMat;
	FMatrix Matrix = GetCameraViewProj();
	FString MatrixString = FString::Printf(TEXT("Matrix: [%f, %f, %f, %f], [%f, %f, %f, %f], [%f, %f, %f, %f], [%f, %f, %f, %f]"),
		Matrix.M[0][0], Matrix.M[0][1], Matrix.M[0][2], Matrix.M[0][3],
		Matrix.M[1][0], Matrix.M[1][1], Matrix.M[1][2], Matrix.M[1][3],
		Matrix.M[2][0], Matrix.M[2][1], Matrix.M[2][2], Matrix.M[2][3],
		Matrix.M[3][0], Matrix.M[3][1], Matrix.M[3][2], Matrix.M[3][3]);

	//UE_LOG(LogTemp, Log, TEXT("%s"), *MatrixString);
	//[0.307379, 1.286949, 0.000000, 0.603157], 
	// [0.864823, -0.457413, 0.000000, -0.214377],
	//  [-0.000000, 1.137994, 0.000000, -0.768274], 
	// [-17.340699, 254.286230, 10.000000, 377.376608]

	FMatrix TestMatrix;
	TestMatrix.M[0][0] = 0.307379;
	TestMatrix.M[0][1] = 1.286949;
	TestMatrix.M[0][2] = 0.000000;
	TestMatrix.M[0][3] = 0.603157;

	TestMatrix.M[0][0] = 0.864823;
	TestMatrix.M[0][1] = -0.457413;
	TestMatrix.M[0][2] = 0.000000;
	TestMatrix.M[0][3] = -0.214377;

	TestMatrix.M[0][0] = 0.0;
	TestMatrix.M[0][1] = 1.137994;
	TestMatrix.M[0][2] = 0.000000;
	TestMatrix.M[0][3] = -0.768274;

	TestMatrix.M[0][0] = -17.340699;
	TestMatrix.M[0][1] = 254.286230;
	TestMatrix.M[0][2] = 10.000000;
	TestMatrix.M[0][3] = 377.376608;


	for (int32 Row = 0; Row < 4; ++Row)
	{
		for (int32 Col = 0; Col < 4; ++Col)
		{
			// Note: FMatrix is column based, glm::mat4 is row based, need to switch // orignal was commented
			//cameraViewProj[Col][Row] = Matrix.M[Row][Col]; // orignal was commented
			cameraViewProj[Col][Row] = TestMatrix.M[Col][Row];
		}
	}

	extract_planes_from_projmat(cameraViewProj, frustumEquation);

	//vector<CustomChunk*> chunkList // orignal was commented
	if (!once) {
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
			//cout << loadpath << endl;

			if (_octree.GetTotalFrame() == 1)
				loadpath = this->dataFolder + L"/Level" + to_wstring(i) + L"_index.bin";
			else
				loadpath = this->dataFolder + to_wstring(nowFrame) + L"/Level" + to_wstring(i) + L"_index.bin";
			in2->open(loadpath, ios_base::in | ios_base::binary);
			fileIndexList.push_back(in2);
			//cout << loadpath << endl;
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
			//cout << loadpath << endl;

			if (_octree.GetTotalFrame() == 1)
				loadpath = this->dataFolder + L"/Level" + to_wstring(i) + L"_index.bin";
			else
				loadpath = this->dataFolder + to_wstring(nowFrame - ((nowFrame - 1) % timeBase)) + L"/Level" + to_wstring(i) + L"_index.bin";
			in2->open(loadpath, ios_base::in | ios_base::binary);
			baseFileIndexList.push_back(in2);

		}

		loadChunkCount = 0;
		GetChunkInFrustum(_octree.GetRoot(), chunkList, frustumEquation);

		once = true;
	}
	

	UE_LOG(LogTemp, Log, TEXT("Loaded %d chunks."), loadChunkCount);
	FVector playerPos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("Player %f, %f %f"), playerPos.X, playerPos.Y, playerPos.Z);

	DrawCube(glm2FVec(_octree.GetMin()), glm2FVec(_octree.GetMax()));

	UpdateTexBuffer();

	lineComponent->Flush();
	//lineComponent->DrawLines(steadyStreamParams.lines);
	lineComponent->DrawLines(dynamicStreamParams.lines);
	if (clock() - lastAnimate > (double)CLOCKS_PER_SEC / 33.3333) {
		if (first) { animateTime = visibleLength + invisibleLength - 1; first = 0; }
		lastAnimate = clock();
		animateTime -= animateSpeed;
		if (animateTime < 0)
			animateTime = visibleLength + invisibleLength - 1;
	}
	UpdateDynamicStreamLine();
	//UpdateSteadyStreamLine();
}

//Editing LoadChunkDataFromFile Function
void ASceneManagerTest::LoadChunkDataFromFile(CustomChunk* _Chunk, int _chunkListIndex) {
	if (DrawRedDot)
		DrawDebugPoint(GetWorld(), glm2FVec(_Chunk->center), 5, FColor::Red, false, 0.1f);

	try {
		++loadChunkCount;
		Frame& fc = _octree.GetFrameCollection()[nowFrame - 1];
		//�]�wTree�������Chunk����ChunkList��Index,Chunk.dataIndex�N���Chunk�b��Level����Index(DFS)
		fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex].chunkListIndex = _chunkListIndex;
		//��s��Chunk���Ҧ�parent�����A��True
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
	glm::dvec4 _min = glm::dvec4(_Chunk->min[0], _Chunk->min[1], _Chunk->min[2], 1);
	glm::dvec4 _max = glm::dvec4(_Chunk->max[0], _Chunk->max[1], _Chunk->max[2], 1);

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
		for (int i = 0; i < 8; i++) {
			if (ClipFrustum(_Chunk->child[i], frustumEquation)) {
				FVector distVec = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - glm2FVec(_Chunk->child[i]->center);
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
	for (int i = 0; i < 4;++i) {
		int index = rotateArr[i];
		FVector base((index & 1) ? min.X : max.X, (index & 2) ? min.Y  : max.Y , min.Z);
		FVector target(base.X, base.Y, max.Z );
		float scaleSize = 100.0f * MyScale;
		//DrawDebugLine(GetWorld(), base, target, FColor::Cyan, false, 1, 0, 10);
		DrawDebugLine(GetWorld(), base * scaleSize + Center, target * scaleSize + Center, FColor::Cyan, false, 1, 0, 5* MyScale);

		int index2 = rotateArr[(i + 1) & 3];
		target = FVector((index2 & 1) ? min.X : max.X, (index2 & 2) ? min.Y : max.Y, min.Z);
		//DrawDebugLine(GetWorld(), base, target, FColor::Cyan, false, 1, 0, 10);
		DrawDebugLine(GetWorld(), base * scaleSize + Center, target * scaleSize + Center, FColor::Cyan, false, 1, 0, 5* MyScale);

		base.Z = target.Z = max.Z;
		//DrawDebugLine(GetWorld(), base, target, FColor::Cyan, false, 1, 0, 10);
		DrawDebugLine(GetWorld(), base * scaleSize + Center, target * scaleSize + Center, FColor::Cyan, false, 1, 0, 5* MyScale);
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

		if (fc.levelFile[0].chunk[0].hasChildInChunkList == false) {//��Root��G�A���`�I
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
	//G:0���ܥN��ۤv�M�l�`�I���S���Q���J�A1���ܥN����Y�Ӥl�`�I�Q���J�A2���ܥN��o�Ӹ`�I���Q���J
	//R�bG��0�����p�L�ġA�bG��1�����p�N��U�ӻݭnTrace��Index�A�bG��2�����p�N���Chunk�bChunkList����Index
	//�ۤv�M�l�`�I���S�����J�AR�L�ġA�bG��0�AReturn
	Chunk& c = fc.levelFile[_Chunk->level].chunk[_Chunk->dataIndex];
	if (c.hasChildInChunkList == false) {
		index_tbo_data[tbo_index] = -3;
		status_tbo_data[tbo_index] = 0;
	}
	//�ۤv�Τl�`�I�����J
	else {
		//�l�`�I���H���J�A���ULoad�AR��l�`�IIndex�AG��1
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
		//�ۤv�����J�AR������chunkListIndex�AG��2
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

void ASceneManagerTest::UpdateProceduralMesh() {
	CreateTextures();

	for (int32 j = 0; j < ProceduralMeshComponent->GetNumSections(); j++) {
		ProceduralMeshComponent->SetMaterial(j, MaterialToApplyToClickedObject);
		UMaterialInstanceDynamic* MID = ProceduralMeshComponent->CreateAndSetMaterialInstanceDynamic(j);
		MID->SetTextureParameterValue("IndexTex", (UTexture*)IndexTex);
		MID->SetTextureParameterValue("StatusTex", (UTexture*)StatusTex);
		MID->SetTextureParameterValue("VelTex", (UTexture*)VelTex);
		MID->SetTextureParameterValue("PreTex", (UTexture*)PreTex);
		MID->SetScalarParameterValue("index_tex_size", IndexTex->GetSizeX());
		MID->SetScalarParameterValue("vel_tex_size", VelTex->GetSizeX());

		// not sure whether is wrong
		MID->SetScalarParameterValue("index_length", index_tbo_data.size());
		MID->SetScalarParameterValue("chunklist_length", chunkList.size());
		MID->SetVectorParameterValue("chunkSize", glm2FVec(glm::vec3(_octree.GetChunkSize())));
		MID->SetVectorParameterValue("minPos", glm2FVec(_octree.GetMin()));
		MID->SetVectorParameterValue("maxPos", glm2FVec(_octree.GetMax()));
		MID->SetVectorParameterValue("spacing", glm2FVec(_octree.GetSampledSpacing()));
		MID->SetScalarParameterValue("totalLevel", _octree.GetTotalLevel());

		// only on plane shader
		MID->SetScalarParameterValue("minValue", 0.0f);
		MID->SetScalarParameterValue("maxValue", _octree.GetMaxMagnitude());
		MID->SetScalarParameterValue("renderingMode", 4);
	}
}

void ASceneManagerTest::UpdateSteadyStreamLine() {
	std::vector<glm::vec4> points;
	points.resize(lineGenerator.spawnCount);
	UpdateSpawnPointPositions(points);

	steadyStreamParams = FSteadyStreamParameters(points, index_tbo_data.size(), chunkList.size(), _octree);

	FMyShaders::GetSteadyStreamLine(index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, steadyStreamParams);
}

void ASceneManagerTest::UpdateDynamicStreamLine() {
	std::vector<glm::vec4> points;
	points.resize(lineGenerator.spawnCount);
	UpdateSpawnPointPositions(points);

	dynamicStreamParams = FDynamicStreamParameters(points, index_tbo_data.size(), chunkList.size(), _octree);
	dynamicStreamParams.visibleLength = visibleLength;
	dynamicStreamParams.invisibleLength = invisibleLength;
	dynamicStreamParams.animateTime = animateTime;
	dynamicStreamParams.hack = hack;
	dynamicStreamParams.center = Center;
	dynamicStreamParams.myScale = MyScale;
	dynamicStreamParams.transform = glm2FVec(lineGenerator.transform);
	FMyShaders::GetDynamicStreamLine(index_tbo_data, status_tbo_data, vel_tbo_data, pre_tbo_data, dynamicStreamParams);
}

void ASceneManagerTest::UpdateSpawnPointPositions(std::vector<glm::vec4>& points) {

	int sideCount = sqrt(lineGenerator.spawnCount);
	glm::vec3 unitPos(0, -1, -1);
	float bias = 2.f / (float)(sideCount - 1);

	unitPos = glm::vec3(0, -1, 0);
	bias = 2.f / (float)(lineGenerator.spawnCount - 1);
	glm::vec3 dist = _octree.GetMax() - _octree.GetMin();
	glm::vec3 startPos = _octree.GetMin();

	//float scale = (_octree.GetMax().y - _octree.GetMin().y) / lineGenerator.spawnCount;

	//UE_LOG(LogTemp, Log, TEXT("dist is %f, %f, %f"), dist.x, dist.y, dist.z);
	//UE_LOG(LogTemp, Log, TEXT("Max is %f, %f, %f, startPos is %lf, %lf, %lf, Trans is %f, %f, %f, %f"), _octree.GetMax().x, _octree.GetMax().y, _octree.GetMax().z, startPos.x, startPos.y, startPos.z, lineGenerator.transform.x, lineGenerator.transform.y, lineGenerator.transform.z, lineGenerator.scale);
	for (int i = 0; i < lineGenerator.spawnCount; i++) {
		//dist = _octree.GetMax() - _octree.GetMin();
		//startPos = _octree.GetMin();

		/*glm::vec4 pos = glm::vec4(startPos +
			unitPos, 0);*/
		glm::vec3 apply = glm::vec3(glm::vec4(unitPos * lineGenerator.scale, 1));
		glm::vec4 pos = glm::vec4(startPos + dist * lineGenerator.transform +
			apply, 0);
		points[i] = pos;
		//unitPos[1] += scale;
		unitPos[1] += bias;
		//UE_LOG(LogTemp, Log, TEXT("unitPos[%d] is %f, %f, %f"), i, unitPos.x, unitPos.y, unitPos.z);
		//UE_LOG(LogTemp, Log, TEXT("apply[%d] is %f, %f, %f"), i, apply.x, apply.y, apply.z);
		//UE_LOG(LogTemp, Log, TEXT("pos[%d] is %f, %f, %f"), i, pos.x, pos.y, pos.z);
	}
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

	/*gIsosurface.drawCount = isosurfaceIndexList.size();

	glBindBuffer(GL_ARRAY_BUFFER, gIsosurface.vbo); 
	glBufferData(GL_ARRAY_BUFFER, isosurfacePointList.size() * sizeof(GLfloat), isosurfacePointList.data(), GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIsosurface.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, isosurfaceIndexList.size() * sizeof(GLuint), isosurfaceIndexList.data(), GL_DYNAMIC_DRAW);*/
}

void ASceneManagerTest::IncreaseSpawnCount() {
	if (lineGenerator.spawnCount < 100)
		lineGenerator.spawnCount += 5;
	UpdateSteadyStreamLine();
	UpdateDynamicStreamLine();
}

void ASceneManagerTest::DecreaseSpawnCount() {
	if (lineGenerator.spawnCount > 5)
		lineGenerator.spawnCount -= 5;
	UpdateSteadyStreamLine();
	UpdateDynamicStreamLine();
}

void ASceneManagerTest::ShiftXPos() {
	lineGenerator.transform.x += 0.025;
}

void ASceneManagerTest::ShiftXNeg() {
	lineGenerator.transform.x -= 0.025;
}

void ASceneManagerTest::ShiftYPos() {
	lineGenerator.transform.y += 0.025;
}

void ASceneManagerTest::ShiftYNeg() {
	lineGenerator.transform.y -= 0.025;
}

void ASceneManagerTest::ShiftZPos() {
	lineGenerator.transform.z += 0.01;
}

void ASceneManagerTest::ShiftZNeg() {
	lineGenerator.transform.z -= 0.01;
}

void ASceneManagerTest::SwitchHack() {
	hack = !hack;
}

void ASceneManagerTest::IncreaseScale() {
	if (lineGenerator.scale < 1)
		lineGenerator.scale += 0.05;
}

void ASceneManagerTest::DecreaseScale() {
	if (lineGenerator.scale > 0.05)
		lineGenerator.scale -= 0.05;
}

void ASceneManagerTest::UpdateCenter(FVector InCenter) {
	Center = InCenter;
}

void ASceneManagerTest::UpdateScale(float InScale) {
	MyScale = InScale;
}