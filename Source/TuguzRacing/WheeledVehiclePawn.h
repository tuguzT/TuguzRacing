// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "WheeledVehiclePawn.generated.h"

/**
 * Base class of wheeled vehicle pawn
 */
UCLASS()
class TUGUZRACING_API AWheeledVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	/**
	 * Constructor of the object
	 */
	AWheeledVehiclePawn();

	virtual void Tick(float DeltaSeconds) override;

	/**
	 * Control vehicle movement in air
	 */
	UFUNCTION()
	virtual void InAirControl(float DeltaSeconds);

	/**
	 * Steering vehicle function
	 */
	virtual void ApplySteering(float Value);

	/**
	 * Throttle vehicle function
	 */
	virtual void ApplyThrottle(float Value);

	/**
	 * On handbrake press event function
	 */
	virtual void OnHandbrakePress();

	/**
	 * On handbrake release event function
	 */
	virtual void OnHandbrakeRelease();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
