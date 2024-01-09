// Copyright Ludens Studio


#include "Character/LokiCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/LokiAbilitySystemComponent.h"

// Sets default values
ALokiCharacterBase::ALokiCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ALokiCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ALokiCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ALokiCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> EffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(EffectClass);
	
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(EffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ALokiCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1);
	ApplyEffectToSelf(DefaultVitalAttributes, 1);
}

void ALokiCharacterBase::AddCharacterAbilities()
{
	ULokiAbilitySystemComponent* LokiAbilitySystemComponent = CastChecked<ULokiAbilitySystemComponent>(GetAbilitySystemComponent());

	LokiAbilitySystemComponent->AddCharacterAbilities(StartupAbilities);
}

FVector ALokiCharacterBase::GetCombatSocketLocation()
{
	return GetMesh()->GetSocketLocation(WeaponTipSocketName);
}

FVector ALokiCharacterBase::GetCombatAimLocation()
{
	return ICombatInterface::GetCombatAimLocation();
}
