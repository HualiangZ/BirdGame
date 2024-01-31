// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
ABird::ABird()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABird::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveBack"), this, &ABird::MoveBack);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABird::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookTurn"), this, &ABird::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABird::AddControllerPitchInput);
}

void ABird::MoveRight(float value) {
	AddMovementInput(GetActorRightVector() * value);
}

void ABird::MoveForward(float value) {
	AddMovementInput(GetActorForwardVector() * value);

}
void ABird::MoveBack(float value) {
	AddMovementInput(GetActorForwardVector() * value);
}
