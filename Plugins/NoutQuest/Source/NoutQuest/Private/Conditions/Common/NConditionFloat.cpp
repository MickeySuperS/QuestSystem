// Copyright MickeySuperS

#include "Conditions/Common/NConditionFloat.h"


float UNConditionFloat::GetLeftHandSide_Implementation() const
{
    return 0.f;
}

bool UNConditionFloat::EvaluateInternal_Implementation() const
{
    const float Left = GetLeftHandSide();
    switch (Operator)
    {
    case ENumericalCheck::Equal:
        return Left == RightHandSide;
        break;
    case ENumericalCheck::NotEqual:
        return Left != RightHandSide;
        break;
    case ENumericalCheck::Less:
        return Left < RightHandSide;
        break;
    case ENumericalCheck::LessOrEqual:
        return Left <= RightHandSide;
        break;
    case ENumericalCheck::Greater:
        return Left > RightHandSide;
        break;
    case ENumericalCheck::GreaterOrEqual:
        return Left >= RightHandSide;
        break;
    default:
        ensureMsgf(false, TEXT("Unhandled operator %d"), Operator);
        return false;
        break;
    }
}
