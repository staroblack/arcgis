#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "D:\\AR\\arcgis\\ThirdParty\\PROJ\\include\\proj_api.h"
#include "MapSystemBFL.generated.h"

class FJsonObject;

/**
 * 
 */
UCLASS()
class AMapSystemBFL : public AActor
{
	GENERATED_UCLASS_BODY()

public:
	

	UFUNCTION(BlueprintCallable, Category = "MapSystem")
	static FVector TileNumberSize(double lat, int level);

	UFUNCTION(BlueprintCallable, Category = "MapSystem")
	static FVector TileNumberLatlontoNum(double lat, double lon, int level);
	UFUNCTION(BlueprintCallable, Category = "MapSystem")
	static FVector TileNumberNumtoLatlon(double x, double y, int level);

	UFUNCTION(BlueprintCallable, Category = "MapSystem")
	static FVector WGS84toTWD97(double wgs84x, double wgs84y);
	UFUNCTION(BlueprintCallable, Category = "MapSystem")
	static FVector TWD97toWGS84(double x, double y);


};
