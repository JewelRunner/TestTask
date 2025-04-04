// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DialogInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDialogInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTTASK_API IDialogInterface
{
	GENERATED_BODY()

public:
	virtual void StartDialog() {};
	virtual void EndDialog() {};

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
