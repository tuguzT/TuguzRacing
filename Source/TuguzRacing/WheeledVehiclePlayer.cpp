// Fill out your copyright notice in the Description page of Project Settings.

#include "WheeledVehiclePlayer.h"

AWheeledVehiclePlayer::AWheeledVehiclePlayer() : Super()
{
	// Setup spring arm component for camera component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 250;
	SpringArmComponent->bUsePawnControlRotation = true;

	// Setup camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->FieldOfView = 90;
}
