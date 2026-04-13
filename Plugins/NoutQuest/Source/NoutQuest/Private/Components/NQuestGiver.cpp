// Copyright MickeySuperS

#include "Components/NQuestGiver.h"

#include "NQuestLog.h"
#include "NQuestSubsystem.h"

UNQuestGiver::UNQuestGiver()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UNQuestGiver::ActivateQuest()
{
	if (!IsValid(QuestAsset))
	{
		UE_LOG(LogNQuest, Error, TEXT("Failed to Activate Quest. Not assigned in : %s"), *GetOwner()->GetName());
		return false;
	}

	if (IsRunning())
	{
		return false;
	}

	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	UNQuestSubsystem* QuestSubsystem = GameInstance->GetSubsystem<UNQuestSubsystem>();

	FNQuestCompleted dummy;
	const bool QuestIsAlreadyCompleted = QuestSubsystem->FindQuestCompleted(QuestAsset->QuestID, dummy);
	if (QuestIsAlreadyCompleted && !CanReactivateQuest)
	{
		return false;
	}

	Instance = QuestSubsystem->CreateQuestInstance(GetOwner(), QuestAsset);
	if (Instance.IsValid())
	{
		QuestSubsystem->StartQuest(Instance.Get());
	}
    
	return true;
}

bool UNQuestGiver::IsRunning()
{
	if (!IsValid(QuestAsset) || !IsValid(Instance.Get()))
	{
		return false;
	}

	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	UNQuestSubsystem* QuestSubsystem = GameInstance->GetSubsystem<UNQuestSubsystem>();

	return IsValid(QuestSubsystem->FindQuest(QuestAsset->QuestID));
}

UNQuestInstance* UNQuestGiver::GetInstance()
{
    return Instance.Get();
}
