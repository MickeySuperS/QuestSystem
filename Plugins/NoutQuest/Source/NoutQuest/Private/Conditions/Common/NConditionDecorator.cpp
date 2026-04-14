// Copyright MickeySuperS

#include "Conditions/Common/NConditionDecorator.h"


bool UNConditionDecorator::EvaluateInternal_Implementation()
{
    return IsValid(Condition) ? Condition->EvaluateInternal() : false;
}

FText UNConditionDecorator::GetDisplayText_Implementation() const
{
    return DisplayText;
}