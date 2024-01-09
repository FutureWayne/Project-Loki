// Copyright Ludens Studio

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/LokiGameplayAbility.h"
#include "LokiProjectileSpell.generated.h"

class ALokiProjectile;
/**
 * 
 */
UCLASS()
class LOKI_API ULokiProjectileSpell : public ULokiGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable, Category = "Loki|Projectile")
	void SpawnProjectile();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ALokiProjectile> ProjectileClass;
};
