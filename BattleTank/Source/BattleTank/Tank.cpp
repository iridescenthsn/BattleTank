// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	CurrentHealth = CurrentHealth - (FPlatformMath::RoundToInt(Damage));
	CurrentHealth=FMath::Clamp<int32>(CurrentHealth,0,100);

	if (CurrentHealth<=0)
	{
		OnDeath.Broadcast();
	}
	return Damage;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}


