// Copyright MickeySuperS

#include "Conditions/NConditionBase.h"

#include "NQuestSubsystem.h"

//Engine
#include "GameplayTagContainer.h"
//

FText UNConditionBase::GetDisplayText_Implementation() const
{
    return FText::FromString("Invalid Condition!, Override GetDisplayText()");
}

bool UNConditionBase::EvaluateInternal_Implementation()
{
    return false;
}

bool UNConditionBase::Evaluate()
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