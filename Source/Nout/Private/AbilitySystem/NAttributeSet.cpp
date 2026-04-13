// Copyright MickeySuperS

#include "Nout/Public/AbilitySystem/NAttributeSet.h"

//Engine
#include "Net/UnrealNetwork.h"
//

#include "Nout/Public/AbilitySystem/NAbilitySystemComponent.h"

class UWorld;

UNAttributeSet::UNAttributeSet()
    : Health(100.0f)
	, MaxHealth(100.0f)
    , BaseDamage(10.0f)
	, Currency(10.0f)
{
}

UWorld* UNAttributeSet::GetWorld() const
{
	const UObject* Outer = GetOuter();
	check(Outer);

	return Outer->GetWorld();
}

UNAbilitySystemComponent* UNAttributeSet::GetNAbilitySystemComponent() const
{
	return Cast<UNAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}

void UNAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UNAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNAttributeSet, BaseDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UNAttributeSet, Currency, COND_None, REPNOTIFY_Always);
}


void UNAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNAttributeSet, Health, OldValue);
}

void UNAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNAttributeSet, MaxHealth, OldValue);
}

void UNAttributeSet::OnRep_BaseDamage(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNAttributeSet, BaseDamage, OldValue);
}

void UNAttributeSet::OnRep_Currency(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UNAttributeSet, Currency, OldValue);
}
