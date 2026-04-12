// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "Engine/DataAsset.h"
#include "StructUtils/InstancedStruct.h"
#include "GameplayTagContainer.h"
//--Engine Include

#include "NQuest.generated.h"

struct FObjectiveData;
class UNRewardBase;

/////////////////////// Data Asset ////////////////////////

UCLASS(BlueprintType)
class NOUTQUEST_API UNQuestData : public UDataAsset
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag QuestID; //@@TODO(mickey): require validation

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Title;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (TitleProperty = "Title"))
    TArray<FObjectiveData> Objectives;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, meta = (TitleProperty = "DesignerDescription"))
    TArray<TObjectPtr<class UNRewardBase>> Rewards;

};

/////////////////////// Quest Instance ////////////////////////

UCLASS(BlueprintType)
class NOUTQUEST_API UNQuestInstance : public UObject
{
	GENERATED_BODY()

public:

// Quest Data
    UPROPERTY()
    FGameplayTag QuestID;
    
    UPROPERTY()
    FText Title;
    
    UPROPERTY()
    FText Description;
   
    UPROPERTY()
    TArray<struct FObjectiveData> Objectives;

    UPROPERTY()
	TObjectPtr<UNQuestData> TemplateAsset;

    UPROPERTY()
    TObjectPtr<UObject> Owner;

protected:

    UPROPERTY()
    int32 CurrentObjectiveInstance = 0;

    UPROPERTY()
    bool bIsCompleted = false;

public:
	void InitializeInstance(UObject* InOwner, UNQuestData& QuestTemplate);
	bool IsInstanceInitialized() const { return IsValid(TemplateAsset); }
	UNQuestData* GetTemplateAsset() const { return TemplateAsset; }

    bool Evaluate();
    bool IsCompleted() const;

};


/////////////////////// Completed Quests ////////////////////////

USTRUCT(BlueprintType)
struct NOUTQUEST_API FNQuestCompleted
{
	GENERATED_BODY()

    UPROPERTY()
    FGameplayTag QuestID;
    
    UPROPERTY()
    FText Title;
    
    UPROPERTY()
    FText Description;
};
