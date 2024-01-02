// Copyright Ludens Studio


#include "Character/LokiEnemy.h"

#include "AbilitySystem/LokiAbilitySystemComponent.h"
#include "AbilitySystem/LokiAttributeSet.h"

ALokiEnemy::ALokiEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<ULokiAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<ULokiAttributeSet>(TEXT("AttributeSet"));
}

void ALokiEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
