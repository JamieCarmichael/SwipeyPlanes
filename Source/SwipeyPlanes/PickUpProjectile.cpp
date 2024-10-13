// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpProjectile.h"
#include "Components/BoxComponent.h"
#include "PlayerPawn.h"

// Sets default values
APickUpProjectile::APickUpProjectile()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;


    // Create a box component for collision detection
    MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));

    //// Set this as the root component
    RootComponent = MyBoxComponent;

    // Enable overlap events and collision
    MyBoxComponent->SetGenerateOverlapEvents(true);
    MyBoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    MyBoxComponent->SetCollisionObjectType(ECC_WorldDynamic);
    MyBoxComponent->SetCollisionResponseToAllChannels(ECR_Overlap);

    // Bind the OnOverlapBegin function to the event
    MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APickUpProjectile::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APickUpProjectile::BeginPlay()
{
    Super::BeginPlay();

    lifeTimer = 0.0f;
}

// Called every frame
void APickUpProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Get the forward vector of the actor (the direction it's facing)
    FVector ForwardVector = GetActorUpVector();

    // Calculate the movement distance for this frame
    FVector Movement = ForwardVector * speed * DeltaTime;

    // Movs by the delta with collisions enabled.
    AddActorWorldOffset(Movement, true);


    // Accumulate the time elapsed since the actor began playing
    lifeTimer += DeltaTime;

    // Check if the elapsed time is greater than or equal to the time before destruction
    if (lifeTimer >= lifetime)
    {
        Destroy();
    }
}


// Called when the BoxComponent overlaps with another actor
void APickUpProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && (OtherActor != this))
    {
        // Handle overlap logic here

        // Check if the OtherActor is a bullet (by class)
        APlayerPawn* playerPawn = Cast<APlayerPawn>(OtherActor);
        if (playerPawn)
        {
            // give more projectiles
            playerPawn->MoreProjectile();

            Destroy();
        }

    }
}

