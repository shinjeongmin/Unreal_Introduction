// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h" // UNavigationSystemV1�� ���� ���
#include "Blueprint/AIBlueprintHelperLibrary.h"

AMyAIController::AMyAIController()
{

}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// RandomMove�Լ��� �ֱ������� �����ϴ� Timer
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyAIController::RandomMove, 3.f, true);
}

void AMyAIController::OnUnPossess() 
{
	Super::OnUnPossess();

	// TimerHandle�� ������ �Լ� ��ƾ�� clear
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AMyAIController::RandomMove()
{
	auto CurrentPawn = GetPawn();

	// Navigation system�� ����
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
		return;

	FNavLocation RandomLocation;
	// �ݰ� �� ������ �� ��ǥ�� RandomLocation�� ����
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		// �̵��Լ�
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}