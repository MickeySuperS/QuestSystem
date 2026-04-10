// Copyright MickeySuperS

#pragma once

#include "Engine/DataAsset.h"

//Engine
#include "StructUtils/InstancedStruct.h"
//

#include "NQuestData.generated.h"

class UNConditionBase;

UCLASS(BlueprintType)
class NOUTQUEST_API UQuestData : public UDataAsset
{
	GENERATED_BODY()

public:
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    //UPROPERTY(EditAnywhere, meta = (BaseStruct = "/Script/NoutQuest.NConditoinBase", ExcludeBaseStruct))
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, meta = (TitleProperty = "DesignerDescription"))
    TArray<TObjectPtr<class UNConditionBase>> Objectives;
};