// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponent* skeletalMeshComp;

	UPROPERTY(EditAnywhere)
	float moveSpeed = 500.0f;

	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition_1;
	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition_2;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> bulletFactory;

	UPROPERTY(EditAnywhere)
	class USoundBase* fireSound;

private:
	float h;
	float v;
	float angle;

	void MoveHorizontal(float val);
	void MoveVertical(float val);

	void Fire();
};
