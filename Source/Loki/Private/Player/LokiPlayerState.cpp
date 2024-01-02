// Copyright Ludens Studio


#include "Player/LokiPlayerState.h"

#include "AbilitySystem/LokiAbilitySystemComponent.h"

ALokiPlayerState::ALokiPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<ULokiAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ALokiPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
