// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void
UTankAimingComponent::SetBarrelReference(UTankBarrel* pTankBarrelComponent)
{
	TankBarrelComponent = pTankBarrelComponent;
}

void 
UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (TankBarrelComponent)
	{
		FVector lTossVelocity(0.F);
		
		if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			lTossVelocity,
			TankBarrelComponent->GetSocketLocation("Projectile"),
			HitLocation,
			LaunchSpeed,
			false,
			0.F, 
			0.F, 
			ESuggestProjVelocityTraceOption::DoNotTrace))
		{

			FVector AimDirection = lTossVelocity.GetSafeNormal();

			MoveBarrelTowards(AimDirection);

			//TankBarrelComponent->GetComponentLocation().ToString
			UE_LOG(LogTemp, Warning, TEXT("Aim at %s"),
				*AimDirection.ToString());
			//UE_LOG(LogTemp, Warning, TEXT("Tank %s hit %s from %s at %s"),
				//*GetOwner()->GetName(),
				//*HitLocation.ToString(),
				//*TankBarrelComponent->GetComponentLocation().ToString(),
				//*AimDirection.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Not possible to calculate projectile velocity"));
		}
	}
}


void 
UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// find the difference between the current barrel rotation and the aim direction
	FRotator BarrelRotation = TankBarrelComponent->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotation;
	UE_LOG(LogTemp, Warning, TEXT("DeltaRotator.Pitch: %f"), DeltaRotator.Pitch);
	TankBarrelComponent->Elevate(DeltaRotator.Pitch);
	// move the barrel towards to aim direction
	// the movement shall be based on elevation speed and frame rate
}

