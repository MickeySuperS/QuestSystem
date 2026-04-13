// Copyright MickeySuperS

#include "Quest/NObjective.h"

#include "Conditions/NConditionBase.h"

bool FObjectiveData::Evaluate()
{
    if (bIsCompleted)
    {
        return true;
    }

    bool isCompleted = true;
    for (const TObjectPtr<UNConditionBase>& Condition : Conditions)
    {
        if (!IsValid(Condition))
        {
            continue;
        }

        isCompleted &= Condition->Evaluate();
    }

    bIsCompleted = isCompleted;
    return isCompleted;
}

bool FObjectiveData::IsCompleted() const
{
    return bIsCompleted;
}