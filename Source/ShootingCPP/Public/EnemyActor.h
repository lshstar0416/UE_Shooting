// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class SHOOTINGCPP_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	//UPROPERTY(EditAnywhere)
	//class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponent* skeletalMeshComp;

	UPROPERTY(EditAnywhere)
	int32 traceRate = 50;

	UPROPERTY(EditAnyWhere)
	float moveSpeed = 800.0f;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* explosionFX;

	UFUNCTION()
		void OnEnemyOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	FVector dir;
};
