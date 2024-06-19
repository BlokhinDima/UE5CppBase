// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTranformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditInstanceOnly)
	int EnemyNum = 1;

	UPROPERTY(EditInstanceOnly)
	float CurrentHealth = 100;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UPROPERTY(EditAnywhere)
	float Amplitude = 100;

	UPROPERTY(EditAnywhere)
	float Frequency = 1;

	UPROPERTY(EditAnywhere)
	FVector InitialLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	UFUNCTION(BlueprintCallable)
	void SinMovement();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
