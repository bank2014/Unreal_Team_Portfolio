// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BTS_ItemObject.generated.h"

class UMaterialInterface;
class ABTS_ItemUI;

// ItemObject Base Class.
// Admin: PSC
UCLASS(Blueprintable)
class BRUTALTAKEDOWNSQUAD_API UBTS_ItemObject : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FIntPoint GetDimensions() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMaterialInterface* GetIcon() const;

	UFUNCTION(BlueprintCallable)
	void Rotate();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsRotate();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TSubclassOf<ABTS_ItemUI> GetItemClass();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Rotated = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true, Instanced))
	FIntPoint Dimensions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true, Instanced))
	TObjectPtr<UMaterialInterface> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true, Instanced))
	TObjectPtr<UMaterialInterface> IconRotated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true, Instanced))
	TSubclassOf<ABTS_ItemUI> ItemClass;
};
