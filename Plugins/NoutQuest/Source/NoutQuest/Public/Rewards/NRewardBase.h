// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "Core/NObject.h"

#include "NRewardBase.generated.h"

UCLASS(Abstract, BlueprintType, EditinlineNew, meta = (Category = "Rewards", DisplayName = "Reward Base"))
class NOUTQUEST_API UNRewardBase : public UNObject
{
    GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
    // Editor Only Designer Description
    UPROPERTY(Category="Default", EditInstanceOnly, meta = (DisplayPriority="1"))
    FString DesignerDescription;
#endif

    UFUNCTION(Category="Reward", BlueprintNativeEvent, BlueprintCallable)
    void GiveReward(UObject* InOwner);
};