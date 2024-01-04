// Copyright Ludens Studio

#pragma once

#include "CoreMinimal.h"
#include "Character/LokiCharacterBase.h"
#include "LokiEnemy.generated.h"

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

protected:
	virtual void InitAbilityActorInfo() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 Level = 1;
};
