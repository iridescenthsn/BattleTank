// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"	
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurrretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

private:

	UPROPERTY(EditAnywhere, Category = firing)
	float LaunchSpeed = 10000;//TODO find sensible result.

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;   

	float ReloadTime = 3;

	double LastFireTime = 0;
};