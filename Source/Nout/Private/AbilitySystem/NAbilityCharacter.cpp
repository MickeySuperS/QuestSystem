// Copyright MickeySuperS

#include "Nout/Public/AbilitySystem/NAbilityCharacter.h"

#include "Nout/Public/AbilitySystem/NAbilitySystemComponent.h"
#include "Nout/Public/AbilitySystem/NAttributeSet.h"


ANAbilityCharacter::ANAbilityCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    AbilitySystemComponent = CreateDefaultSubobject<UNAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AttributeSet = CreateDefaultSubobject<UNAttributeSet>(TEXT("AttributeSet"));
}

void ANAbilityCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }
}

UAbilitySystemComponent* ANAbilityCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}
