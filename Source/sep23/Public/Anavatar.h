// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Anavatar.generated.h"

UCLASS()
class SEP23_API AAnavatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnavatar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void walkForward(float amount);
	void walkBack(float amount);
	void walkLeft(float amount);
	void walkRight(float amount);
	
	void Yaw(float amount); 		//rotate to look right
	void NYaw(float amount); 		//rotate to look right
	void Pitch(float amount);		//rotate to look left
	void PlayerJump();
};
