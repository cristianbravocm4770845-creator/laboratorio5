// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puerta.generated.h"

UCLASS()
class NAVESUSFX_02_2026_API APuerta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuerta();

	UPROPERTY()
	class UStaticMeshComponent* mallaPuerta;	

	UPROPERTY()
	class UBoxComponent* zonaOverlap;

	UFUNCTION()
	void atravesar(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bNivelCompletado;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
