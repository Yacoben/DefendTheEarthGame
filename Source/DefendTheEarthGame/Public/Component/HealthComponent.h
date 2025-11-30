// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdateCurrentHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEFENDTHEEARTHGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


public:
	UFUNCTION(BlueprintCallable, Category = "Health")
	int32 TakeDamage();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(int32 HealAmount);


	/* Events Dispatchers */
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnUpdateCurrentHealth OnUpdateCurrentHealth;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDeath OnDeath;
	/* Events Dispatchers */


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	int32 MaxHealth;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	int32 CurrentHealth;

public:
	UFUNCTION(BlueprintCallable, Category = "Health")
	int32 GetCurrentHealth() const { return CurrentHealth; }
		
};
