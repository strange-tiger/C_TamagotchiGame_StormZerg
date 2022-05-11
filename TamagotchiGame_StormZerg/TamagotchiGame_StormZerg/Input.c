#include "Common.h"
#include "Input.h"

#define IS_KEY_PRESSED(vkey) (0x8000 & GetAsyncKeyState(vkey))

// 이전 프레임의 키 상태
bool s_isKeyPressedOnPrevFrame[256];

// 현재 프레임의 키 상태
bool s_isKeyPressedOnCurrentFrame[256];

void Input_Update(void)
{
	// 이전 프레임의 키 상태를 저장 -> memcpy 함수로 s_isKeyPressedOnCurrentFrame의 데이터를 s_isKeyPressedOnPrevFrame로 복사
	memcpy(s_isKeyPressedOnPrevFrame, s_isKeyPressedOnCurrentFrame, sizeof(s_isKeyPressedOnCurrentFrame));

	for (int32 vkey = 0; vkey < 256; vkey++)
	{
		if (IS_KEY_PRESSED(vkey))
		{
			s_isKeyPressedOnCurrentFrame[vkey] = true;
		}
		else
		{
			s_isKeyPressedOnCurrentFrame[vkey] = false;
		}
	}
}

bool Input_GetKeyPressed(uint8 vkey)		// 키가 눌러진 순간
{
	if (s_isKeyPressedOnPrevFrame[vkey] == false && s_isKeyPressedOnCurrentFrame[vkey] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_GetKeyNonPressed(uint8 vkey)		// 키가 떼어진 순간
{
	if (s_isKeyPressedOnPrevFrame[vkey] == true && s_isKeyPressedOnCurrentFrame[vkey] == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_GetKey(uint8 vkey)		// 키가 눌러지고 있는 동안
{
	if (s_isKeyPressedOnPrevFrame[vkey] == true && s_isKeyPressedOnCurrentFrame[vkey] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}