// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Include/CustomOctree.h"
#include <string.h>
using namespace std;
using namespace tdogl;

#define INPUT_SAMPLED_GRID false

/**
 * 
 */
class CUSTOMOCTREEPLUGIN_API Preprocessor
{
public:
	Preprocessor();
	~Preprocessor();

	UFUNCTION(BlueprintCallable, Category = "OctreePlugin")
	void StartProcessing();
	
private:
	bool MainProcess();
	void InitialOctree(string filename, string outputfilename, string streamDataFilename);
	string simplifiedPath(string input);
	bool VerifyInputValue_MainProcess();
	bool ReadModel();

	string totalLevel, quantizationThreshold, motionIndexFrameNum, 
		inputFolderpath, flowfieldDatabaseFolderPath, filePostfixInput, 
		modelInputChoice, frameCountInput;
	bool organizedInput, motionIndexOutput, laplacianPyramidOutput, binaryInput;
	int compressionMethodChoice;

	int frameCount;

	CustomOctree _octree;
	//unibn::Octree<CustomPoint> _OctreeSearch;
	//vector<Mesh> meshes;

	vector<pair<string, ObjMarkerData>> listModelObjMarker;
	vector<pair<string, string>> listModelStreamData;
	//string flowfieldDatabaseFolderPath = RootPathPreprocessor("../Server/FlowfieldDatabase/");
	//string assetsStorageFolderPath = RootPathPreprocessor("../Server/AssetsStorage/");

};
