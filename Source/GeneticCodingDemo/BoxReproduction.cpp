// Fill out your copyright notice in the Description page of Project Settings.

#include "BoxReproduction.h"
#include <Components/StaticMeshComponent.h>

/// <summary>
/// Handles initializing new values here
/// </summary>
void UBoxReproduction::SetVariables() {
		m_dynamicMaterial->SetVectorParameterValue(FName(TEXT("DiffuseColor")), FLinearColor(GenePool[3].GetValue(), GenePool[4].GetValue(), GenePool[5].GetValue()));
		m_meshComponent->SetRelativeScale3D(FVector(GenePool[2].GetValue(), GenePool[1].GetValue(), GenePool[0].GetValue()));
}

/// <summary>
/// Gets the refrences to the 
/// </summary>
void UBoxReproduction::RefrencedValues()
{
	//Gets the actors Static Mesh Component 
	m_meshComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	//if there is a static mesh 
	if (m_meshComponent)
	{
		//Creates a dynamic material instance With the mesh's material 
		m_dynamicMaterial = UMaterialInstanceDynamic::Create(m_meshComponent->GetMaterial(0), NULL);
		//Then setting that dynamic instance to be the new material for the mesh
		m_meshComponent->SetMaterial(0, m_dynamicMaterial);
	}
}

void UBoxReproduction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	SetVariables();
}
