// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void 
UTankMovementComponent::Initialise(UTankTrack* LeftTrackReference, UTankTrack* RightTrackReference)
{
	if ((!LeftTrackReference) || (!RightTrackReference)) 
		return;

	LeftTrack = LeftTrackReference;
	RightTrack = RightTrackReference;
}

void 
UTankMovementComponent::IntendMoveForward(float Throw)
{
	if ((!LeftTrack) || (!RightTrack))
		return;

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}


void
UTankMovementComponent::IntendTurnRight(float TurnValue)
{
	if ((!LeftTrack) || (!RightTrack))
		return;

	LeftTrack->SetThrottle(TurnValue);
	RightTrack->SetThrottle(-TurnValue);
}
