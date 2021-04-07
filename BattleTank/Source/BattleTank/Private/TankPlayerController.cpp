// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	ATank *Tank = Cast<ATank>(GetPawn());

	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Controlled: %s"), *Tank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Tank found"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetReticleHitLocation().ToString())
}

FVector ATankPlayerController::GetReticleHitLocation()
{
	// get reticle position in pixels
	int32 ViewSizeX, ViewSizeY;
	GetViewportSize(ViewSizeX, ViewSizeY);
	FVector2D ReticleScreenXY = FVector2D(ViewSizeX*ReticleScreenPercentX, ViewSizeY*ReticleScreenPercentY);
	
	// deproject reticle screen position to world space
	FVector Location, Direction;
	DeprojectScreenPositionToWorld(ReticleScreenXY.X, ReticleScreenXY.Y, Location, Direction);

	// line trace to get hitting object location
	FVector OutLocation(0);
	if (GetLineTraceResult(OutLocation, Direction)) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *OutLocation.ToString())
	}
	return OutLocation;
}

bool ATankPlayerController::GetLineTraceResult(FVector & OutLocation, FVector ReticleDirection)
{
	FHitResult OutHit;
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + ReticleDirection * FireRange;

	GetWorld()->LineTraceSingleByChannel(
		OutHit,
		Start,
		End,
		ECollisionChannel::ECC_Visibility,
		FCollisionQueryParams::DefaultQueryParam,
		FCollisionResponseParams::DefaultResponseParam
	);

	if (OutHit.IsValidBlockingHit()) {
		OutLocation = OutHit.Location;
		return true;
	}
	return false;
}
