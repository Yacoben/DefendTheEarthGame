// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ObjectPoolComponent.h"

// Sets default values for this component's properties
UObjectPoolComponent::UObjectPoolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObjectPoolComponent::BeginPlay()
{
	Super::BeginPlay();

	APawn* OwnerPawn = Cast<APawn>(GetOwner());

	if (OwnerPawn)
	{
		PoolPawnOwner = OwnerPawn;

		if (ActorClasses.IsEmpty())
		{
			InitializePool();
		}
		else
		{
			InitializePoolWithManyClass();
		}

	};
}


// Called every frame
void UObjectPoolComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* UObjectPoolComponent::GetPooledActor()
{
	return nullptr;
}

void UObjectPoolComponent::ReturnActorToPool(AActor* ActorToReturn)
{
}

void UObjectPoolComponent::DeinitializePool()
{
}

void UObjectPoolComponent::InitializePool()
{
}

void UObjectPoolComponent::InitializePoolWithManyClass()
{
}

