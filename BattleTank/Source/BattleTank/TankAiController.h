// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"	
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 14000;

private:
	void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();
};
