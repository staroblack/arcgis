#include "CustomOctree.h"
#include <set>

//glm::vec3 Toglm(cv::Vec3f in) {
//	return glm::vec3(in[0], in[1], in[2]);
//}

//cv::Vec3f Tocv(glm::vec3 in) {
//	return cv::Vec3f(in[0], in[1], in[2]);
//}

#pragma region CustomPointData
CustomPointData operator+(CustomPointData l, CustomPointData r) {
	CustomPointData p;
	p.SetXYZVel(l.GetXVel() + r.GetXVel(), l.GetYVel() + r.GetYVel(), l.GetZVel() + r.GetZVel());
	p.SetPressure(l.GetPressure() + r.GetPressure());
	p.SetTemperature(l.GetTemperature() + r.GetTemperature());
	return p;
}
CustomPointData operator-(CustomPointData l, CustomPointData r)
{
	CustomPointData p;
	p.SetXYZVel(l.GetXVel() - r.GetXVel(), l.GetYVel() - r.GetYVel(), l.GetZVel() - r.GetZVel());
	p.SetPressure(l.GetPressure() - r.GetPressure());
	p.SetTemperature(l.GetTemperature() - r.GetTemperature());
	return p;
}
CustomPointData operator*(CustomPointData l, float s) {
	CustomPointData p;
	p.SetXYZVel(l.GetXVel() * s, l.GetYVel() * s, l.GetZVel() * s);
	p.SetPressure(l.GetPressure() * s);
	p.SetTemperature(l.GetTemperature() * s);
	return p;
}
CustomPointData operator*(float s, CustomPointData l) {
	CustomPointData p;
	p.SetXYZVel(l.GetXVel() * s, l.GetYVel() * s, l.GetZVel() * s);
	p.SetPressure(l.GetPressure() * s);
	p.SetTemperature(l.GetTemperature() * s);
	return p;
}
CustomPointData operator/(CustomPointData l, float s) {
	CustomPointData p;
	p.SetXYZVel(l.GetXVel() / s, l.GetYVel() / s, l.GetZVel() / s);
	p.SetPressure(l.GetPressure() / s);
	p.SetTemperature(l.GetTemperature() / s);
	return p;
}
bool operator==(CustomPointData l, CustomPointData r) {
	if (l.GetMagnitude() - r.GetMagnitude() < 0.1f && l.GetPressure() - r.GetPressure() < 0.1f && l.GetTemperature() - r.GetTemperature() < 0.1f)
		return true;
	else
		return false;
}
ostream& operator<<(ostream& os, const CustomPointData& cp)
{
	os << cp.vel[0] << ' ' << cp.vel[1] << ' ' << cp.vel[2] << ' '
		<< cp.pre << ' ' << cp.temp << endl;
	return os;
}
istream& operator>>(istream& is, CustomPointData& cp)
{
	is >> cp.vel[0] >> cp.vel[1] >> cp.vel[2]
		>> cp.pre >> cp.temp;
	return is;
}

CustomPointData::CustomPointData() {
	vel[0] = 0; vel[1] = 0; vel[2] = 0;
	pre = 0;
	temp = 0;
}

