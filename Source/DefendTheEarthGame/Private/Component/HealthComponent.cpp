// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

int32 UHealthComponent::TakeDamage()
{
	CurrentHealth--;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	else
	{
		OnUpdateCurrentHealth.Broadcast();
	}
	return CurrentHealth;
}

void UHealthComponent::Heal(int32 HealAmount)
{
	CurrentHealth = FMath::Clamp(HealAmount + CurrentHealth, 0, MaxHealth);
	OnUpdateCurrentHealth.Broadcast();
}

