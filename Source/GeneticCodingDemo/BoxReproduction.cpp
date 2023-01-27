// Fill out your copyright notice in the Description page of Project Settings.

#include <Components/StaticMeshComponent.h>
#include "BoxReproduction.h"


void UBoxReproduction::SetVariables() {

	m_meshComponent = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	if (m_meshComponent)
	{

		m_meshComponent->SetRelativeScale3D(FVector(GenePool[0].GetValue(), GenePool[1].GetValue(), GenePool[2].GetValue()));
	}
}