float CustomPointData::GetXVel() const {
	return vel[0];
}
float CustomPointData::GetYVel() const {
	return vel[1];
}
float CustomPointData::GetZVel() const {
	return vel[2];
}
//cv::Vec3f CustomPointData::GetVel() {
//	return vel;
//}
glm::vec3 CustomPointData::GetVel() {
	return vel;
}
void CustomPointData::SetXVel(float xVel) {
	this->vel[0] = xVel;
}
void CustomPointData::SetYVel(float yVel) {
	this->vel[1] = yVel;
}
void CustomPointData::SetZVel(float zVel) {
	this->vel[2] = zVel;
}
void CustomPointData::SetXYZVel(float x, float y, float z) {
	this->vel[0] = x;
	this->vel[1] = y;
	this->vel[2] = z;
}
//void CustomPointData::SetXYZVel(cv::Vec3f velo) {
//	this->vel = velo;
//}
void CustomPointData::SetXYZVel(glm::vec3 velo) {
	this->vel = velo;
}
float CustomPointData::GetPressure() {
	return pre;
}
void CustomPointData::SetPressure(float pres) {
	this->pre = pres;
}
float CustomPointData::GetTemperature() const {
	return temp;
}
void CustomPointData::SetTemperature(float tempr) {
	this->temp = tempr;
}
void CustomPointData::SetData(CustomPointData p) {
	this->vel = p.vel;
	this->pre = p.pre;
	this->temp = p.temp;
}
float CustomPointData::GetMagnitude()
{
	return sqrt(pow(vel[0], 2) + pow(vel[1], 2) + pow(vel[2], 2));
}
#pragma endregion 

#pragma region CustomPoint
CustomPoint operator+(CustomPoint l, CustomPoint r) {
	CustomPoint p;
	p.SetXYZ(l.GetX() + r.GetX(), l.GetY() + r.GetY(), l.GetZ() + r.GetZ());
	p.SetXYZVel(l.GetXVel() + r.GetXVel(), l.GetYVel() + r.GetYVel(), l.GetZVel() + r.GetZVel());
	p.SetPressure(l.GetPressure() + r.GetPressure());
	p.SetTemperature(l.GetTemperature() + r.GetTemperature());
	return p;
}
CustomPoint operator*(CustomPoint l, float s) {
	CustomPoint p;
	p.SetXYZ(l.GetX(), l.GetY(), l.GetZ());
	p.SetXYZVel(l.GetXVel() * s, l.GetYVel() * s, l.GetZVel() * s);
	p.SetPressure(l.GetPressure() * s);
	p.SetTemperature(l.GetTemperature() * s);
	return p;
}
CustomPoint operator*(float s, CustomPoint l) {
	CustomPoint p;
	p.SetXYZ(l.GetX(), l.GetY(), l.GetZ());
	p.SetXYZVel(l.GetXVel() * s, l.GetYVel() * s, l.GetZVel() * s);
	p.SetPressure(l.GetPressure() * s);
	p.SetTemperature(l.GetTemperature() * s);
	return p;
}
CustomPoint operator/(CustomPoint l, float s) {
	CustomPoint p;
	p.SetXYZ(l.GetX(), l.GetY(), l.GetZ());
	p.SetXYZVel(l.GetXVel() / s, l.GetYVel() / s, l.GetZVel() / s);
	p.SetPressure(l.GetPressure() / s);
	p.SetTemperature(l.GetTemperature() / s);
	return p;
}
ostream& operator<<(ostream& os, const CustomPoint& cp)
{
	os << cp.pos[0] << ' ' << cp.pos[1] << ' ' << cp.pos[2] << ' '
		<< cp.vel[0] << ' ' << cp.vel[1] << ' ' << cp.vel[2] << ' '
		<< cp.pre << ' ' << cp.temp << endl;
	return os;
}
istream& operator>>(istream& is, CustomPoint& cp)
{
	is >> cp.pos[0] >> cp.pos[1] >> cp.pos[2]
		>> cp.vel[0] >> cp.vel[1] >> cp.vel[2]
		>> cp.pre >> cp.temp;
	return is;
}

