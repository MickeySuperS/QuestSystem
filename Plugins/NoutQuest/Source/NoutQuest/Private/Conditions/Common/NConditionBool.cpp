// Copyright MickeySuperS

#include "Conditions/Common/NConditionBool.h"


bool UNConditionBool::EvaluateLeftHandSide_Implementation() const
{
    return true;
}

bool UNConditionBool::EvaluateInternal_Implementation()
{
    LeftHandSide = EvaluateLeftHandSide();
    const bool EvaluationCondition = LeftHandSide == RightHandSide;
    return Invert ? !EvaluationCondition : EvaluationCondition;
}

FText UNConditionBool::GetDisplayText_Implementation() const
{
    return Super::GetDisplayText_Implementation();
}