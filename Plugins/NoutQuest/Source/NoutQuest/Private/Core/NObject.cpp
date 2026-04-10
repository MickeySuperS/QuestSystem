// Copyright MickeySuperS

#include "Core/NObject.h"

UWorld* UNObject::GetWorld() const
{
	return HasAnyFlags(RF_ClassDefaultObject) ? nullptr : GetOuter()->GetWorld();
}
