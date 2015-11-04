// Fill out your copyright notice in the Description page of Project Settings.

#include "sep23.h"
#include "spawnedBalls.h"
#include "theBall.h"

// Sets default values
AspawnedBalls::AspawnedBalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

   // Create dummy root scene component
   DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
   RootComponent = DummyRoot;

}

// Called when the game starts or when spawned
void AspawnedBalls::BeginPlay()
{
	Super::BeginPlay();
   AtheBall *NewBall;
   int NumBalls=15;

   /*    From BlockGrid.cpp   */
   const FVector BallLocation = FVector(10.f, 10.f, 0.f) + GetActorLocation(); //get location of spawnedBalls.cpp actor

   for(int i=0; i<NumBalls; i++)
      // Spawn a block
      NewBall = GetWorld()->SpawnActor<AtheBall>(BallLocation+FVector(10.f*i, 5.f*i, 0.f), FRotator(0,0,0));

   if(GEngine)
      GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "Start Point: "+BallLocation.ToString());
}

// Called every frame
void AspawnedBalls::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}





