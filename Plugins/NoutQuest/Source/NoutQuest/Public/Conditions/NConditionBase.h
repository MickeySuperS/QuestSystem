// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "Core/NObject.h"

#include "NConditionBase.generated.h"

UCLASS(Abstract, BlueprintType, EditinlineNew, meta = (Category = "Conditions", DisplayName = "Condition Base"))
class NOUTQUEST_API UNConditionBase : public UNObject
{
    GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
    // Editor Only Designer Description
    UPROPERTY(Category="Default", EditInstanceOnly, meta = (DisplayPriority="1"))
    FString DesignerDescription;
#endif

    UFUNCTION(Category="Condition", BlueprintNativeEvent, BlueprintCallable)
    bool Evaluate() const;
};