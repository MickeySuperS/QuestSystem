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

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Title;

    //UPROPERTY(EditAnywhere, meta = (BaseStruct = "/Script/NoutQuest.NConditoinBase", ExcludeBaseStruct))
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, meta = (TitleProperty = "DesignerDescription"))
    TArray<TObjectPtr<class UNConditionBase>> Conditions;

    bool IsCompleted() const;
};
