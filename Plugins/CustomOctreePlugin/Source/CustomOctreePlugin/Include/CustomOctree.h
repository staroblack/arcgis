#pragma once
#ifndef CUSTOMOCTREEHEADER
#define CUSTOMOCTREEHEADER

//#include <windows.h>
//#include <map>
//#include <random>
//#include <chrono>
//#include <opencv.hpp>

#include "octree_search/Octree.hpp"
#include "tdogl/Model.h"
#include "acc/bvh_tree.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <random>
#include <glm/glm.hpp>
//#include <core.hpp>
namespace tdogl {
	class Model;
}

using namespace std;

#define OUTPUT_BINARY true

#define FOR_3 for (int i = 0; i < 3; i++)

//glm::vec3 Toglm(cv::Vec3f in);
//cv::Vec3f Tocv(glm::vec3 in);
enum class CompressionMethod {
	NoCompression,
	SimilarEliminateOriginal,
	SimilarEliminateAdaptive,
	SimilarEliminateKmeans,
	SimilarEliminateMedianCut,
	ZFP,
	JPEG,
	LagrangianMethod,
	DUMMY
};

class LagrangianVelSource {
public:
	//cv::Vec3f vel;
	//cv::Vec3f pos;
	glm::vec3 vel;
	glm::vec3 pos;
	float radius;
};

class LagrangianPreSource {
public:
	float pre;
	//cv::Vec3f pos;
	glm::vec3 pos;
	float radius;
};

class CustomPointData {
protected:
	//cv::Vec3f vel; //velocity
	glm::vec3 vel;
	float pre; //pressure
	float temp; // temperature
public:
	CustomPointData();
	float GetXVel() const;
	float GetYVel() const;
	float GetZVel() const;
	//cv::Vec3f GetVel();
	glm::vec3 GetVel() const;
	void SetXVel(float xVel);
	void SetYVel(float yVel);
	void SetZVel(float zVel);
	void SetXYZVel(float x, float y, float z);
	//void SetXYZVel(cv::Vec3f vel);
	void SetXYZVel(glm::vec3 vel);
	float GetPressure() const;
	void SetPressure(float pre);
	float GetTemperature() const;
	void SetTemperature(float temp);
	void SetData(CustomPointData p);
	float GetMagnitude();
	CustomPointData friend operator+(CustomPointData l, CustomPointData r);
	CustomPointData friend operator*(CustomPointData l, float s);
	CustomPointData friend operator*(float s, CustomPointData l);
	CustomPointData friend operator/(CustomPointData l, float s);
	//bool friend operator<(CustomPointData l, CustomPointData r);
	friend ostream& operator<<(ostream& os, const CustomPointData& dt);
	friend istream& operator>>(istream& is, CustomPointData& dt);
};

class CustomPoint : public CustomPointData {
private:
	//cv::Vec3f pos; //position
	glm::vec3 pos;
public:
#pragma region operations
	CustomPoint(float x, float y, float z);
	//CustomPoint(cv::Vec3f _pos);
	CustomPoint(glm::vec3 _pos);
	CustomPoint();

	float GetX() const;
	float GetY() const;
	float GetZ() const;
	//cv::Vec3f GetXYZ();
	glm::vec3 GetXYZ();
	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	void SetXYZ(float x, float y, float z);
	//void SetXYZ(cv::Vec3f _pos);
	void SetXYZ(glm::vec3 _pos);
#pragma endregion 

	CustomPoint friend operator+(CustomPoint l, CustomPoint r);
	CustomPoint friend operator*(CustomPoint l, float s);
	CustomPoint friend operator*(float s, CustomPoint l);
	CustomPoint friend operator/(CustomPoint l, float s);
	friend ostream& operator<<(ostream& os, const CustomPoint& dt);
	friend istream& operator>>(istream& is, CustomPoint& dt);
};

