// Fill out your copyright notice in the Description page of Project Settings.

#include "MyRogue.h"
#include "MyRogueGameMode.h"
#include "DungeonVisualizer.h"


AMyRogueGameMode::AMyRogueGameMode(const FObjectInitializer& PCIP)
	: Super(PCIP)
{

    HUDClass = ADungeonVisualizer::StaticClass();
}


