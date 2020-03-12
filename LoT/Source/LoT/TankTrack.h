// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class LOT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	// Sets the throttle between 1 and -1 
	UFUNCTION (BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// Max Force per Track
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000.f; // Assume 40 tonne tank, acceleration = 1g.
};
