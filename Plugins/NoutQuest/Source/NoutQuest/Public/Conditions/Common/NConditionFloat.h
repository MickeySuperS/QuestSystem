// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "Conditions/NConditionBase.h"

#include "NConditionFloat.generated.h"

// Copied from AIModule::EGenericAICheck
UENUM()
enum class ENumericalCheck : uint8
{
	Less,
	LessOrEqual,
	Equal,
	NotEqual,
	GreaterOrEqual,
	Greater,
	IsTrue,

	MAX UMETA(Hidden)
};
 
UCLASS(Abstract, BlueprintType, meta = (Category = "Conditions", DisplayName = "Condition Numerical"))
class NOUTQUEST_API UNConditionFloat : public UNConditionBase
{
    GENERATED_BODY()

public:

    UPROPERTY()
	float LeftHandSide = 0.f;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    float RightHandSide = 0.f;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    ENumericalCheck Operator = ENumericalCheck::Equal;

	UFUNCTION(Category="Condition", BlueprintNativeEvent, BlueprintCallable)
    float EvaluateLeftHandSide() const;

    UFUNCTION(Category="Condition", BlueprintCallable)
    float GetLeftHandSide() const { return LeftHandSide; }

	virtual bool EvaluateInternal_Implementation() override;

	virtual FText GetDisplayText_Implementation() const override;
};
