// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent)/*, hidecategories = ("Collision")*/)
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float relativeSpeed);
private:
	// Barrel movement speed
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5.f;
	// barrel maximum elevation in degrees
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxBarrelElevation = 40.f;
	// barrel minimum elevation in degrees
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinBarrelElevation = -3.f;
	
};
