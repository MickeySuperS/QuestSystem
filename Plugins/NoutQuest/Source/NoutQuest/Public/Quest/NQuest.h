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
    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    FGameplayTag QuestID;
    
    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    FText Title;
    
    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    FText Description;
   
    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    TArray<struct FObjectiveData> Objectives;

    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UNQuestData> TemplateAsset;

    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    TObjectPtr<UObject> Owner;

protected:

    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    int32 CurrentObjectiveInstance = 0;

    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    bool bIsCompleted = false;

public:
	void InitializeInstance(UObject* InOwner, UNQuestData& QuestTemplate);
	bool IsInstanceInitialized() const { return IsValid(TemplateAsset); }
	UNQuestData* GetTemplateAsset() const { return TemplateAsset; }

    bool Evaluate();

    UFUNCTION(Category = "Quest", BlueprintCallable)
    bool IsCompleted() const;

};


/////////////////////// Completed Quests ////////////////////////

USTRUCT(BlueprintType)
struct NOUTQUEST_API FNQuestCompleted
{
	GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    FGameplayTag QuestID;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    FText Title;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    FText Description;
};
