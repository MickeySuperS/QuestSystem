// Copyright MickeySuperS

#include "Conditions/Common/NConditionBool.h"

bool UNConditionBool::GetLeftHandSide_Implementation() const
{
    return true;
}

bool UNConditionBool::Evaluate_Implementation() const
{
    const bool EvaluationCondition = GetLeftHandSide() == RightHandSide;
    return Invert ? !EvaluationCondition : EvaluationCondition;
}