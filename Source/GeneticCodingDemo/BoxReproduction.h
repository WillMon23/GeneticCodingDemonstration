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
	void SetVariables() override;

private: 
	
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* m_meshComponent;

	class UMaterialInterface* m_material;

	class UMaterialInstanceDynamic* m_dynamicMaterial;
	FColor fColor;
};
