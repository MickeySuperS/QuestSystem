// Copyright MickeySuperS

#include "Quest/NObjective.h"
#include "Conditions/NConditionBase.h"

bool FObjectiveData::IsCompleted() const
{
    bool isCompleted = true;
    for (const TObjectPtr<UNConditionBase>& Condition : Conditions)
    {
        if (!IsValid(Condition))
        {
            continue;
        }
        isCompleted &= Condition->Evaluate();
    }
    return isCompleted;
}