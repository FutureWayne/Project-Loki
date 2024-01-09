// Copyright Ludens Studio


#include "AbilitySystem/Abilities/LokiProjectileSpell.h"

#include "Actor/LokiProjectile.h"
#include "Camera/CameraComponent.h"
#include "Character/LokiPlayer.h"
#include "GameFramework/Character.h"
#include "Interaction/CombatInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void ULokiProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UKismetSystemLibrary::PrintString(this, "Projectile Spell Activated", true, true, FLinearColor::Red, 5.f);

	if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo()))
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		const FVector AimLocation = CombatInterface->GetCombatAimLocation();
		const FRotator AimRotation = UKismetMathLibrary::FindLookAtRotation(SocketLocation, AimLocation);
		
		// Create a transform with the muzzle location and the aim rotation
		FTransform SpawnTransform(AimRotation, SocketLocation);
		
		ALokiProjectile* Projectile = GetWorld()->SpawnActorDeferred<ALokiProjectile>(
			ProjectileClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		if (Projectile)
		{
			//TODO: Give the Projectile a Gameplay Effect Spec for causing Damage.

			// Complete the spawn after setting up initial conditions
			Projectile->FinishSpawning(SpawnTransform);
		}

		// Debug: Draw a line from the muzzle in the direction the camera is facing
		FVector Start = SocketLocation;
		FVector End = AimLocation;

		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		ACharacter* Character = Cast<ACharacter>(GetAvatarActorFromActorInfo());
		CollisionParams.AddIgnoredActor(Character); // Ignore the player character in the line trace

		bool bHit = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			Start,
			End,
			ECC_Visibility, // Change this to the appropriate collision channel
			CollisionParams
		);

		// Draw a debug line
		DrawDebugLine(
			GetWorld(),
			Start,
			End,
			FColor::Red, // Line color
			false, // Persistent (remains after one frame)
			5.0f, // Duration of line display
			0, // Depth priority
			1.0f // Line thickness
		);

		// If the line trace hits something, draw a debug sphere at the hit location
		if (bHit)
		{
			DrawDebugSphere(
				GetWorld(),
				HitResult.Location,
				25.0f, // Sphere radius
				32, // Sphere segments
				FColor::Blue, // Sphere color
				false, // Persistent (remains after one frame)
				5.0f, // Duration of sphere display
				0, // Depth priority
				1.0f // Line thickness
			);
		}
	}
}
