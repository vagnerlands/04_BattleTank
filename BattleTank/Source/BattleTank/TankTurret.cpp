// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void 
UTankTurret::TurnTurret(float relativeSpeed)
{
	auto YawChange = FMath::Clamp<float>(relativeSpeed, -1.F, 1.F) * TurnDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	FRotator RawNewYaw = FRotator(0.F, RelativeRotation.Yaw + YawChange, 0.F);

	RawNewYaw.Yaw = FMath::Clamp<float>(RawNewYaw.Yaw, MinTurnAngle, MaxTurnAngle);

	// clamp the barrel elevation
	//if (RawNewElevation.Pitch > MaxBarrelElevation)
	//	RawNewElevation.Pitch = MaxBarrelElevation;

	// updates the barrel position in BP
	SetRelativeRotation(RawNewYaw);
}



