// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

// Behavior Tree 및 Blackboard 관련 헤더 추가
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	// Behavior Tree 에셋 불러오기
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("BehaviorTree'/Game/AI/BT_MyCharacter.BT_MyCharacter'"));
	if (BT.Succeeded()) {
		BehaviorTree = BT.Object;
	}
	// Blackboard 에셋 불러오기
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BD(TEXT("BlackboardData'/Game/AI/BB_MyCharacter.BB_MyCharacter'"));
	if (BD.Succeeded()) {
		BlackboardData = BD.Object;
	}
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyAIController::RandomMove, 3.f, true);

	// TODO:
	if (UseBlackboard(BlackboardData, Blackboard)) {
		if (RunBehaviorTree(BehaviorTree)) {

		}
	}
}

void AMyAIController::OnUnPossess() 
{
	Super::OnUnPossess();

	//GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
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