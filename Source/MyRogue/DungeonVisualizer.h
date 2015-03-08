// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "LevelGenerator.h"
#include "DungeonVisualizer.generated.h"

/**
 * 
 */
UCLASS()
class MYROGUE_API ADungeonVisualizer : public AHUD
{
    GENERATED_BODY()
public:

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
        int32 X;
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Parameters)
        int32 Y;
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tiles)
        UClass* WallTile;
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tiles)
        UClass* GroundTile;

        ADungeonVisualizer(const FObjectInitializer& init);
        void PostInitializeComponents() override;
	
};


