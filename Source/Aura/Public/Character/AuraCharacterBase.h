// Copyright JiminKim

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

// 몬스터나 플레이어 캐릭터의 베이스가 될 클래스
// 실제로 뭘 할 클래스가 아니니깐 상속받아서 사용 클래스라 Abstract 지정자
// Abstract 클래스는 레벨로 드래그해서 만들수 없음
UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

};
