// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Intialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();

	auto TurnThrow = FVector::CrossProduct(TankForward,AiForwardIntention );
	auto ForwardThrow = FVector::DotProduct(TankForward, AiForwardIntention);

	IntendMoveForward(ForwardThrow);
	IntendTurnRight(TurnThrow.Z);
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack || !RightTrack))
	{
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack || !RightTrack))
	{
		return;
	}
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

