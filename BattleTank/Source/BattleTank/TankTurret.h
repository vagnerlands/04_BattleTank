// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void TurnTurret(float relativeSpeed);

private:
	UPROPERTY(EditAnywhere)
	float MinTurnAngle = -180.F;
	UPROPERTY(EditAnywhere)
	float MaxTurnAngle = 180.F;
	UPROPERTY(EditAnywhere)
	float TurnDegreesPerSecond = 50.F;
	
	
};
