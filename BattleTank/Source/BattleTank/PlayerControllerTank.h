// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// forward declaration to optimize compilation time
class ATank;

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerTank.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API APlayerControllerTank : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

private:
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& outHitLocation) const;
	
	
};
