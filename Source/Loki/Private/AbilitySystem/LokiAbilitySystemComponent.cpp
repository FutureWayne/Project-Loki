// Copyright Ludens Studio


#include "AbilitySystem/LokiAbilitySystemComponent.h"

void ULokiAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ULokiAbilitySystemComponent::EffectApplied);
}

void ULokiAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* Source, const FGameplayEffectSpec& SpecApplied,
                                                FActiveGameplayEffectHandle ActiveHandle) const
{
	FGameplayTagContainer TagContainer;
	SpecApplied.GetAllAssetTags(TagContainer);
	OnEffectAssetTags.Broadcast(TagContainer);
}
