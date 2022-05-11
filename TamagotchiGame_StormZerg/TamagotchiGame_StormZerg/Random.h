#pragma once

#include "Type.h"

// 랜덤 초기화
void Random_Init(void);

// 무작위 정수를 가져온다.
// min : 최솟값 // max : 최댓값
// [min, max) 범위의 무작위 정수
int32 Random_GetIntegerNumFromRange(int32 min, int32 max);

// 무작위 실수를 가져온다.
// min : 최솟값 // max : 최댓값
// [min, max] 범위의 무작위 실수
float Random_GetFloatNumFromRange(float min, float max);

