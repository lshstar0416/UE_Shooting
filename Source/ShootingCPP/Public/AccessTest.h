// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AccessTest.generated.h"

UCLASS()
class SHOOTINGCPP_API AAccessTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAccessTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 number;
	int32* numPtr;

	UPROPERTY(EditAnywhere)
	class ACodingTestActor* testPointer;

	void AddPrint(int32 num1, int32 num2, int32* result);

	void MultiplyPrint(int32 num1, int32 num2, int32* result);
};