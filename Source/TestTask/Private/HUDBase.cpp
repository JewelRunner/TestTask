// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDBase.h"
#include "Blueprint/UserWidget.h"

AHUDBase::AHUDBase()
{
	
}

void AHUDBase::InitOverlay()
{
	if (OverlayWidgetClass)
	{
		OverlayWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
		OverlayWidget->AddToViewport();
	}
}
