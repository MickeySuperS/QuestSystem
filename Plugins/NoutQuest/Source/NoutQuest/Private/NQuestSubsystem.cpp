// Copyright MickeySuperS

#include "NQuestSubsystem.h"

#include "Quest/NQuest.h"
#include "NQuestLog.h"

UNQuestInstance *UNQuestSubsystem::CreateQuestInstance(UObject* Owner, UNQuestData *QuestAsset)
{
    UNQuestInstance* NewInstance = NewObject<UNQuestInstance>(this);
	NewInstance->InitializeInstance(Owner, *QuestAsset);

    return NewInstance;
}

void UNQuestSubsystem::StartQuest(UNQuestInstance* Quest)
{
    if (!IsValid(Quest))
    {
        return;
    }

    ActiveQuests.Emplace(Quest);

    if (Quest->QuestID.IsValid())
    {
        ActiveSpecialQuests.Add(Quest->QuestID, Quest);
    }

    UE_LOG(LogNQuest, Log, TEXT("Starting Quest: %s"), *Quest->Title.ToString());
}

bool UNQuestSubsystem::FinishQuest(const UNQuestInstance* Quest)
{
    //@@TODO(mickey): Give Rewards

    CompletedQuests.Emplace(
        FNQuestCompleted{
            Quest->QuestID,
            Quest->Title,
            Quest->Description
        }
    );

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

        if (Quest->IsCompleted())
        {
            It.RemoveCurrent();
            FinishQuest(Quest);
            continue;
        }
    }
}
