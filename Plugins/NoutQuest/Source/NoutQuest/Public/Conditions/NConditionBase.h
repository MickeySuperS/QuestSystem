// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
//--Engine Include

#include "Core/NObject.h"

#include "NConditionBase.generated.h"

UCLASS(Abstract, BlueprintType, EditinlineNew, meta = (Category = "Conditions", DisplayName = "Condition Base"))
class NOUTQUEST_API UNConditionBase : public UNObject
{
    GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
    // Editor Only Designer Description
    UPROPERTY(Category="Default", EditInstanceOnly, meta = (DisplayPriority="1"))
    FString DesignerDescription;
#endif

    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    FGameplayTag QuestID;

    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    bool bIsCompleted = false;

public:

    UFUNCTION(Category = "Quest", BlueprintNativeEvent, BlueprintCallable)
    FText GetDisplayText() const;

    UFUNCTION(Category = "Quest", BlueprintNativeEvent, BlueprintCallable)
    bool EvaluateInternal();

    UFUNCTION(Category = "Quest", BlueprintCallable)
    bool Evaluate();

    UFUNCTION(Category = "Quest", BlueprintCallable)
    bool IsCompleted() const;

    // Called On Demand to Refresh Conditions Data in UI
    UFUNCTION(Category = "Quest", BlueprintCallable)
    void CallOnConditionStateChanged() const;
};
