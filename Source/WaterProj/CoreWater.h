// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CoreWater.generated.h"

UCLASS()
class WATERPROJ_API ACoreWater : public AActor
{
	GENERATED_BODY()

// FUNCTION	
public:	
	// Sets default values for this actor's properties
	ACoreWater();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Return Box Component
	FORCEINLINE UBoxComponent* GetWaterVolume() { return WaterVolume; }

	// Initialize Water Actor
	UFUNCTION(BlueprintCallable, Category = "Water")
	void InitializeWater();

// PROPERTY
private:
	// Create water plane
	UFUNCTION()
	UStaticMeshComponent* CreateWaterPlane();

protected:
	// Box component to determine how big is the water
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Water")
	UBoxComponent* WaterVolume;

	// WaterMesh 
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Water")
	UStaticMeshComponent* WaterMesh;

public:
	// Generate water if bWaterPlane is true
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Water")
	bool bWaterPlane;

};
