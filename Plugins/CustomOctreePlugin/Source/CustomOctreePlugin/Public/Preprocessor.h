// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Include/CustomOctree.h"
//#include <string.h>

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Preprocessor.generated.h"
using namespace std;
using namespace tdogl;

#define INPUT_SAMPLED_GRID false

/**
 * 
 */
UCLASS()
class CUSTOMOCTREEPLUGIN_API UPreprocessor : public UObject
{
	GENERATED_BODY()

public:
	UPreprocessor();

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void StartProcessing();

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetTotalLevel(FString TotalLevel);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetQuantizationThreshold(FString QuantizationThresh);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetMotionIndexFrameNum(FString MotionIndexFrameNum);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetInputFolderPath(FString InputFolderPath);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetDataFolderPath(FString DataFolderPath);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetFilePostfixInput(FString FilePostfixInput);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetModelInputChoice(FString ModelInputChoice);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetFrameCountInput(FString FrameCountInput);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetBinaryInput(bool BinaryInput);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetOrganizedInput(bool OrganizedInput);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetLaplacianPyramidOutput(bool LaplacianPyramidOutput);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetMotionIndexOutput(bool MotionIndexOutput);

	UFUNCTION(BlueprintCallable, Category = "Preprocessor")
	void SetCmpressionMethodChoice(int choice);
private:
	bool MainProcess();
	void InitialOctree(string filename, string outputfilename, string streamDataFilename);
	string simplifiedPath(string input);
	bool VerifyInputValue_MainProcess();
	bool ReadModel();
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

	string totalLevel, quantizationThreshold, motionIndexFrameNum,
		inputFolderPath, flowfieldDatabaseFolderPath, filePostfixInput,
		modelInputChoice, frameCountInput;
	bool organizedInput, motionIndexOutput, laplacianPyramidOutput, binaryInput;
	int compressionMethodChoice;

	int frameCount;

	CustomOctree _octree;
	unibn::Octree<CustomPoint> _OctreeSearch;
	vector<Mesh> meshes;

	vector<pair<string, ObjMarkerData>> listModelObjMarker;
	vector<pair<string, string>> listModelStreamData;
	//string flowfieldDatabaseFolderPath = RootPathPreprocessor("../Server/FlowfieldDatabase/");
	//string assetsStorageFolderPath = RootPathPreprocessor("../Server/AssetsStorage/");
};
