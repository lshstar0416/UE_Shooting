// Fill out your copyright notice in the Description page of Project Settings.


#include "AccessTest.h"
#include "CodingTestActor.h"

// Sets default values
AAccessTest::AAccessTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAccessTest::BeginPlay()
{
	Super::BeginPlay();

	number = 200;
	numPtr = &number;
	*numPtr = -30;

	UE_LOG(LogTemp, Warning, TEXT("number : %d"), number);
	UE_LOG(LogTemp, Warning, TEXT("numPtr : %d"), *numPtr);

	if (testPointer != nullptr)
	{
		//testPointer->number2 = -10;
		testPointer->number2 = -10;
	}

	int32 val_1 = 5;
	int32 val_2 = 10;
	int32 sum = 0;
	int32 mul = 0;

	AddPrint(val_1, val_2, &sum);
	MultiplyPrint(val_1, val_2, &mul);
	UE_LOG(LogTemp, Warning, TEXT("SUM : %d"), sum);
	UE_LOG(LogTemp, Warning, TEXT("MUL : %d"), mul);
}

// Called every frame
void AAccessTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAccessTest::MultiplyPrint(int32 num1, int32 num2, int32* result)
{
	*result = num1 * num2;
}

void AAccessTest::AddPrint(int32 num1, int32 num2, int32* result)
{
	*result = num1 + num2;
}

