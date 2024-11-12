// Fill out your copyright notice in the Description page of Project Settings.


#include "Preprocessor.h"

#include "Misc/Paths.h"

UPreprocessor::UPreprocessor() {
	totalLevel = "5";
	quantizationThreshold = "0.1";
	motionIndexFrameNum = "5";
	inputFolderPath = "";

	FString FullPath = FPaths::Combine(*FPaths::ProjectDir(), TEXT("StreamDatas"));
	flowfieldDatabaseFolderPath = std::string(TCHAR_TO_UTF8(*FullPath));

	filePostfixInput = ".dat";
	modelInputChoice = "-----";
	frameCountInput = "1";
	organizedInput = false;
	motionIndexOutput = false;
	laplacianPyramidOutput = false;
	binaryInput = false;
}

bool UPreprocessor::VerifyInputValue_MainProcess() {
	frameCount = stoi(frameCountInput);
	string ifPath = inputFolderPath;
	string _streamdataFilename = ifPath.substr(ifPath.find_last_of('\\') + 1);

	string modelInput = modelInputChoice;
	if (inputFolderPath == "") {
		//fl_message("請選擇流場資料夾!");
		//cout << "請選擇流場資料夾!" << endl;
		return false;
	}
	else if (_streamdataFilename.find(" ") != std::string::npos) {
		//fl_message("流場資料夾名稱包含空格!");
		//cout << "流場資料夾名稱包含空格!" << endl;
		return false;
	}
	else if (frameCount < 1) {
		//fl_message("幀數不得小於1!");
		//cout << "幀數不得小於1!" << endl;
		return false;
	}
	else if (modelInput.find("-----") != std::string::npos) {
		//fl_message("請選擇有效模型!");
		//cout << "請選擇有效模型!" << endl;
		return false;
	}
	return true;

}

bool UPreprocessor::ReadModel() {
	//string _modelName = modelInputChoice;
	//string objname;
	//bool momFound = false;
	//for (auto& modelObjMarker : listModelObjMarker)
	//	if (_modelName == modelObjMarker.first) {
	//		objname = RootPathPreprocessor("..\\Server\\AssetsStorage\\" + modelObjMarker.second.GetObjName());
	//		momFound = true;
	//		break;
	//	}
	//if (!momFound) {
	//	//fl_message("未知錯誤，找不到模型");
	//	return false;
	//}

	//Assimp::Importer importer;

	//const aiScene* scene = importer.ReadFile(objname, aiProcess_Triangulate | aiProcess_GenBoundingBoxes |
	//	aiProcess_JoinIdenticalVertices | aiProcess_OptimizeGraph | aiProcess_OptimizeMeshes);

	//// Check for errors
	//if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	//{
	//	//fl_message((string("ERROR::ASSIMP:: ") + string(importer.GetErrorString())).c_str());
	//	//cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
	//	return false;
	//}

	//// Process ASSIMP's root node recursively
	//processNode(scene->mRootNode, scene);

	return true;
}

void UPreprocessor::StartProcessing() {
	//cout << "Verifying Input..." << endl;
	if (VerifyInputValue_MainProcess()) {
		//cout << "Reading Model..." << endl;
		if (ReadModel()) {
			//cout << "Processing Data..." << endl;

			bool ok = true;
			vector<string> levels;
			vector<string> thresholds;
			vector<string> motionIndexFrames;
			//_octree.totalLevel = stoi(totalLevel->value());
			//_octree.magThreshold = stof(quantizationThreshold->value());
			//_octree.preThreshold = stof(quantizationThreshold->value());
			string originalLevel = totalLevel;
			string originalThreshold = quantizationThreshold;
			string originalMotionIndexFrame = motionIndexFrameNum;

			string levelstr = totalLevel;
			string thresholdstr = quantizationThreshold;
			string motionIndexFrameStr = motionIndexFrameNum;

			while (levelstr.find(':') != string::npos) {
				levels.push_back(levelstr.substr(0, levelstr.find(':')));
				levelstr = levelstr.substr(levelstr.find(':') + 1);
			}
			levels.push_back(levelstr);

			while (thresholdstr.find(':') != string::npos) {
				thresholds.push_back(thresholdstr.substr(0, thresholdstr.find(':')));
				thresholdstr = thresholdstr.substr(thresholdstr.find(':') + 1);
			}
			thresholds.push_back(thresholdstr);

			while (motionIndexFrameStr.find(':') != string::npos) {
				motionIndexFrames.push_back(motionIndexFrameStr.substr(0, motionIndexFrameStr.find(':')));
				motionIndexFrameStr = motionIndexFrameStr.substr(motionIndexFrameStr.find(':') + 1);
			}
			motionIndexFrames.push_back(motionIndexFrameStr);

			for (string level : levels) {
				for (string threshold : thresholds) {
					for (string motionIndexFrame : motionIndexFrames) {
						//cout << "Target with level " << level << ", threshold " << threshold << " start." << endl;

						//totalLevel->value(level.c_str());
						//quantizationThreshold->value(threshold.c_str());
						//motionIndexFrameNum->value(motionIndexFrame.c_str());

						ok &= MainProcess();

						//if (ok)
						//	cout << "Target with level " << level << ", threshold " << threshold << " done." << endl;
					}
				}
			}

			//totalLevel->value(originalLevel.c_str());
			//quantizationThreshold->value(originalThreshold.c_str());
			//motionIndexFrameNum->value(originalMotionIndexFrame.c_str());

			//if (ok) {
			//	fl_message("處理完成!");
			//}
		}
	}
}

