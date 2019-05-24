// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VertexDataTest.generated.h"

UCLASS()
class WATERPROJ_API AVertexDataTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVertexDataTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION(BlueprintPure, Category = "InternalData")
	TArray<FVector> GetVertexData(const UStaticMeshComponent* Mesh);

private:

	//PROPERTY
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "True"))
		UStaticMeshComponent* TestMesh;
};
