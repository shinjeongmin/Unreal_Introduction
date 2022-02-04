// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALINTRODUCTION_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindHp(class UMyStatComponent* StatComp);

	void UpdateHp();

private:
	// 일반 포인터를 사용하지 않고 Weak 포인터를 사용
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	// meta를 이용하면 위젯의 프로퍼티와 자동으로 연결해줌
	UPROPERTY(meta=(BindWidget))
	class UProgressBar* PB_HpBar;
};
