// Copyright Ludens Studio


#include "AbilitySystem/Abilities/LokiProjectileSpell.h"

#include "Kismet/KismetSystemLibrary.h"

void ULokiProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UKismetSystemLibrary::PrintString(this, "Projectile Spell Activated", true, true, FLinearColor::Red, 5.f);
}
