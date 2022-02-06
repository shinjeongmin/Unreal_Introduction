// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
// 헤더 추가
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// 상위 부모 호출, 오버라이딩의 기본
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyCharacter == nullptr)
		return EBTNodeResult::Failed;

	MyCharacter->Attack();
	bIsAttacking = true;

	// OnAttackEnd 함수에 람다(무명)함수로 정의
	MyCharacter->OnAttackEnd.AddLambda([this]()
		{
			bIsAttacking = false;
		});

	return Result;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	
	if (bIsAttacking == false)
		// Behavior Tree 종료처리
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