bool UPreprocessor::MainProcess() {
	string ifPath = inputFolderPath;
	string compressedStr;
	switch (compressionMethodChoice) {
	case 0:
		compressedStr = "_un";// path too long.....
		break;
	case 1:
		compressedStr = "_compressed";
		break;
	case 2:
		compressedStr = "_adaptive";
		break;
	case 3:
		compressedStr = "_kmeans";
		break;
	case 4:
		compressedStr = "_median";
		break;
	case 5:
		compressedStr = "_zfp";
		break;
	case 6:
		compressedStr = "_jpeg";
		break;
	case 7:
		compressedStr = "_lagrangian";
		break;
	}
	string levelStr = "_COT" + to_string(stoi(totalLevel));
	string streamdataFilename = ifPath.substr(ifPath.find_last_of('\\') + 1);
	string thresholdStr = "_" + string(quantizationThreshold);
	string motionIndexStr = motionIndexOutput ? "_mo" + to_string(stoi(motionIndexFrameNum)) : "";

	string inputFolder = string(inputFolderPath) + "\\";
	//string outputFolder = flowfieldDatabaseFolderPath + "\\" + streamdataFilename + levelStr + compressedStr + thresholdStr + motionIndexStr + "_collection/";
	string outputFolder = flowfieldDatabaseFolderPath + "\\" + streamdataFilename + "_collection/";
	outputFolder = simplifiedPath(outputFolder);

	string filePostfix = filePostfixInput;

	//SimpleTimer timer;
	//timer.start();
	_octree.SetCompressionMethod((CompressionMethod)compressionMethodChoice);
	_octree.SetWithLaplacianPyramidOutput(laplacianPyramidOutput);
	_octree.SetWithMotionIndexOutput(motionIndexOutput);
	_octree.SetIsInputOrganized(organizedInput);
	_octree.InitMinMaxValue();
	int timeBase = stoi(motionIndexFrameNum);
	for (int i = 1; i < frameCount + 1; i++) {
		//cout << "Processing File " << to_string(i) << "!" << endl;
		string filenameIndex, path;
		if (frameCount == 1)
			filenameIndex = streamdataFilename;
		else if (frameCount > 1)
			filenameIndex = streamdataFilename + to_string(i);
		path = inputFolder + filenameIndex + filePostfix;
		//cout << path << endl;
		_octree.CleanUpChunkStructure();
		fstream f(path, ios::in);
		if (!f)
		{
			//fl_message((string("File ") + to_string(i) + string(" Not Found!")).c_str());
			//cout << "File " << to_string(i) << " Not Found!" << endl;
			return false;
		}
		f.close();
		//_octree.CustomCalculate(path+"_resampled");
		filenameIndex = streamdataFilename + levelStr + compressedStr + thresholdStr + motionIndexStr + (frameCount > 1 ? to_string(i) : "");

		if (!INPUT_SAMPLED_GRID) {
			InitialOctree(path, outputFolder + filenameIndex + "/", streamdataFilename);
			_octree.CalculatePreprocess();
			//_octree.ResampleStructuredGrid(_OctreeSearch, &meshes[0]);
			bool outputSampledGrid = false;
			_octree.OutputGridInfoToBinaryFile(outputFolder, inputFolder + filenameIndex + "_resampled", frameCount, outputSampledGrid);
		}
		else {
			_octree.InputGridInfo(outputFolder);
			_octree.InputResampledGrid(inputFolder + filenameIndex + "_resampled");
		}
		_octree.SequentialReadStructuredGridAndMergeToFile(outputFolder, filenameIndex, ((i - 1) % timeBase) == 0 ? true : false);
		//_octree.SequentialReadStructuredGridAndMergeToFile(outputFolder, filenameIndex, false);
		_octree.UpdateMinMaxValue();

	}
	//timer.stop();
	//cout << "Process Finished!" << endl;
	//cout << "Total Time: " << timer.elapsed() << " seconds." << endl;
	if (!INPUT_SAMPLED_GRID)
		_octree.SaveMinMaxValue(outputFolder);

	streamdataFilename += levelStr + compressedStr + thresholdStr + motionIndexStr;

	string _modelName = modelInputChoice;
	bool msdFound = false;
	for (auto& modelStreamData : listModelStreamData)
		if (_modelName == modelStreamData.first && streamdataFilename == modelStreamData.second) {
			msdFound = true;
			break;
		}
	if (!msdFound) {
		listModelStreamData.push_back(pair<string, string>(_modelName, streamdataFilename));
	}

	ofstream fileModelStreamData;
	string pathModelStreamData = flowfieldDatabaseFolderPath + string("/") + "database-stream_data.txt";

	fileModelStreamData.open(pathModelStreamData, std::ios_base::out | std::ios_base::trunc);

	fileModelStreamData << "//Model Name,StreamData Name" << endl;
	for (auto& modelStreamData : listModelStreamData)
		fileModelStreamData << modelStreamData.first << " " << modelStreamData.second << endl;
	//modelInputChoice->value(0);
	return true;
}

