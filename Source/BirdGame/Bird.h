// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Bird.generated.h"

UCLASS()
class BIRDGAME_API ABird : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABird();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ArmSpring")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NumFris")
	bool haveFrisbe = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NumHit")
	int HitNum = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "IsDead")
	bool  isDead = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float value);
	void MoveBack(float value);
	void MoveRight(float value);

	void SlowMoveSpeed();
	void NormalMoveSpeed();
};
