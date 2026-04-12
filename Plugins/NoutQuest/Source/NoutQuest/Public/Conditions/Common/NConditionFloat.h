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
    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    float RightHandSide = 0.f;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    ENumericalCheck Operator = ENumericalCheck::Equal;

    UFUNCTION(Category="Condition", BlueprintNativeEvent, BlueprintCallable)
    float GetLeftHandSide() const;

	virtual bool Evaluate_Implementation() const override;
};
