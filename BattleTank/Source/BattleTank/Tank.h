// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// for the tank aiming component initialization
class UTankAimingComponent;
class UTankBarrel;

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// prepare to aim towards the target
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTankBarrelReference(UTankBarrel* pTankBarrel);

	// launch speed for the tank projectile - initial value may be changed in the BP
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f;
	
};
