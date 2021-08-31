// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//Move barrel the right amount
	//Given a max elevation speed, and the frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevating at: %f"),DegreesPerSecond);
}
