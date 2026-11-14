// Fill out your copyright notice in the Description page of Project Settings.


#include "Puerta.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"	
#include "UObject/ConstructorHelpers.h"	
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

// Sets default values
APuerta::APuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bNivelCompletado = false;
	mallaPuerta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPuerta"));
	RootComponent = mallaPuerta;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshPuerta(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if(meshPuerta.Succeeded())
	{
		mallaPuerta->SetStaticMesh(meshPuerta.Object);
	}

	//para que no se me olvide el overlap
	mallaPuerta->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	zonaOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("ZonaOverlap"));
	zonaOverlap->SetupAttachment(RootComponent);
	zonaOverlap->SetBoxExtent(FVector(50.f, 50.f, 100.f));
	zonaOverlap->SetCollisionEnabled(ECollisionEnabled::QueryOnly);	
	zonaOverlap->SetCollisionResponseToAllChannels(ECR_Overlap);
	zonaOverlap->OnComponentBeginOverlap.AddDynamic(this, &APuerta::atravesar);

}

// Called when the game starts or when spawned
void APuerta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void APuerta::atravesar(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(bNivelCompletado)
	{
		return;
	}
	if(OtherActor && OtherActor->IsA(APawn::StaticClass()))
	{
		bNivelCompletado = true;
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Nivel Completado!"));
		}
		UE_LOG(LogTemp, Warning, TEXT("Nivel Completado!"));
	}
}

