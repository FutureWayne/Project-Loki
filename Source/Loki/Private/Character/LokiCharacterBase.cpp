// Copyright Ludens Studio


#include "Character/LokiCharacterBase.h"

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

