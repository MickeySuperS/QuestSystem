// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "Conditions/NConditionBase.h"

#include "NConditionBool.generated.h"
 
UENUM(BlueprintType)
enum class ENBoolOperation : uint8
{
    EQUAL       UMETA(DisplayName = "Equal"),
    NOTEQUAL    UMETA(DisplayName = "Not Equal"),
};

UCLASS(BlueprintType, meta = (Category = "Conditions", DisplayName = "Condition Bool"))
class NOUTQUEST_API UNConditionBool : public UNConditionBase
{
    GENERATED_BODY()

public:
    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    bool LeftHandSide = false;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    bool RightHandSide = false;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    ENBoolOperation BoolOperation = ENBoolOperation::EQUAL;

	virtual bool Evaluate_Implementation() const override { return true; }
};
