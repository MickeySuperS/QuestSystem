// Copyright MickeySuperS

#include "NQuestSubsystem.h"

#include "Quest/NQuest.h"
#include "NQuestLog.h"
#include "Rewards/NRewardBase.h"

UNQuestInstance *UNQuestSubsystem::CreateQuestInstance(UObject* Owner, UNQuestData *QuestAsset)
{
    if (!IsValid(QuestAsset) || !QuestAsset->QuestID.IsValid())
    {
        //@@TODO(mickey): Get Asset Name
        UE_LOG(LogNQuest, Log, TEXT("Failed to Create Quest: %s"), *QuestAsset->Title.ToString());
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

    UE_LOG(LogNQuest, Log, TEXT("Starting Quest: %s"), *Quest->Title.ToString());
}

bool UNQuestSubsystem::FinishQuest(const UNQuestInstance* Quest)
{
    for (const TObjectPtr<class UNRewardBase>& Reward : Quest->TemplateAsset->Rewards)
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

    UE_LOG(LogNQuest, Log, TEXT("Completed Quest: %s"), *Quest->Title.ToString());

    return true;
}

void UNQuestSubsystem::EvaluateQuests()
{
    for (auto It = ActiveQuests.CreateIterator(); It; ++It)
    {
        UNQuestInstance* Quest = *It;

        if (!IsValid(Quest))
        {
            It.RemoveCurrent();
            continue;
        }

        Quest->Evaluate();

        if (Quest->IsCompleted())
        {
            FinishQuest(Quest);
            ActiveQuestsMap.Remove(Quest->QuestID);
            It.RemoveCurrent();
            continue;
        }
    }
}
