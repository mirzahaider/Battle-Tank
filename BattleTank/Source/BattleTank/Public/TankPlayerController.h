// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	FVector GetReticleHitLocation();

private:
	// Given ReticleDirection, do LineTrace and set OutLocation to a visible hitting object
	bool GetLineTraceResult(FVector &OutLocation, FVector ReticleDirection);
	
	// Controlled Tank
	ATank *Tank = nullptr;

	float ReticleScreenPercentX = 0.5f;		// X position of Reticle as a percentage of screen
	float ReticleScreenPercentY = 0.4f;		// Y position of Reticle as a percentage of screen
	float FireRange = 100000.0f;
};
