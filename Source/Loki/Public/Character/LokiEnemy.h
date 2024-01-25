// Copyright Ludens Studio

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "Character/LokiCharacterBase.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "LokiEnemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class LOKI_API ALokiEnemy : public ALokiCharacterBase
{
	GENERATED_BODY()

public:
	ALokiEnemy();

	virtual void BeginPlay() override;
	
	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	/** Combat Interface */
	virtual int32 GetCharacterLevel() override;
	
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealtChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealtChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintReadOnly, Category = "GAS|Attributes")
	bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category = "GAS|Attributes")
	float BaseWalkSpeed = 600.f;

protected:
	virtual void InitAbilityActorInfo() override;

	virtual void InitializeDefaultAttributes() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	ECharacterClass CharacterClass = ECharacterClass::Elementalist;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
