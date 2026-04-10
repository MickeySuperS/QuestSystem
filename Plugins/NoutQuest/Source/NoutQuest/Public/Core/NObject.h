// Copyright MickeySuperS

#pragma once

#include "CoreMinimal.h"
#include "NObject.generated.h"

UCLASS(Blueprintable)
class UNObject : public UObject
{
    GENERATED_BODY()
 
public:
	virtual UWorld* GetWorld() const override;

};
