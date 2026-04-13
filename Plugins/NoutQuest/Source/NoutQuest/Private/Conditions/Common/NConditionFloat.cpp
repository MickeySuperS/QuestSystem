// Copyright MickeySuperS

#include "Conditions/Common/NConditionFloat.h"


void UNConditionFloat::InitCondition_Implementation()
{
    if (Policy == ENPolicy::Accumulative)
    {
        CacheCurrent = EvaluateLeftHandSide();
    }
}

float UNConditionFloat::EvaluateLeftHandSide_Implementation() const
{
    return 0.f;
}

bool UNConditionFloat::EvaluateInternal_Implementation()
{
    const float oldLeftHandSide = LeftHandSide;
    LeftHandSide = EvaluateLeftHandSide() - CacheCurrent;
    if (oldLeftHandSide != LeftHandSide)
    {
        CallOnConditionStateChanged();
    }
    switch (Operator)
    {
    case ENOperation::Equal:
        return LeftHandSide == RightHandSide;
        break;
    case ENOperation::NotEqual:
        return LeftHandSide != RightHandSide;
        break;
    case ENOperation::Less:
        return LeftHandSide < RightHandSide;
        break;
    case ENOperation::LessOrEqual:
        return LeftHandSide <= RightHandSide;
        break;
    case ENOperation::Greater:
        return LeftHandSide > RightHandSide;
        break;
    case ENOperation::GreaterOrEqual:
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
