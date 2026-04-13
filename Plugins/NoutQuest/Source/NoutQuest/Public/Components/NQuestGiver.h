// Copyright MickeySuperS

#pragma once


//Engine
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//

#include "NQuestGiver.generated.h"

class NQuestData;
class UNQuestInstance;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NOUTQUEST_API UNQuestGiver : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNQuestGiver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UNQuestData> QuestAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanReactivateQuest = false;

	UPROPERTY()
	TWeakObjectPtr<class UNQuestInstance> Instance;

public:
	UFUNCTION(BlueprintCallable)
	bool ActivateQuest();

	UFUNCTION(BlueprintCallable)
	bool IsRunning();

	UFUNCTION(BlueprintCallable)
	UNQuestInstance* GetInstance();

};
