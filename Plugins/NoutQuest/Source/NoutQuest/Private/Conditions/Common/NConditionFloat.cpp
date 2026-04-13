// Copyright MickeySuperS

#include "Conditions/Common/NConditionFloat.h"


float UNConditionFloat::EvaluateLeftHandSide_Implementation() const
{
    return 0.f;
}

bool UNConditionFloat::EvaluateInternal_Implementation()
{
    LeftHandSide = EvaluateLeftHandSide();
    switch (Operator)
    {
    case ENumericalCheck::Equal:
        return LeftHandSide == RightHandSide;
        break;
    case ENumericalCheck::NotEqual:
        return LeftHandSide != RightHandSide;
        break;
    case ENumericalCheck::Less:
        return LeftHandSide < RightHandSide;
        break;
    case ENumericalCheck::LessOrEqual:
        return LeftHandSide <= RightHandSide;
        break;
    case ENumericalCheck::Greater:
        return LeftHandSide > RightHandSide;
        break;
    case ENumericalCheck::GreaterOrEqual:
        return LeftHandSide >= RightHandSide;
        break;
    default:
        ensureMsgf(false, TEXT("Unhandled operator %d"), Operator);
        return false;
        break;
    }
}

FText UNConditionFloat::GetDisplayText_Implementation() const
{
    return Super::GetDisplayText_Implementation();
}
