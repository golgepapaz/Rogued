// Fill out your copyright notice in the Description page of Project Settings.

#include "MyRogue.h"
#include "DungeonVisualizer.h"
#include "UtilityFunctions.h"
#include "Engine/StaticMeshActor.h"


ADungeonVisualizer::ADungeonVisualizer(const FObjectInitializer& init) : Super(init)
{
    // ConstructorHelpers::FClassFinder<AStaticMeshActor> WallTile(TEXT("Blueprint'/Game/Blueprints/MazeTiles/BP_Block.BP_Block'"));
    //   ConstructorHelpers::FClassFinder<AStaticMeshActor> GroundTile(TEXT("Blueprint'/Game/Blueprints/MazeTiles/BP_GroundTile.BP_GroundTile'"));


}
void ADungeonVisualizer::PostInitializeComponents()
{
    Super::PostInitializeComponents();


    auto offset = 80;
    BSPLevelGenerator buh;
    DungeonLevel* lev = buh.GenerateLevel(X, Y);

    for (auto x = 0; x < X; ++x)
        for (auto y = 0; y < Y; ++y)
        {
            FVector loc(x * offset, y * offset, 0);
            FRotator rot(0, 0, 0);
            Tile t = (*lev)[x][y];
            
     //       Tile t = tt[y];
            if (t.IsWall())
                Util::SpawnBlueprint<AStaticMeshActor>(GetWorld(), WallTile, loc, rot, true , this);
            else
                Util::SpawnBlueprint<AStaticMeshActor>(GetWorld(), GroundTile, loc, rot ,true ,this);

        }

}




