// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX_02_2026GameMode.h"
#include "NavesUSFX_02_2026Pawn.h"
#include "Plataforma.h"
#include "Puerta.h"

ANavesUSFX_02_2026GameMode::ANavesUSFX_02_2026GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesUSFX_02_2026Pawn::StaticClass();
}

void ANavesUSFX_02_2026GameMode::BeginPlay()
{
	Super::BeginPlay();
	GenerarCaminos();

}

void ANavesUSFX_02_2026GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ANavesUSFX_02_2026GameMode::GenerarCaminos()
{
	const int32 CantidadPlataformas = 6;
	const float EspacioEntrePlataformas = 300.f;

	FVector PosicionActual = FVector(-430.0f, -10.0f, 280.0f);

		for (int32 i = 0; i < CantidadPlataformas; i++)
		{
			APlataforma* NuevaPlataforma = GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), PosicionActual, FRotator::ZeroRotator);

			if (NuevaPlataforma != nullptr)
			{
				plataformas.Add(NuevaPlataforma);
			}

			PosicionActual.X += EspacioEntrePlataformas;
		}

		APuerta* NuevaPuerta = GetWorld()->SpawnActor<APuerta>(APuerta::StaticClass(), PosicionActual, FRotator::ZeroRotator);

		if (NuevaPuerta != nullptr)
		{
			puertas.Add(NuevaPuerta);
		}

		UE_LOG(LogTemp, Warning, TEXT("Generadas %d plataformas y %d puertas"), plataformas.Num(), puertas.Num());
	
}
