// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning ,TEXT("Donkey: constructor called"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Donkey: Begin play called"));
}

void ATank::Fire()
{
	if (!ensure(Barrel))
	{
		return;
	}
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (IsReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}



