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

    UPROPERTY()
    bool LeftHandSide = true;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    bool RightHandSide = true;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    bool Invert = false;

    UFUNCTION(Category="Condition", BlueprintNativeEvent, BlueprintCallable)
    bool EvaluateLeftHandSide() const;

    UFUNCTION(Category="Condition", BlueprintCallable)
    bool GetLeftHandSide() const { return LeftHandSide; }

	virtual bool EvaluateInternal_Implementation() override;

    virtual FText GetDisplayText_Implementation() const override;
};
