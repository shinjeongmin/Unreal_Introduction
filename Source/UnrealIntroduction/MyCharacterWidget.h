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
	// �Ϲ� �����͸� ������� �ʰ� Weak �����͸� ���
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	// meta�� �̿��ϸ� ������ ������Ƽ�� �ڵ����� ��������
	UPROPERTY(meta=(BindWidget))
	class UProgressBar* PB_HpBar;
};
