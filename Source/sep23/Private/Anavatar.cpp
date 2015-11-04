// Fill out your copyright notice in the Description page of Project Settings.

#include "sep23.h"
#include "Anavatar.h"


// Sets default values
AAnavatar::AAnavatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnavatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnavatar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAnavatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

   //Super::SetupPlayerInputComponent(InputComponent);
   check(InputComponent);
   InputComponent->BindAxis("W",this,&AAnavatar::walkForward);
   InputComponent->BindAxis("S",this,&AAnavatar::walkBack);
   InputComponent->BindAxis("Q",this,&AAnavatar::walkLeft);
   InputComponent->BindAxis("E",this,&AAnavatar::walkRight);
   InputComponent->BindAxis("mouse_X",this,&AAnavatar::Yaw); //look left-right
   //InputComponent->BindAxis("A",this,&AAnavatar::NYaw);
   //InputComponent->BindAxis("D",this,&AAnavatar::Yaw);
   InputComponent->BindAxis("mouse_Y",this,&AAnavatar::Pitch); //look up-down
   InputComponent->BindAction("Space",IE_Pressed,this,&AAnavatar::PlayerJump); //look up-down

}

void AAnavatar::walkForward(float amount)
{
   if(Controller && amount){
      FVector fwd=GetActorForwardVector();
      AddMovementInput(fwd, amount);
   }
}

void AAnavatar::walkBack(float amount)
{
   AAnavatar::walkForward(-.7*amount);
}

void AAnavatar::walkLeft(float amount)
{
   AAnavatar::walkRight(-1.0*amount);
}

void AAnavatar::walkRight(float amount)
{
   if(Controller && amount){
      FVector fwd=GetActorRightVector();
      AddMovementInput(fwd, amount);
   }
}

void AAnavatar::Yaw(float amount)
{
   AddControllerYawInput( 200.f * .6*amount * (GetWorld())->GetDeltaSeconds() );
}

void AAnavatar::NYaw(float amount)
{
   Yaw(-1.0*amount);
}

void AAnavatar::Pitch(float amount)
{
   AddControllerPitchInput( -200.f * amount * (GetWorld())->GetDeltaSeconds() );
   //Yaw(-1.0*amount);
}

void AAnavatar::PlayerJump()
{
   Jump();
   /*
   if ( CharacterOwner )
   {
      // Don't jump if we can't move up/down.
      if (FMath::Abs(PlaneConstraintNormal.Z) != 1.f)
      {
          Velocity.Z = JumpZVelocity;
          SetMovementMode(MOVE_Falling);
          return ;
      }
   }

   return ;
   */
}
