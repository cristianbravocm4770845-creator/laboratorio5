// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshNave(TEXT("/Engine/BasicShapes/Cube.Cube"));

	mallaNave = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaNave"));
	mallaNave->SetStaticMesh(meshNave.Object);
	 
	RootComponent = mallaNave;	

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> materialAsset(TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
	if(materialAsset.Succeeded())
	{
		mallaNave->SetMaterial(0, materialAsset.Object);
	}

	materialDinamico = mallaNave->CreateDynamicMaterialInstance(0);
	if(materialDinamico != nullptr)
	{
		materialDinamico->SetVectorParameterValue("Color", FLinearColor::Green);
	}

	mallaNave->SetNotifyRigidBodyCollision(true);	
	mallaNave->OnComponentHit.AddDynamic(this, &APlataforma::Choque);
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlataforma::Choque(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Choque detectado con: %s"), *OtherActor->GetName());
	if(materialDinamico != nullptr)
	{
		materialDinamico->SetVectorParameterValue("Color", FLinearColor::Red);
	}
}	

