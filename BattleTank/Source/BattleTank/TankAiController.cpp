// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAiController.h"

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AiTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!AiTank||!PlayerTank)
	{
		return;
	}
	AiTank->AimAt(PlayerTank->GetActorLocation());
	AiTank->Fire();
}