CustomPoint::CustomPoint(float x, float y, float z) {
	pos[0] = x; pos[1] = y; pos[2] = z;
	vel[0] = 0; vel[1] = 0; vel[2] = 0;
	pre = 0;
	temp = 0;
}
CustomPoint::CustomPoint(glm::vec3 _pos) {
	pos = _pos;
	vel[0] = 0; vel[1] = 0; vel[2] = 0;
	pre = 0;
	temp = 0;
}
CustomPoint::CustomPoint() {
	pos[0] = 0; pos[1] = 0; pos[2] = 0;
	vel[0] = 0; vel[1] = 0; vel[2] = 0;
	pre = 0;
	temp = 0;
}
float CustomPoint::GetX() const {
	return pos[0];
}
float CustomPoint::GetY() const {
	return pos[1];
}
float CustomPoint::GetZ() const {
	return pos[2];
}
//cv::Vec3f CustomPoint::GetXYZ() {
//	return pos;
//}
glm::vec3 CustomPoint::GetXYZ() {
	return pos;
}
void CustomPoint::SetX(float x) {
	this->pos[0] = x;
}
void CustomPoint::SetY(float y) {
	this->pos[1] = y;
}
void CustomPoint::SetZ(float z) {
	this->pos[2] = z;
}
void CustomPoint::SetXYZ(float x, float y, float z) {
	this->pos[0] = x;
	this->pos[1] = y;
	this->pos[2] = z;
}
//void CustomPoint::SetXYZ(cv::Vec3f _pos) {
//	this->pos = _pos;
//}
void CustomPoint::SetXYZ(glm::vec3 _pos) {
	this->pos = _pos;
}
#pragma endregion

#pragma region CustomOctree
//---Private
CustomPoint* CustomOctree::GetPointRef(vector<CustomPoint>& cpoints, int i, int j, int k)
{
	assert(i < sampledDim[0] && j < sampledDim[1] && k < sampledDim[2]);
	return &cpoints[i + sampledDim[0] * (j + sampledDim[1] * k)];
}

void CustomOctree::FillPointDataByValueIndex(CustomPoint& _point, int& valueIndex, string& value) {
	switch (valueIndex)
	{
	case 0:
		_point.SetX(stof(value));
		break;
	case 1:
		_point.SetY(stof(value));
		break;
	case 2:
		_point.SetZ(stof(value));
		break;
	case 3:
		_point.SetXVel(stof(value));
		break;
	case 4:
		_point.SetYVel(stof(value));
		break;
	case 5:
		_point.SetZVel(stof(value));
		break;
	case 6:
		_point.SetPressure(stof(value));
		break;
	}
}

CustomChunk* CustomOctree::GetRoot()
{
	return &_Root;
}

vector<Frame>& CustomOctree::GetFrameCollection()
{
	return frameCollection;
}

Frame& CustomOctree::GetCachedFrame()
{
	return cachedFrame;
}

//---Public
CustomOctree::CustomOctree()
{

}

CustomOctree::~CustomOctree() {
	CleanUpChunkStructure();
}

int CustomOctree::GetTotalLevel() {
	return totalLevel;
}

int CustomOctree::GetTotalFrame()
{
	return totalFrame;
}

int CustomOctree::GetChunkPointCount()
{
	return (chunkSize[0] + 1) * (chunkSize[1] + 1) * (chunkSize[2] + 1);
}

glm::ivec3 CustomOctree::GetChunkSize()
{
	//return Toglm(chunkSize);
	return chunkSize;
}

float CustomOctree::GetMaxSampledSpacing()
{
	float s = sampledSpacing[0] > sampledSpacing[1] ? sampledSpacing[0] : sampledSpacing[1];
	s = s > sampledSpacing[2] ? s : sampledSpacing[2];
	return s;
}

glm::vec3 CustomOctree::GetSampledSpacing()
{
	//return Toglm(sampledSpacing);
	return sampledSpacing;
}

glm::vec3 CustomOctree::GetMin()
{
	//return Toglm(min);
	return min;
}

glm::vec3 CustomOctree::GetMax()
{
	//return Toglm(max);
	return max;
}

void CustomOctree::CleanUpChunkStructure_Recursive(CustomChunk* _Chunk) {
	if (_Chunk == nullptr)
		return;
	for (int i = 0; i < _Chunk->child.size(); i++) {
		CleanUpChunkStructure_Recursive(_Chunk->child[i]);
	}

	if (_Chunk != &_Root)
		delete _Chunk;
}

