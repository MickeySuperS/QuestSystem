// Copyright Epic Games, Inc. All Rights Reserved.

#include "NoutQuest.h"

//Engine
#include "Interfaces/IPluginManager.h"
#include "GameplayTagsManager.h"
//

#define LOCTEXT_NAMESPACE "FNoutQuestModule"

void FNoutQuestModule::StartupModule()
{
	//https://github.com/tranek/GASDocumentation/issues/125
	TSharedPtr<IPlugin> ThisPlugin = IPluginManager::Get().FindPlugin(TEXT("NoutQuest"));
	check(ThisPlugin.IsValid());
	
	UGameplayTagsManager::Get().AddTagIniSearchPath(ThisPlugin->GetBaseDir() / TEXT("Config") / TEXT("Tags"));
}

void FNoutQuestModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNoutQuestModule, NoutQuest)