string UPreprocessor::simplifiedPath(string input) {

	vector<string> parts;
	{
		string temp("");
		for (char c : input) {
			if (c == '\\' || c == '/') {
				parts.push_back(temp);
				temp = "";
			}
			else {
				temp += c;
			}
		}
		if (temp != "")
			parts.push_back(temp);
	}

	for (int i = 0; i < parts.size() - 1; ++i) {
		if (i >= 0 && parts[i] != ".." && parts[i + 1] == "..") {
			parts.erase(parts.begin() + i + 1);
			parts.erase(parts.begin() + i);
			i -= 2;
		}
	}

	string output("");
	for (string part : parts) {
		output += part + "/";
	}
	return output;
}

void UPreprocessor::InitialOctree(string filename, string outputfilename, string streamDataFilename)
{
	// init file header
	_octree.hdr.fileName = streamDataFilename;
	_octree.hdr.vel = 1;
	_octree.hdr.pre = 2;
	_octree.hdr.temp = -1;
	_octree.hdr.rad = -1;

	//if (INPUT_BINARY_FILE)
	if (binaryInput)
		_octree.InputPointDataFromBinaryFile(filename);
	else
		_octree.InputPointDataFromTextFile(filename);
	std::vector<CustomPoint>& _points = _octree.GetPointsRef();

	_octree.totalLevel = stoi(totalLevel);
	_octree.magThreshold = stof(quantizationThreshold);
	_octree.preThreshold = stof(quantizationThreshold);
	_octree.tempThreshold = stof(quantizationThreshold);

	//std::cout << "Read " << _points.size() << " points." << std::endl;
	if (_points.size() == 0)
	{
		//std::cerr << "Empty point cloud." << std::endl;
	}

	//if (!organizedInput)
		//_OctreeSearch.initialize(_points);
}

void UPreprocessor::SetTotalLevel(FString TotalLevel) {
	this->totalLevel = TCHAR_TO_UTF8(*TotalLevel);
}

void UPreprocessor::SetQuantizationThreshold(FString QuantizationThresh) {
	this->quantizationThreshold = TCHAR_TO_UTF8(*QuantizationThresh);
}

void UPreprocessor::SetMotionIndexFrameNum(FString MotionIndexFrameNum) {
	this->motionIndexFrameNum = TCHAR_TO_UTF8(*MotionIndexFrameNum);
}

void UPreprocessor::SetInputFolderPath(FString InputFolderPath) {
	this->inputFolderPath = TCHAR_TO_UTF8(*InputFolderPath);
}

void UPreprocessor::SetDataFolderPath(FString DataFolderPath) {
	this->flowfieldDatabaseFolderPath = TCHAR_TO_UTF8(*DataFolderPath);
}

void UPreprocessor::SetFilePostfixInput(FString FilePostfixInput) {
	this->filePostfixInput = TCHAR_TO_UTF8(*FilePostfixInput);
}

void UPreprocessor::SetModelInputChoice(FString ModelInputChoice) {
	this->modelInputChoice = TCHAR_TO_UTF8(*ModelInputChoice);
}

void UPreprocessor::SetFrameCountInput(FString FrameCountInput) {
	this->frameCountInput = TCHAR_TO_UTF8(*FrameCountInput);
}

void UPreprocessor::SetBinaryInput(bool BinaryInput) {
	this->binaryInput = BinaryInput;
}

void UPreprocessor::SetOrganizedInput(bool OrganizedInput) {
	this->organizedInput = OrganizedInput;
}

void UPreprocessor::SetLaplacianPyramidOutput(bool LaplacianPyramidOutput) {
	this->laplacianPyramidOutput = LaplacianPyramidOutput;
}

void UPreprocessor::SetMotionIndexOutput(bool MotionIndexOutput) {
	this->motionIndexOutput = MotionIndexOutput;
}

void UPreprocessor::SetCmpressionMethodChoice(int choice) {
	this->compressionMethodChoice = choice;
}