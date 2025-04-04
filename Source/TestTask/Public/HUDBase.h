// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_API AHUDBase : public AHUD
{
	GENERATED_BODY()
	AHUDBase();
public:
	void InitOverlay();

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> OverlayWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UUserWidget> OverlayWidget = nullptr;
};
