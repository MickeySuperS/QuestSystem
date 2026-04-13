// Copyright MickeySuperS

#pragma once

//Engine
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
//

#include "Quest/NQuest.h"

#include "NQuestSubsystem.generated.h"

//Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FQuestEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaggedQuestEvent, const FGameplayTag&, QuestTags);


UCLASS()
class NOUTQUEST_API UNQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UNQuestSubsystem() {};

protected:
	UPROPERTY()
	TArray<TObjectPtr<UNQuestInstance>> ActiveQuests;

	UPROPERTY()
	TMap<FGameplayTag, TObjectPtr<UNQuestInstance>> ActiveQuestsMap;

	UPROPERTY()
	TArray<FNQuestCompleted> CompletedQuests;

public:
	UPROPERTY(Category = "Quest", BlueprintAssignable)
	FTaggedQuestEvent OnQuestCreated;

	UPROPERTY(Category = "Quest", BlueprintAssignable)
	FTaggedQuestEvent OnQuestCompleted;

	UPROPERTY(Category = "Quest", BlueprintAssignable)
	FTaggedQuestEvent OnObjectiveCompleted;

	UPROPERTY(Category = "Quest", BlueprintAssignable)
	FTaggedQuestEvent OnConditionCompleted;

public:
    UFUNCTION(Category = "Quest", BlueprintCallable)
    UNQuestInstance* CreateQuestInstance(UObject* Owner, UNQuestData* QuestAsset);

	UFUNCTION(Category = "Quest", BlueprintCallable)
    void StartQuest(UNQuestInstance* Quest);

	UFUNCTION(Category = "Quest", BlueprintCallable)
    bool FinishQuest(const UNQuestInstance* Quest);

	UFUNCTION(Category = "Quest", BlueprintCallable)
    void EvaluateQuests();

	UFUNCTION(Category = "Quest", BlueprintCallable)
    UNQuestInstance* FindQuest(FGameplayTag Tag);
};
