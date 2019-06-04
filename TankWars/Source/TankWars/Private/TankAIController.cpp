// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing: %s"), *(ControlledTank->GetName()))
	}

	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not seeing a player controlled tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is seeing player controlled tank: %s"), *(PlayerControlledTank->GetName()), *(ControlledTank->GetName()))
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}