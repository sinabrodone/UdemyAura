// Copyright


#include "Character/AuraCharacterBase.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// CreateDefaultSubobject�� ���� FName�޾Ƽ� TEXT��ũ�� �� �ʿ� ����
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	// ���� ���̷�Ż �޽� ������Ʈ��, ���� ���̷�Ż �޽� ���Ͽ� ����
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	// ����� � �ݸ��� �ۿ뵵 ���ϰ�
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


