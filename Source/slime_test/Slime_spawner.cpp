// Fill out your copyright notice in the Description page of Project Settings.


#include "Slime_spawner.h"
#include "FSlimeBubble.h"
#include "EngineUtils.h"
#include "ECS_Test/Database.h"
#include "ECS_Test/Query.h"

// Sets default values for this component's properties
USlime_spawner::USlime_spawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USlime_spawner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			AActor* B = GetWorld()->SpawnActor<AActor>(SlimeBubble, 100 * FVector(i - 30 / 2, j - 30 / 2, 0), FRotator(0, 0, 0));
			
		}
	}
}


// Called every frame
void USlime_spawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

