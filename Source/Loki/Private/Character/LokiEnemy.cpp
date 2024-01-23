// Copyright Ludens Studio


#include "Character/LokiEnemy.h"

#include "AbilitySystem/LokiAbilitySystemComponent.h"
#include "AbilitySystem/LokiAttributeSet.h"
#include "Components/WidgetComponent.h"
#include "UI/Widget/LokiUserWidget.h"

ALokiEnemy::ALokiEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<ULokiAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<ULokiAttributeSet>(TEXT("AttributeSet"));

	HealthBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));
	HealthBar->SetupAttachment(GetRootComponent());
}

void ALokiEnemy::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();

	if (ULokiUserWidget* LokiUserWidget = Cast<ULokiUserWidget>(HealthBar->GetUserWidgetObject()))
	{
		LokiUserWidget->SetWidgetController(this);
	}

	if (const ULokiAttributeSet* LokiAttributeSet = CastChecked<ULokiAttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(LokiAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {
		OnHealthChanged.Broadcast(Data.NewValue);
		});

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(LokiAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data) {
		OnMaxHealthChanged.Broadcast(Data.NewValue);
		});

		// Broadcast initial values
		OnHealthChanged.Broadcast(LokiAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(LokiAttributeSet->GetMaxHealth());
	}
}

int32 ALokiEnemy::GetCharacterLevel()
{
	return Level;
}

void ALokiEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<ULokiAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

	InitializeDefaultAttributes();
}
