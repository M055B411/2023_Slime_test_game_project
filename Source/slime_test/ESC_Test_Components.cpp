// Fill out your copyright notice in the Description page of Project Settings.


#include "ESC_Test_Components.h"
#include "ECS_Manager_test.h"
#include "EngineUtils.h"

// Sets default values for this component's properties

UECSLinker::UECSLinker()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UECSLinker::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetOwner()->GetWorld();

	if (World)
	{
		for (TActorIterator<AECS_Manager_test> It(World, AECS_Manager_test::StaticClass()); It; ++It) {
			if (IsValid(*It)) 
			{
				ECSManager = *It;
				break;
			}
		}
	}

	if (ECSManager == nullptr) {
		ECSManager = World->SpawnActor<AECS_Manager_test>(AECS_Manager_test::StaticClass());
	}
	if (ECSManager) {
		EntityId = ECSManager->DB->CreateEntity();
	}
	RegisterWithECS();
}

void UECSLinker::RegisterWithECS()
{
	Database* DB = ECSManager->DB;
	DB->AddComp(EntityId, FActorReference(GetOwner()));

	if (TransformSync == ETransformSyncType::Actor_To_ECS || TransformSync == ETransformSyncType::BothWays)
	{
		DB->AddComp(EntityId, FCopyTransformToECS());
	}
	if (TransformSync == ETransformSyncType::ECS_To_Actor || TransformSync == ETransformSyncType::BothWays)
	{
		DB->AddComp(EntityId, FCopyTransformToActor());
	}

	for (auto c : GetOwner()->GetComponents())
	{
		auto wr = Cast<IComponentWrapper>(c);
		if (wr) {
			wr->AddToEntity(DB, EntityId);
		}
	}
}

