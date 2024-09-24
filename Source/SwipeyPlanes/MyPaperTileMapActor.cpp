// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperTileMapActor.h"

AMyPaperTileMapActor::AMyPaperTileMapActor()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMyPaperTileMapActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Begin"));
}

void AMyPaperTileMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("Tick"));

	FVector movePos = GetActorLocation() + (moveDirection * speed * DeltaTime);

	SetActorLocation(movePos);
	if (GetActorLocation().Z < movePoint)
	{
		SetActorLocation(GetActorLocation() - (moveDirection * teleportMove));
	}

	UE_LOG(LogTemp, Log, TEXT("Move Position: X = %f, Z = %f"), movePos.X, movePos.Z);
}
