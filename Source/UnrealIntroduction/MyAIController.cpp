// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h" // UNavigationSystemV1을 위한 헤더
#include "Blueprint/AIBlueprintHelperLibrary.h"

AMyAIController::AMyAIController()
{

}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// RandomMove함수를 주기적으로 실행하는 Timer
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyAIController::RandomMove, 3.f, true);
}

void AMyAIController::OnUnPossess() 
{
	Super::OnUnPossess();

	// TimerHandle에 설정된 함수 루틴이 clear
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AMyAIController::RandomMove()
{
	auto CurrentPawn = GetPawn();

	// Navigation system을 설정
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
		return;

	FNavLocation RandomLocation;
	// 반경 내 임의의 점 좌표를 RandomLocation에 저장
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		// 이동함수
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}