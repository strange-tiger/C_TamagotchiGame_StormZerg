#include "Common.h"
#include "Renderer.h"

HANDLE s_screens[2];
int32 s_backBufferIndex;

bool Renderer_Init(void)
{
    // 스크린을 만든다.
	s_screens[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[0] == INVALID_HANDLE_VALUE)				// 예외 처리
	{
		return false;
	}

	s_screens[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (s_screens[1] == INVALID_HANDLE_VALUE)				// 예외 처리
	{
		CloseHandle(s_screens[0]);
		// s_screens[0]은 정상적으로 만들어졌으므로 정리를 해줘야 한다.

		return false;
	}

	return true;
}

void Renderer_Cleanup(void)									// 자원 정리
{
    CloseHandle(s_screens[0]);
    CloseHandle(s_screens[1]);
}

void Renderer_Flip(void)									// 더블 버퍼링을 위한 스크린 전환 함수
{
	// 1. 현재 콘솔의 스크린 버퍼를 백 버퍼로 지정
	SetConsoleActiveScreenBuffer(s_screens[s_backBufferIndex]);
	// SetConsoleActiveScreenBuffer() : 어떤 스크린을 사용할 지 결정하는 함수

// 2. 백 버퍼 전환
	s_backBufferIndex = !s_backBufferIndex;
}

void Renderer_Clear(void)									// 스크린 정리 함수 : 백 버퍼의 내용을 지우는 함수  
{
	HANDLE consoleHandle = s_screens[s_backBufferIndex];

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}

void Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y)	// 이 프레임 워크에서는 printf 등의 콘솔 출력 함수를 더 이상 쓸 수 없기에, 새로이 함수를 정의하여 출력
// 문자색 등의 속성이 들어간 문자열을 출력, 출력 위치 지정 가능
{
	// 1. 백 버퍼에 대한 핸들을 가져온다.
	HANDLE backBuffer = s_screens[s_backBufferIndex];

	// 2. 커서 위치를 옮겨준다.
	COORD pos = { x, y };
	SetConsoleCursorPosition(backBuffer, pos);

	// 3. 백 버퍼에 텍스트를 출력한다.
	for (int32 i = 0; i < numberOfChar; ++i)
	{
		SetConsoleTextAttribute(backBuffer, text[i].Attributes);
		WriteConsole(backBuffer, &text[i].Char, 1, NULL, NULL);
	}
	SetConsoleTextAttribute(backBuffer, TEXT_COLOR_WHITE);
	// WriteConsole() : 현재 커서 위에서 문자열을 출력하는 함수
	// WriteConsole() -> w버전, 유니코드 WriteConsoleA() -> A버전, 아스키코드 
	// SetConsoleTextAttribute() : 텍스트의 색을 지정하는 함수
}