#include "Common.h"
#include "Game.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"

bool Game_Init() 						    // 초기화
{
	if (false == Renderer_Init())			// 예외 처리
	{
		return false;
	}
	return true;
}

void processInput()				        	// 입력 처리
{
	Input_Update();
}

// char str[128];
void update()				        		// 게임 업데이트 : 갱신
{
	//sprintf_s(str, sizeof(str), "Text");
	// Timer_GetDeltaTime();
}

void render()							    // 게임 출력
{
	// Renderer_DrawText("Text", sizeof("Text"));

	// 더블 버퍼링
	// 1. 화면 전환하고
	Renderer_Flip();

	// 2. 백 버퍼의 내용(이전 화면)을 지워준다.
	Renderer_Clear();
}

int32 Game_Run()			    			// 게임 실행
{
	Timer_Init();							// Timer 초기화
	Random_Init();							// Random 초기화

	// Game Loop
	while (true)
	{

		Timer_Update();						// Timer 업데이트
		processInput();						// 입력처리
		update();							// 게임 업데이트
		render();							// 게임 출력 

	}

	return 0;
}