void CustomOctree::CleanUpChunkStructure() {
	//_Root.min = 0;
	_Root.min = glm::vec3(0.0f);
	//_Root.max = 0;
	_Root.max = glm::vec3(0.0f);
	//_Root.center = 0;
	_Root.center = glm::vec3(0.0f);
	//_Root.distance = 0;
	_Root.distance = glm::vec3(0.0f);
	_Root.level = -1;
	//_Root.chunkIndex = 0;
	_Root.chunkIndex = glm::ivec3(0);
	_Root.child.clear();
	CleanUpChunkStructure_Recursive(&_Root);
}

void CustomOctree::FillTreeStructureFromInfo_Recursive(CustomChunk* _Chunk, int nowLevel, int totalLv, /*cv::Vec3i*/glm::ivec3 chunkIndex) {
	for (int k = 0; k < 2; k++) {
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 2; i++) {
				CustomChunk* cc = new CustomChunk;
				//cv::Vec3f bias(0, 0, 0);
				glm::vec3 bias(0, 0, 0);
				switch (i + 2 * (j + 2 * k)) {
				case 0:
					//bias = cv::Vec3f(0, 0, 0);
					bias = glm::vec3(0, 0, 0);
					break;
				case 1:
					//bias = cv::Vec3f(_Chunk->distance[0], 0, 0);
					bias = glm::vec3(_Chunk->distance[0], 0, 0);
					break;
				case 2:
					//bias = cv::Vec3f(0, _Chunk->distance[1], 0);
					bias = glm::vec3(0, _Chunk->distance[1], 0);
					break;
				case 3:
					//bias = cv::Vec3f(_Chunk->distance[0], _Chunk->distance[1], 0);
					bias = glm::vec3(_Chunk->distance[0], _Chunk->distance[1], 0);
					break;
				case 4:
					//bias = cv::Vec3f(0, 0, _Chunk->distance[2]);
					bias = glm::vec3(0, 0, _Chunk->distance[2]);
					break;
				case 5:
					//bias = cv::Vec3f(_Chunk->distance[0], 0, _Chunk->distance[2]);
					bias = glm::vec3(_Chunk->distance[0], 0, _Chunk->distance[2]);
					break;
				case 6:
					//bias = cv::Vec3f(0, _Chunk->distance[1], _Chunk->distance[2]);
					bias = glm::vec3(0, _Chunk->distance[1], _Chunk->distance[2]);
					break;
				case 7:
					//bias = cv::Vec3f(_Chunk->distance[0], _Chunk->distance[1], _Chunk->distance[2]);
					bias = glm::vec3(_Chunk->distance[0], _Chunk->distance[1], _Chunk->distance[2]);
					break;
				}
				cc->min = _Chunk->min + bias;
				cc->max = _Chunk->center + bias;
				//cc->center = (cc->min + cc->max) / 2;
				cc->center = (cc->min + cc->max) / glm::vec3(2.0f);
				cc->distance = cc->max - cc->center;
				//cc->chunkIndex = chunkIndex * 2 + cv::Vec3i(i, j, k);
				cc->chunkIndex = chunkIndex * 2 + glm::ivec3(i, j, k);
				cc->level = nowLevel;
				cc->dataIndex = cc->chunkIndex[0] + (int)pow(2, cc->level) * (cc->chunkIndex[1] + (int)pow(2, cc->level) * cc->chunkIndex[2]);
				cc->parent = _Chunk;
				if (nowLevel + 1 <= totalLv)
					FillTreeStructureFromInfo_Recursive(cc, nowLevel + 1, totalLevel, cc->chunkIndex);
				_Chunk->child.push_back(cc);
			}
		}
	}
}

