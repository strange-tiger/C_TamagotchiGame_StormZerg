#pragma once

#include <stdbool.h>
#include "Common.h"
#include "Text.h"

// 렌더러를 초기화
// 초기화에 성공했으면 true, 아니면 false
bool   Renderer_Init(void);

// 렌더러를 정리
void   Renderer_Cleanup(void);


// 화면을 바꾼다.
void   Renderer_Flip(void);

// 화면에 텍스트를 출력한다.
void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y);
// printf를 더 이상 못 쓰기에, 콘솔에 출력할 함수를 만듦
// 문자색 등의 속성이 들어간 문자열을 출력, 출력 위치 지정 가능