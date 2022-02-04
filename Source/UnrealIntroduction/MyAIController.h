// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALINTRODUCTION_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AMyAIController();

	// Pawn에 인칭이 고정될 때 호출
	virtual void OnPossess(APawn* InPawn) override;
	// 인칭이 풀릴 때 호출
	virtual void OnUnPossess() override;

private:
	void RandomMove();
private:
	// deletgate의 타이머를 구분할 수 있는 핸들
	FTimerHandle TimerHandle;
};
