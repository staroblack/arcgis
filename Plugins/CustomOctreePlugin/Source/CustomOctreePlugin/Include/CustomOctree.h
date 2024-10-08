#pragma once
#ifndef CUSTOMOCTREEHEADER
#define CUSTOMOCTREEHEADER

//#include <windows.h>
//#include <map>
//#include <random>
//#include <chrono>
//#include <opencv.hpp>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <glm/glm.hpp>
//#include <core.hpp>

using namespace std;

#define FOR_3 for (int i = 0; i < 3; i++)

//glm::vec3 Toglm(cv::Vec3f in);
//cv::Vec3f Tocv(glm::vec3 in);

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
	glm::vec3 GetVel();
	void SetXVel(float xVel);
	void SetYVel(float yVel);
	void SetZVel(float zVel);
	void SetXYZVel(float x, float y, float z);
	//void SetXYZVel(cv::Vec3f vel);
	void SetXYZVel(glm::vec3 vel);
	float GetPressure();
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

	int totalLevel;
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

	//Tree Structure,整個Complete樹的結構
	CustomChunk _Root;

	//Data Loading Structure,紀錄已被動態載入的Chunk和該Chunk能否被看見
	vector<Frame> frameCollection;//According to totalFrame

	//快取的Frame資料
	Frame cachedFrame;

	//If preprocessed
	bool preprocessed = false;

	vector<vector<vector<CustomPointData>>> basePointCacheList;

	fileHeader hdr;

	CustomPoint* GetPointRef(vector<CustomPoint>& points,int i,int j,int k);

	void FillPointDataByValueIndex(CustomPoint& _point, int& valueIndex, string& value);
	void TraceTree_Recursive(CustomChunk* _Chunk,vector<int>& count);
	//void FillTreeStructureFromInfo_Recursive(CustomChunk* _Chunk, int nowLevel, int totalLevel, cv::Vec3i chunkIndex);
	void FillTreeStructureFromInfo_Recursive(CustomChunk* _Chunk, int nowLevel, int totalLevel, glm::ivec3 chunkIndex);
	void CleanUpChunkStructure_Recursive(CustomChunk* _Chunk);

public:
	CustomOctree();
	~CustomOctree();

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

	//no one calls
	//vector<CustomPoint>& GetPointsRef();

	glm::vec3 GetMin();
	glm::vec3 GetMax();

	//no one calls
	//void InputPointDataFromTextFile(string s);
	//void InputPointDataFromBinaryFile(string s);
	//void OutputPointDataToBinaryFile(string s);
	//void CalculatePreprocess();
	//void ResampleStructuredGrid(unibn::Octree<CustomPoint>& _OctreeSearch, tdogl::Mesh* modelMesh);
	//void OutputGridInfoToBinaryFile(string outFolder,string s, int _totalFrame, bool outputSampledGrid);
	//void CustomCalculate(string path);
	//void InputGridInfo(string outFolder);
	//void InputResampledGrid(string resampledGridFilename);
	//void SequentialReadStructuredGridAndMergeToFile(string outFolder,string filename,bool isBaseFile);

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

	bool GetVorticity(int& i,int& j,int& k,float& vorticity);
	bool GetQCritirea(int& i, int& j, int& k, float& qcritirea);

	//no one calls
	//void InitMinMaxValue();
	//void UpdateMinMaxValue();
	//void SaveMinMaxValue(string outFolder);

}; 

#endif // !CUSTOMOCTREEHEADER