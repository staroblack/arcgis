// Fill out your copyright notice in the Description page of Project Settings.
#include "MapSystemBFL.h"
#include "Serialization/JsonSerializer.h"
#include "JsonObjectConverter.h"

AMapSystemBFL::AMapSystemBFL(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

FVector AMapSystemBFL::TileNumberLatlontoNum(double lat, double lon, int level) {
	double n = (1 << level);
	double lon_deg = lon;
	double lat_rad = lat * PI / 180.0;
	double xtile = floor(((lon_deg + 180) / 360.0 * n));
	double ytile = floor((1.0 - asinh(tan(lat_rad)) / PI) / 2.0 * n);
	return FVector(xtile, ytile, 0);
}

FVector AMapSystemBFL::TileNumberNumtoLatlon(double x, double y, int level) {
	double n = (1 << level);
	double xtile = x;
	double ytile = y;
	double lon_deg = xtile / n * 360.0 - 180.0;
	double c = PI - 2.0 * PI * ytile / n;
	double lat_deg = 180.0 / PI * atan(0.5 * (exp(c) - exp(-c)));
	//double lat_rad = atan(sinh(PI * (1.0 - (2.0 * ytile) / n)));
	//double lat_deg = lat_rad * 180.0 / PI;
	return FVector(lat_deg, lon_deg, 0);
}

FVector AMapSystemBFL::TileNumberSize(double lat, int level) {
	double midlat = 24;
	double C = 40075016.686;
	double lat_rad = (midlat / 180.0) * PI;
	double SizeY = C * cos(lat_rad) / pow(2, (level)) / 256.0;
	
	return FVector(SizeY, SizeY, 0);
}

FVector AMapSystemBFL::WGS84toTWD97(double wgs84x, double wgs84y)
{
	// Define the target coordinate reference system (TWD97 / TM2 zone 121)
	projPJ source_crs = pj_init_plus("+proj=longlat +datum=WGS84");

	projPJ target_crs = pj_init_plus("+proj=tmerc +lat_0=0 +lon_0=121 +k=0.9999 +x_0=250000 +y_0=0 +ellps=GRS80 +units=m +no_defs");

	double twd97_x = wgs84y * 3.1415926 / 180.0;
	double twd97_y = wgs84x * 3.1415926 / 180.0;

	// Transform pixel coordinates from source CRS to target CRS
	pj_transform(source_crs, target_crs, 1, 1, &twd97_x, &twd97_y, nullptr);

	return FVector(twd97_x, -twd97_y, 0);

}

FVector AMapSystemBFL::TWD97toWGS84(double twd97x, double twd97y)
{
	// Define the target coordinate reference system (TWD97 / TM2 zone 121)
	projPJ source_crs = pj_init_plus("+proj=tmerc +lat_0=0 +lon_0=121 +k=0.9999 +x_0=250000 +y_0=0 +ellps=GRS80 +units=m +no_defs");

	projPJ target_crs = pj_init_plus("+proj=longlat +datum=WGS84");

	double wgs84_x = twd97x;
	double wgs84_y = -twd97y;

	// Transform pixel coordinates from source CRS to target CRS
	pj_transform(source_crs, target_crs, 1, 1, &wgs84_x, &wgs84_y, nullptr);

	wgs84_x = wgs84_x * 180.0 / 3.1415926;
	wgs84_y = wgs84_y * 180.0 / 3.1415926;

	return FVector(wgs84_y, wgs84_x, 0);

	
}