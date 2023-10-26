// Copyright JiminKim

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

// ���ͳ� �÷��̾� ĳ������ ���̽��� �� Ŭ����
// ������ �� �� Ŭ������ �ƴϴϱ� ��ӹ޾Ƽ� ��� Ŭ������ Abstract ������
// Abstract Ŭ������ ������ �巡���ؼ� ����� ����
UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

};
