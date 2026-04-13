// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "Conditions/NConditionBase.h"

#include "NConditionBool.generated.h"
 
UCLASS(Abstract, BlueprintType, meta = (Category = "Conditions", DisplayName = "Condition Bool"))
class NOUTQUEST_API UNConditionBool : public UNConditionBase
{
    GENERATED_BODY()

public:

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    bool RightHandSide = true;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    bool Invert = false;

    UFUNCTION(Category="Condition", BlueprintNativeEvent, BlueprintCallable)
    bool GetLeftHandSide() const;

	virtual bool EvaluateInternal_Implementation() const override;
};
