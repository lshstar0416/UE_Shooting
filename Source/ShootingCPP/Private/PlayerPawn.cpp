// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Bullet.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	SetRootComponent(boxComp);

	//meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	//meshComp->SetupAttachment(boxComp);

	skeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("My Skeletal Mesh"));
	skeletalMeshComp->SetupAttachment(boxComp);

	FVector boxSize = FVector(50.0f, 50.0f, 50.0f);
	boxComp->SetBoxExtent(boxSize);

	firePosition_1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Fire Position 1"));
	firePosition_1->SetupAttachment(boxComp);
	firePosition_2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Fire Position 2"));
	firePosition_2->SetupAttachment(boxComp);

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	boxComp->SetCollisionObjectType(ECC_GameTraceChannel1);
	boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);
	boxComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector dir = FVector(0, h, v);
	dir.Normalize();

	if (dir.Y == 0)
	{
		angle = 0;
	}
	else if (dir.Y > 0 && angle > -40)
	{
		angle -= 3;
	}
	else if (dir.Y < 0 && angle < 40)
	{
		angle += 3;
	}

	FVector newLocation = GetActorLocation() + dir * moveSpeed * DeltaTime;
	FRotator newRotation = FRotator(0, angle, 0);
	SetActorLocation(newLocation, true);
	SetActorRotation(newRotation);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawn::MoveHorizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawn::MoveVertical);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerPawn::Fire);
}

void APlayerPawn::MoveHorizontal(float val)
{
	h = val;
}

void APlayerPawn::MoveVertical(float val)
{
	v = val;
}

void APlayerPawn::Fire()
{
	ABullet* bullet_1 = GetWorld()->SpawnActor<ABullet>(
		bulletFactory, 
		firePosition_1->GetComponentLocation(), 
		firePosition_1->GetComponentRotation());
	ABullet* bullet_2 = GetWorld()->SpawnActor<ABullet>(
		bulletFactory,
		firePosition_2->GetComponentLocation(),
		firePosition_2->GetComponentRotation());

	UGameplayStatics::PlaySound2D(GetWorld(), fireSound);
}

