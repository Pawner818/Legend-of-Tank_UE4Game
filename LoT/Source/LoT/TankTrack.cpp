// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

//Acceleration every frame to correct 
void UTankTrack::ApplySidewaysForce()
{
	// Calculate the slippage speed
	auto SlippaggeSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceperation = -SlippaggeSpeed / DeltaTime * GetRightVector();

	// Calculation of the sideways (F = m * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass()) * CorrectionAcceperation / 2; // because of 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1.f, 1.f);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
