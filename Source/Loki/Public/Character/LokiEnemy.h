// Copyright Ludens Studio

#pragma once

#include "CoreMinimal.h"
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

	/** Combat Interface */
	virtual int32 GetCharacterLevel() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealtChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealtChangedSignature OnMaxHealthChanged;

protected:
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
