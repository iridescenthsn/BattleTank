// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	//-1 is max downward speed and 1 is max up movement
	void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere,Category="Setup")
	float MaxDegreesPerSecond=5;//sensible default
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevation=20;
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinElevation=0;

	float MaxSpeed = 1;
	float MinSpeed = -1;
};