void CustomOctree::SetupInfo(FString s, float scale) {
	wstring path = wstring((wchar_t*)TCHAR_TO_UTF16(*s));
	fstream fs(path, std::ios_base::in);
	
	//debug
	if (!fs.is_open()) {
		//file open fail
		UE_LOG(LogTemp, Log, TEXT("file open fail: %s"), path.c_str());
	}
	else {
		//file open succeed
		UE_LOG(LogTemp, Log, TEXT("file open succeed"));

		fs >> chunkSize[0] >> chunkSize[1] >> chunkSize[2];
		fs >> totalLevel;
		fs >> sampledDim[0] >> sampledDim[1] >> sampledDim[2];
		fs >> min[0] >> min[1] >> min[2];
		fs >> max[0] >> max[1] >> max[2];
		fs >> totalFrame;
		fs >> maxXVel;
		fs >> maxYVel;
		fs >> maxZVel;
		fs >> minMagnitude >> maxMagnitude;
		fs >> minPressure >> maxPressure;
		fs >> minVorticity >> maxVorticity;
		fs >> minQCritirea >> maxQCritirea;
		fs.close();

		min *= scale;
		max *= scale;
			
		preprocessed = true;	
		this->FillTreeStructureFromInfo();
	}
}

void CustomOctree::FillTreeStructureFromInfo() {
	CleanUpChunkStructure();

	FOR_3 sampledSpacing[i] = (max[i] - min[i]) / (sampledDim[i] - 1);

	_Root.min = min;
	_Root.max = max;
	//_Root.center = (max + min) / 2;
	_Root.center = (max + min) / glm::vec3(2.0f);
	_Root.distance = max - _Root.center;
	_Root.level = 0;
	//_Root.chunkIndex = cv::Vec3i(0, 0, 0);
	_Root.chunkIndex = glm::ivec3(0, 0, 0);
	_Root.dataIndex = 0;
	_Root.parent = nullptr;
	FillTreeStructureFromInfo_Recursive(&_Root, 1, totalLevel, _Root.chunkIndex);

	frameCollection.clear();
	frameCollection.resize(totalFrame);//if totalFrame = 100 represents 1~100
	for (auto& fc : frameCollection) {
		fc.levelFile.resize(totalLevel + 1);//if totalLevel = 5 represents 0~5
		int level = 0;
		for (auto& lv : fc.levelFile) {
			lv.chunk.resize(pow(8, level));

			level++;
		}
	}
	cachedFrame.levelFile.clear();
	cachedFrame.levelFile.resize(totalLevel + 1);
	int level = 0;
	for (auto& lv : cachedFrame.levelFile) {
		lv.chunk.resize(pow(8, level));
		level++;
	}

	//cout << "Level0: " << _Root.min << " " << _Root.max << endl;
	//for (int i = 0; i < _Root.child.size(); i++) {
	//	cout << "Level1: "<<_Root.child[i].min << " " << _Root.child[i].max << endl;
	//	for (int j = 0; j < _Root.child[i].child.size(); j++)
	//		cout << "Level2: " << _Root.child[i].child[j].min << " " << _Root.child[i].child[j].max << endl;
	//}

	TraceTree();
}

float CustomOctree::GetMaxXVel()
{
	return maxXVel;
}
float CustomOctree::GetMaxYVel()
{
	return maxYVel;
}
float CustomOctree::GetMaxZVel()
{
	return maxZVel;
}
float CustomOctree::GetMinMagnitude()
{
	return minMagnitude;
}

float CustomOctree::GetMaxMagnitude()
{
	return maxMagnitude;
}

float CustomOctree::GetMinPressure()
{
	return minPressure;
}

float CustomOctree::GetMaxPressure()
{
	return maxPressure;
}

float CustomOctree::GetMinVorticity()
{
	return minVorticity;
}

float CustomOctree::GetMaxVorticity()
{
	return maxVorticity;
}

float CustomOctree::GetMinQCritirea()
{
	return minQCritirea;
}

float CustomOctree::GetMaxQCritirea()
{
	return maxQCritirea;
}

