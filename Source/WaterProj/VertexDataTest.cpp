// Fill out your copyright notice in the Description page of Project Settings.


#include "VertexDataTest.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "StaticMeshResources.h"



// Sets default values
AVertexDataTest::AVertexDataTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TestMesh"));

	GetVertexData(TestMesh);
}

// Called when the game starts or when spawned
void AVertexDataTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVertexDataTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FVector> AVertexDataTest::GetVertexData(const UStaticMeshComponent* Mesh)
{
	TArray<FVector> Vertices = TArray<FVector>();

	if (!IsValidLowLevel()) return Vertices;
	if (Mesh == nullptr) return Vertices;
	if (Mesh->GetStaticMesh() == nullptr) return Vertices;
	if (Mesh->GetStaticMesh()->RenderData) return Vertices;

	// Thanks to RAMA @ https://forums.unrealengine.com/development-discussion/c-gameplay-programming/7509-accessing-vertex-positions-of-static-mesh
	if (Mesh->GetStaticMesh()->RenderData->LODResources.Num() > 0)
	{
		FPositionVertexBuffer* VertexBuffer = &Mesh->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer;
		if (VertexBuffer)
		{
			const int32 VertexCount = VertexBuffer->GetNumVertices();
			for (int32 Index = 0; Index < VertexCount; Index++)
			{
				//This is in the Static Mesh Actor Class, so it is location and tranform of the SMActor
				const FVector WorldSpaceVertexLocation = GetActorLocation() + GetTransform().TransformVector(VertexBuffer->VertexPosition(Index));
				//add to output FVector array
				Vertices.Add(WorldSpaceVertexLocation);
			}
		}
	}
	return Vertices;
}

