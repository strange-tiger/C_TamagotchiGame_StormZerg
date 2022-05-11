#pragma once

#include "Type.h"

// 게임을 초기화
// 초기화에 성공했으면 true, 아니면 false
bool Gmae_Init(void);

// 게임을 실행
// 앱이 정상적으로 종료됐다면 0, 아니라면 0이 아닌값
int32 Game_Run(void);