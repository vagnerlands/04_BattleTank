// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

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
}

