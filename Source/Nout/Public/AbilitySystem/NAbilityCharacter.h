// Copyright MickeySuperS

#include "CoreMinimal.h"

//Engine
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
//

#include "Nout/NoutCharacter.h"

#include "NAbilityCharacter.generated.h"

class UNAbilitySystemComponent;
class UNAttributeSet;


UCLASS()
class NOUT_API ANAbilityCharacter : public ANoutCharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:

    ANAbilityCharacter();

    virtual void BeginPlay() override;

    UAbilitySystemComponent* GetAbilitySystemComponent() const override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TObjectPtr<UNAbilitySystemComponent> AbilitySystemComponent;

    UPROPERTY()
	TObjectPtr<UNAttributeSet> AttributeSet;
};