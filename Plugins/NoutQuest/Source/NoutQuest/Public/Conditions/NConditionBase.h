// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
//--Engine Include

#include "Core/NObject.h"

#include "NConditionBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FConditionEvent);

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

    UPROPERTY(Category = "Quest", BlueprintReadOnly)
    FGameplayTag QuestID;

    UPROPERTY(Category = "Quest", BlueprintReadOnly)
    bool bIsCompleted = false;

public:

    UFUNCTION(Category = "Quest", BlueprintNativeEvent, BlueprintCallable)
    void InitCondition();

    UFUNCTION(Category = "Quest", BlueprintNativeEvent, BlueprintCallable)
    FText GetDisplayText() const;

    UFUNCTION(Category = "Quest", BlueprintNativeEvent, BlueprintCallable)
    bool EvaluateInternal();

    UFUNCTION(Category = "Quest", BlueprintCallable)
    bool Evaluate();

    UFUNCTION(Category = "Quest", BlueprintCallable)
    bool IsCompleted() const;

    UFUNCTION(Category = "Quest", BlueprintCallable)
    void CallOnConditionStateChanged() const;

    // Called On Demand to Refresh Conditions Data in UI
	UPROPERTY(Category = "Quest", BlueprintAssignable)
	FConditionEvent OnConditionStateChanged;
};
