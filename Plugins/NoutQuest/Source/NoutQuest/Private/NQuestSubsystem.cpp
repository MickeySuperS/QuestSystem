// Copyright MickeySuperS

#include "NQuestSubsystem.h"

#include "Quest/NQuest.h"
#include "NQuestLog.h"
#include "Rewards/NRewardBase.h"

//Engine
#include "GameplayTagsManager.h"
//

UNQuestInstance *UNQuestSubsystem::CreateQuestInstance(UObject* Owner, UNQuestData *QuestAsset)
{
    if (!IsValid(QuestAsset) || !QuestAsset->QuestID.IsValid() || ActiveQuestsMap.Contains(QuestAsset->QuestID))
    {
        //@@TODO(mickey): Get Asset Name
        UE_LOG(LogNQuest, Error, TEXT("Failed to Create Quest: %s"), *QuestAsset->Title.ToString());
        return nullptr;
    }

    UNQuestInstance* NewInstance = NewObject<UNQuestInstance>(this);
	NewInstance->InitializeInstance(Owner, *QuestAsset);

    return NewInstance;
}

void UNQuestSubsystem::StartQuest(UNQuestInstance* Quest)
{
    if (!IsValid(Quest) || !Quest->QuestID.IsValid())
    {
        return;
    }

    ActiveQuests.Emplace(Quest);
    ActiveQuestsMap.Add(Quest->QuestID, Quest);

    OnQuestCreated.Broadcast(Quest->QuestID);
    UE_LOG(LogNQuest, Log, TEXT("Starting Quest: %s"), *Quest->Title.ToString());
}

bool UNQuestSubsystem::FinishQuest(const UNQuestInstance* Quest)
{
    for (const TObjectPtr<class UNRewardBase>& Reward : Quest->Rewards)
    {
        if (!IsValid(Reward)) { continue; }

        Reward->GiveReward(Quest->Owner);
    }

    CompletedQuests.Emplace(
        FNQuestCompleted{
            Quest->QuestID,
            Quest->Title,
            Quest->Description
        }
    );

    OnQuestCompleted.Broadcast(Quest->QuestID);
    UE_LOG(LogNQuest, Log, TEXT("Completed Quest: %s"), *Quest->Title.ToString());

    return true;
}

void UNQuestSubsystem::EvaluateQuests()
{
    for (int32 i = ActiveQuests.Num() - 1; i >= 0; --i)
    {
        UNQuestInstance* Quest = ActiveQuests[i];

        if (!IsValid(Quest))
        {
            ActiveQuests.RemoveAtSwap(i);
            continue;
        }

        Quest->Evaluate();

        if (Quest->IsCompleted())
        {
            FinishQuest(Quest);
            ActiveQuestsMap.Remove(Quest->QuestID);
            ActiveQuests.RemoveAtSwap(i);
            continue;
        }
    }
}

UNQuestInstance* UNQuestSubsystem::FindQuest(FGameplayTag Tag)
{
    if (ActiveQuestsMap.Contains(Tag))
    {
        return ActiveQuestsMap[Tag];
    }
    return nullptr;
}

bool UNQuestSubsystem::FindQuestCompleted(FGameplayTag Tag, FNQuestCompleted& OutQuest)
{
    for(const FNQuestCompleted& quest : CompletedQuests)
    {
        if (quest.QuestID == Tag)
        {
            OutQuest = quest;
            return true;
        }
    }
    return false;
}