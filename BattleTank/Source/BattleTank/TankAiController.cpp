// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAiController.h"


void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI could not find a player tank"));
	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found Player %s"),*(GetPlayerTank()->GetName())) ;
	}
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}

ATank* ATankAiController::GetAiTank() const
{
	return Cast<ATank>(GetPawn());
}
