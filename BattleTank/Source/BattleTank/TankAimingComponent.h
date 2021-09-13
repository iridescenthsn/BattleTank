// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Locked,
	Aiming
};

//forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable)
	void intialize(UTankTurret* TankTurret, UTankBarrel* TankBarrel);

protected:

	UPROPERTY(BlueprintReadOnly,Category="State")
	EFiringState FiringState = EFiringState::Reloading;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable,Category="Firing")
	void Fire();

private:

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditAnywhere, Category = "firing")
	float LaunchSpeed = 10000;//TODO find sensible result.

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	float ReloadTime = 3;
	double LastFireTime = 0;

	void MoveBarrel(FVector AimDirection);
};
