// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankAiController.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Engine/World.h"



void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find a player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);

}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}




