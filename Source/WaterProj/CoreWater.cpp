// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreWater.h"

// Sets default values
ACoreWater::ACoreWater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize water plane
	bWaterPlane = true;

	// Initialize Water Volume
	WaterVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("WaterVolume"));
	RootComponent = WaterVolume;
}

// Called when the game starts or when spawned
void ACoreWater::BeginPlay()
{
	Super::BeginPlay();
	InitializeWater();
}

// Called every frame
void ACoreWater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoreWater::InitializeWater() {
	// Check if bWaterPlane is True, otherwise return
	if (bWaterPlane)
	{
		// CreateWaterPlane
		WaterMesh = CreateWaterPlane();
	}
	else
	{
		return;
	}
}



UStaticMeshComponent* ACoreWater::CreateWaterPlane() 
{
	return CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WaterPlaneMesh"));
}
