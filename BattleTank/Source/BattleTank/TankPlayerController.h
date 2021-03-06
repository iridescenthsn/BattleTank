// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"	
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent,Category="Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingComponent);

private:

	//start the tank moving the barrel so that a shot would hit
	//where the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightHitLocation(FVector& OutHitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange=1000000;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocaion(FVector LookDirection, FVector& Hitlocation) const;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

public:
	void Tick(float Deltatime) override;

	void BeginPlay() override;

};
