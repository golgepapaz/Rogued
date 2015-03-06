
#include "Engine/StaticMeshActor.h"
namespace Util
{
template <typename  T>
T* SpawnBlueprint(UWorld* world, UClass* bp , const FVector& loc , const FRotator& rot, 
                 bool noCollisionFail = true, AActor* owner = nullptr, APawn* instigator = nullptr)
{
    FActorSpawnParameters info;
    info.bNoCollisionFail = noCollisionFail;
    info.Owner = owner;
    info.Instigator = instigator;
    info.bDeferConstruction = false;
    return world->SpawnActor<T>(world, bp, loc, rot, info);
}
}