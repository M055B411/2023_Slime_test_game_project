// Fill out your copyright notice in the Description page of Project Settings.


#include "TestSystem.h"
#include <functional>
#include <stdio.h>

void TestSystem::Update(float deltaTime, Database* DB)
{
	//Add FActorTransform to all entities(Actors for this case) with FCopyTransformToECS
	Query<TExclude<FActorTransform>, FCopyTransformToECS> ToAddTransform;
	ToAddTransform.Each(*DB, [=](int32 EntityId, FCopyTransformToECS& _)
		{
			DB->AddComp(EntityId, FActorTransform());
			return true;
		});

	//Copy FTransform of Actor from all entities with FActorReference and FActorTransform
	Query<FActorReference, FActorTransform> ToCopyTransform;
	ToCopyTransform.Each(*DB, [=](int32 EntityId, const FActorReference& v, FActorTransform& Transform)
		{
			const FTransform& ActorTransform = v.Ptr->GetActorTransform();
			Transform.transform = ActorTransform;
			return true;
		});

	//insert here


	/*Query<FSlimeCoreComp, FActorTransform> LocateSlimeCore;
	LocateSlimeCore.Each(*DB, [=](int32 EntityId, FSlimeCoreComp& CoreComp, FActorTransform& CoreTransform)
		{
			BubbleHealth = 0;
			const auto CoreLocation = CoreTransform.transform.GetLocation();
			Query<FSlimeBubbleComp, FActorReference, FActorTransform> MoveSlimebubble;
			MoveSlimebubble.Each(*DB, [=](int32 EntityId, FSlimeBubbleComp& BubbleComp, const FActorReference& v, FActorTransform& Transform)
				{
					auto bubbleclocation = Transform.transform.GetLocation();
					float gravity = ((6.67430e-11) * 150000) / (FVector::Distance(CoreLocation, bubbleclocation) * FVector::Distance(CoreLocation, bubbleclocation));
					FVector NextPos = bubbleclocation + (FVector)(gravity * (CoreLocation - bubbleclocation).GetSafeNormal());
					Transform.transform.SetLocation(NextPos);
					AFSlimeBubble* bubble = Cast<AFSlimeBubble>(v.Ptr);
					BubbleHealth += bubble->bubblehealth;
					return true;
				});
			return true;
		});

	Query<FSlimeCoreComp, FActorTransform> HealSlimeCore;
	HealSlimeCore.Each(*DB, [=](int32 EntityId, FSlimeCoreComp& CoreComp, FActorReference& CoreReference)
		{
			AFSlimeCoreCharacter* Core = Cast<AFSlimeCoreCharacter>(CoreReference.Ptr);
			Core->SlimeHealth = Core->SlimeCoreHealth + BubbleHealth;
			return true;
		});*/

	//end zone

	//Copy FActorTransform data to Actors with FCopyTransformToActor
	Query<FCopyTransformToActor, FActorReference, FActorTransform> ToCopyTransformToActor;
	ToCopyTransformToActor.Each(*DB, [=](int32 EntityId, FCopyTransformToActor& _, FActorReference& v, FActorTransform& Transform)
		{
			v.Ptr->SetActorTransform(Transform.transform);
			return true;
		});
}