bool CustomOctree::GetVorticity(int& i, int& j, int& k, float& vorticity_)
{
	if (i + 1 >= sampledDim[0] || i - 1 < 0 || j + 1 >= sampledDim[1] || j - 1 < 0 || k + 1 >= sampledDim[2] || k - 1 < 0)
		return true;

	//cv::Vec3f origin = GetPointRef(sampledPoints, i, j, k)->GetVel();
	//cv::Vec3f xDirVel = GetPointRef(sampledPoints, i + 1, j, k)->GetVel();
	//cv::Vec3f yDirVel = GetPointRef(sampledPoints, i, j + 1, k)->GetVel();
	//cv::Vec3f zDirVel = GetPointRef(sampledPoints, i, j, k + 1)->GetVel();
	//cv::Vec3f xDirVel_m = GetPointRef(sampledPoints, i - 1, j, k)->GetVel();
	//cv::Vec3f yDirVel_m = GetPointRef(sampledPoints, i, j - 1, k)->GetVel();
	//cv::Vec3f zDirVel_m = GetPointRef(sampledPoints, i, j, k - 1)->GetVel();
	glm::vec3 origin = GetPointRef(sampledPoints, i, j, k)->GetVel();
	glm::vec3 xDirVel = GetPointRef(sampledPoints, i + 1, j, k)->GetVel();
	glm::vec3 yDirVel = GetPointRef(sampledPoints, i, j + 1, k)->GetVel();
	glm::vec3 zDirVel = GetPointRef(sampledPoints, i, j, k + 1)->GetVel();
	glm::vec3 xDirVel_m = GetPointRef(sampledPoints, i - 1, j, k)->GetVel();
	glm::vec3 yDirVel_m = GetPointRef(sampledPoints, i, j - 1, k)->GetVel();
	glm::vec3 zDirVel_m = GetPointRef(sampledPoints, i, j, k - 1)->GetVel();


	float iVorticity = (yDirVel[2] - origin[2]) / sampledSpacing[1] - (zDirVel[1] - origin[1]) / sampledSpacing[2];
	float jVorticity = (zDirVel[0] - origin[0]) / sampledSpacing[2] - (xDirVel[2] - origin[2]) / sampledSpacing[0];
	float kVorticity = (xDirVel[1] - origin[1]) / sampledSpacing[0] - (yDirVel[0] - origin[0]) / sampledSpacing[1];
	float vorticity = sqrt(pow(iVorticity, 2) + pow(jVorticity, 2) + pow(kVorticity, 2));//¥k°¼

	float iVorticity_m = (yDirVel_m[2] - origin[2]) / sampledSpacing[1] - (zDirVel_m[1] - origin[1]) / sampledSpacing[2];
	float jVorticity_m = (zDirVel_m[0] - origin[0]) / sampledSpacing[2] - (xDirVel_m[2] - origin[2]) / sampledSpacing[0];
	float kVorticity_m = (xDirVel_m[1] - origin[1]) / sampledSpacing[0] - (yDirVel_m[0] - origin[0]) / sampledSpacing[1];
	float vorticity_m = sqrt(pow(iVorticity_m, 2) + pow(jVorticity_m, 2) + pow(kVorticity_m, 2));//¥ª°¼

	vorticity_ = (vorticity + vorticity_m) / 2;
	return false;
}

