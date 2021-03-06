// Copyright Zakhar Hurov, Poznań, 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class LOT_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ASprungWheel();

	void SetupConstraint();

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	USphereComponent* Wheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	USphereComponent* Axle = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	UPhysicsConstraintComponent* PhysicsConstraint = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	UPhysicsConstraintComponent* AxelWheelConstraint = nullptr;
    

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
