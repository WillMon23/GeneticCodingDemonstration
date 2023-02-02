// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeneticCodingComponentP.h"
#include "BoxReproduction.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GENETICCODINGDEMO_API UBoxReproduction :public UGeneticCodingComponentP
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	/// <summary>
	/// Handles initializing new values here
	/// </summary>
	void SetVariables() override;

	UFUNCTION(BlueprintCallable)
	/// <summary>
	/// Gets the refrences to the 
	/// </summary>
	void RefrencedValues();

	
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private: 
	class UStaticMeshComponent* m_meshComponent;

	class UMaterialInstanceDynamic* m_dynamicMaterial;
};
