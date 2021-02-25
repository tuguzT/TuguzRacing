// Fill out your copyright notice in the Description page of Project Settings.

#include "WheeledVehiclePawn.h"
#include "WheeledVehicleMovementComponent4W.h"

AWheeledVehiclePawn::AWheeledVehiclePawn()
{
	// Get movement component of the super class
	auto &MovementComponent = *CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());

	// Setup tire loading
	MovementComponent.MinNormalizedTireLoad = 0;
	MovementComponent.MinNormalizedTireLoadFiltered = 0.2;
	MovementComponent.MaxNormalizedTireLoad = 2;
	MovementComponent.MaxNormalizedTireLoadFiltered = 2;
	MovementComponent.MaxEngineRPM = 5700;

	// Setup torque
	auto &TorqueCurve = *MovementComponent.EngineSetup.TorqueCurve.GetRichCurve();
	TorqueCurve.Reset();
	TorqueCurve.AddKey(0, 400);
	TorqueCurve.AddKey(1890, 500);
	TorqueCurve.AddKey(5730, 400);

	// Setup steering
	auto &SteeringCurve = *MovementComponent.SteeringCurve.GetRichCurve();
	SteeringCurve.Reset();
	SteeringCurve.AddKey(0, 1);
	SteeringCurve.AddKey(40, 0.7);
	SteeringCurve.AddKey(120, 0.6);

	auto &Differential = MovementComponent.DifferentialSetup;
	Differential.DifferentialType = EVehicleDifferential4W::LimitedSlip_4W;
	Differential.FrontRearSplit = 0.65;

	// Setup automatic gearbox
	auto &Transmission = MovementComponent.TransmissionSetup;
	Transmission.bUseGearAutoBox = true;
	Transmission.GearSwitchTime = 0.15;
	Transmission.GearAutoBoxLatency = 1;
}

void AWheeledVehiclePawn::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	InAirControl(DeltaSeconds);
}

void AWheeledVehiclePawn::InAirControl(const float DeltaSeconds)
{
}

void AWheeledVehiclePawn::ApplySteering(const float Value)
{
	GetVehicleMovementComponent()->SetSteeringInput(Value);
}

void AWheeledVehiclePawn::ApplyThrottle(const float Value)
{
	GetVehicleMovementComponent()->SetThrottleInput(Value);
}

void AWheeledVehiclePawn::OnHandbrakePress()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AWheeledVehiclePawn::OnHandbrakeRelease()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void AWheeledVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AWheeledVehiclePawn::ApplyThrottle);
	PlayerInputComponent->BindAxis("Right", this, &AWheeledVehiclePawn::ApplySteering);

	PlayerInputComponent->BindAction(
		"Handbrake", IE_Pressed, this, &AWheeledVehiclePawn::OnHandbrakePress);
	PlayerInputComponent->BindAction(
		"Handbrake", IE_Released, this, &AWheeledVehiclePawn::OnHandbrakeRelease);
}
