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

	void AimTowardsCrosshair();

	ATank* GetControlledTank() const;

private:

	bool GetSightRayHitLocation(FVector& outHitLocation) const;

	bool GetLookVectorHitLocation(const FVector2D ScreenLocation, FVector& outHitLocation) const;

	UPROPERTY(EditAnywhere)
	float TankFireReach = 10000.f;

	// X the crosshair relative point in the screen
	UPROPERTY(EditAnywhere, Category = Setup)
	float crosshairRelativeX = 0.5f;
	// Y the crosshair relative point in the screen
	UPROPERTY(EditAnywhere, Category = Setup)
	float crosshairRelativeY = 1.0f / 3.0f;	
	
};
