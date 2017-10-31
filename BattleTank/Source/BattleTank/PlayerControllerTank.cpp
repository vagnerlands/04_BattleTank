// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerControllerTank.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void
APlayerControllerTank::BeginPlay()
{
	// calls super class (AActor) first
	Super::BeginPlay();

	ATank* controlledTank = GetControlledTank();
	if (controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn name %s"), *controlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerControllerTank not possessed by anyone!"));
	}
}

void APlayerControllerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* 
APlayerControllerTank::GetControlledTank() const
{
	ATank* retVal = 0;

	retVal = Cast<ATank>(GetPawn());

	return retVal;
}

void APlayerControllerTank::AimTowardsCrosshair()
{
	// do not proceed if this controller has no tank associated
	if (!GetControlledTank())
	{
		return;
	}

	FVector HitLocation = FVector();

	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: nothing in range"));
	}
	
	// If it hits the landscape
	    // Tell controlled tank to aim at this point
}

bool 
APlayerControllerTank::GetSightRayHitLocation(FVector & outHitLocation) const
{
	bool retVal = false;
	ATank* tankRef = GetControlledTank();

	// visible window sizes (x and y)
	int32 ViewportSizeX, ViewportSizeY;
	// get the current sizes of the window
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	// builds a 2D for the current screen location
	// X is the middle of the screen
	// Y is 1/3 from top to bottom of the screen
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * crosshairRelativeX, ViewportSizeY * crosshairRelativeY);

	return GetLookVectorHitLocation(ScreenLocation, outHitLocation);
}

bool 
APlayerControllerTank::GetLookVectorHitLocation(const FVector2D ScreenLocation, FVector& outHitLocation) const
{
	bool retVal = false;

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection, LookStartLocation;
	// takes a 2D coordinate and projects it into the 3D coordinate
	// Output LookStartLocation / LookDirection vectors
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, LookStartLocation, LookDirection))
	{
		// prepares the Hit result structure
		FHitResult HitResult;

		// checks 
		retVal = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			LookStartLocation,
			LookStartLocation + LookDirection * TankFireReach,
			ECollisionChannel::ECC_Visibility);

		// if valid - raycast found a target (perhaps ground, mountain, whatever...)
		if (retVal)
		{
			outHitLocation = HitResult.Location;
		}
	}
	return retVal;
}

