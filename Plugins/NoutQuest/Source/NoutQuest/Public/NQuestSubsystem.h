// Copyright MickeySuperS

//Engine
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
//

#include "NQuestSubsystem.generated.h"

//Delegates


class UNQuestData;
class UNQuestInstance;
struct FNQuestCompleted;

UCLASS()
class NOUTQUEST_API UNQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UNQuestSubsystem() {};

protected:
	UPROPERTY()
	TSet<TObjectPtr<UNQuestInstance>> ActiveQuests;

	UPROPERTY()
	TMap<FGameplayTag, TObjectPtr<UNQuestInstance>> ActiveQuestsMap;

	UPROPERTY()
	TArray<FNQuestCompleted> CompletedQuests;

public:
    UFUNCTION(Category = "Quest", BlueprintCallable)
    UNQuestInstance* CreateQuestInstance(UObject* Owner, UNQuestData* QuestAsset);

	UFUNCTION(Category = "Quest", BlueprintCallable)
    void StartQuest(UNQuestInstance* Quest);

	UFUNCTION(Category = "Quest", BlueprintCallable)
    bool FinishQuest(const UNQuestInstance* Quest);

	UFUNCTION(Category = "Quest", BlueprintCallable)
    void EvaluateQuests();
};
