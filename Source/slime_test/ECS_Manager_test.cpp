// Fill out your copyright notice in the Description page of Project Settings.


#include "ECS_Manager_test.h"
#include "ECS_Test/Database.h"
#include "TestSystem.h"

// Sets default values
AECS_Manager_test::AECS_Manager_test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DB = new Database();
	Systems.Add(new TestSystem());
}

// Called when the game starts or when spawned
void AECS_Manager_test::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AECS_Manager_test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bEnableTick) return;

	for (auto& system : Systems)
	{
		system->Update(DeltaTime, DB);
	}
}

