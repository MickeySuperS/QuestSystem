// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "Engine/DataAsset.h"
#include "StructUtils/InstancedStruct.h"
//--Engine Include

#include "NObjective.generated.h"

class UNConditionBase;

USTRUCT(BlueprintType)
struct NOUTQUEST_API FObjectiveData
{
    GENERATED_BODY()

    UPROPERTY(Category = "Quest", EditAnywhere, BlueprintReadOnly)
    FText Title;

    //UPROPERTY(EditAnywhere, meta = (BaseStruct = "/Script/NoutQuest.NConditoinBase", ExcludeBaseStruct))
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, meta = (TitleProperty = "DesignerDescription"))
    TArray<TObjectPtr<class UNConditionBase>> Conditions;

    UPROPERTY(Category = "Quest", BlueprintReadOnly, VisibleAnywhere)
    bool bIsCompleted = false;

public:

    bool Evaluate();
    bool IsCompleted() const;

};
