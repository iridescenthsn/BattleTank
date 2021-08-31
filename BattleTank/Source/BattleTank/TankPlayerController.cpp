// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
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
	FVector HitLocation;//out parameter
	if (GetSightHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}	
}

//Get world location if linetrace through crossshair

bool ATankPlayerController::GetSightHitLocation(FVector& HitLocation) const
{
	//find the crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation);

	
	//"De-Project" the screen position of the crosshair to a world direction
	FVector LookDiretion;
	if (GetLookDirection(ScreenLocation,LookDiretion))
	{
		//line trace that direction and see where in the world we hit(up to max range)
		GetLookVectorHitLocaion(LookDiretion, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;
	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection));
}

bool ATankPlayerController::GetLookVectorHitLocaion(FVector LookDirection, FVector& Hitlocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility))
	{
		Hitlocation = HitResult.Location;
		return true;
	}
	return false;
}



