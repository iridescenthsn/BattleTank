// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"	
#include "TankAiController.h"

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AiTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (ensure(PlayerTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
		if (!ensure(AimingComponent))
		{
			return;
		}

		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
		if (AimingComponent->GetFiringState()==EFiringState::Locked)
		{
			AimingComponent->Fire();
		}

	}
}

