// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GeneticCodingTraitInfoP.h"
#include "GeneticCodingComponentP.generated.h"

class AGeneticCodingActorP;

struct Allies {
	bool alliesOne = false;
	bool alliesTwo = false;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GENETICCODINGPLUGIN_API UGeneticCodingComponentP : public UActorComponent
{
	GENERATED_BODY()

public:	
	/// <summary>
	/// Sets default values for this component's properties
	/// </summary>
	UGeneticCodingComponentP();


	virtual void SetVariables();

	UFUNCTION(BlueprintCallable)
	float AddToGenePool(FString name, bool traitsDomOne, bool traitsDomTwo, float domineteTrait, float resessiveTrait);

	/// <summary>
	/// Takes it's self recreates it with a new set of traits inherited by it's own traits 
	/// based on the trait info provided 
	/// </summary>
	/// <returns>returns true If the inheritance passed perfectly</returns>
	bool CanReproduce();

	UFUNCTION(BlueprintCallable)
	/// <summary>
	/// Takes Takes some other genes then recreates a new set of traits inherited by it's own traits 
	/// based on the trait info provided
	/// Then takes the name an attaches To the other 
	/// </summary>
	/// <param name="otherGenes">the other gene been contribuatting to the inheritance</param>
	/// <returns>returns true If the inheritance passed perfectly</returns>
	bool CanReproduce(UGeneticCodingComponentP* otherGenes);

	UFUNCTION(BlueprintCallable)
	/// <summary>
	/// Updates the data asset attached to this component 
	/// </summary>
	void AddToManager();

	UFUNCTION(BlueprintCallable)
	/// <summary>
	/// Once ready for recreate it'll spawn a new actor with a new genepool inherited 
	/// </summary>
	AActor* Recreate(FVector Location, FRotator Rotation);

	UFUNCTION(BlueprintCallable)
	/// <summary>
	/// Sets the current stat of reproduction
	/// </summary>
	/// <param name="reproductionStat"></param>
	void IsReadyToRepoduce(bool reproductionStat) { _readyToReproduce = reproductionStat; }

public:
	/// <summary>
	/// Container for the traits of this actor
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<FGeneticCodingTraitInfoP> GenePool;

	/// <summary>
	/// The name of the offspring
	/// </summary>
	UPROPERTY(EditAnywhere)
		FString Name;


	AActor* Parent;

private:
	
	/// <summary>
	/// If ready to reproduce this will be sest to true other wise it'll stay false
	/// </summary>
	UPROPERTY(EditAnywhere)
		bool _readyToReproduce = false;

	/// <summary>
	/// Able to sen the stats to Data Manager
	/// </summary>
	UPROPERTY(EditAnywhere)
		class UGeneticCodingGameManagerP* _gameManager;


	/// <summary>
	/// Offsprings new set stats
	/// </summary>
	UGeneticCodingComponentP* _offSpring;
};
