// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void 
UTankTrack::SetThrottle(float throttlePower)
{
	UE_LOG(LogTemp, Warning, TEXT("this track throttle %f"), throttlePower);
	// TODO: clamp actual ThrottleValue to avoid player cheating the game
	FVector forceApplied = GetForwardVector() * throttlePower * MaxDrivingForce;
	FVector forceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(forceApplied, forceLocation);
}


