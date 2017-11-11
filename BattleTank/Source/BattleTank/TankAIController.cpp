// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTankReference = Cast<ATank>(GetPawn());

	if (ControlledTankReference)
	{
		UE_LOG(LogTemp, Error, TEXT("Non player tank with no AI defined"));
	}

	MainPlayerReference = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (MainPlayerReference)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to find player tank"));
	}
}

void
ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledTankReference && MainPlayerReference)
	{
		ControlledTankReference->AimAt(MainPlayerReference->GetActorLocation());

		ControlledTankReference->Fire();
	}
}
