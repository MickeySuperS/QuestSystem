// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "Conditions/NConditionBase.h"

#include "NConditionDecorator.generated.h"
 
UCLASS(BlueprintType, meta = (Category = "Conditions", DisplayName = "Condition Decorator"))
class NOUTQUEST_API UNConditionDecorator : public UNConditionBase
{
    GENERATED_BODY()

public:

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    FText DisplayText;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite, Instanced)
    TObjectPtr<UNConditionBase> Condition;

	virtual bool EvaluateInternal_Implementation() override;

    virtual FText GetDisplayText_Implementation() const override;
};
