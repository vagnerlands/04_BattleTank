// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"
//#include "BattleTank.h"


void 
UTankBarrel::Elevate(float relativeSpeed)
{
	auto ElevationChange = FMath::Clamp<float>(relativeSpeed, -1.F, 1.F) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	FRotator RawNewElevation = FRotator(RelativeRotation.Pitch + ElevationChange, 0.F, 0.F);

	RawNewElevation.Pitch = FMath::Clamp<float>(RawNewElevation.Pitch, MinBarrelElevation, MaxBarrelElevation);

	// clamp the barrel elevation
	//if (RawNewElevation.Pitch > MaxBarrelElevation)
	//	RawNewElevation.Pitch = MaxBarrelElevation;
	
	// updates the barrel position in BP
	SetRelativeRotation(RawNewElevation);
}
