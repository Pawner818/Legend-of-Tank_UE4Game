// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// Calculate the slippage speed
    auto SlippaggeSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	//Acceleration every frame to correct 
	auto CorrectionAcceperation = -SlippaggeSpeed / DeltaTime * GetRightVector();

	// Calculation of the sideways (F = m * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass()) * CorrectionAcceperation / 2; // because of 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot =Cast<UPrimitiveComponent>( GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
