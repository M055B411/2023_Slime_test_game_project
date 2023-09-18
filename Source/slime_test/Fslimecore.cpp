// Fill out your copyright notice in the Description page of Project Settings.


#include "Fslimecore.h"

// Sets default values
AFslimecore::AFslimecore()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFslimecore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFslimecore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFslimecore::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

