// Copyright


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	// ��Ƽ ����
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);
	
	// UEnhancedInputLocalPlayerSubsystem�� �̱���
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	// 0�� �켱����
	Subsystem->AddMappingContext(AuraContext, 0);

	//���콺 Ŀ�� ���̱�
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	// ����Ʈ���� ���콺 �ȸ���
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	// ������ inputcomponent(�÷��̾���Ʈ�ѷ��� �⺻������ �־���)�� enhanced�������� �ٲ����
	// CastChecked ĳ��Ʈ ���н� ũ����
	// #include "EnhancedInputComponent.h"
	UEnhancedInputComponent* EnhancedInputComopennt = CastChecked<UEnhancedInputComponent>(InputComponent);

	// input�׼ǰ� ���ε��� �Լ� ����
	EnhancedInputComopennt->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	// ��� ������ ã��
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	const FVector FowardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	APawn* ControlledPawn = GetPawn<APawn>();
	if (ControlledPawn)
	{
		ControlledPawn->AddMovementInput(FowardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
