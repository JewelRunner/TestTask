// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogActor.h"

#include "DialogInterface.h"
#include "Components/BoxComponent.h"

// Sets default values
ADialogActor::ADialogActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BoxInitDialog = CreateDefaultSubobject<UBoxComponent>("BoxInitDialog");
	SetRootComponent(BoxInitDialog);

	BoxFinishDialog = CreateDefaultSubobject<UBoxComponent>("BoxFinishDialog");
	BoxFinishDialog->SetupAttachment(GetRootComponent());
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("StaticMeshComponent");
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ADialogActor::BeginPlay()
{
	Super::BeginPlay();

	BoxInitDialog->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxFinishDialog->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	BoxInitDialog->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxFinishDialog->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	BoxInitDialog->OnComponentBeginOverlap.AddDynamic(this, &ADialogActor::OnBoxInitDialogBeginOverlap);
	BoxFinishDialog->OnComponentEndOverlap.AddDynamic(this, &ADialogActor::OnBoxFinishDialogEndOverlap);
}

void ADialogActor::OnBoxInitDialogBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IDialogInterface* DialogInterface = Cast<IDialogInterface>(OtherActor))
	{
		DialogInterface->StartDialog();
	}
}

void ADialogActor::OnBoxFinishDialogEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (IDialogInterface* DialogInterface = Cast<IDialogInterface>(OtherActor))
	{
		DialogInterface->EndDialog();
	}
}


// Called every frame
void ADialogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

