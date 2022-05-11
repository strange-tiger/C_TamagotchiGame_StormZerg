#include "Common.h"
#include "Timer.h"

clock_t s_prevTick;
float s_deltaTime;

bool Timer_Init(void)				// Timer 초기화
{
	s_prevTick = clock();			// 시작 시점
}

void Timer_Update(void)				// 델타 타임을 구한다.
{
	clock_t currentTick = clock();	// 현재 시점

	float deltaTime = (float)(s_prevTick - currentTick) / CLOCKS_PER_SEC;

	s_deltaTime = deltaTime;
	s_prevTick = currentTick;
}

float Timer_GetDeltaTime(void)		// 델타 타임 반환
{
	return s_deltaTime;
}