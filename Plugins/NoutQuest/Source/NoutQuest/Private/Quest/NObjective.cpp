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

        const bool oldCompletionState = Condition->IsCompleted();
        const bool newCompletionState = Condition->Evaluate();
  
        if (!oldCompletionState && newCompletionState)
        {
            //@@TODO(mickey): State change, Fire Delegate Condition Completed
        }

        isCompleted &= newCompletionState;
    }

    bIsCompleted = isCompleted;
    return isCompleted;
}

bool FObjectiveData::IsCompleted() const
{
    return bIsCompleted;
}