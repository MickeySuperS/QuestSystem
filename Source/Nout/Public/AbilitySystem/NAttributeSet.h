// Copyright MickeySuperS

#pragma once

//Engine
#include "CoreMinimal.h"
#include "AttributeSet.h"

//
#include "Nout/Public/AbilitySystem/NAbilitySystemComponent.h"

#include "NAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeEvent, float, EffectMagnitude, float, NewValue);

class UNAbilitySystemComponent;

UCLASS(BlueprintType)
class NOUT_API UNAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

    UNAttributeSet();

	UWorld* GetWorld() const override;
	class UNAbilitySystemComponent* GetNAbilitySystemComponent() const;


    ATTRIBUTE_ACCESSORS(UNAttributeSet, Health);
    ATTRIBUTE_ACCESSORS(UNAttributeSet, MaxHealth);
    ATTRIBUTE_ACCESSORS(UNAttributeSet, BaseDamage);

    ATTRIBUTE_ACCESSORS(UNAttributeSet, Currency);

protected:

    UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

    UFUNCTION()
	void OnRep_BaseDamage(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Currency(const FGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BaseDamage, Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData BaseDamage;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Currency, Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Currency;
};