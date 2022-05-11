#pragma once

#include "Type.h"

// 렌더러를 초기화
// 초기화에 성공했으면 true, 아니면 false
bool   Renderer_Init(void);

// 렌더러를 정리
void   Renderer_Cleanup(void);


// 화면을 바꾼다.
void   Renderer_Flip(void);

// 화면에 텍스트를 출력한다.
void   Renderer_DrawText(const char* text, int32 numberOfChar);