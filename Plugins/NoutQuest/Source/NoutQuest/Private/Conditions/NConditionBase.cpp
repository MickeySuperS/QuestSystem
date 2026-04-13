// Copyright MickeySuperS

#include "Conditions/NConditionBase.h"

bool UNConditionBase::EvaluateInternal_Implementation() const
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
    return bIsCompleted;
}

bool UNConditionBase::IsCompleted() const
{
    return bIsCompleted;
}