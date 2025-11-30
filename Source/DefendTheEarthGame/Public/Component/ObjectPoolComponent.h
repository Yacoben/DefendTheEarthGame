// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPoolComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPoolSpawned, UObjectPoolComponent*, ObjectPoolComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetActorFromPool, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReturnActorToPool, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeinitialize);




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEFENDTHEEARTHGAME_API UObjectPoolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectPoolComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		

public:

	AActor* GetPooledActor();

	void ReturnActorToPool(AActor* ActorToReturn);

	void DeinitializePool();

	


	/* Events Dispatchers */
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnPoolSpawned OnPoolSpawned;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnGetActorFromPool OnGetActorFromPool;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnReturnActorToPool OnReturnActorToPool;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDeinitialize OnDeinitialize;
	/* Events Dispatchers */


	UPROPERTY(BlueprintReadWrite, Category = "Pool")
	TArray<TObjectPtr<AActor>> ActorPool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool")
	int32 PoolSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(BlueprintReadWrite, Category = "Pool")
	TObjectPtr<APawn> PoolPawnOwner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool")
	TMap<TSubclassOf<AActor>, int32> ActorClasses;

	UPROPERTY(BlueprintReadOnly, Category = "Pool")
	bool bIsDeinitializing = false;


private:

	void InitializePool();
	void InitializePoolWithManyClass();

};
