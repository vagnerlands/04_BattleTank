// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and apply moving force on the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// sets a track value between -1 to +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throttlePower);

private:
	float ThrottleValue;

	// Maximum force per track, in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDrivingForce = 400000.F; // assumes a 40ton tank with 1g acceleration
	
	
};
