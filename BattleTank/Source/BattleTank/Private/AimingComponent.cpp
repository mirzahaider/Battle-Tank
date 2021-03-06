// Fill out your copyright notice in the Description page of Project Settings.


#include "AimingComponent.h"

// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	FString TankName = GetOwner()->GetName();
	FVector TankTowerPosition = TankTowerMesh->GetComponentLocation();
	FVector OutLaunchVelocity;

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,

	)) {

	}

	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *TankName, *HitLocation.ToString(), *TankTowerPosition.ToString())
}

void UAimingComponent::SetTankTowerMesh(UStaticMeshComponent *Mesh)
{
	TankTowerMesh = Mesh;
}