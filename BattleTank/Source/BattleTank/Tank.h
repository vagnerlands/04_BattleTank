// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// for the tank aiming component initialization
class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class UTankMovementComponent;

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
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// prepare to aim towards the target
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTankComponentsReference(UTankBarrel* tankBarrel, UTankTurret* tankTurret);

	// launch speed for the tank projectile - initial value may be changed in the BP
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<class AProjectile> ProjectileBlueprint;

private:
	// local reference to tank barrel 
	UTankBarrel* BarrelReference = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	double ReloadTimeInSeconds = 5.0;

	double LastFireTime = 0.0;
	
};
