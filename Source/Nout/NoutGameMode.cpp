// Copyright Epic Games, Inc. All Rights Reserved.

#include "NoutGameMode.h"
#include "NoutCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANoutGameMode::ANoutGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
