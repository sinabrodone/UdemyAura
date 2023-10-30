// Copyright


#include "Character/AuraCharacterBase.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// CreateDefaultSubobject은 인자 FName받아서 TEXT매크로 쓸 필요 없음
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	// 웨폰 스켈레탈 메쉬 컴포넌트를, 메인 스켈레탈 메쉬 소켓에 장착
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	// 무기는 어떤 콜리전 작용도 안하게
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


