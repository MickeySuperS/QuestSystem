// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "Conditions/NConditionBase.h"

#include "NConditionFloat.generated.h"

// Copied from AIModule::EGenericAICheck
UENUM()
enum class ENOperation : uint8
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

UENUM()
enum class ENPolicy : uint8
{
	None, 			// None
	Accumulative,	// Based on current. So, if total jumps is 40 and condition is 5 jumps we count 40 to 45

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

	UPROPERTY()
	float CacheCurrent = 0;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
    ENOperation Operator = ENOperation::Equal;

    UPROPERTY(Category="Default", EditAnywhere, BlueprintReadWrite)
	ENPolicy Policy = ENPolicy::None;

	UFUNCTION(Category="Condition", BlueprintNativeEvent, BlueprintCallable)
    float EvaluateLeftHandSide() const;

    UFUNCTION(Category="Condition", BlueprintCallable)
    float GetLeftHandSide() const { return LeftHandSide; }

	virtual void InitCondition_Implementation() override;

	virtual bool EvaluateInternal_Implementation() override;

	virtual FText GetDisplayText_Implementation() const override;
};
