// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase() 
{
	// GameMode의 DefaultPawnClass값을 변경
	DefaultPawnClass = AMyCharacter::StaticClass();
}