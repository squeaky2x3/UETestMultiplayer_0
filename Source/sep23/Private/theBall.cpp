// Fill out your copyright notice in the Description page of Project Settings.

#include "sep23.h"
#include "theBall.h"


// Sets default values
AtheBall::AtheBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
   // Structure to hold one-time initialization
   struct FConstructorStatics
   {
      ConstructorHelpers::FObjectFinderOptional<UStaticMesh> BallMesh;
      ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> BallMat;
      FConstructorStatics()
         : BallMesh(TEXT("/Game/shape_ball.shape_ball"))  // /Game == Unreal Projects/projectDirectory/Content
         , BallMat(TEXT("/Game/_ballMat._ballMat"))
      {
      }
   };
   static FConstructorStatics ConstructorStatics;

   // Create dummy root scene component
   DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
   RootComponent = DummyRoot;

   // Create static mesh component
   BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh0"));
   BallMesh->SetStaticMesh(ConstructorStatics.BallMesh.Get());
   BallMesh->SetRelativeScale3D(FVector(1.f,1.f,1.f));
   BallMesh->SetRelativeLocation(FVector(1.f,1.f,1.f));
   BallMesh->SetMaterial(0, ConstructorStatics.BallMat.Get());
   BallMesh->SetSimulatePhysics(true);
   BallMesh->AttachTo(DummyRoot);
   //BallMesh->OnClicked.AddDynamic(this, &AtheBall::BlockClicked);
   //BallMesh->OnInputTouchBegin.AddDynamic(this, &AtheBall::OnFingerPressedBlock);

   // Save a pointer to the orange material
   //GreenMaterial = ConstructorStatics.GreenMaterial.Get();
   //PinkMaterial = ConstructorStatics.PinkMaterial.Get();
}

// Called when the game starts or when spawned
void AtheBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AtheBall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

