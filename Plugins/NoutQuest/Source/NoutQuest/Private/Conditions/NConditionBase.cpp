// Copyright MickeySuperS

#include "Conditions/NConditionBase.h"

#include "NQuestSubsystem.h"

//Engine
#include "GameplayTagContainer.h"
//

bool UNConditionBase::EvaluateInternal_Implementation() const
{
    return false;
}

bool UNConditionBase::Evaluate(FGameplayTag QuestID)
{
    if (bIsCompleted)
    {
        return true;
    }

    bIsCompleted = EvaluateInternal();
    if (bIsCompleted)
    {
        // Fire Condition Delegate
        if (UGameInstance* GameInstance = GetWorld()->GetGameInstance())
        {
            UNQuestSubsystem* QuestSubsystem = GameInstance->GetSubsystem<UNQuestSubsystem>();
            QuestSubsystem->OnConditionCompleted.Broadcast(QuestID);
        }
    }

    return bIsCompleted;
}

bool UNConditionBase::IsCompleted() const
{
    return bIsCompleted;
}