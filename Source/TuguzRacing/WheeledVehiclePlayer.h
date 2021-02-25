// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "WheeledVehiclePlayer.generated.h"

/**
 * Base class of wheeled vehicle player
 */
UCLASS()
class TUGUZRACING_API AWheeledVehiclePlayer : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	/**
	 * Constructor of the object
	 */
	AWheeledVehiclePlayer();

private:
	UPROPERTY(VisibleAnywhere, Category="Camera")
	USpringArmComponent *SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category="Camera")
	UCameraComponent *CameraComponent;
};
