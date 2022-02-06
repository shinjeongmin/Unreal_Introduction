// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_CanAttack.h"
// 헤더 추가
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTDecorator_CanAttack::UBTDecorator_CanAttack() 
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return false;

	// Target으로 catch 한 값을 가져옴
	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	// Target과 거리 계산
	return bResult && Target->GetDistanceTo(CurrentPawn) <= 200.f;
}