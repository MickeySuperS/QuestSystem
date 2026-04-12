// Copyright MickeySuperS

#pragma once

//--Engine Include
#include "CoreMinimal.h"
//--Engine Include

#include "NObject.generated.h"

UCLASS(Blueprintable)
class UNObject : public UObject
{
    GENERATED_BODY()
 
public:
	virtual UWorld* GetWorld() const override;

};
