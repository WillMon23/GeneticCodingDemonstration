// Fill out your copyright notice in the Description page of Project Settings.

#include <Components/StaticMeshComponent.h>
#include "BoxReproduction.h"


void UBoxReproduction::SetVariables() {
		m_dynamicMaterial->SetVectorParameterValue(FName(TEXT("DiffuseColor")), FLinearColor(GenePool[3].GetValue(), GenePool[4].GetValue(), GenePool[5].GetValue()));
		m_meshComponent->SetRelativeScale3D(FVector(GenePool[2].GetValue(), GenePool[1].GetValue(), GenePool[0].GetValue()));
}

void UBoxReproduction::RefrenceValues()
{
	m_meshComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	if (m_meshComponent)
	{
		m_material = m_meshComponent->GetMaterial(0);
		m_dynamicMaterial = UMaterialInstanceDynamic::Create(m_material, NULL);
		m_meshComponent->SetMaterial(0, m_dynamicMaterial);
	}
}



void UBoxReproduction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	SetVariables();
}
