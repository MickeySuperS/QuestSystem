// Copyright MickeySuperS

#include "Quest/NQuest.h"
#include "Quest/NObjective.h"
#include "Conditions/NConditionBase.h"
#include "NQuestLog.h"

/////////////////////// NQuestInstance ////////////////////////

void UNQuestInstance::InitializeInstance(UObject* InOwner, UNQuestData& QuestTemplate)
{
    Owner = InOwner;
    TemplateAsset = &QuestTemplate;

    QuestID = QuestTemplate.QuestID;
    Title = QuestTemplate.Title;
    Description = QuestTemplate.Description;
    CurrentObjectiveInstance = 0;
    bIsCompleted = false;

    for (const FObjectiveData& ObjectiveTemplate : QuestTemplate.Objectives)
    {
        FObjectiveData NewObjective;
        NewObjective.Title = ObjectiveTemplate.Title;

        for (const TObjectPtr<UNConditionBase>& Condition : ObjectiveTemplate.Conditions)
        {
            if (IsValid(Condition))
            {
                UNConditionBase* NewCondition = DuplicateObject<UNConditionBase>(
                    Condition,
                    this
                );

                NewObjective.Conditions.Add(NewCondition);
            }
        }

        Objectives.Add(NewObjective);
    }
}

bool UNQuestInstance::Evaluate()
{
    if (bIsCompleted)
    {
        return true;
    }

    if (Objectives.IsEmpty())
    {
         bIsCompleted = true;
         return true;
    }

    if (!Objectives[CurrentObjectiveInstance].IsCompleted())
    {
        return false;
    }

    UE_LOG(LogNQuest, Log, TEXT("Objective Completed: %s for Quest: %s"), 
        *Objectives[CurrentObjectiveInstance].Title.ToString(), 
        *Title.ToString());

    if (!Objectives.IsValidIndex(++CurrentObjectiveInstance))
    {
        bIsCompleted = true;
    }
    return bIsCompleted;
}

bool UNQuestInstance::IsCompleted() const
{
   return bIsCompleted;
}
