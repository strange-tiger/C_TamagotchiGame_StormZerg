#pragma once

#include <stdbool.h>

// 타이머를 초기화
bool Timer_Init(void);

// 타이머를 업데이트
void Timer_Update(void);
float Timer_GetDeltaTime(void);