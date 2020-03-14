// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { UE_LOG(LogTemp, Warning, TEXT("Left ot Right track is misssing!")); return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

// UP button on the keyboard
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

// DOWN button on the keyboard
void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);
}

// RIGHT button on the keyboard
void UTankMovementComponent::IntendMoveRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

// LEFT button on the keyboard
void UTankMovementComponent::IntendMoveLeft(float Throw)
{
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

