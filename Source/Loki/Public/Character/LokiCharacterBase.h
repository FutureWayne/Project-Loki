// Copyright Ludens Studio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LokiCharacterBase.generated.h"

UCLASS()
class LOKI_API ALokiCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALokiCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
