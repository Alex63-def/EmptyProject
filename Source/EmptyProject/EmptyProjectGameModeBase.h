// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EmptyProjectGameModeBase.generated.h"

// макрос на проверку платформы
#if PLATFORM_ANDROID
#include "src/pugixml.hpp"
#endif

/**
 * 
 */
UCLASS()
class EMPTYPROJECT_API AEmptyProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
};
