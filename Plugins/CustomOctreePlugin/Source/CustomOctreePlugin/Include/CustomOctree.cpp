#include "CustomOctree.h"
#include "zfp/include/zfp.h"

//glm::vec3 Toglm(cv::Vec3f in) {
//	return glm::vec3(in[0], in[1], in[2]);
//}

//cv::Vec3f Tocv(glm::vec3 in) 
//	return cv::Vec3f(in[0], in[1], in[2]);
//}
float Magnitude(glm::vec3 a) {
	return sqrt(pow(a[0], 2) + pow(a[1], 2) + pow(a[2], 2));
}
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
glm::vec3 CustomPointData::GetVel() const {
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
float CustomPointData::GetPressure() const {
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

#pragma region ObjMarkerData
ObjMarkerData::ObjMarkerData() {}
ObjMarkerData::ObjMarkerData(string _objName, string _markerMapName, glm::vec3 _translation, glm::vec3 _rotation, glm::vec3 _scale) :
	objName(_objName), markerMapName(_markerMapName), translation(_translation), rotation(_rotation), scale(_scale) {}
void ObjMarkerData::SetData(string _objName, string _markerMapName, glm::vec3 _translation, glm::vec3 _rotation, glm::vec3 _scale) {
	objName = _objName; markerMapName = _markerMapName; translation = _translation; rotation = _rotation; scale = _scale;
}
void ObjMarkerData::SetFileName(string _objName, string _markerMapName) {
	objName = _objName; markerMapName = _markerMapName;
}
void ObjMarkerData::SetTransform(glm::vec3 _translation, glm::vec3 _rotation, glm::vec3 _scale) {
	translation = _translation; rotation = _rotation; scale = _scale;
}
string ObjMarkerData::GetObjName() {
	return objName;
}
string ObjMarkerData::GetMarkerMapName() {
	return markerMapName;
}
glm::vec3 ObjMarkerData::GetTranslation() {
	return translation;
}
glm::vec3 ObjMarkerData::GetRotation() {
	return rotation;
}
glm::vec3 ObjMarkerData::GetScale() {
	return scale;
}

ostream& operator<<(ostream& os, const ObjMarkerData& omd)
{
	os << omd.objName << ' ' << omd.markerMapName << ' ' << omd.translation[0] << ' ' << omd.translation[1] << ' '
		<< omd.translation[2] << ' ' << omd.rotation[0] << ' ' << omd.rotation[1] << ' ' << omd.rotation[2] << ' '
		<< omd.scale[0] << ' ' << omd.scale[1] << ' ' << omd.scale[2];
	return os;
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

vector<CustomPoint>& CustomOctree::GetPointsRef() {
	return points;
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

void CustomOctree::InputPointDataFromBinaryFile(string s) {
	//SimpleTimer timer;
	//timer.start();

	if (this->points.size() != 0 && this->pointCount != 0)
	{
		this->points.clear();
		this->pointCount = 0;
	}

	CustomPoint _point;
	ifstream fs(s, std::ios_base::in | std::ios_base::binary);
	fs.read((char*)&(this->pointCount), sizeof(uint64_t));
	this->points.clear();
	this->points.resize(this->pointCount);
	fs.read((char*)&(this->points[0]), sizeof(CustomPoint) * this->pointCount);
	/*for (long i = 0; i < this->pointCount; i++)
	{
		fs.read((char*)&_point, sizeof(CustomPoint));
		this->points.push_back(_point);
		if (i % 1000000 == 0)
			cout << "Points " << i << " Read!" << endl;
	}*/

	//timer.stop();
	//std::cout << "Input Point Data from binary costs " << timer.elapsed() << " seconds." << std::endl;

	//cout << "Input Finished!" << endl;
	fs.close();
}

void CustomOctree::InputPointDataFromTextFile(string s) {
	//SimpleTimer timer;
	//timer.start();

	if (this->points.size() != 0 || this->pointCount != 0)
	{
		this->points.clear();
		this->pointCount = 0;
	}

	fstream file;
	file.open(s, ios::in);
	string line;
	//getline(file, line);
	int lineCount = 0;
	int valueIndex = 0;
	CustomPoint _point;

	/*for (int i = 0; i < 14; i++) {
		getline(file, line);
	}*/

	while (getline(file, line))
	{
		string value = "";

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] != ' ')
				value += line[i];
			else if (i > 1)
			{
				if (line[i] == ' ' && line[i - 1] != ' ')
				{
					FillPointDataByValueIndex(_point, valueIndex, value);
					value = "";
					valueIndex++;
				}
			}
		}
		FillPointDataByValueIndex(_point, valueIndex, value);
		this->points.push_back(_point);
		this->pointCount++;
		lineCount++;
		valueIndex = 0;
		//if (lineCount % 100000 == 0)
			//cout << "Line " << lineCount << " Read!" << endl;
	}
	//cout << "Line " << lineCount << " Read!" << endl;

	//timer.stop();
	//std::cout << "Input Point Data from text costs " << timer.elapsed() << " seconds." << std::endl;
}

void CustomOctree::CalculatePreprocess() {
	//spacing min max
	FOR_3 pcCoordSet[i].clear();
	for (int i = 0; i < points.size(); i++)
	{
		pcCoordSet[0].insert(points[i].GetX());
		pcCoordSet[1].insert(points[i].GetY());
		pcCoordSet[2].insert(points[i].GetZ());
	}

	FOR_3{
		min[i] = *pcCoordSet[i].begin();
		max[i] = *pcCoordSet[i].rbegin();
	}

	FOR_3 originalDim[i] = (int)pcCoordSet[i].size();
	//cout << "Point Cloud MinXYZ: " << min[0] << " " << min[1] << " " << min[2] << endl;
	//cout << "Point Cloud MaxXYZ: " << max[0] << " " << max[1] << " " << max[2] << endl;
	//cout << "Point Cloud CoordCount: " << originalDim[0] << " " << originalDim[1] << " " << originalDim[2] << endl;

	FOR_3 originalSpacing[i] = (max[i] - min[i]) / (originalDim[i] - 1);
	//cout << "Point Cloud Spacing: " << originalSpacing[0] << " " << originalSpacing[1] << " " << originalSpacing[2] << endl;
	//TO FIX:Spacing?O??Cloud??Spacing??n???s?p??
	//int minDim = originalDim[0] < originalDim[1] ? originalDim[0] : originalDim[1];
	//minDim = minDim < originalDim[2] ? minDim : originalDim[2];
	//totalLevel = (int)floor(log2(minDim));
	//totalLevel = OCTREE_LEVEL; 
	//cout << "Point Cloud Total Level: " << totalLevel << endl;
	FOR_3{
		int unit = (int)pow(2,totalLevel);
		int closestBlockCount = unit;

		int safeCounter = 0;
		while (closestBlockCount < originalDim[i]) {
			closestBlockCount += unit;
			if (safeCounter < 500000)
				safeCounter++;
			else
			{
				//cout << "WARNING! SAFECOUNTER REACHED LIMIT!" << endl;
				break;
			}
		}
		//?????
		int upper = abs(closestBlockCount - originalDim[i]),lower = abs(closestBlockCount - unit - originalDim[i]);
		sampledDim[i] = (upper < lower ? closestBlockCount : closestBlockCount - unit);

		//???????j??
		//sampledDim[i] = closestBlockCount;

		chunkSize[i] = sampledDim[i] / unit;
		////?âZ???????+1
		sampledDim[i]++;

		sampledSpacing[i] = (max[i] - min[i]) / (sampledDim[i] - 1);
	}
	//cout << "Point Cloud Sampled Dimension: " << sampledDim[0] << " " << sampledDim[1] << " " << sampledDim[2] << endl;

	preprocessed = true;
}
/*
void CustomOctree::ResampleStructuredGrid(unibn::Octree<CustomPoint>& _OctreeSearch, tdogl::Mesh* modelMesh) {
	if (preprocessed) {
		sampledPoints.clear();
		vector<bool> invalidPoint;

		float progress = 0, totalAmount = (float)sampledDim[0] * (float)sampledDim[1] * (float)sampledDim[2], percent = 0;

		float searchRadius = originalSpacing[0] > originalSpacing[1] ? originalSpacing[0] : originalSpacing[1];
		searchRadius = searchRadius > originalSpacing[2] ? searchRadius : originalSpacing[2];
		searchRadius *= 1.5f;

		acc::BVHTree bvhtree(modelMesh->indices, modelMesh->vertices);//BVH Tree

		int insideCount = 0;

		//SimpleTimer timer;
		//timer.start();

		sampledPoints.resize(sampledDim[0] * sampledDim[1] * sampledDim[2]);
		invalidPoint.resize(sampledDim[0] * sampledDim[1] * sampledDim[2]);

		bool useOCSearch = !isInputOrganized || !(pcCoordSet[0].size() > 0 && pcCoordSet[1].size() > 0 && pcCoordSet[2].size() > 0);
		vector<float> orderedCoords[3];
		glm::ivec3 pointsDim;
		if (!useOCSearch) {
			FOR_3{
				orderedCoords->reserve(pcCoordSet[i].size());
				copy(pcCoordSet[i].begin(), pcCoordSet[i].end(), back_inserter(orderedCoords[i]));
				pointsDim[i] = orderedCoords[i].size();
			}
		}

#pragma omp parallel for collapse(2)
		for (int k = 0; k < sampledDim[2]; k++) {
			for (int j = 0; j < sampledDim[1]; j++) {
				for (int i = 0; i < sampledDim[0]; i++) {
					CustomPoint startPoint;
					startPoint.SetXYZ(points[0].GetX() + i * sampledSpacing.x, points[0].GetY() + j * sampledSpacing.y, points[0].GetZ() + k * sampledSpacing.z);
					CustomPoint A;
					float B = 0;

					//?gray????O?_?b??v????
					acc::Ray ray;
					ray.origin = startPoint.GetXYZ();
					ray.dir = glm::vec3(0, 0, 1);
					ray.tmin = 0.0f;
					ray.tmax = std::numeric_limits<float>::infinity();
					int times = 0;
					acc::BVHTree::Hit hit;
					while (bvhtree.intersect(ray, &hit))
					{
						if (hit.t < 0.0001f) {
							break;
						}
						ray.origin += hit.t * 1.01f * ray.dir;
						times++;
					}

					vector<uint64_t> result;
					vector<float> distance;

					if (useOCSearch)
						_OctreeSearch.radiusNeighbors<unibn::L2Distance<CustomPoint>>(startPoint, searchRadius, result, distance);
					else {
						result.reserve(27);
						distance.reserve(27);
						glm::ivec3 start;
						FOR_3{
							vector<float>::iterator it = lower_bound(orderedCoords[i].begin(), orderedCoords[i].end(), startPoint.GetXYZ()[i] - searchRadius);
							start[i] = it - orderedCoords[i].begin();
						}
						for (uint64_t nowz = start.z; nowz < orderedCoords[2].size() && orderedCoords[2][nowz] <= startPoint.GetZ() + searchRadius; ++nowz) {
							for (uint64_t nowy = start.y; nowy < orderedCoords[1].size() && orderedCoords[1][nowy] <= startPoint.GetY() + searchRadius; ++nowy) {
								for (uint64_t nowx = start.x; nowx < orderedCoords[0].size() && orderedCoords[0][nowx] <= startPoint.GetX() + searchRadius; ++nowx) {
									uint64_t index = nowx + pointsDim[0] * (nowy + pointsDim[1] * nowz);
									float d = glm::distance(startPoint.GetXYZ(), points[index].GetXYZ());
									if (d < searchRadius) {
										{
											result.push_back(index);
											distance.push_back(d);
										}
									}
								}
							}
						}
					}

					for (int p = 0; p < result.size(); p++)
					{
						if (points[result[p]].GetZ() == min[2])//?o???a?O
							continue;

						//float dist = sqrt(distance[p]); <-Maybe wrong
						float dist = pow(distance[p], 2);//??j?|?z????inf

						if (dist == 0)
						{
							A = points[result[p]];
							B = 1;
							break;
						}
						A = A + points[result[p]] / dist;
						B = B + 1 / dist;
					}
					if (B != 0)
						A = A / B;

					if (times % 2 != 0)//?bModel?~??
					{
						insideCount++;
						invalidPoint[i + (uint64_t)sampledDim[0] * (j + (uint64_t)sampledDim[1] * (uint64_t)k)] = true;
					}
					startPoint.SetData(A);
					*GetPointRef(sampledPoints, i, j, k) = startPoint;

#pragma omp critical
					{
						progress++;
						if (progress > totalAmount / 100.f)
						{
							percent += totalAmount >= 100 ? 1.f : 100.f / totalAmount;
							//cout << "Points" << " resampling: " << percent << "%!" << endl;
							progress -= totalAmount / 100.f;
						}
					}
				}
			}
		}

		points.clear();
		points.shrink_to_fit();

		//timer.stop();
		//cout << "Points resampled!" << endl;
		//cout << "Sampled Point Size: " << sampledPoints.size() << endl;
		//cout << "Used Time: " << timer.elapsed() << " seconds." << endl;

		FOR_3 orderedCoords[i].clear();
		FOR_3 orderedCoords[i].reserve(sampledDim[i]);
		FOR_3{
			for (int j = 0; j < sampledDim[i]; ++j) {
				orderedCoords[i].push_back(sampledPoints[0].GetXYZ()[i] + sampledSpacing[i] * j);
			}
		}

		searchRadius = sampledSpacing[0] > sampledSpacing[1] ? sampledSpacing[0] : sampledSpacing[1];
		searchRadius = searchRadius > sampledSpacing[2] ? searchRadius : sampledSpacing[2];
		searchRadius *= 1.5f;

		//timer.start();
#pragma omp parallel for collapse(2)
		for (int k = 0; k < sampledDim[2]; k++) {
			for (int j = 0; j < sampledDim[1]; j++) {
				for (int i = 0; i < sampledDim[0]; i++) {
					CustomPoint startPoint;
					startPoint.SetXYZ(sampledPoints[0].GetX() + i * sampledSpacing.x, sampledPoints[0].GetY() + j * sampledSpacing.y, sampledPoints[0].GetZ() + k * sampledSpacing.z);

					if (invalidPoint[i + (uint64_t)sampledDim[0] * (j + (uint64_t)sampledDim[1] * (uint64_t)k)]) {
						CustomPoint A = startPoint;

						vector<uint64_t> result;
						vector<float> distance;

						//_OctreeSearchResampled.radiusNeighbors<unibn::L2Distance<CustomPoint>>(startPointNew, searchRadius, result, distance);

						result.reserve(27);
						glm::ivec3 start;
						FOR_3{
							vector<float>::iterator it = lower_bound(orderedCoords[i].begin(), orderedCoords[i].end(), startPoint.GetXYZ()[i] - searchRadius);
							start[i] = it - orderedCoords[i].begin();
						}

						for (uint64_t nowz = start.z; nowz < orderedCoords[2].size(); ++nowz) {
							if (orderedCoords[2][nowz] > startPoint.GetZ() + searchRadius)
								break;
							for (uint64_t nowy = start.y; nowy < orderedCoords[1].size(); ++nowy) {
								if (orderedCoords[1][nowy] > startPoint.GetY() + searchRadius)
									break;
								for (uint64_t nowx = start.x; nowx < orderedCoords[0].size(); ++nowx) {
									if (orderedCoords[0][nowx] > startPoint.GetX() + searchRadius)
										break;
									float d = glm::distance(startPoint.GetXYZ(), GetPointRef(sampledPoints, nowx, nowy, nowz)->GetXYZ());
									if (d < searchRadius) {
										result.push_back(nowx + (uint64_t)sampledDim[0] * (nowy + (uint64_t)sampledDim[1] * nowz));
									}
								}
							}
						}

						for (int p = 0; p < result.size(); p++)
						{
							if (!invalidPoint[result[p]]) {
								float length = (sampledPoints[result[p]].GetXYZ() - startPoint.GetXYZ()).length();
								acc::Ray ray;
								ray.origin = startPoint.GetXYZ();
								ray.dir = sampledPoints[result[p]].GetXYZ() - startPoint.GetXYZ();
								ray.tmin = 0.0f;
								ray.tmax = std::numeric_limits<float>::infinity();
								acc::BVHTree::Hit hit;
								bvhtree.intersect(ray, &hit);
								float hitt = hit.t;
								float nothitt = length - hit.t;
								CustomPoint tmpA;
								if (nothitt > 0.001f)
									tmpA = sampledPoints[result[p]] / nothitt * hitt;
								else
									tmpA = sampledPoints[result[p]]; //????OPoints?????D??????A??sampledPoints?p?G?????A??
								A.SetXYZVel(tmpA.GetXVel(), tmpA.GetYVel(), tmpA.GetZVel());
								break;
							}
						}

						A.SetXYZVel(-A.GetVel());

						*GetPointRef(sampledPoints, i, j, k) = A;
					}
				}
			}
		}
		//timer.stop();
		//cout << "Inside Model Point Counting Finished!" << endl;
		//cout << "Used Time: " << timer.elapsed() << " seconds." << endl;
		// << "Inside Model Point Size: " << insideCount << endl;

	}
	else
	{
		//cout << "DATA NOT PREPROCESSED,SKIP RESAMPLING!" << endl;
	}
}
*/
void CustomOctree::OutputGridInfoToBinaryFile(string outFolder, string resampledGridFilename, int _totalFrame, bool outputGridInfo) {
	//if (!fs::exists(outFolder))
		//fs::create_directory(outFolder);

	fstream writeInfo(outFolder + "gridinfo.bin", std::ios_base::out);

	// file header
	writeInfo << hdr.fileMagic << endl;
	writeInfo << hdr.fileName << endl;
	writeInfo << hdr.vel << hdr.pre << hdr.temp << hdr.rad << endl;

	writeInfo << chunkSize[0] << " " << chunkSize[1] << " " << chunkSize[2] << endl;
	writeInfo << totalLevel << endl;
	writeInfo << sampledDim[0] << " " << sampledDim[1] << " " << sampledDim[2] << endl;
	writeInfo << min[0] << " " << min[1] << " " << min[2] << endl;
	writeInfo << max[0] << " " << max[1] << " " << max[2] << endl;
	writeInfo << _totalFrame << endl;
	writeInfo.close();

	if (outputGridInfo) {
		fstream fs(resampledGridFilename, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
		float progress = 0, totalAmount = (float)sampledDim[0] * (float)sampledDim[1] * (float)sampledDim[2], percent = 0;
		for (int k = 0; k < sampledDim[2]; k++) {
			for (int j = 0; j < sampledDim[1]; j++) {
				for (int i = 0; i < sampledDim[0]; i++) {
					fs.write((char*)GetPointRef(sampledPoints, i, j, k), sizeof(CustomPoint));
					progress++;
					if (progress > totalAmount / 100.f)
					{
						percent += totalAmount >= 100 ? 1.f : 100.f / totalAmount;
						//cout << "Resampled point outputed: " << percent << "%!" << endl;
						progress -= totalAmount / 100.f;
					}
				}
			}
		}
		fs.close();
	}
}

void CustomOctree::InputGridInfo(string outFolder)
{
	fstream readInfo(outFolder + "gridinfo.bin", std::ios_base::in);
	readInfo >> chunkSize[0] >> chunkSize[1] >> chunkSize[2];
	readInfo >> totalLevel;
	readInfo >> sampledDim[0] >> sampledDim[1] >> sampledDim[2];
	readInfo >> min[0] >> min[1] >> min[2];
	readInfo >> max[0] >> max[1] >> max[2];
	readInfo >> totalFrame;
	readInfo.close();
}

void CustomOctree::InputResampledGrid(string resampledGridFilename) {

	FOR_3 sampledSpacing[i] = (max[i] - min[i]) / (sampledDim[i] - 1);

	sampledPoints.clear();
	sampledPoints.resize(sampledDim[0] * sampledDim[1] * sampledDim[2]);
	//cout << resampledGridFilename << endl;
	fstream fs(resampledGridFilename, std::ios_base::in | std::ios_base::binary);
	float progress = 0, totalAmount = (float)sampledDim[0] * (float)sampledDim[1] * (float)sampledDim[2], percent = 0;
	for (int k = 0; k < sampledDim[2]; k++) {
		for (int j = 0; j < sampledDim[1]; j++) {
			for (int i = 0; i < sampledDim[0]; i++) {
				fs.read((char*)GetPointRef(sampledPoints, i, j, k), sizeof(CustomPoint));
				progress++;
				if (progress > totalAmount / 100.f)
				{
					percent += totalAmount >= 100 ? 1.f : 100.f / totalAmount;
					//cout << "Resampled point inputed: " << percent << "%!" << endl;
					progress -= totalAmount / 100.f;
				}
			}
		}
	}
	fs.close();
}

bool SourceInChunk(glm::vec3 origin, float radius, glm::vec3 pos, glm::vec3 spacing)
{
	if (origin[0] <= pos[0] + spacing[0] && origin[0] >= pos[0] - spacing[0] &&
		origin[1] <= pos[1] + spacing[1] && origin[1] >= pos[1] - spacing[1] &&
		origin[2] <= pos[2] + spacing[2] && origin[2] >= pos[2] - spacing[2])
		return true;
	return false;
}

template<class T>
void ProcessChunkIntersection(vector<vector<vector<T>>>& chunkSource, T& source, int totalLevel, int level, glm::vec3 pos, glm::vec3 spacing, glm::vec3 min)
{
	glm::vec3 chunkMin = pos - spacing;
	glm::vec3 chunkOffset = glm::vec3((chunkMin[0] - min[0]) / spacing[0] / 2, (chunkMin[1] - min[1]) / spacing[1] / 2, (chunkMin[2] - min[2]) / spacing[2] / 2);
	int indexInLevel = chunkOffset[0] + (int)pow(2, level) * (chunkOffset[1] + (int)pow(2, level) * chunkOffset[2]);
	//cout << level << " ";
	//cout << chunkOffset << " ";
	//cout << indexInLevel << endl;
	if (SourceInChunk(source.pos, source.radius, pos, spacing)) {
		spacing /= 2.0f;
		chunkSource[level][indexInLevel].push_back(source);
		if (level >= totalLevel)
			return;
		for (int i = 0; i < 8; i++) {
			glm::vec3 temPos = pos;
			if (i == 0 || i == 2 || i == 4 || i == 6)
				temPos[0] -= spacing[0];
			else
				temPos[0] += spacing[0];
			if (i == 0 || i == 1 || i == 4 || i == 5)
				temPos[1] -= spacing[1];
			else
				temPos[1] += spacing[1];
			if (i == 0 || i == 1 || i == 2 || i == 3)
				temPos[2] -= spacing[2];
			else
				temPos[2] += spacing[2];
			ProcessChunkIntersection<T>(chunkSource, source, totalLevel, level + 1, temPos, spacing, min);
		}
	}
}

template<typename T1, typename T2>
pair<uint64_t, float> CustomOctree::CompressToValueIndex(const vector<T1>& target, vector<T2>& value, vector<unsigned char>& valueIndex, float subtract(const T2& a, const T2& b), T2 access(const T1& x), float threshold, const vector<int>& targetIndex, CompressionMethod method) {
	pair<uint64_t, float> error = { 0, 0 };
	value.clear();
	valueIndex.clear();
	valueIndex.resize(target.size());

	if (method == CompressionMethod::DUMMY)
		method = compressionMethod;

	switch (method) {
	case CompressionMethod::SimilarEliminateOriginal:
	{
		for (int sp = 0; sp < target.size(); sp++) {
			int index = sp;
			if (targetIndex.size() > 0)
				index = targetIndex[sp];

			bool qualifiedFound = false;
			unsigned char qualifiedIndex = 0;
			float minVal = std::numeric_limits<float>().max();
			for (int i = 0; i < value.size(); i++) {
				float val = subtract(value[i], access(target[index]));
				if (val < minVal) {
					qualifiedIndex = i;
					minVal = val;
					if (val < threshold) {
						qualifiedFound = true;
					}
				}
			}

			if (!qualifiedFound && value.size() < 256) {
				valueIndex[index] = value.size();
				value.push_back(access(target[index]));
			}
			else {
				if (!qualifiedFound)
					++error.first;
				valueIndex[index] = qualifiedIndex;
				error.second += minVal;
			}
		}
	}
	break;
	case CompressionMethod::SimilarEliminateAdaptive:
	{
		for (int sp = 0; sp < target.size(); sp++) {
			int index = sp;
			if (targetIndex.size() > 0)
				index = targetIndex[sp];

			bool qualifiedFound = false;
			unsigned char qualifiedIndex = 0;
			float minVal = std::numeric_limits<float>().max();
			for (int i = 0; i < value.size(); i++) {
				float val = subtract(value[i], access(target[index]));
				if (val < minVal) {
					qualifiedIndex = i;
					minVal = val;
					if (val < threshold) {
						qualifiedFound = true;
					}
				}
			}

			if (!qualifiedFound && value.size() < 256) {
				valueIndex[index] = value.size();
				value.push_back(access(target[index]));
			}
			else {
				if (!qualifiedFound) {
					value.clear();
					valueIndex.clear();
					return { 0, -1 };
				}
				valueIndex[index] = qualifiedIndex;
				error.second += minVal;
			}
		}
	}
	break;
	case CompressionMethod::SimilarEliminateKmeans:
	{
		for (int i = 0; i < 256; ++i) {
			int index = i;
			if (targetIndex.size() > 0)
				index = targetIndex[i];
			value.push_back(access(target[index]));
		}

#pragma omp parallel for
		for (int i = 0; i < target.size(); ++i) {
			unsigned char qualifiedIndex = 0;
			float minVal = std::numeric_limits<float>().max();
			for (int j = 0; j < value.size(); j++) {
				float val = subtract(value[j], access(target[i]));
				if (val < minVal) {
					qualifiedIndex = j;
					minVal = val;
				}
			}
			valueIndex[i] = qualifiedIndex;
			error.second += minVal;
			if (minVal > threshold)
				++error.first;
		}
	}
	break;
	}
	return error;
}

void CustomOctree::SequentialReadStructuredGridAndMergeToFile(string outFolder, string filename, bool isBaseFile) {
	//SimpleTimer timer;

	size_t pos = filename.find("COT");
	string result = filename.substr(0, pos - 1);  // -1 to remove the underscore before "COT"

	// folder_filename = outFolder + filename + "/";
	string folder_filename = outFolder + result + "/";

	//try {
	//	if (!fs::exists(folder_filename))
	//		fs::create_directory(folder_filename);
	//}
	//catch (exception& e) {
	//	cout << e.what() << endl;
	//}
	float progress = 0, totalAmount = (float)sampledDim[0] * (float)sampledDim[1] * (float)sampledDim[2], percent = 0;

	//Compress And Output
	if (compressionMethod != CompressionMethod::LagrangianMethod) {
		CustomPointData* cp;

		vector<vector<vector<pair<CustomPointData*, uint64_t>>>> pointCache;

		int sampledPointSize = GetChunkPointCount();
		pointCache.resize(totalLevel + 1);
		for (int i = 0; i <= totalLevel; i++) {
			pointCache[i].resize((int)pow(8, i));
			for (int j = 0; j < (int)pow(8, i); ++j)
				pointCache[i].reserve(sampledPointSize);
		}

		//timer.start();

		//Merge To Chunk
		for (int k = 0; k < sampledDim[2]; k++) {
			for (int j = 0; j < sampledDim[1]; j++) {
				for (int i = 0; i < sampledDim[0]; i++) {

					cp = GetPointRef(sampledPoints, i, j, k);
					//#pragma omp parallel for
					for (int l = totalLevel; l >= 0; l--) {
						int multiplier = (int)pow(2, totalLevel - l);
						if (i % multiplier != 0 || j % multiplier != 0 || k % multiplier != 0)
							break;

						glm::ivec3 chunkSizeCounter = chunkSize * (int)pow(2, totalLevel - l);

						glm::vec3 chunkIndex, isOverlap(0.0f, 0.0f, 0.0f);
						chunkIndex[0] = (float)i / (float)chunkSizeCounter[0];
						chunkIndex[1] = (float)j / (float)chunkSizeCounter[1];
						chunkIndex[2] = (float)k / (float)chunkSizeCounter[2];
						if (i != 0 && i != sampledDim[0] - 1)
							if (i % chunkSizeCounter[0] == 0)
								isOverlap[0] = 1;
						if (j != 0 && j != sampledDim[1] - 1)
							if (j % chunkSizeCounter[1] == 0)
								isOverlap[1] = 1;
						if (k != 0 && k != sampledDim[2] - 1)
							if (k % chunkSizeCounter[2] == 0)
								isOverlap[2] = 1;
						if (i == sampledDim[0] - 1)
							chunkIndex[0]--;
						if (j == sampledDim[1] - 1)
							chunkIndex[1]--;
						if (k == sampledDim[2] - 1)
							chunkIndex[2]--;
						for (int z = 0; z <= isOverlap[2]; z++) {
							for (int y = 0; y <= isOverlap[1]; y++) {
								for (int x = 0; x <= isOverlap[0]; x++) {
									uint64_t wholeIndex = (uint64_t)chunkIndex[0] - x + (uint64_t)pow(2, l) * ((uint64_t)chunkIndex[1] - y + (uint64_t)pow(2, l) * ((uint64_t)chunkIndex[2] - z));
									pointCache[l][wholeIndex].push_back(pair<CustomPointData*, uint64_t>(cp, wholeIndex));
								}
							}
						}
					}
					progress++;
					if (progress > totalAmount / 100.f)
					{
						percent += totalAmount >= 100 ? 1.f : 100.f / totalAmount;
						//cout << "Chunk" << " cut: " << percent << "%!" << endl;
						progress -= totalAmount / 100.f;
					}
				}
			}
		}

		//timer.stop();
		//std::cout << "Cut Chunks costs " << timer.elapsed() << " seconds." << std::endl;

		string pathErrorLog = folder_filename + "ChunkErrorLog.txt";
		fstream errorLog;
		errorLog.open(pathErrorLog, ios::out | ios::trunc);

		if (isBaseFile) {
			basePointCacheList.clear();
			basePointCacheList.resize(pointCache.size());
		}
		for (int sl = 0; sl < pointCache.size(); sl++) {
			//timer.start();
			if (isBaseFile) {
				basePointCacheList[sl].resize(pointCache[sl].size());
			}
			string pathValue, pathIndex, pathLaplacian, pathLaplacianIndex;

			pathValue = folder_filename + "Level" + to_string(sl) + "_compressed.bin";
			pathIndex = folder_filename + "Level" + to_string(sl) + "_index.bin";
			pathLaplacian = folder_filename + "Level" + to_string(sl) + "_laplacian_compressed.bin";
			pathLaplacianIndex = folder_filename + "Level" + to_string(sl) + "_laplacian_index.bin";

			fstream fileValue, fileIndex, fileLaplacian, fileLaplacianIndex;
			fileValue.open(pathValue, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
			fileIndex.open(pathIndex, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
			if (withLaplacianPyramid && sl > 0) {
				fileLaplacian.open(pathLaplacian, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
				fileLaplacianIndex.open(pathLaplacianIndex, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
			}

			int64_t accumulatedSize = 0;
			int64_t accumulatedLaplacianSize = 0;
			int totalVelCount = 0;
			int totalPreCount = 0;
			int totalTempCount = 0;

			uint64_t chunkQuantizedPointsMax = 0;
			uint64_t chunkQuantizedPointsSum = 0;
			uint64_t chunkCount = 0;
			uint64_t compressedChunkCount = 0;
			double chunkErrorMax = 0;
			double allChunkErrorSum = 0;

			vector<int> indexes;
			indexes.resize(GetChunkPointCount());
			for (int i = 0; i < indexes.size(); i++) {
				indexes[i] = i;
			}

			std::random_device rd;
			std::mt19937 g(rd());

			std::shuffle(indexes.begin(), indexes.end(), g);

#pragma omp parallel for ordered
			for (int sf = 0; sf < pointCache[sl].size(); sf++) {
				vector<pair<CustomPointData*, uint64_t>> sortList;
				vector<float> value_list;	// add by Liu

				for (int sp = 0; sp < pointCache[sl][sf].size(); sp++) {
					sortList.push_back(pointCache[sl][sf][sp]);
				}

				// unnecessary? since sf is equal to p.second
				stable_sort(sortList.begin(), sortList.end(), [](const pair<CustomPointData*, uint64_t>& a, const pair<CustomPointData*, uint64_t>& b) -> bool
					{
						return a.second < b.second;
					});
				if (isBaseFile) {
					for (int sp = 0; sp < pointCache[sl][sf].size(); sp++) {
						basePointCacheList[sl][sf].push_back(*pointCache[sl][sf][sp].first);
					}
				}

				// output to file
				switch (compressionMethod) {
				case CompressionMethod::NoCompression:
				{
					bool isSimilar = false;
					if (withMotionIndex && !isBaseFile) {
						isSimilar = true;
						for (int sp = 0; sp < GetChunkPointCount(); sp++) {
							float mag = Magnitude(basePointCacheList[sl][sf][sp].GetVel() - sortList[sp].first->GetVel());
							float pre = abs(basePointCacheList[sl][sf][sp].GetPressure() - sortList[sp].first->GetPressure());
							if (mag > magThreshold || pre > preThreshold) {
								isSimilar = false;
								break;
							}
						}
					}

					if (!isSimilar) {
						vector<glm::vec3> velValues;
						vector<float> preValues;

						for (int sp = 0; sp < sortList.size(); sp++) {
							velValues.push_back(sortList[sp].first->GetVel());
							preValues.push_back(sortList[sp].first->GetPressure());
						}

#pragma omp ordered
						{
							size_t sizeVelValues = velValues.size();
							totalVelCount += sizeVelValues;
							size_t sizePreValues = preValues.size();
							totalPreCount += sizePreValues;
							fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
							fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
							fileValue.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
							fileValue.write((char*)preValues.data(), sizeof(float) * sizePreValues);

							fileIndex.write((char*)&accumulatedSize, sizeof(accumulatedSize));
							accumulatedSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
								sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues;
						}
					}
					else {
						int64_t pointToBaseFile = -1;
#pragma omp ordered
						fileIndex.write((char*)&pointToBaseFile, sizeof(int64_t));
					}
					break;
				}
				case CompressionMethod::SimilarEliminateOriginal:
				{
					uint64_t chunkQuantizedPoints = 0;
					double chunkErrorSum = 0;
					bool isSimilar = false;
					if (withMotionIndex && !isBaseFile) {
						isSimilar = true;
						for (int sp = 0; sp < GetChunkPointCount(); sp++) {
							float mag = Magnitude(basePointCacheList[sl][sf][sp].GetVel() - sortList[sp].first->GetVel());
							float pre = abs(basePointCacheList[sl][sf][sp].GetPressure() - sortList[sp].first->GetPressure());

							// temp
							float temp = abs(basePointCacheList[sl][sf][sp].GetTemperature() - sortList[sp].first->GetTemperature());
							if (mag > magThreshold || pre > preThreshold || temp > tempThreshold) {
								isSimilar = false;
								break;
							}
						}
					}
					if (!isSimilar) {
						vector<glm::vec3> velValues;
						vector<float> preValues;
						vector<float> tempValues;
						vector<unsigned char> velIndexes;
						velIndexes.resize(sortList.size());
						vector<unsigned char> preIndexes;
						preIndexes.resize(sortList.size());
						vector<unsigned char> tempIndexes;
						tempIndexes.resize(sortList.size());

						pair<uint64_t, float > result2 = CompressToValueIndex<pair<CustomPointData*, uint64_t>, glm::vec3>(sortList, velValues, velIndexes,
							[](auto a, auto b) -> auto {return Magnitude(a - b); },
							[](auto x)-> auto {return x.first->GetVel(); }, magThreshold, indexes);
						chunkQuantizedPoints += result2.first;
						chunkErrorSum += result2.second;

						CompressToValueIndex<pair<CustomPointData*, uint64_t>, float>(sortList, preValues, preIndexes,
							[](auto a, auto b) -> auto {return abs(a - b); },
							[](auto x)-> auto {return x.first->GetPressure(); }, preThreshold, indexes);

						CompressToValueIndex<pair<CustomPointData*, uint64_t>, float>(sortList, tempValues, tempIndexes,
							[](auto a, auto b) -> auto {return abs(a - b); },
							[](auto x)-> auto {return x.first->GetTemperature(); }, tempThreshold, indexes);


#pragma omp ordered
						{
							size_t sizeVelValues = velValues.size();
							totalVelCount += sizeVelValues;
							size_t sizePreValues = preValues.size();
							totalPreCount += sizePreValues;
							size_t sizeTempValues = tempValues.size();
							totalTempCount += sizeTempValues;
							fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
							fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
							// temp
							fileValue.write((char*)&sizeTempValues, sizeof(sizeTempValues));
							fileValue.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
							fileValue.write((char*)preValues.data(), sizeof(float) * sizePreValues);
							// temp
							fileValue.write((char*)tempValues.data(), sizeof(float) * sizeTempValues);
							fileValue.write((char*)velIndexes.data(), sizeof(unsigned char) * velIndexes.size());
							fileValue.write((char*)preIndexes.data(), sizeof(unsigned char) * preIndexes.size());
							// temp
							fileValue.write((char*)tempIndexes.data(), sizeof(unsigned char) * tempIndexes.size());

							// temp
							fileIndex.write((char*)&accumulatedSize, sizeof(accumulatedSize));
							accumulatedSize += sizeof(sizeVelValues) + sizeof(sizePreValues) + sizeof(sizeTempValues) +
								sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues + sizeof(float) * sizeTempValues +
								sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size() + sizeof(unsigned char) * tempIndexes.size();

							++compressedChunkCount;
							chunkQuantizedPointsSum += chunkQuantizedPoints;
							++chunkCount;
							if (chunkQuantizedPointsMax < chunkQuantizedPoints)
								chunkQuantizedPointsMax = chunkQuantizedPoints;
							double chunkErrorAvg = chunkErrorSum / sortList.size();
							if (chunkErrorMax < chunkErrorAvg)
								chunkErrorMax = chunkErrorAvg;
							allChunkErrorSum += chunkErrorAvg;
						}

						// for laplacian
						for (int sp = 0; sp < pointCache[sl][sf].size(); sp++) {
							pointCache[sl][sf][sp].first->SetXYZVel(velValues[velIndexes[sp]]);
							pointCache[sl][sf][sp].first->SetPressure(preValues[preIndexes[sp]]);
							// temp
							pointCache[sl][sf][sp].first->SetTemperature(tempValues[tempIndexes[sp]]);
						}
					}
					else if (isSimilar) {
						int64_t pointToBaseFile = -1;
#pragma omp ordered
						fileIndex.write((char*)&pointToBaseFile, sizeof(int64_t));
					}
					break;
				}
				case CompressionMethod::SimilarEliminateAdaptive:
				{
					uint64_t chunkQuantizedPoints = 0;
					double chunkErrorSum = 0;
					bool isSimilar = false;
					if (withMotionIndex && !isBaseFile) {
						isSimilar = true;
						for (int sp = 0; sp < GetChunkPointCount(); sp++) {
							float mag = Magnitude(basePointCacheList[sl][sf][sp].GetVel() - sortList[sp].first->GetVel());
							float pre = abs(basePointCacheList[sl][sf][sp].GetPressure() - sortList[sp].first->GetPressure());
							if (mag > magThreshold || pre > preThreshold) {
								isSimilar = false;
								break;
							}
						}
					}
					if (!isSimilar) {
						vector<glm::vec3> velValues;
						vector<float> preValues;
						vector<unsigned char> velIndexes;
						velIndexes.resize(sortList.size());
						vector<unsigned char> preIndexes;
						preIndexes.resize(sortList.size());

						bool isNotCompressible = false;


						pair<uint64_t, float > result2 = CompressToValueIndex<pair<CustomPointData*, uint64_t>, glm::vec3>(sortList, velValues, velIndexes,
							[](auto a, auto b) -> auto {return Magnitude(a - b); },
							[](auto x)-> auto {return x.first->GetVel(); }, magThreshold, indexes);
						if (result2.second >= 0) {
							chunkQuantizedPoints += result2.first;
							chunkErrorSum += result2.second;
						}
						else {
							isNotCompressible = true;
						}

						result2 = CompressToValueIndex<pair<CustomPointData*, uint64_t>, float>(sortList, preValues, preIndexes,
							[](auto a, auto b) -> auto {return abs(a - b); },
							[](auto x)-> auto {return x.first->GetPressure(); }, preThreshold, indexes);
						if (result2.second < 0)
							isNotCompressible = true;

						if (isNotCompressible) {
							velValues.resize(sortList.size());
							preValues.resize(sortList.size());
							for (int sp = 0; sp < sortList.size(); sp++) {
								velValues[sp] = sortList[sp].first->GetVel();
								preValues[sp] = sortList[sp].first->GetPressure();
							}
						}


#pragma omp ordered
						{
							if (isNotCompressible) {
								size_t sizeVelValues = 0;
								size_t sizePreValues = 0;
								fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
								fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
								sizeVelValues = velValues.size();
								sizePreValues = preValues.size();
								fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
								fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
								fileValue.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
								fileValue.write((char*)preValues.data(), sizeof(float) * sizePreValues);

								fileIndex.write((char*)&accumulatedSize, sizeof(accumulatedSize));
								accumulatedSize += sizeof(sizeVelValues) * 2 + sizeof(sizePreValues) * 2 +
									sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues;
							}
							else {
								// original
								size_t sizeVelValues = velValues.size();
								totalVelCount += sizeVelValues;
								size_t sizePreValues = preValues.size();
								totalPreCount += sizePreValues;
								fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
								fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
								fileValue.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
								fileValue.write((char*)preValues.data(), sizeof(float) * sizePreValues);
								fileValue.write((char*)velIndexes.data(), sizeof(unsigned char) * velIndexes.size());
								fileValue.write((char*)preIndexes.data(), sizeof(unsigned char) * preIndexes.size());

								fileIndex.write((char*)&accumulatedSize, sizeof(accumulatedSize));
								accumulatedSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
									sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues +
									sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size();
							}

							chunkQuantizedPointsSum += chunkQuantizedPoints;
							++chunkCount;
							if (!isNotCompressible)
								++compressedChunkCount;
							if (chunkQuantizedPointsMax < chunkQuantizedPoints)
								chunkQuantizedPointsMax = chunkQuantizedPoints;
							double chunkErrorAvg = chunkErrorSum / sortList.size();
							if (chunkErrorMax < chunkErrorAvg)
								chunkErrorMax = chunkErrorAvg;
							allChunkErrorSum += chunkErrorAvg;
						}
					}
					else if (isSimilar) {
						int64_t pointToBaseFile = -1;
#pragma omp ordered
						fileIndex.write((char*)&pointToBaseFile, sizeof(int64_t));
					}
				}
				break;
				case CompressionMethod::SimilarEliminateKmeans:
				{
					uint64_t chunkQuantizedPoints = 0;
					double chunkErrorSum = 0;
					bool isSimilar = false;
					if (withMotionIndex && !isBaseFile) {
						isSimilar = true;
						for (int sp = 0; sp < GetChunkPointCount(); sp++) {
							float mag = Magnitude(basePointCacheList[sl][sf][sp].GetVel() - sortList[sp].first->GetVel());
							float pre = abs(basePointCacheList[sl][sf][sp].GetPressure() - sortList[sp].first->GetPressure());
							if (mag > magThreshold || pre > preThreshold) {
								isSimilar = false;
								break;
							}
						}
					}
					if (!isSimilar) {
						vector<glm::vec3> velValues;
						velValues.reserve(256);
						vector<float> preValues;
						preValues.reserve(256);
						vector<unsigned char> velIndexes;
						velIndexes.resize(sortList.size());
						vector<unsigned char> preIndexes;
						preIndexes.resize(sortList.size());

						if (sortList.size() < 256) {
							for (int sp = 0; sp < sortList.size(); sp++) {
								velValues.push_back(sortList[sp].first->GetVel());
								velIndexes[sp] = sp;

								preValues.push_back(sortList[sp].first->GetPressure());
								preIndexes[sp] = sp;
							}
						}
						else {
							pair<uint64_t, float > result2 = CompressToValueIndex<pair<CustomPointData*, uint64_t>, glm::vec3>(sortList, velValues, velIndexes,
								[](auto a, auto b) -> auto {return Magnitude(a - b); },
								[](auto x)-> auto {return x.first->GetVel(); }, magThreshold, indexes);
							chunkQuantizedPoints += result2.first;
							chunkErrorSum += result2.second;

							CompressToValueIndex<pair<CustomPointData*, uint64_t>, float>(sortList, preValues, preIndexes,
								[](auto a, auto b) -> auto {return abs(a - b); },
								[](auto x)-> auto {return x.first->GetPressure(); }, preThreshold, indexes);
						}

#pragma omp ordered
						{
							size_t sizeVelValues = velValues.size();
							totalVelCount += sizeVelValues;
							size_t sizePreValues = preValues.size();
							totalPreCount += sizePreValues;
							fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
							fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
							fileValue.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
							fileValue.write((char*)preValues.data(), sizeof(float) * sizePreValues);
							fileValue.write((char*)velIndexes.data(), sizeof(unsigned char) * velIndexes.size());
							fileValue.write((char*)preIndexes.data(), sizeof(unsigned char) * preIndexes.size());

							fileIndex.write((char*)&accumulatedSize, sizeof(accumulatedSize));
							accumulatedSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
								sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues +
								sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size();

							chunkQuantizedPointsSum += chunkQuantizedPoints;
							++chunkCount;
							if (chunkQuantizedPointsMax < chunkQuantizedPoints)
								chunkQuantizedPointsMax = chunkQuantizedPoints;
							double chunkErrorAvg = chunkErrorSum / sortList.size();
							if (chunkErrorMax < chunkErrorAvg)
								chunkErrorMax = chunkErrorAvg;
							allChunkErrorSum += chunkErrorAvg;
						}
					}
					else if (isSimilar) {
						int64_t pointToBaseFile = -1;
#pragma omp ordered
						fileIndex.write((char*)&pointToBaseFile, sizeof(int64_t));
					}
					break;
				}
				case CompressionMethod::SimilarEliminateMedianCut:
				{
					uint64_t chunkQuantizedPoints = 0;
					double chunkErrorSum = 0;
					bool isSimilar = false;
					if (withMotionIndex && !isBaseFile) {
						isSimilar = true;
						for (int sp = 0; sp < GetChunkPointCount(); sp++) {
							float mag = Magnitude(basePointCacheList[sl][sf][sp].GetVel() - sortList[sp].first->GetVel());
							float pre = abs(basePointCacheList[sl][sf][sp].GetPressure() - sortList[sp].first->GetPressure());
							if (mag > magThreshold || pre > preThreshold) {
								isSimilar = false;
								break;
							}
						}
					}
					if (!isSimilar) {
						vector<glm::vec3> velValues;
						vector<unsigned char> velIndexes;
						velIndexes.resize(sortList.size());
						vector<float> preValues;
						vector<unsigned char> preIndexes;
						preIndexes.resize(sortList.size());

						if (sortList.size() < 256) {
							for (int sp = 0; sp < sortList.size(); sp++) {
								velValues.push_back(sortList[sp].first->GetVel());
								velIndexes[sp] = sp;

								preValues.push_back(sortList[sp].first->GetPressure());
								preIndexes[sp] = sp;
							}
						}
						else {
							// I don't know how to make this to be a template function.....
							//velocity
							{
								vector<glm::vec3> target;
								target.resize(sortList.size());
								for (int i = 0; i < sortList.size(); ++i)
									target[i] = sortList[i].first->GetVel();

								vector<pair<int, int>> bucketIndeces;
								bucketIndeces.push_back({ 0, target.size() });
								for (int medianCutCount = 0; medianCutCount < 8; ++medianCutCount) {
									vector<pair<int, int>> nextBucketIndeces;
									nextBucketIndeces.resize(bucketIndeces.size() * 2);

#pragma omp parallel for
									for (int pindex = 0; pindex < bucketIndeces.size(); ++pindex) {
										auto pi = bucketIndeces[pindex];

										glm::vec3 minimum(numeric_limits<float>::max());
										glm::vec3 maximum(numeric_limits<float>::min());
										for (auto index = pi.first; index != pi.second; ++index) {
											FOR_3{
												if (minimum[i] > target[index][i])
													minimum[i] = target[index][i];
												if (maximum[i] < target[index][i])
													maximum[i] = target[index][i];
											}
										}

										int targetIndex = 0;
										for (int i = 1; i < 3; ++i)
											if (max[targetIndex] - minimum[targetIndex] < max[i] - min[i])
												targetIndex = i;

										// Dude, WTF is this
										if (targetIndex == 0)
											sort(target.begin() + pi.first, target.begin() + pi.second, [](const glm::vec3& a, const glm::vec3& b)-> bool {return a[0] < b[0]; });
										else if (targetIndex == 1)
											sort(target.begin() + pi.first, target.begin() + pi.second, [](const glm::vec3& a, const glm::vec3& b)-> bool {return a[1] < b[1]; });
										else
											sort(target.begin() + pi.first, target.begin() + pi.second, [](const glm::vec3& a, const glm::vec3& b)-> bool {return a[2] < b[2]; });

										int mid = (pi.first + pi.second) / 2;
										nextBucketIndeces[pindex * 2] = { pi.first, mid };
										nextBucketIndeces[pindex * 2 + 1] = { mid, pi.second };
									}
									bucketIndeces = nextBucketIndeces;
								}

								velValues.resize(256);
#pragma omp parallel for
								for (int i = 0; i < 256; ++i) {
									glm::vec3 velSum(0);
									for (int index = bucketIndeces[i].first; index < bucketIndeces[i].second; ++index)
										velSum += target[index];
									velValues[i] = velSum / glm::vec3(bucketIndeces[i].second - bucketIndeces[i].first);
								}

#pragma omp parallel for
								for (int sp = 0; sp < sortList.size(); sp++) {
									unsigned char qualifiedIndex = 0;
									float minMag = std::numeric_limits<float>().max();
									for (int i = 0; i < velValues.size(); i++) {
										float mag = Magnitude(velValues[i] - sortList[sp].first->GetVel());
										if (mag < minMag) {
											qualifiedIndex = i;
											minMag = mag;
										}
									}
									if (minMag > magThreshold)
										++chunkQuantizedPoints;
									velIndexes[sp] = qualifiedIndex;
									chunkErrorSum += minMag;
								}
							}
							//pressure
							{
								vector<float> target;
								target.resize(sortList.size());
								for (int i = 0; i < sortList.size(); ++i)
									target[i] = sortList[i].first->GetPressure();

								sort(target.begin(), target.end());

								preValues.resize(256);
								double step = target.size() / 256;
#pragma omp parallel for
								for (int i = 0; i < 256; ++i) {
									float preSum(0);
									int base = (int)(i * step);
									int num = (int)((i + 1) * step) - base;
									for (int index = base; index < base + num; ++index)
										preSum += target[index];
									preValues[i] = preSum / num;
								}

#pragma omp parallel for
								for (int sp = 0; sp < sortList.size(); sp++) {
									unsigned char qualifiedIndex = 0;
									float minMag = std::numeric_limits<float>().max();
									for (int i = 0; i < preValues.size(); i++) {
										float mag = abs(preValues[i] - sortList[sp].first->GetPressure());
										if (mag < minMag) {
											qualifiedIndex = i;
											minMag = mag;
										}
									}
									preIndexes[sp] = qualifiedIndex;
								}
							}
						}

#pragma omp ordered
						{
							size_t sizeVelValues = velValues.size();
							totalVelCount += sizeVelValues;
							size_t sizePreValues = preValues.size();
							totalPreCount += sizePreValues;
							fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
							fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
							fileValue.write((char*)velValues.data(), sizeof(glm::vec3)* sizeVelValues);
							fileValue.write((char*)preValues.data(), sizeof(float)* sizePreValues);
							fileValue.write((char*)velIndexes.data(), sizeof(unsigned char)* velIndexes.size());
							fileValue.write((char*)preIndexes.data(), sizeof(unsigned char)* preIndexes.size());

							if (velIndexes.size() != GetChunkPointCount())
								//cout << "velIndexes size is wrong." << endl;
							if (preIndexes.size() != GetChunkPointCount())
								//cout << "preIndexes size is wrong." << endl;

							fileIndex.write((char*)&accumulatedSize, sizeof(accumulatedSize));
							accumulatedSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
								sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues +
								sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size();

							chunkQuantizedPointsSum += chunkQuantizedPoints;
							++chunkCount;
							++compressedChunkCount;
							if (chunkQuantizedPointsMax < chunkQuantizedPoints)
								chunkQuantizedPointsMax = chunkQuantizedPoints;
							double chunkErrorAvg = chunkErrorSum / sortList.size();
							if (chunkErrorMax < chunkErrorAvg)
								chunkErrorMax = chunkErrorAvg;
							allChunkErrorSum += chunkErrorAvg;
						}
					}
					else if (isSimilar) {
						int64_t pointToBaseFile = -1;
#pragma omp ordered
						fileIndex.write((char*)&pointToBaseFile, sizeof(int64_t));
					}
					break;
				}
				case CompressionMethod::ZFP:
				{
					for (int i = 0; i < 4; i++) {
						value_list.clear();
						for (int j = 0; j < sortList.size(); j++) {
							if (i == 0)
								value_list.push_back(sortList[j].first->GetXVel());
							else if (i == 1)
								value_list.push_back(sortList[j].first->GetYVel());
							else if (i == 2)
								value_list.push_back(sortList[j].first->GetZVel());
							else if (i == 3)
								value_list.push_back(sortList[j].first->GetPressure());
						}

						// Initialize ZFP compression parameter
						zfp_type type = zfp_type_float;                          // array scalar type
						zfp_field* field = zfp_field_3d(value_list.data(), type, chunkSize[0] + 1, chunkSize[1] + 1, chunkSize[2] + 1); // array metadata
						zfp_stream* zfp = zfp_stream_open(NULL);                  // compressed stream and parameters
						zfp_stream_set_accuracy(zfp, 1e-1);                  // set tolerance for fixed-accuracy mode

						// Compress data
						size_t bufsize = zfp_stream_maximum_size(zfp, field);     // capacity of compressed buffer (conservative)
						void* buffer = ::operator new(bufsize);                           // storage for compressed stream
						bitstream* stream = stream_open(buffer, bufsize);         // bit stream to compress to
						zfp_stream_set_bit_stream(zfp, stream);                   // associate with compressed stream
						//zfp_stream_rewind(zfp);                                   // rewind stream to beginning
						size_t zfpsize = zfp_compress(zfp, field);                // return value is byte size of compressed stream

#pragma omp ordered
						{
							fileValue.write((char*)buffer, zfpsize);
							fileIndex.write((char*)&accumulatedSize, sizeof(int));
							fileIndex.write((char*)&zfpsize, sizeof(int));
							accumulatedSize += zfpsize;
						}
						// Cleanup
						zfp_field_free(field);
						zfp_stream_close(zfp);
						stream_close(stream);
						delete(buffer);
					}
					break;
				}
				case CompressionMethod::JPEG:
				{
					/*uint64_t chunkQuantizedPoints = 0;
					double chunkErrorSum = 0;
					bool isSimilar = false;
					if (withMotionIndex && !isBaseFile) {
						isSimilar = true;
						for (int sp = 0; sp < GetChunkPointCount(); sp++) {
							float mag = Magnitude(basePointCacheList[sl][sf][sp].GetVel() - sortList[sp].first->GetVel());
							float pre = abs(basePointCacheList[sl][sf][sp].GetPressure() - sortList[sp].first->GetPressure());
							if (mag > magThreshold || pre > preThreshold) {
								isSimilar = false;
								break;
							}
						}
					}
					if (!isSimilar) {
						//cv::Vec3f minVel, maxVel;
						glm::vec3 minVel, maxVel;
						float minPre, maxPre;

						for (int dir = 0; dir < 3; dir++) {
							minVel[dir] = std::numeric_limits<float>().max();
							maxVel[dir] = std::numeric_limits<float>().min();
							for (int sp = 0; sp < sortList.size(); sp++) {
								float vel = sortList[sp].first->GetVel()[dir];
								if (vel < minVel[dir])
									minVel[dir] = vel;
								if (vel > maxVel[dir])
									maxVel[dir] = vel;
							}
						}
						minPre = std::numeric_limits<float>().max();
						maxPre = std::numeric_limits<float>().min();
						for (int sp = 0; sp < sortList.size(); sp++) {
							float pre = sortList[sp].first->GetPressure();
							if (pre < minPre)
								minPre = pre;
							if (pre > maxPre)
								maxPre = pre;
						}

						int width = std::max(chunkSize[0], std::max(chunkSize[1], chunkSize[2])) + 1;
						int height = GetChunkPointCount() / width;

						std::vector<int> encodeParams;
						//IMWRITE_JPEG_QUALITY For JPEG, it can be a quality from 0 to 100 (the higher is the better). Default value is 95 
						encodeParams.push_back(cv::IMWRITE_JPEG_QUALITY);
						encodeParams.push_back(95);

						vector<unsigned char> encodedImgVel;
						cv::Mat originalImgVel = cv::Mat(width, height, CV_8UC3);
						for (int dir = 0; dir < 3; dir++) {
							float spacing = (maxVel[dir] - minVel[dir]) / 255;
							for (int w = 0; w < width; w++) {
								for (int h = 0; h < height; h++) {
									unsigned char pixelVal = round(sortList[w * height + h].first->GetVel()[dir] - minVel[dir] / spacing);
									originalImgVel.at<cv::Vec3b>(w, h)[dir] = pixelVal;
								}
							}
						}
						cv::imencode(".jpg", originalImgVel, encodedImgVel, encodeParams);

						vector<unsigned char> encodedImgPre;
						cv::Mat originalImgPre = cv::Mat(width, height, CV_8UC3);
						float spacing = (maxPre - minPre) / 255;
						for (int dir = 0; dir < 3; dir++) {
							for (int w = 0; w < width; w++) {
								for (int h = 0; h < height; h++) {
									if (dir == 0) {
										unsigned char pixelVal = round(sortList[w * height + h].first->GetPressure() - minPre / spacing);
										originalImgPre.at<cv::Vec3b>(w, h)[dir] = pixelVal;
									}
									else {
										originalImgPre.at<cv::Vec3b>(w, h)[dir] = 0;
									}
								}
							}
						}
						cv::imencode(".jpg", originalImgPre, encodedImgPre, encodeParams);

#pragma omp ordered
						{
							int sizeVelValues = encodedImgVel.size();
							totalVelCount += sizeVelValues;
							int sizePreValues = encodedImgPre.size();
							totalPreCount += sizePreValues;
							fileValue.write((char*)&sizeVelValues, sizeof(sizeVelValues));
							fileValue.write((char*)&sizePreValues, sizeof(sizePreValues));
							fileValue.write((char*)&minVel, sizeof(cv::Vec3f));
							fileValue.write((char*)&maxVel, sizeof(cv::Vec3f));
							fileValue.write((char*)&minPre, sizeof(float));
							fileValue.write((char*)&maxPre, sizeof(float));
							fileValue.write((char*)encodedImgVel.data(), sizeof(unsigned char) * encodedImgVel.size());
							fileValue.write((char*)encodedImgPre.data(), sizeof(unsigned char) * encodedImgPre.size());

							fileIndex.write((char*)&accumulatedSize, sizeof(int));
							accumulatedSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
								sizeof(cv::Vec3f) * 2 + sizeof(float) * 2 +
								sizeof(unsigned char) * encodedImgVel.size() + sizeof(unsigned char) * encodedImgPre.size();
						}
					}
					else if (isSimilar) {
						int64_t pointToBaseFile = -1;
#pragma omp ordered
						fileIndex.write((char*)&pointToBaseFile, sizeof(int64_t));
					}
					break;*/
				}
				}

				// laplacian output
				if (withLaplacianPyramid && sl > 0) {
					int levelChunkCount = (int)pow(2, sl);
					int pLevelChunkCount = (int)pow(2, sl - 1);
					glm::ivec3 chunkIndex(sf % levelChunkCount, sf / levelChunkCount % levelChunkCount, sf / levelChunkCount / levelChunkCount % levelChunkCount);
					glm::ivec3 parentChunkIndex = chunkIndex / 2;
					int pSf = parentChunkIndex.x + parentChunkIndex.y * pLevelChunkCount + parentChunkIndex.z * pLevelChunkCount * pLevelChunkCount;

					glm::ivec3 pOffset(
						chunkIndex.x % 2 ? chunkSize.x / 2 : 0,
						chunkIndex.y % 2 ? chunkSize.y / 2 : 0,
						chunkIndex.z % 2 ? chunkSize.z / 2 : 0);

					vector<CustomPointData> diff;
					diff.resize(sortList.size());

#pragma omp parallel for
					for (int k = 0; k < chunkSize[2]; ++k) {
						for (int j = 0; j < chunkSize[1]; ++j) {
							for (int i = 0; i < chunkSize[0]; ++i) {
								CustomPointData ref = CustomPointData();
								// get parent reference point
								{
									glm::ivec3 baseIndex(i / 2, j / 2, k / 2);

									unsigned char pC = 0;
									for (unsigned char subk = 0; subk <= k % 2; ++subk)
										for (unsigned char subj = 0; subj <= j % 2; ++subj)
											for (unsigned char subi = 0; subi <= i % 2; ++subi) {
												glm::ivec3 pIndex = pOffset + baseIndex + glm::ivec3(subi, subj, subk);
												ref = ref + *(pointCache[sl - 1][pSf][pIndex.x + pIndex.y * (chunkSize.x + 1) + pIndex.z * (chunkSize.x + 1) * (chunkSize.y + 1)].first);
												++pC;
											}
									ref = ref / pC;
								}

								// store the difference
								int index = i + j * (chunkSize.x + 1) + k * (chunkSize.x + 1) * (chunkSize.y + 1);
								diff[index] = *(sortList[index].first) - ref;
							}
						}
					}

					switch (compressionMethod) {
					case CompressionMethod::NoCompression:
					{
						vector<glm::vec3> velValues;
						vector<float> preValues;

						for (int sp = 0; sp < diff.size(); sp++) {
							velValues.push_back(diff[sp].GetVel());
							preValues.push_back(diff[sp].GetPressure());
						}

						size_t sizeVelValues = velValues.size();
						totalVelCount += sizeVelValues;
						size_t sizePreValues = preValues.size();
						totalPreCount += sizePreValues;
						fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
						fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
						fileLaplacian.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
						fileLaplacian.write((char*)preValues.data(), sizeof(float) * sizePreValues);

						fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(accumulatedLaplacianSize));
						accumulatedLaplacianSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
							sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues;
						break;
					}
					case CompressionMethod::SimilarEliminateOriginal:
					{
						uint64_t chunkQuantizedPoints = 0;
						double chunkErrorSum = 0;
						bool isSimilar = false;
						if (!isSimilar) {
							vector<glm::vec3> velValues;
							vector<float> preValues;
							vector<unsigned char> velIndexes;
							velIndexes.resize(diff.size());
							vector<unsigned char> preIndexes;
							preIndexes.resize(diff.size());

							pair<uint64_t, float > result2 = CompressToValueIndex<CustomPointData, glm::vec3>(diff, velValues, velIndexes,
								[](auto a, auto b) -> auto {return Magnitude(a - b); },
								[](auto x)-> auto {return x.GetVel(); }, magThreshold, indexes);
							chunkQuantizedPoints += result2.first;
							chunkErrorSum += result2.second;

							CompressToValueIndex<CustomPointData, float>(diff, preValues, preIndexes,
								[](auto a, auto b) -> auto {return abs(a - b); },
								[](auto x)-> auto {return x.GetPressure(); }, preThreshold, indexes);

#pragma omp ordered
							{
								size_t sizeVelValues = velValues.size();
								totalVelCount += sizeVelValues;
								size_t sizePreValues = preValues.size();
								totalPreCount += sizePreValues;
								fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
								fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
								fileLaplacian.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
								fileLaplacian.write((char*)preValues.data(), sizeof(float) * sizePreValues);
								fileLaplacian.write((char*)velIndexes.data(), sizeof(unsigned char) * velIndexes.size());
								fileLaplacian.write((char*)preIndexes.data(), sizeof(unsigned char) * preIndexes.size());

								fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(accumulatedLaplacianSize));
								accumulatedLaplacianSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
									sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues +
									sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size();

								++compressedChunkCount;
								chunkQuantizedPointsSum += chunkQuantizedPoints;
								++chunkCount;
								if (chunkQuantizedPointsMax < chunkQuantizedPoints)
									chunkQuantizedPointsMax = chunkQuantizedPoints;
								double chunkErrorAvg = chunkErrorSum / diff.size();
								if (chunkErrorMax < chunkErrorAvg)
									chunkErrorMax = chunkErrorAvg;
								allChunkErrorSum += chunkErrorAvg;
							}
						}
						break;
					}
					case CompressionMethod::SimilarEliminateAdaptive:
					{
						uint64_t chunkQuantizedPoints = 0;
						double chunkErrorSum = 0;
						bool isSimilar = false;
						if (!isSimilar) {
							vector<glm::vec3> velValues;
							vector<float> preValues;
							vector<unsigned char> velIndexes;
							velIndexes.resize(diff.size());
							vector<unsigned char> preIndexes;
							preIndexes.resize(diff.size());

							bool isNotCompressible = false;


							pair<uint64_t, float > result2 = CompressToValueIndex<CustomPointData, glm::vec3>(diff, velValues, velIndexes,
								[](auto a, auto b) -> auto {return Magnitude(a - b); },
								[](auto x)-> auto {return x.GetVel(); }, magThreshold, indexes);
							if (result2.second >= 0) {
								chunkQuantizedPoints += result2.first;
								chunkErrorSum += result2.second;
							}
							else {
								isNotCompressible = true;
							}

							result2 = CompressToValueIndex<CustomPointData, float>(diff, preValues, preIndexes,
								[](auto a, auto b) -> auto {return abs(a - b); },
								[](auto x)-> auto {return x.GetPressure(); }, preThreshold, indexes);
							if (result2.second < 0)
								isNotCompressible = true;

							if (isNotCompressible) {
								velValues.resize(diff.size());
								preValues.resize(diff.size());
								for (int sp = 0; sp < diff.size(); sp++) {
									velValues[sp] = diff[sp].GetVel();
									preValues[sp] = diff[sp].GetPressure();
								}
							}


#pragma omp ordered
							{
								if (isNotCompressible) {
									size_t sizeVelValues = 0;
									size_t sizePreValues = 0;
									fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
									fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
									sizeVelValues = velValues.size();
									sizePreValues = preValues.size();
									fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
									fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
									fileLaplacian.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
									fileLaplacian.write((char*)preValues.data(), sizeof(float) * sizePreValues);

									fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(accumulatedLaplacianSize));
									accumulatedLaplacianSize += sizeof(sizeVelValues) * 2 + sizeof(sizePreValues) * 2 +
										sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues;
								}
								else {

									// original
									size_t sizeVelValues = velValues.size();
									totalVelCount += sizeVelValues;
									size_t sizePreValues = preValues.size();
									totalPreCount += sizePreValues;
									fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
									fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
									fileLaplacian.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
									fileLaplacian.write((char*)preValues.data(), sizeof(float) * sizePreValues);
									fileLaplacian.write((char*)velIndexes.data(), sizeof(unsigned char) * velIndexes.size());
									fileLaplacian.write((char*)preIndexes.data(), sizeof(unsigned char) * preIndexes.size());

									fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(accumulatedLaplacianSize));
									accumulatedLaplacianSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
										sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues +
										sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size();
								}

								chunkQuantizedPointsSum += chunkQuantizedPoints;
								++chunkCount;
								if (!isNotCompressible)
									++compressedChunkCount;
								if (chunkQuantizedPointsMax < chunkQuantizedPoints)
									chunkQuantizedPointsMax = chunkQuantizedPoints;
								double chunkErrorAvg = chunkErrorSum / diff.size();
								if (chunkErrorMax < chunkErrorAvg)
									chunkErrorMax = chunkErrorAvg;
								allChunkErrorSum += chunkErrorAvg;
							}
						}
					}
					break;
					case CompressionMethod::SimilarEliminateKmeans:
					{
						uint64_t chunkQuantizedPoints = 0;
						double chunkErrorSum = 0;
						bool isSimilar = false;
						if (!isSimilar) {
							vector<glm::vec3> velValues;
							velValues.reserve(256);
							vector<float> preValues;
							preValues.reserve(256);
							vector<unsigned char> velIndexes;
							velIndexes.resize(diff.size());
							vector<unsigned char> preIndexes;
							preIndexes.resize(diff.size());

							if (diff.size() < 256) {
								for (int sp = 0; sp < diff.size(); sp++) {
									velValues.push_back(diff[sp].GetVel());
									velIndexes[sp] = sp;

									preValues.push_back(diff[sp].GetPressure());
									preIndexes[sp] = sp;
								}
							}
							else {
								pair<uint64_t, float > result2 = CompressToValueIndex<CustomPointData, glm::vec3>(diff, velValues, velIndexes,
									[](auto a, auto b) -> auto {return Magnitude(a - b); },
									[](auto x)-> auto {return x.GetVel(); }, magThreshold, indexes);
								chunkQuantizedPoints += result2.first;
								chunkErrorSum += result2.second;

								CompressToValueIndex<CustomPointData, float>(diff, preValues, preIndexes,
									[](auto a, auto b) -> auto {return abs(a - b); },
									[](auto x)-> auto {return x.GetPressure(); }, preThreshold, indexes);
							}

#pragma omp ordered
							{
								size_t sizeVelValues = velValues.size();
								totalVelCount += sizeVelValues;
								size_t sizePreValues = preValues.size();
								totalPreCount += sizePreValues;
								fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
								fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
								fileLaplacian.write((char*)velValues.data(), sizeof(glm::vec3) * sizeVelValues);
								fileLaplacian.write((char*)preValues.data(), sizeof(float) * sizePreValues);
								fileLaplacian.write((char*)velIndexes.data(), sizeof(unsigned char) * velIndexes.size());
								fileLaplacian.write((char*)preIndexes.data(), sizeof(unsigned char) * preIndexes.size());

								fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(accumulatedLaplacianSize));
								accumulatedLaplacianSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
									sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues +
									sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size();

								chunkQuantizedPointsSum += chunkQuantizedPoints;
								++chunkCount;
								if (chunkQuantizedPointsMax < chunkQuantizedPoints)
									chunkQuantizedPointsMax = chunkQuantizedPoints;
								double chunkErrorAvg = chunkErrorSum / diff.size();
								if (chunkErrorMax < chunkErrorAvg)
									chunkErrorMax = chunkErrorAvg;
								allChunkErrorSum += chunkErrorAvg;
							}
						}
						break;
					}
					case CompressionMethod::SimilarEliminateMedianCut:
					{
						uint64_t chunkQuantizedPoints = 0;
						double chunkErrorSum = 0;
						bool isSimilar = false;
						if (!isSimilar) {
							vector<glm::vec3> velValues;
							vector<unsigned char> velIndexes;
							velIndexes.resize(diff.size());
							vector<float> preValues;
							vector<unsigned char> preIndexes;
							preIndexes.resize(diff.size());

							if (diff.size() < 256) {
								for (int sp = 0; sp < diff.size(); sp++) {
									velValues.push_back(diff[sp].GetVel());
									velIndexes[sp] = sp;

									preValues.push_back(diff[sp].GetPressure());
									preIndexes[sp] = sp;
								}
							}
							else {
								// I don't know how to make this be a template function.....
								//velocity
								{
									vector<glm::vec3> target;
									target.resize(diff.size());
									for (int i = 0; i < diff.size(); ++i)
										target[i] = diff[i].GetVel();

									vector<pair<int, int>> bucketIndeces;
									bucketIndeces.push_back({ 0, target.size() });
									for (int medianCutCount = 0; medianCutCount < 8; ++medianCutCount) {
										vector<pair<int, int>> nextBucketIndeces;
										nextBucketIndeces.resize(bucketIndeces.size() * 2);

#pragma omp parallel for
										for (int pindex = 0; pindex < bucketIndeces.size(); ++pindex) {
											auto pi = bucketIndeces[pindex];

											glm::vec3 minimum(numeric_limits<float>::max());
											glm::vec3 maximum(numeric_limits<float>::min());
											for (auto index = pi.first; index != pi.second; ++index) {
												FOR_3{
													if (minimum[i] > target[index][i])
														minimum[i] = target[index][i];
													if (maximum[i] < target[index][i])
														maximum[i] = target[index][i];
												}
											}

											int targetIndex = 0;
											for (int i = 1; i < 3; ++i)
												if (maximum[targetIndex] - minimum[targetIndex] < maximum[i] - minimum[i])
													targetIndex = i;

											// Dude, WTF is this
											if (targetIndex == 0)
												sort(target.begin() + pi.first, target.begin() + pi.second, [](const glm::vec3& a, const glm::vec3& b)-> bool {return a[0] < b[0]; });
											else if (targetIndex == 1)
												sort(target.begin() + pi.first, target.begin() + pi.second, [](const glm::vec3& a, const glm::vec3& b)-> bool {return a[1] < b[1]; });
											else
												sort(target.begin() + pi.first, target.begin() + pi.second, [](const glm::vec3& a, const glm::vec3& b)-> bool {return a[2] < b[2]; });

											int mid = (pi.first + pi.second) / 2;
											nextBucketIndeces[pindex * 2] = { pi.first, mid };
											nextBucketIndeces[pindex * 2 + 1] = { mid, pi.second };
										}
										bucketIndeces = nextBucketIndeces;
									}

									velValues.resize(256);
#pragma omp parallel for
									for (int i = 0; i < 256; ++i) {
										glm::vec3 velSum(0);
										for (int index = bucketIndeces[i].first; index < bucketIndeces[i].second; ++index)
											velSum += target[index];
										velValues[i] = velSum / glm::vec3(bucketIndeces[i].second - bucketIndeces[i].first);
									}

#pragma omp parallel for
									for (int sp = 0; sp < diff.size(); sp++) {
										unsigned char qualifiedIndex = 0;
										float minMag = std::numeric_limits<float>().max();
										for (int i = 0; i < velValues.size(); i++) {
											float mag = Magnitude(velValues[i] - diff[sp].GetVel());
											if (mag < minMag) {
												qualifiedIndex = i;
												minMag = mag;
											}
										}
										if (minMag > magThreshold)
											++chunkQuantizedPoints;
										velIndexes[sp] = qualifiedIndex;
										chunkErrorSum += minMag;
									}
								}
								//pressure
								{
									vector<float> target;
									target.resize(diff.size());
									for (int i = 0; i < diff.size(); ++i)
										target[i] = diff[i].GetPressure();

									sort(target.begin(), target.end());

									preValues.resize(256);
									double step = target.size() / 256;
#pragma omp parallel for
									for (int i = 0; i < 256; ++i) {
										float preSum(0);
										int base = (int)(i * step);
										int num = (int)((i + 1) * step) - base;
										for (int index = base; index < base + num; ++index)
											preSum += target[index];
										preValues[i] = preSum / num;
									}

#pragma omp parallel for
									for (int sp = 0; sp < diff.size(); sp++) {
										unsigned char qualifiedIndex = 0;
										float minMag = std::numeric_limits<float>().max();
										for (int i = 0; i < preValues.size(); i++) {
											float mag = abs(preValues[i] - diff[sp].GetPressure());
											if (mag < minMag) {
												qualifiedIndex = i;
												minMag = mag;
											}
										}
										preIndexes[sp] = qualifiedIndex;
									}
								}
							}

#pragma omp ordered
							{
								size_t sizeVelValues = velValues.size();
								totalVelCount += sizeVelValues;
								size_t sizePreValues = preValues.size();
								totalPreCount += sizePreValues;
								fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
								fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
								fileLaplacian.write((char*)velValues.data(), sizeof(glm::vec3)* sizeVelValues);
								fileLaplacian.write((char*)preValues.data(), sizeof(float)* sizePreValues);
								fileLaplacian.write((char*)velIndexes.data(), sizeof(unsigned char)* velIndexes.size());
								fileLaplacian.write((char*)preIndexes.data(), sizeof(unsigned char)* preIndexes.size());

								if (velIndexes.size() != GetChunkPointCount())
									//cout << "velIndexes size is wrong." << endl;
								if (preIndexes.size() != GetChunkPointCount())
									//cout << "preIndexes size is wrong." << endl;

								fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(accumulatedLaplacianSize));
								accumulatedLaplacianSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
									sizeof(glm::vec3) * sizeVelValues + sizeof(float) * sizePreValues +
									sizeof(unsigned char) * velIndexes.size() + sizeof(unsigned char) * preIndexes.size();

								chunkQuantizedPointsSum += chunkQuantizedPoints;
								++chunkCount;
								++compressedChunkCount;
								if (chunkQuantizedPointsMax < chunkQuantizedPoints)
									chunkQuantizedPointsMax = chunkQuantizedPoints;
								double chunkErrorAvg = chunkErrorSum / diff.size();
								if (chunkErrorMax < chunkErrorAvg)
									chunkErrorMax = chunkErrorAvg;
								allChunkErrorSum += chunkErrorAvg;
							}
						}
						break;
					}
					case CompressionMethod::ZFP:
					{
//						for (int i = 0; i < 4; i++) {
//							value_list.clear();
//							for (int j = 0; j < diff.size(); j++) {
//								if (i == 0)
//									value_list.push_back(diff[j].GetXVel());
//								else if (i == 1)
//									value_list.push_back(diff[j].GetYVel());
//								else if (i == 2)
//									value_list.push_back(diff[j].GetZVel());
//								else if (i == 3)
//									value_list.push_back(diff[j].GetPressure());
//							}
//
//							// Initialize ZFP compression parameter
//							zfp_type type = zfp_type_float;                          // array scalar type
//							zfp_field* field = zfp_field_3d(value_list.data(), type, chunkSize[0] + 1, chunkSize[1] + 1, chunkSize[2] + 1); // array metadata
//							zfp_stream* zfp = zfp_stream_open(NULL);                  // compressed stream and parameters
//							zfp_stream_set_accuracy(zfp, 1e-1);                  // set tolerance for fixed-accuracy mode
//
//							// Compress data
//							size_t bufsize = zfp_stream_maximum_size(zfp, field);     // capacity of compressed buffer (conservative)
//							void* buffer = ::operator new(bufsize);                           // storage for compressed stream
//							bitstream* stream = stream_open(buffer, bufsize);         // bit stream to compress to
//							zfp_stream_set_bit_stream(zfp, stream);                   // associate with compressed stream
//							//zfp_stream_rewind(zfp);                                   // rewind stream to beginning
//							size_t zfpsize = zfp_compress(zfp, field);                // return value is byte size of compressed stream
//
//#pragma omp ordered
//							{
//								fileLaplacian.write((char*)buffer, zfpsize);
//								fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(int));
//								fileLaplacianIndex.write((char*)&zfpsize, sizeof(int));
//								accumulatedLaplacianSize += zfpsize;
//							}
//							// Cleanup
//							zfp_field_free(field);
//							zfp_stream_close(zfp);
//							stream_close(stream);
//							delete(buffer);
//						}
						break;
					}
					case CompressionMethod::JPEG:
					{
						/*uint64_t chunkQuantizedPoints = 0;
						double chunkErrorSum = 0;
						bool isSimilar = false;
						if (!isSimilar) {
							//cv::Vec3f minVel, maxVel;
							glm::vec3 minVel, maxVel;
							float minPre, maxPre;

							for (int dir = 0; dir < 3; dir++) {
								minVel[dir] = std::numeric_limits<float>().max();
								maxVel[dir] = std::numeric_limits<float>().min();
								for (int sp = 0; sp < diff.size(); sp++) {
									float vel = diff[sp].GetVel()[dir];
									if (vel < minVel[dir])
										minVel[dir] = vel;
									if (vel > maxVel[dir])
										maxVel[dir] = vel;
								}
							}
							minPre = std::numeric_limits<float>().max();
							maxPre = std::numeric_limits<float>().min();
							for (int sp = 0; sp < diff.size(); sp++) {
								float pre = diff[sp].GetPressure();
								if (pre < minPre)
									minPre = pre;
								if (pre > maxPre)
									maxPre = pre;
							}

							int width = std::max(chunkSize[0], std::max(chunkSize[1], chunkSize[2])) + 1;
							int height = GetChunkPointCount() / width;

							std::vector<int> encodeParams;
							//IMWRITE_JPEG_QUALITY For JPEG, it can be a quality from 0 to 100 (the higher is the better). Default value is 95
							encodeParams.push_back(cv::IMWRITE_JPEG_QUALITY);
							encodeParams.push_back(95);

							vector<unsigned char> encodedImgVel;
							cv::Mat originalImgVel = cv::Mat(width, height, CV_8UC3);
							for (int dir = 0; dir < 3; dir++) {
								float spacing = (maxVel[dir] - minVel[dir]) / 255;
								for (int w = 0; w < width; w++) {
									for (int h = 0; h < height; h++) {
										unsigned char pixelVal = round(diff[w * height + h].GetVel()[dir] - minVel[dir] / spacing);
										originalImgVel.at<cv::Vec3b>(w, h)[dir] = pixelVal;
									}
								}
							}
							cv::imencode(".jpg", originalImgVel, encodedImgVel, encodeParams);

							vector<unsigned char> encodedImgPre;
							cv::Mat originalImgPre = cv::Mat(width, height, CV_8UC3);
							float spacing = (maxPre - minPre) / 255;
							for (int dir = 0; dir < 3; dir++) {
								for (int w = 0; w < width; w++) {
									for (int h = 0; h < height; h++) {
										if (dir == 0) {
											unsigned char pixelVal = round(diff[w * height + h].GetPressure() - minPre / spacing);
											originalImgPre.at<cv::Vec3b>(w, h)[dir] = pixelVal;
										}
										else {
											originalImgPre.at<cv::Vec3b>(w, h)[dir] = 0;
										}
									}
								}
							}
							cv::imencode(".jpg", originalImgPre, encodedImgPre, encodeParams);

#pragma omp ordered
							{
								int sizeVelValues = encodedImgVel.size();
								totalVelCount += sizeVelValues;
								int sizePreValues = encodedImgPre.size();
								totalPreCount += sizePreValues;
								fileLaplacian.write((char*)&sizeVelValues, sizeof(sizeVelValues));
								fileLaplacian.write((char*)&sizePreValues, sizeof(sizePreValues));
								fileLaplacian.write((char*)&minVel, sizeof(cv::Vec3f));
								fileLaplacian.write((char*)&maxVel, sizeof(cv::Vec3f));
								fileLaplacian.write((char*)&minPre, sizeof(float));
								fileLaplacian.write((char*)&maxPre, sizeof(float));
								fileLaplacian.write((char*)encodedImgVel.data(), sizeof(unsigned char) * encodedImgVel.size());
								fileLaplacian.write((char*)encodedImgPre.data(), sizeof(unsigned char) * encodedImgPre.size());

								fileLaplacianIndex.write((char*)&accumulatedLaplacianSize, sizeof(int));
								accumulatedLaplacianSize += sizeof(sizeVelValues) + sizeof(sizePreValues) +
									sizeof(cv::Vec3f) * 2 + sizeof(float) * 2 +
									sizeof(unsigned char) * encodedImgVel.size() + sizeof(unsigned char) * encodedImgPre.size();
							}
						}
						break;*/
					}
					}
				}
			}
			errorLog << "Level: " << sl << endl;
			errorLog << "Total chunk Count: " << chunkCount << endl;
			errorLog << "Total Vel Count: " << totalVelCount << endl;
			errorLog << "Total Pre Count: " << totalPreCount << endl;
			errorLog << "Compressed Chunk Count: " << compressedChunkCount << endl;
			errorLog << "No Compressed Chunk Count: " << chunkCount - compressedChunkCount << endl;
			errorLog << "Average bad quantized points count: " << chunkQuantizedPointsSum / (double)compressedChunkCount << endl;
			errorLog << "Max bad quantized points points count: " << chunkQuantizedPointsMax << endl;
			errorLog << "Average chunk error: " << allChunkErrorSum / compressedChunkCount << endl;
			errorLog << "Max chunk error: " << chunkErrorMax << endl;
			fileValue.close();
			fileIndex.close();

			//timer.stop();
			//std::cout << "Output Level " << sl << " Chunks costs " << timer.elapsed() << " seconds." << std::endl;
		}
		errorLog.close();
	}
	else {
		//std::cout << "Calculating Sources..." << std::endl;
		percent = 0;
		progress = 0;
		//timer.start();
		vector<LagrangianVelSource> velSources;
		vector<LagrangianPreSource> preSources;
		vector<bool> pointProcessedVel, pointProcessedPre;
		pointProcessedVel.resize(sampledDim[0] * sampledDim[1] * sampledDim[2]);
		pointProcessedPre.resize(sampledDim[0] * sampledDim[1] * sampledDim[2]);
		for (int i = 0; i < pointProcessedVel.size(); i++) {
			pointProcessedVel[i] = pointProcessedPre[i] = false;
		}

		//unibn::Octree<CustomPoint> _OctreeSearchResampled;

		vector<float> orderedCoords[3];
		FOR_3{
			orderedCoords[i].reserve(sampledDim[i]);
			for (int j = 0; j < sampledDim[i]; ++j) {
				orderedCoords[i].push_back(sampledPoints[0].GetXYZ()[i] + sampledSpacing[i] * j);
			}
		}

		vector<tuple<uint64_t, bool, float>> result2;
		result2.reserve(27);

		CustomPoint nowPoint;

		float magThreshold2 = 1.0f;

		vector<int> indexes;
		indexes.resize(pointProcessedVel.size());

		for (int i = 0; i < indexes.size(); i++) {
			indexes[i] = i;
		}

		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(indexes.begin(), indexes.end(), g);

		for (int i = 0; i < indexes.size(); i++) {
			if (pointProcessedVel[indexes[i]] == false) {
				bool notSimilared = false;
				nowPoint = sampledPoints[indexes[i]];
				glm::ivec3 start(-1);
				result2.clear();

				//FOR_3
				for (int j = 0; j < 3; j++) {
					vector<float>::iterator it = lower_bound(orderedCoords[i].begin(), orderedCoords[i].end(), nowPoint.GetXYZ()[i]);
					start[i] = it - orderedCoords[i].begin();
				}
				int nowSearchL1Distance = 1;
				float nearestBadDistance = 1e30f;
				while (1) {
#pragma omp parallel for
					for (int subz = -nowSearchL1Distance; subz <= nowSearchL1Distance; ++subz) {
						int nowz = start.z + subz;
						int residualY = nowSearchL1Distance - abs(subz);
						if (residualY < 0 || nowz < 0 || nowz >= orderedCoords[2].size())
							continue;
						for (int suby = -residualY; suby <= residualY; suby++) {
							int nowy = start.y + suby;
							int residualX = residualY - abs(suby);
							if (residualX < 0 || nowy < 0 || nowy >= orderedCoords[1].size())
								continue;

							int subx = -residualX;
							do {
								int nowx = start.x + subx;
								subx += residualX * 2;
								if (nowx < 0 || nowx >= orderedCoords[0].size())
									continue;
								uint64_t index = nowx + sampledDim[0] * (nowy + sampledDim[1] * nowz);
								CustomPoint* point = &sampledPoints[index];
								float d = glm::distance(nowPoint.GetXYZ(), point->GetXYZ());
#pragma omp critical
								{
									result2.push_back(tuple<uint64_t, bool, float>(index, /*!pointProcessedVel[index] && */Magnitude(point->GetVel() - nowPoint.GetVel()) <= magThreshold2, d));
									if (!get<1>(result2.back())) {
										if (nearestBadDistance > d)
											nearestBadDistance = d;
										notSimilared = true;
									}
								}
							} while (subx != residualX * 3);
						}
					}

					if (notSimilared) {
						int targetL1Distance = int(nearestBadDistance + 1);
						while (++nowSearchL1Distance <= targetL1Distance) {
#pragma omp parallel for
							for (int subz = -nowSearchL1Distance; subz <= nowSearchL1Distance; ++subz) {
								int nowz = start.z + subz;
								int residualY = nowSearchL1Distance - abs(subz);
								if (residualY < 0 || nowz < 0 || nowz >= orderedCoords[2].size())
									continue;
								for (int suby = -residualY; suby <= residualY; suby++) {
									int nowy = start.y + suby;
									int residualX = residualY - abs(suby);
									if (residualX < 0 || nowy < 0 || nowy >= orderedCoords[1].size())
										continue;

									int subx = -residualX;
									do {
										int nowx = start.x + subx;
										subx += residualX * 2;
										if (nowx < 0 || nowx >= orderedCoords[0].size())
											continue;
										uint64_t index = nowx + sampledDim[0] * (nowy + sampledDim[1] * nowz);
										CustomPoint* point = &sampledPoints[index];
										float d = glm::distance(nowPoint.GetXYZ(), point->GetXYZ());
#pragma omp critical
										result2.push_back(tuple<uint64_t, bool, float>(index, /*!pointProcessedVel[index] && */Magnitude(point->GetVel() - nowPoint.GetVel()) <= magThreshold2, d));

									} while (subx != residualX * 3);
								}
							}
						}
						break;
					}
					++nowSearchL1Distance;
					if (result2.size() >= sampledPoints.size() - 5)
						break;
				}
				sort(result2.begin(), result2.end(), [](const tuple<uint64_t, bool, float>& a, const tuple<uint64_t, bool, float>& b) {return get<2>(a) < get<2>(b); });

				LagrangianVelSource source;
				source.pos = nowPoint.GetXYZ();
				source.vel = nowPoint.GetVel();
				for (int p = 0; p < result2.size(); p++) {
					if (!get<1>(result2[p]))
						break;
					source.radius = get<2>(result2[p]);
					pointProcessedVel[get<0>(result2[p])] = true;
				}
				velSources.push_back(source);

				pointProcessedVel[indexes[i]] = true;
			}
			if (pointProcessedPre[indexes[i]] == false) {
				bool notSimilared = false;
				nowPoint = sampledPoints[indexes[i]];
				glm::ivec3 start(-1);
				result2.clear();
				// FOR_3
				for (int j = 0; j < 3; j++) {
					vector<float>::iterator it = lower_bound(orderedCoords[i].begin(), orderedCoords[i].end(), nowPoint.GetXYZ()[i]);
					start[i] = it - orderedCoords[i].begin();
				}
				int nowSearchL1Distance = 1;
				float nearestBadDistance = 1e30f;
				while (1) {
#pragma omp parallel for
					for (int subz = -nowSearchL1Distance; subz <= nowSearchL1Distance; ++subz) {
						int nowz = start.z + subz;
						int residualY = nowSearchL1Distance - abs(subz);
						if (residualY < 0 || nowz < 0 || nowz >= orderedCoords[2].size())
							continue;
						for (int suby = -residualY; suby <= residualY; suby++) {
							int nowy = start.y + suby;
							int residualX = residualY - abs(suby);
							if (residualX < 0 || nowy < 0 || nowy >= orderedCoords[1].size())
								continue;
							int subx = -residualX;
							do {
								int nowx = start.x + subx;
								subx += residualX * 2;
								if (nowx < 0 || nowx >= orderedCoords[0].size())
									continue;
								uint64_t index = nowx + sampledDim[0] * (nowy + sampledDim[1] * nowz);
								CustomPoint* point = &sampledPoints[index];
								float d = glm::distance(nowPoint.GetXYZ(), point->GetXYZ());
#pragma omp critical
								{
									result2.push_back(tuple<uint64_t, bool, float>(index, /*!pointProcessedPre[index] && */abs(point->GetPressure() - nowPoint.GetPressure()) <= preThreshold, d));
									if (!get<1>(result2.back())) {
										if (nearestBadDistance > d)
											nearestBadDistance = d;
										notSimilared = true;
									}
								}
							} while (subx != residualX * 3);
						}
					}

					if (notSimilared) {
						int targetL1Distance = int(nearestBadDistance + 1);
						while (++nowSearchL1Distance <= targetL1Distance) {
#pragma omp parallel for
							for (int subz = -nowSearchL1Distance; subz <= nowSearchL1Distance; ++subz) {
								int nowz = start.z + subz;
								int residualY = nowSearchL1Distance - abs(subz);
								if (residualY < 0 || nowz < 0 || nowz >= orderedCoords[2].size())
									continue;
								for (int suby = -residualY; suby <= residualY; suby++) {
									int nowy = start.y + suby;
									int residualX = residualY - abs(suby);
									if (residualX < 0 || nowy < 0 || nowy >= orderedCoords[1].size())
										continue;
									int subx = -residualX;
									do {
										int nowx = start.x + subx;
										subx += residualX * 2;
										if (nowx < 0 || nowx >= orderedCoords[0].size())
											continue;
										uint64_t index = nowx + sampledDim[0] * (nowy + sampledDim[1] * nowz);
										CustomPoint* point = &sampledPoints[index];
										float d = glm::distance(nowPoint.GetXYZ(), point->GetXYZ());
#pragma omp critical
										result2.push_back(tuple<uint64_t, bool, float>(index, /*!pointProcessedPre[index] && */abs(point->GetPressure() - nowPoint.GetPressure()) <= preThreshold, d));

									} while (subx != residualX * 3);
								}
							}
						}
						break;
					}
					if (result2.size() >= sampledPoints.size() - 5)
						break;

					++nowSearchL1Distance;
				}
				sort(result2.begin(), result2.end(), [](const tuple<uint64_t, bool, float>& a, const tuple<uint64_t, bool, float>& b) {return get<2>(a) < get<2>(b); });

				LagrangianPreSource source;
				source.pos = nowPoint.GetXYZ();
				source.pre = nowPoint.GetPressure();
				for (int p = 0; p < result2.size(); p++) {
					if (!get<1>(result2[p]))
						break;
					source.radius = get<2>(result2[p]);
					pointProcessedPre[get<0>(result2[p])] = true;
				}
				preSources.push_back(source);

				pointProcessedPre[indexes[i]] = true;
			}
			progress++;
			if (progress > totalAmount / 100.f)
			{
				percent += totalAmount >= 100 ? 1.f : 100.f / totalAmount;
				//cout << "Source" << " Calculating: " << percent << "%!" << endl;
				progress -= totalAmount / 100.f;
			}
		}

		//timer.stop();
		//std::cout << "Calculate Sources costs " << timer.elapsed() << " seconds." << std::endl;
		//cout << "Velocity Sources Count: " << velSources.size() << endl;
		//cout << "Pressure Sources Count: " << preSources.size() << endl;

		//timer.start();

		vector<vector<vector<LagrangianVelSource>>> chunkSourceVel;
		vector<vector<vector<LagrangianPreSource>>> chunkSourcePre;

		vector<vector<int>> orderCorrector;

		chunkSourceVel.resize(totalLevel + 1);
		chunkSourcePre.resize(totalLevel + 1);
		for (int l = 0; l <= totalLevel; l++) {
			chunkSourceVel[l].resize((int)pow(8, l));
			chunkSourcePre[l].resize((int)pow(8, l));
		}


		for (int si = 0; si < velSources.size(); si++) {
			ProcessChunkIntersection<LagrangianVelSource>(chunkSourceVel, velSources[si], totalLevel, 0, min + (max - min) / 2.0f, (max - min) / 2.0f, min);
		}

		//timer.stop();
		//std::cout << "Calculate Velocity Source In Chunks costs " << timer.elapsed() << " seconds." << std::endl;

		//timer.start();
		for (int si = 0; si < preSources.size(); si++) {
			ProcessChunkIntersection<LagrangianPreSource>(chunkSourcePre, preSources[si], totalLevel, 0, min + (max - min) / 2.0f, (max - min) / 2.0f, min);
		}
		//timer.stop();
		//std::cout << "Calculate Pressure Source In Chunks costs " << timer.elapsed() << " seconds." << std::endl;
		//timer.start();
		for (int l = 0; l <= totalLevel; l++) {
			uint64_t accumulatedSize = 0;
			fstream fileValue, fileIndex;
			if (OUTPUT_BINARY) {
				string pathValue = folder_filename + "Level" + to_string(l) + "_lagrangian_data.bin";
				string pathIndex = folder_filename + "Level" + to_string(l) + "_lagrangian_index.bin";
				fileValue.open(pathValue, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
				fileIndex.open(pathIndex, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
			}
			else {
				string pathValue = folder_filename + "Level" + to_string(l) + "_lagrangian_data_text.bin";
				string pathIndex = folder_filename + "Level" + to_string(l) + "_lagrangian_index_text.bin";
				fileValue.open(pathValue, std::ios_base::out | std::ios_base::trunc);
				fileIndex.open(pathIndex, std::ios_base::out | std::ios_base::trunc);
			}
			int zeroCount = 0;
			for (int i = 0; i < chunkSourceVel[l].size(); i++) {

				if (OUTPUT_BINARY) {
					uint64_t size = chunkSourceVel[l][i].size();
					fileValue.write((char*)&size, sizeof(uint64_t));
					fileValue.write((char*)chunkSourceVel[l][i].data(), chunkSourceVel[l][i].size() * sizeof(LagrangianVelSource));
					if (size == 0)
						zeroCount++;
					size = chunkSourcePre[l][i].size();
					fileValue.write((char*)&size, sizeof(uint64_t));
					fileValue.write((char*)chunkSourcePre[l][i].data(), chunkSourcePre[l][i].size() * sizeof(LagrangianPreSource));

					fileIndex.write((char*)&accumulatedSize, sizeof(uint64_t));
					accumulatedSize += chunkSourceVel[l][i].size() * sizeof(LagrangianVelSource) + sizeof(uint64_t);
					accumulatedSize += chunkSourcePre[l][i].size() * sizeof(LagrangianPreSource) + sizeof(uint64_t);
				}
				else {
					int size = chunkSourceVel[l][i].size();
					fileValue << size << endl;
					for (int j = 0; j < size; j++) {
						fileValue << chunkSourceVel[l][i][j].pos[0] << " " << chunkSourceVel[l][i][j].pos[1] << " " << chunkSourceVel[l][i][j].pos[2] << " ";
						fileValue << chunkSourceVel[l][i][j].radius << " ";
						fileValue << chunkSourceVel[l][i][j].vel[0] << " " << chunkSourceVel[l][i][j].vel[1] << " " << chunkSourceVel[l][i][j].vel[2] << endl;
					}
					if (size == 0)
						zeroCount++;
					size = chunkSourcePre[l][i].size();
					fileValue << size << endl;
					for (int j = 0; j < size; j++) {
						fileValue << chunkSourcePre[l][i][j].pos[0] << " " << chunkSourcePre[l][i][j].pos[1] << " " << chunkSourcePre[l][i][j].pos[2] << " ";
						fileValue << chunkSourcePre[l][i][j].radius << " ";
						fileValue << chunkSourcePre[l][i][j].pre << endl;
					}
					fileIndex << accumulatedSize << endl;
					accumulatedSize += chunkSourceVel[l][i].size() + 1;
					accumulatedSize += chunkSourcePre[l][i].size() + 1;
				}
			}

			//cout << "Level " << l << " Zero Count:" << zeroCount << endl;
		}

		std::sort(velSources.begin(), velSources.end(), [](LagrangianVelSource a, LagrangianVelSource b) {
			return a.radius > b.radius;
			});
		std::sort(preSources.begin(), preSources.end(), [](LagrangianPreSource a, LagrangianPreSource b) {
			return a.radius > b.radius;
			});

		fstream fileVelSource, filePreSource;
		if (OUTPUT_BINARY) {
			string pathVelSource = folder_filename + "vel_source.bin";
			string pathPreSource = folder_filename + "pre_source.bin";
			fileVelSource.open(pathVelSource, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
			filePreSource.open(pathPreSource, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
			uint64_t size = velSources.size();
			fileVelSource.write((char*)&size, sizeof(uint64_t));
			fileVelSource.write((char*)velSources.data(), velSources.size() * sizeof(LagrangianVelSource));
			size = preSources.size();
			filePreSource.write((char*)&size, sizeof(uint64_t));
			filePreSource.write((char*)preSources.data(), preSources.size() * sizeof(LagrangianPreSource));
		}
		else {
			string pathVelSource = folder_filename + "vel_source_text.bin";
			string pathPreSource = folder_filename + "pre_source_text.bin";
			fileVelSource.open(pathVelSource, std::ios_base::out | std::ios_base::trunc);
			filePreSource.open(pathPreSource, std::ios_base::out | std::ios_base::trunc);
			int size = velSources.size();
			fileVelSource << size << endl;
			for (int j = 0; j < size; j++) {
				fileVelSource << velSources[j].pos[0] << " " << velSources[j].pos[1] << " " << velSources[j].pos[2] << " ";
				fileVelSource << velSources[j].radius << " ";
				fileVelSource << velSources[j].vel[0] << " " << velSources[j].vel[1] << " " << velSources[j].vel[2] << endl;
			}
			size = preSources.size();
			filePreSource << size << endl;
			for (int j = 0; j < size; j++) {
				filePreSource << preSources[j].pos[0] << " " << preSources[j].pos[1] << " " << preSources[j].pos[2] << " ";
				filePreSource << preSources[j].radius << " ";
				filePreSource << preSources[j].pre << endl;
			}
		}
		//timer.stop();
		//std::cout << "Output Sources To File costs " << timer.elapsed() << " seconds." << std::endl;
	}
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

		string str;
		fs >> str;
		if (str != hdr.fileMagic) {
			preprocessed = false;
			return;
		}

		fs >> hdr.fileName;
		fs >> hdr.vel >> hdr.pre >> hdr.temp >> hdr.rad;

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
		if (hdr.temp != -1) {
			fs >> minTemperature >> maxTemperature;
			minTemperature = 0;
		}

		fs.close();

		min *= scale;
		max *= scale;
			
		preprocessed = true;	
		this->FillTreeStructureFromInfo();
	}
}

void CustomOctree::SetCompressionMethod(CompressionMethod newCompressionMethod)
{
	compressionMethod = newCompressionMethod;
}

void CustomOctree::SetWithLaplacianPyramidOutput(bool w) {
	withLaplacianPyramid = w;
}

void CustomOctree::SetWithMotionIndexOutput(bool w) {
	withMotionIndex = w;
}

void CustomOctree::SetIsInputOrganized(bool newIsInputOrganized)
{
	isInputOrganized = newIsInputOrganized;
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

float CustomOctree::GetMaxTemperature()
{
	return maxTemperature;
}

float CustomOctree::GetMinTemperature()
{
	return minTemperature;
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

bool CustomOctree::GetVorticity(vector<CustomPoint>& targetPoints, int& i, int& j, int& k, float& vorticity_)
{
	if (i + 1 >= sampledDim[0] || i - 1 < 0 || j + 1 >= sampledDim[1] || j - 1 < 0 || k + 1 >= sampledDim[2] || k - 1 < 0)
		return true;

	glm::vec3 origin = GetPointRef(targetPoints, i, j, k)->GetVel();
	glm::vec3 xDirVel = GetPointRef(targetPoints, i + 1, j, k)->GetVel();
	glm::vec3 yDirVel = GetPointRef(targetPoints, i, j + 1, k)->GetVel();
	glm::vec3 zDirVel = GetPointRef(targetPoints, i, j, k + 1)->GetVel();
	glm::vec3 xDirVel_m = GetPointRef(targetPoints, i - 1, j, k)->GetVel();
	glm::vec3 yDirVel_m = GetPointRef(targetPoints, i, j - 1, k)->GetVel();
	glm::vec3 zDirVel_m = GetPointRef(targetPoints, i, j, k - 1)->GetVel();


	float iVorticity = (yDirVel[2] - origin[2]) / sampledSpacing[1] - (zDirVel[1] - origin[1]) / sampledSpacing[2];
	float jVorticity = (zDirVel[0] - origin[0]) / sampledSpacing[2] - (xDirVel[2] - origin[2]) / sampledSpacing[0];
	float kVorticity = (xDirVel[1] - origin[1]) / sampledSpacing[0] - (yDirVel[0] - origin[0]) / sampledSpacing[1];
	float vorticity = sqrt(pow(iVorticity, 2) + pow(jVorticity, 2) + pow(kVorticity, 2));//?k??

	float iVorticity_m = (yDirVel_m[2] - origin[2]) / sampledSpacing[1] - (zDirVel_m[1] - origin[1]) / sampledSpacing[2];
	float jVorticity_m = (zDirVel_m[0] - origin[0]) / sampledSpacing[2] - (xDirVel_m[2] - origin[2]) / sampledSpacing[0];
	float kVorticity_m = (xDirVel_m[1] - origin[1]) / sampledSpacing[0] - (yDirVel_m[0] - origin[0]) / sampledSpacing[1];
	float vorticity_m = sqrt(pow(iVorticity_m, 2) + pow(jVorticity_m, 2) + pow(kVorticity_m, 2));//????

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

bool CustomOctree::GetQCritirea(vector<CustomPoint>& targetPoints, int& i, int& j, int& k, float& qcritirea)
{
	if (i + 1 >= sampledDim[0] || i - 1 < 0 || j + 1 >= sampledDim[1] || j - 1 < 0 || k + 1 >= sampledDim[2] || k - 1 < 0)
		return true;

	glm::vec3 origin = GetPointRef(targetPoints, i, j, k)->GetVel();
	glm::vec3 xDirVel = GetPointRef(targetPoints, i + 1, j, k)->GetVel();
	glm::vec3 yDirVel = GetPointRef(targetPoints, i, j + 1, k)->GetVel();
	glm::vec3 zDirVel = GetPointRef(targetPoints, i, j, k + 1)->GetVel();
	glm::vec3 xDirVel_m = GetPointRef(targetPoints, i - 1, j, k)->GetVel();
	glm::vec3 yDirVel_m = GetPointRef(targetPoints, i, j - 1, k)->GetVel();
	glm::vec3 zDirVel_m = GetPointRef(targetPoints, i, j, k - 1)->GetVel();

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

	float QValue = (omega + shear);//?k??
	float QValue_m = (omega_m + shear_m);//????

	qcritirea = (QValue + QValue_m) / 2;
	return false;
}

void CustomOctree::InitMinMaxValue()
{
	this->minMagnitude = this->minPressure = this->minVorticity = this->minQCritirea = this->minTemperature = numeric_limits<float>::max();
	this->maxXVel = this->maxYVel = this->maxZVel = this->maxMagnitude = this->maxPressure = this->maxVorticity = this->maxQCritirea = this->maxTemperature = numeric_limits<float>::min();
}

bool CustomOctree::haveTemperatureData() {
	if (hdr.temp != -1)
		return true;
	return false;
}

void CustomOctree::UpdateMinMaxValue()
{
	//SimpleTimer timer;
	//timer.start();
	vector<CustomPoint>& targetPoints = totalLevel > 0 ? sampledPoints : points;
	for (int k = 0; k < sampledDim[2]; k++) {
		for (int j = 0; j < sampledDim[1]; j++) {
			for (int i = 0; i < sampledDim[0]; i++) {
				CustomPointData* cp = GetPointRef(targetPoints, i, j, k);
				if (abs(cp->GetXVel()) > this->maxXVel)
					this->maxXVel = abs(cp->GetXVel());
				if (abs(cp->GetYVel()) > this->maxYVel)
					this->maxYVel = abs(cp->GetYVel());
				if (abs(cp->GetZVel()) > this->maxZVel)
					this->maxZVel = abs(cp->GetZVel());

				if (cp->GetMagnitude() < this->minMagnitude)
					this->minMagnitude = cp->GetMagnitude();
				if (cp->GetMagnitude() > this->maxMagnitude)
					this->maxMagnitude = cp->GetMagnitude();

				if (cp->GetPressure() < this->minPressure)
					this->minPressure = cp->GetPressure();
				if (cp->GetPressure() > this->maxPressure)
					this->maxPressure = cp->GetPressure();

				float vorticity;
				bool OutOfBound = GetVorticity(targetPoints, i, j, k, vorticity);
				if (OutOfBound)
					continue;
				if (vorticity < this->minVorticity)
					this->minVorticity = vorticity;
				if (vorticity > this->maxVorticity)
					this->maxVorticity = vorticity;

				float qcritirea;

				OutOfBound = GetQCritirea(targetPoints, i, j, k, qcritirea);
				if (OutOfBound)
					continue;
				if (qcritirea < this->minQCritirea)
					this->minQCritirea = qcritirea;
				if (qcritirea > this->maxQCritirea)
					this->maxQCritirea = qcritirea;

				// if have temperature data
				if (hdr.temp != -1) {
					if (cp->GetTemperature() < this->minTemperature && cp->GetTemperature() != 0)
						this->minTemperature = cp->GetTemperature();
					if (cp->GetTemperature() > this->maxTemperature)
						this->maxTemperature = cp->GetTemperature();
				}
			}
		}
	}
	//timer.stop();
	//cout << "Calculate MinMax costs " << timer.elapsed() << " seconds." << std::endl;
}

void CustomOctree::SaveMinMaxValue(string outFolder) {
	fstream writeInfo(outFolder + "gridinfo.bin", std::ios_base::out | std::ios_base::ate | std::ios_base::app);
	writeInfo << this->maxXVel << " " << this->maxYVel << " " << this->maxZVel << endl;
	writeInfo << this->minMagnitude << " " << this->maxMagnitude << endl;
	writeInfo << this->minPressure << " " << this->maxPressure << endl;
	writeInfo << this->minVorticity << " " << this->maxVorticity << endl;
	writeInfo << this->minQCritirea << " " << this->maxQCritirea << endl;
	//cout << "MinMax Magnitude:" << this->minMagnitude << " " << this->maxMagnitude << endl;
	//cout << "MinMax Pressure:" << this->minPressure << " " << this->maxPressure << endl;
	//cout << "MinMax Vorticity:" << this->minVorticity << " " << this->maxVorticity << endl;
	//cout << "MinMax QCritirea:" << this->minQCritirea << " " << this->maxQCritirea << endl;
	if (hdr.temp != -1) {
		writeInfo << this->minTemperature << " " << this->maxTemperature << endl;
		//cout << "MinMax QCritirea:" << this->minTemperature << " " << this->maxTemperature << endl;
	}
	writeInfo.close();
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
	//for (int l = 0; l <= totalLevel; l++)
		//cout << "Level " << l << " Chunk Count: " << count[l] << endl;
}
#pragma endregion