class CustomChunk {
public:
	//cv::Vec3f min;//最小值
	glm::vec3 min;
	//cv::Vec3f max;//最大值
	glm::vec3 max;
	//cv::Vec3f center;//中心點
	glm::vec3 center;
	//cv::Vec3f distance;//中心點至每邊的距離
	glm::vec3 distance;
	vector<CustomChunk*> child;//底下的8個Chunk
	//vector<CustomPoint*> data;//資料
	short level = 0;//現在第幾層
	//CustomChunk* neighbor = nullptr;//同層的鄰居
	//cv::Vec3i chunkIndex;//Chunk在這層裡的Index
	glm::ivec3 chunkIndex;
	int dataIndex;
	CustomChunk* parent = nullptr;
};

class Chunk {
public:
	vector<LagrangianVelSource> velSources;
	vector<LagrangianPreSource> preSources;
	vector<CustomPointData> points;
	bool hasChildInChunkList = false;//是否有Child或自身在ChunkList裡被找到，建表用
	int chunkListIndex = -1;//對應ChunkList的第幾個區塊, -1表示看不到或非Leaf
	int chunkAge = 0;//這個Chunk存在多久了
};

class Level {
public:
	vector<Chunk> chunk;

};

class Frame {
public:
	vector<Level> levelFile;
};

class ObjMarkerData {//???w???c???
public:
	ObjMarkerData();
	ObjMarkerData(string _objName, string _markerMapName, glm::vec3 _translation, glm::vec3 _rotation, glm::vec3 _scale);
	void SetData(string _objName, string _markerMapName, glm::vec3 _translation, glm::vec3 _rotation, glm::vec3 _scale);
	void SetFileName(string _objName, string _markerMapName);
	void SetTransform(glm::vec3 _translation, glm::vec3 _rotation, glm::vec3 _scale);
	string GetObjName();
	string GetMarkerMapName();
	glm::vec3 GetTranslation();
	glm::vec3 GetRotation();
	glm::vec3 GetScale();
	friend ostream& operator<<(ostream& os, const ObjMarkerData& omd);
private:
	string objName;
	string markerMapName;
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
};

class CustomOctree {
private:
	struct fileHeader {
		string fileMagic = "ARdata";
		string fileName;
		int8_t vel, pre, temp, rad;
	};
	//No Saving to gridinfo.bin
	//cv::Vec3f originalSpacing;
	glm::vec3 originalSpacing;
	//cv::Vec3i originalDim;
	glm::ivec3 originalDim;
	//cv::Vec3f sampledSpacing;
	glm::vec3 sampledSpacing;
	set<float> pcCoordSet[3];

	long pointCount;
	vector<CustomPoint> points;//no one uses
	vector<CustomPoint> sampledPoints;

	//Save to gridinfo.bin
	//cv::Vec3f min;
	glm::vec3 min;
	//cv::Vec3f max;
	glm::vec3 max;
	//cv::Vec3i chunkSize;
	glm::ivec3 chunkSize;

	//int totalLevel;
	//cv::Vec3i sampledDim;
	glm::ivec3 sampledDim;
	int totalFrame;

	float maxXVel;	
	float maxYVel;	
	float maxZVel;
	float minMagnitude;
	float maxMagnitude;
	float minPressure;
	float maxPressure;
	float minVorticity;
	float maxVorticity;
	float minQCritirea;
	float maxQCritirea;
	float minTemperature;
	float maxTemperature;

	bool isInputOrganized;
	CompressionMethod compressionMethod = CompressionMethod::SimilarEliminateOriginal;
	bool withLaplacianPyramid = false;
	bool withMotionIndex = false;

	//Tree Structure,整個Complete樹的結構
	CustomChunk _Root;

	//Data Loading Structure,紀錄已被動態載入的Chunk和該Chunk能否被看見
	vector<Frame> frameCollection;//According to totalFrame

	//快取的Frame資料
	Frame cachedFrame;

	//If preprocessed
	bool preprocessed = false;

	vector<vector<vector<CustomPointData>>> basePointCacheList;

