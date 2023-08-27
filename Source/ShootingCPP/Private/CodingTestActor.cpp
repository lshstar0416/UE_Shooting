// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingTestActor.h"
#include "..\Public\CodingTestActor.h"
// Sets default values
ACodingTestActor::ACodingTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ACodingTestActor::BeginPlay()
{
	Super::BeginPlay();
	
	//UE_LOG(LogTemp, Warning, TEXT("Hello World"));
	//UE_LOG(LogTemp, Warning, TEXT("%d"), num1);
	//UE_LOG(LogTemp, Warning, TEXT("%.2f"), num2);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *text1);

	int32 result = Add(number1, number2);
	UE_LOG(LogTemp, Warning, TEXT("%d"), number2);

	if (number1 > 5)
	{
		//UE_LOG(LogTemp, Warning, TEXT("number1 is higher than 5"))
	}

	for (int i = 0; i < 10; i++)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%d"), i);
	}
}

// Called every frame
void ACodingTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACodingTestActor::Add(int32 num1, int32 num2)
{
	int32 result = num1 + num2;
	return result;
}
