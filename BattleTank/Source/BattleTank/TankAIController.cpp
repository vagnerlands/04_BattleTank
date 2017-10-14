// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* controllerAI = GetAIController();

	if (controllerAI)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank %s possessed by AI"), *controllerAI->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Non player tank with no AI defined"));
	}

	ATank* playerControllerRef = GetPlayerTank();

	if (playerControllerRef)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank found %s"), *playerControllerRef->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to find player tank"));
	}
}

ATank* 
ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}

ATank* 
ATankAIController::GetPlayerTank() const
{
	//ATank* retVal = NULL;
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//if (playerPawnRef)
	//{
	//	retVal = playerPawnRef);
	//}
	
	//return retVal;
}
