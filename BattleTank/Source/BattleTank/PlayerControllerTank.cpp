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

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitLocation.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: nothing in range"));
	}
	
	// Get World location if linetrace through crosshair
	// If it hits the landscape
	    // Tell controlled tank to aim at this point
}

bool 
APlayerControllerTank::GetSightRayHitLocation(FVector & outHitLocation) const
{
	bool retVal = false;
	ATank* tankRef = GetControlledTank();

	// Find crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * 0.5f, ViewportSizeY * 0.33333f);

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection, LookStartLocation;


	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, LookStartLocation, LookDirection);
	FHitResult HitResult;
	retVal = GetWorld()->LineTraceSingleByChannel(HitResult, LookStartLocation, LookStartLocation + LookDirection * 5000.f, ECollisionChannel::ECC_Visibility);
	if (retVal)
	{
		outHitLocation = HitResult.Location;
	}
	return retVal;
}
