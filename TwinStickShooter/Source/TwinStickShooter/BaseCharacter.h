// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)		// 클래스를 블루프린트로 구현 가능하게 설정
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

// Make a health property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Health = 100;
	
// Make an isDead property
	UPROPERTY(BlueprintReadOnly, Category = "Base Character")
		bool isDead = false;

// Calculate death function (helper)
	virtual void CalculateDead();

// Calculate health function

	// BlueprintCallable : 이 함수를 블루프린트의 노드로 바꿔줌
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR				// 에디터 상에서 값에 변화를 줄 경우 변화에 반응하여 특정 코드를 실행
// Editor-centic code for changing properies

	// 실제로 있는 명령어
	// FPropertyChangedEvent :언리얼 엔진4 로부터 오는 통보로 프로퍼티에 변화를 줬다는 것을 알려주는 것
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
