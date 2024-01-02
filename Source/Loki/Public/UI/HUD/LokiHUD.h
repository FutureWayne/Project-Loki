// Copyright Ludens Studio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LokiHUD.generated.h"

struct FWidgetControllerParams;
class UAttributeSet;
class UAbilitySystemComponent;
class ULokiUserWidget;
class UOverlayWidgetController;

/**
 * 
 */
UCLASS()
class LOKI_API ALokiHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ULokiUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ULokiUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