	CustomPoint* GetPointRef(vector<CustomPoint>& points,int i,int j,int k);

	void FillPointDataByValueIndex(CustomPoint& _point, int& valueIndex, string& value);
	void TraceTree_Recursive(CustomChunk* _Chunk,vector<int>& count);
	//void FillTreeStructureFromInfo_Recursive(CustomChunk* _Chunk, int nowLevel, int totalLevel, cv::Vec3i chunkIndex);
	void FillTreeStructureFromInfo_Recursive(CustomChunk* _Chunk, int nowLevel, int totalLevel, glm::ivec3 chunkIndex);
	void CleanUpChunkStructure_Recursive(CustomChunk* _Chunk);
	template<typename T1, typename T2>
	pair<uint64_t, float> CompressToValueIndex(const vector<T1>& target,
		vector<T2>& value, vector<unsigned char>& valueIndex,
		float subtract(const T2& a, const T2& b),
		T2 access(const T1& x),
		float threshold = 0,
		const vector<int>& targetIndex = vector<int>(),
		CompressionMethod method = CompressionMethod::DUMMY);

public:
	CustomOctree();
	~CustomOctree();

	string name;

	int totalLevel;
	float magThreshold;
	float preThreshold;
	float tempThreshold;

	fileHeader hdr;

	CustomChunk* GetRoot();
	vector<Frame>& GetFrameCollection();
	Frame& GetCachedFrame();

	int GetTotalLevel();
	int GetTotalFrame();
	int GetChunkPointCount();

	//no one calls
	//int GetChunkGridCount();

	glm::ivec3 GetChunkSize();
	float GetMaxSampledSpacing();
	glm::vec3 GetSampledSpacing();

	vector<CustomPoint>& GetPointsRef();

	glm::vec3 GetMin();
	glm::vec3 GetMax();

	//no one calls
	void InputPointDataFromTextFile(string s);
	void InputPointDataFromBinaryFile(string s);
	//void OutputPointDataToBinaryFile(string s);
	void CalculatePreprocess();
	void ResampleStructuredGrid(unibn::Octree<CustomPoint>& _OctreeSearch, tdogl::Mesh* modelMesh);
	void OutputGridInfoToBinaryFile(string outFolder,string s, int _totalFrame, bool outputSampledGrid);
	//void CustomCalculate(string path);
	void InputGridInfo(string outFolder);
	void InputResampledGrid(string resampledGridFilename);
	void SequentialReadStructuredGridAndMergeToFile(string outFolder,string filename,bool isBaseFile);

	void SetCompressionMethod(CompressionMethod newUsingCompressed);
	void SetWithLaplacianPyramidOutput(bool w);
	void SetWithMotionIndexOutput(bool w);
	void SetIsInputOrganized(bool newIsInputOrganized);

	void CleanUpChunkStructure();
	void TraceTree();
	void SetupInfo(FString s, float scale = 1);
	void FillTreeStructureFromInfo();

	float GetMaxXVel();
	float GetMaxYVel();
	float GetMaxZVel();
	float GetMinMagnitude();
	float GetMaxMagnitude();
	float GetMinPressure();
	float GetMaxPressure();
	float GetMinVorticity();
	float GetMaxVorticity();
	float GetMinQCritirea();
	float GetMaxQCritirea();
	float GetMinTemperature();
	float GetMaxTemperature();

	bool GetVorticity(int& i,int& j,int& k,float& vorticity);
	bool GetQCritirea(int& i, int& j, int& k, float& qcritirea);
	bool GetVorticity(vector<CustomPoint>& targetPoints, int& i, int& j, int& k, float& vorticity);
	bool GetQCritirea(vector<CustomPoint>& targetPoints, int& i, int& j, int& k, float& qcritirea);

	bool haveTemperatureData();

	void InitMinMaxValue();
	void UpdateMinMaxValue();
	void SaveMinMaxValue(string outFolder);

}; 

#endif // !CUSTOMOCTREEHEADER