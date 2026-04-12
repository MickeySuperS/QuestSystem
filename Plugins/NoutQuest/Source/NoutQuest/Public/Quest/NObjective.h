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

#if WITH_EDITORONLY_DATA
    // Editor Only Designer Description
    UPROPERTY(Category="Default", EditInstanceOnly, meta = (DisplayPriority="1"))
    FString ObjectiveDesignerDescription;
#endif

    //UPROPERTY(EditAnywhere, meta = (BaseStruct = "/Script/NoutQuest.NConditoinBase", ExcludeBaseStruct))
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, meta = (TitleProperty = "DesignerDescription"))
    TArray<TObjectPtr<class UNConditionBase>> Conditions;

    bool IsCompleted() const;
};
