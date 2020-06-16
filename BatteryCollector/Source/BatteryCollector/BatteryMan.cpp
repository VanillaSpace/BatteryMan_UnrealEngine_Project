// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryMan.h"

// Sets default values
ABatteryMan::ABatteryMan()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(420.0f, 90.0f);

	//character doesnt rotate
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// in the direction where it is moving
	GetCharacterMovement()->bOrientRotationToMovement = true;

	//rate which we are rotating
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	//how far the camera is going to be away from the Player
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	//camera does not rotate relative to the arm
	FollowCamera->bUsePawnControlRotation = false;

}


// Called when the game starts or when spawned
void ABatteryMan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatteryMan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABatteryMan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

