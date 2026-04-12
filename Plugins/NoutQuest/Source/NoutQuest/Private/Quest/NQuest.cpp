// Copyright MickeySuperS

#include "Quest/NQuest.h"
#include "Quest/NObjective.h"
#include "Conditions/NConditionBase.h"

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

    if (!Objectives[CurrentObjectiveInstance].IsCompleted())
    {
        return false;
    }

    if (Objectives.IsValidIndex(++CurrentObjectiveInstance))
    {
        bIsCompleted = true;
    }
    return bIsCompleted;
}

bool UNQuestInstance::IsCompleted() const
{
   return bIsCompleted;
}
