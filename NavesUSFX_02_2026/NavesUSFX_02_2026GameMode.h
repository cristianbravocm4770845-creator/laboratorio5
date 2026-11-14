// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesUSFX_02_2026GameMode.generated.h"


class APlataforma;
class APuerta;


UCLASS(MinimalAPI)
class ANavesUSFX_02_2026GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesUSFX_02_2026GameMode();

protected:
	virtual void BeginPlay() override;


	UFUNCTION()
	void GenerarCaminos();

	UPROPERTY()
	TArray <APlataforma* > plataformas;

	UPROPERTY()
	TArray <APuerta* > puertas;

public:
	virtual void Tick(float DeltaTime) override;

};



