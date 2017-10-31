// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class UTankBarrel;

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Holds aiming behavior and commands turret movement
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* pTankBarrelComponent);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UTankBarrel* TankBarrelComponent = nullptr;

	UPROPERTY(EditAnywhere)
	float BarrelMovementSpeed = 10.f;

	void MoveBarrelTowards(FVector AimDirection);

	FVector DesiredBarrelDirection;
		
	
};
