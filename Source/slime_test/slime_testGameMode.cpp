// Copyright Epic Games, Inc. All Rights Reserved.

#include "slime_testGameMode.h"
#include "slime_testCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aslime_testGameMode::Aslime_testGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
