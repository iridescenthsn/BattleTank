// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("ticking"));
}
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController begin play"));
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank possessed"));
	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank : %s is possessed"),*(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
	//Get world location if linetrace through crossshair
		//if it hits landscape
			//tell controlled tank to aim at this point
}



