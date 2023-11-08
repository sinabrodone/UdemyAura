// Copyright


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	// 멀티 관련
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);
	
	// UEnhancedInputLocalPlayerSubsystem은 싱글톤
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	// 0는 우선순위
	Subsystem->AddMappingContext(AuraContext, 0);

	//마우스 커서 보이기
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	// 뷰포트에서 마우스 안막음
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	// 기존의 inputcomponent(플레이어컨트롤러에 기본변수로 있었음)를 enhanced버전으로 바꿔야함
	// CastChecked 캐스트 실패시 크래쉬
	// #include "EnhancedInputComponent.h"
	UEnhancedInputComponent* EnhancedInputComopennt = CastChecked<UEnhancedInputComponent>(InputComponent);

	// input액션과 바인드할 함수 연결
	EnhancedInputComopennt->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	// 어디가 앞인지 찾기
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
