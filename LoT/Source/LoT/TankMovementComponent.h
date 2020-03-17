// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LOT_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category=Setup)
    void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

    UFUNCTION(BlueprintCallable, Category=Input)
    void IntendMoveForward(float Throw);

    UFUNCTION(BlueprintCallable, Category = Input)
    void IntendMoveBackward(float Throw);

    UFUNCTION(BlueprintCallable, Category=Input)
    void IntendMoveRight(float Throw);

    UFUNCTION(BlueprintCallable, Category=Input)
    void IntendMoveLeft(float Throw);

private:

    // Called from the pathfinding logic by the AI controller
    virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

    UTankTrack* LeftTrack = nullptr;

    UTankTrack* RightTrack = nullptr;
};  
