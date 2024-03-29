// Copyright Ludens Studio

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LOKI_API ICombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual int32 GetCharacterLevel();

	virtual FVector GetCombatSocketLocation();
	
	virtual FVector GetCombatAimLocation();
	
	virtual void UpdateFacingTarget(const FVector& TargetLocation);

	virtual void Die() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	UAnimMontage* GetHitReactMontage() const;
};