bool CustomOctree::GetQCritirea(int& i, int& j, int& k, float& qcritirea)
{
	if (i + 1 >= sampledDim[0] || i - 1 < 0 || j + 1 >= sampledDim[1] || j - 1 < 0 || k + 1 >= sampledDim[2] || k - 1 < 0)
		return true;

	/*cv::Vec3f origin = GetPointRef(sampledPoints, i, j, k)->GetVel();
	cv::Vec3f xDirVel = GetPointRef(sampledPoints, i + 1, j, k)->GetVel();
	cv::Vec3f yDirVel = GetPointRef(sampledPoints, i, j + 1, k)->GetVel();
	cv::Vec3f zDirVel = GetPointRef(sampledPoints, i, j, k + 1)->GetVel();
	cv::Vec3f xDirVel_m = GetPointRef(sampledPoints, i - 1, j, k)->GetVel();
	cv::Vec3f yDirVel_m = GetPointRef(sampledPoints, i, j - 1, k)->GetVel();
	cv::Vec3f zDirVel_m = GetPointRef(sampledPoints, i, j, k - 1)->GetVel();*/
	glm::vec3 origin = GetPointRef(sampledPoints, i, j, k)->GetVel();
	glm::vec3 xDirVel = GetPointRef(sampledPoints, i + 1, j, k)->GetVel();
	glm::vec3 yDirVel = GetPointRef(sampledPoints, i, j + 1, k)->GetVel();
	glm::vec3 zDirVel = GetPointRef(sampledPoints, i, j, k + 1)->GetVel();
	glm::vec3 xDirVel_m = GetPointRef(sampledPoints, i - 1, j, k)->GetVel();
	glm::vec3 yDirVel_m = GetPointRef(sampledPoints, i, j - 1, k)->GetVel();
	glm::vec3 zDirVel_m = GetPointRef(sampledPoints, i, j, k - 1)->GetVel();

	float iShear = (xDirVel[0] - origin[0]) / sampledSpacing[0];
	float jShear = (yDirVel[1] - origin[1]) / sampledSpacing[1];
	float kShear = (zDirVel[2] - origin[2]) / sampledSpacing[2];
	float shear = (pow(iShear, 2) + pow(jShear, 2) + pow(kShear, 2)) * -0.5f;

	float iOmega = (yDirVel[2] - origin[2]) / sampledSpacing[1] * (zDirVel[1] - origin[1]) / sampledSpacing[2];
	float jOmega = (zDirVel[0] - origin[0]) / sampledSpacing[2] * (xDirVel[2] - origin[2]) / sampledSpacing[0];
	float kOmega = (xDirVel[1] - origin[1]) / sampledSpacing[0] * (yDirVel[0] - origin[0]) / sampledSpacing[1];
	float omega = -(iOmega + jOmega + kOmega);

	float iShear_m = (xDirVel_m[0] - origin[0]) / sampledSpacing[0];
	float jShear_m = (yDirVel_m[1] - origin[1]) / sampledSpacing[1];
	float kShear_m = (zDirVel_m[2] - origin[2]) / sampledSpacing[2];
	float shear_m = (pow(iShear_m, 2) + pow(jShear_m, 2) + pow(kShear_m, 2)) * -0.5f;

	float iOmega_m = (yDirVel_m[2] - origin[2]) / sampledSpacing[1] * (zDirVel_m[1] - origin[1]) / sampledSpacing[2];
	float jOmega_m = (zDirVel_m[0] - origin[0]) / sampledSpacing[2] * (xDirVel_m[2] - origin[2]) / sampledSpacing[0];
	float kOmega_m = (xDirVel_m[1] - origin[1]) / sampledSpacing[0] * (yDirVel_m[0] - origin[0]) / sampledSpacing[1];
	float omega_m = -(iOmega_m + jOmega_m + kOmega_m);

	float QValue = (omega + shear);//¥k°¼
	float QValue_m = (omega_m + shear_m);//¥ª°¼

	qcritirea = (QValue + QValue_m) / 2;
	return false;
}

void CustomOctree::TraceTree_Recursive(CustomChunk* _Chunk, vector<int>& count) {
	count[_Chunk->level]++;
	for (int i = 0; i < _Chunk->child.size(); i++) {
		TraceTree_Recursive(_Chunk->child[i], count);
	}
}

void CustomOctree::TraceTree() {
	vector<int> count;
	count.resize(totalLevel + 1);
	TraceTree_Recursive(&_Root, count);
	for (int l = 0; l <= totalLevel; l++)
		cout << "Level " << l << " Chunk Count: " << count[l] << endl;
}
#pragma endregion