// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "ExplosionEffect.h"
#include "SwipeyPlanesController.h"
#include "Actions/PawnAction.h"
#include "PaperSpriteComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnemySpawner.h"
#include "PickUpSingleton.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Assuming the PaperSprite is already initialized or created
    PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PlayerSprite"));

    // Set the PaperSprite as the RootComponent
    RootComponent = PaperSprite;  // Set the PaperSprite as the root
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();


    if (ProjectileSpawner == nullptr)
    {
        UChildActorComponent* ChildActorComp = FindComponentByClass<UChildActorComponent>();

        if (ChildActorComp)
        {
            // Get the actual child actor of the component
            AActor* ChildActor = ChildActorComp->GetChildActor();

            // Cast it to your desired class, e.g., AMyChildActorClass
            APlayerProjectileSpawner* MyChildActor = Cast<APlayerProjectileSpawner>(ChildActor);
            if (MyChildActor)
            {
                ProjectileSpawner = MyChildActor;
            }
        }
    }

    OnPlayerDespawn();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
    if (!isActive)
    {
        return;
    }

	Super::Tick(DeltaTime);

    //score = GetWorld()->GetTimeSeconds();

    // Apply movement based on input
    FVector Movement = GetPendingMovementInputVector();
    if (!Movement.IsNearlyZero())
    {
        Destination = GetActorLocation() + Movement;
        ConsumeMovementInputVector();  // Clears the input after use
    }

    // Add movement
    FVector actorLocation = GetActorLocation();
    float Distance = FVector::Dist(actorLocation, Destination);
    if (!FMath::IsNearlyZero(Distance))
    {
        FVector direction = Destination - actorLocation;

        FVector finalPoint = actorLocation + FVector(0,0,4) + (direction * speed * DeltaTime);

        SetActorLocation(finalPoint);
    }
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerPawn::PlayerTakeDamage(int damage)
{

    health -= damage;

    if (health <= 0)
    {
        GetWorld()->SpawnActor<AActor>(Explosion, GetActorLocation(), GetActorRotation());

        // Play sound effect when player dies.
        UGameplayStatics::PlaySound2D(GetWorld(), PlayerDeathSound, PlayerDeathVolume, FMath::RandRange(PlayerDeathPitchMin, PlayerDeathPitchMax));

        OnPlayerDespawn();
    }
    else
    {
        // Play sound effect when player hit.
        UGameplayStatics::PlaySound2D(GetWorld(), PlayerDamageSound, PlayerDamageVolume, FMath::RandRange(PlayerDamagePitchMin, PlayerDamagePitchMax));
    }
}

void APlayerPawn::PlayerAddScore(int newScore)
{
    score += newScore;
}

void APlayerPawn::OnPlayerDespawn()
{
    isActive = false;

    // Hide the player character
    SetActorHiddenInGame(true);

    // Disable collision
    SetActorEnableCollision(false);

    // disable tick
    PrimaryActorTick.SetTickFunctionEnable(false);

    // Need to disable spawner    
    // Check if ProjectileSpawner is valid
    ProjectileSpawner->StopSpawning();

    // Disable enemy spanwers
    TArray<AActor*> FoundSpawners;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawner::StaticClass(), FoundSpawners);    
    for (AActor* Actor : FoundSpawners)
    {
        AEnemySpawner* Spawner = Cast<AEnemySpawner>(Actor);
        if (Spawner)
        {
            Spawner->SetSpawningEnabled(false);
        }
    }
}

void APlayerPawn::OnPlayerSpawn()
{
    isActive = true;

    // Reset health
    health = StartHealth;
    score = 0;

    // show the player character
    SetActorHiddenInGame(false);

    // enable collision
    SetActorEnableCollision(true);

    // enable tick
    PrimaryActorTick.SetTickFunctionEnable(true);

    // Need to disable spawner
    ProjectileSpawner->StartSpawning();

    // Spawn player in center of screen
    Destination = SpawnPosition;
    SetActorLocation(SpawnPosition);

    // Enable enemy spanwers
    TArray<AActor*> FoundSpawners;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySpawner::StaticClass(), FoundSpawners);
    for (AActor* Actor : FoundSpawners)
    {
        AEnemySpawner* Spawner = Cast<AEnemySpawner>(Actor);
        if (Spawner)
        {
            Spawner->SetSpawningEnabled(true);
        }
    }

    UPickUpSingleton::Get()->ResetActivePickUp();
}

void APlayerPawn::MoreProjectile()
{
    // add projectile 
    ProjectilePowerUpTimer();
    ProjectileCount++;
    if (ProjectileCount > 10)
    {
        ProjectileCount = 10;
    }
    ProjectileSpawner->ProjectileCount = ProjectileCount;

    UPickUpSingleton::Get()->AddActivePickUp();
}

void APlayerPawn::RemoveProjectile()
{
    // remove projectile 
    ProjectileCount--;
    if (ProjectileCount < 1)
    {
        ProjectileCount = 1;
    }
    ProjectileSpawner->ProjectileCount = ProjectileCount;

    UPickUpSingleton::Get()->RemoveActivePickUp();
}


void APlayerPawn::ProjectilePowerUpTimer()
{
    FTimerHandle TimerHandle;

    // Get the world timer manager
    GetWorld()->GetTimerManager().SetTimer(
        TimerHandle,                               // The timer handle
        this,                                      // The object that owns the function
        &APlayerPawn::RemoveProjectile,            // Function to call
        projectilePowerupTime,                     // Delay in seconds
        false                                      // Whether the timer loops
    );
}

