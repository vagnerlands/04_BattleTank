// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void 
ATank::SetTankComponentsReference(UTankBarrel* tankBarrel, UTankTurret* tankTurret)
{
	UE_LOG(LogTemp, Warning, TEXT("Tank::Barrel and Turret References set"));

	// local reference to tankBarrel;
	BarrelReference = tankBarrel;

	TankAimingComponent->SetBarrelReference(tankBarrel);
	TankAimingComponent->SetTurretReference(tankTurret);
}

void
ATank::AimAt(FVector HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("Tank::AimAt %s"), *HitLocation.ToString());
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void 
ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Tank %s fired!"), *this->GetName());

	if (!BarrelReference)
	{
		return;
	}

	if (!ProjectileBlueprint)
	{
		return;
	}

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded)
	{
		// spawn a projectile at 1 meter from "Projectile" socket with regular 
		FVector projectileLocation = BarrelReference->GetSocketLocation("Projectile") + FVector(0.F, 0.F, 100.F);
		FRotator projectileRotation = BarrelReference->GetSocketRotation("Projectile");

		AProjectile* launchedProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, projectileLocation, projectileRotation);

		launchedProjectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

