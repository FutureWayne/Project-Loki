// Copyright Ludens Studio


#include "AbilitySystem/LokiAbilitySystemLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/LokiPlayerState.h"
#include "UI/HUD/LokiHUD.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ULokiAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ALokiHUD* LokiHUD = Cast<ALokiHUD>(PlayerController->GetHUD()))
		{
			ALokiPlayerState* LokiPlayerState = PlayerController->GetPlayerState<ALokiPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = LokiPlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = LokiPlayerState->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PlayerController, LokiPlayerState, AbilitySystemComponent, AttributeSet);
			return LokiHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* ULokiAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ALokiHUD* LokiHUD = Cast<ALokiHUD>(PlayerController->GetHUD()))
		{
			ALokiPlayerState* LokiPlayerState = PlayerController->GetPlayerState<ALokiPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = LokiPlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = LokiPlayerState->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PlayerController, LokiPlayerState, AbilitySystemComponent, AttributeSet);
			return LokiHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
