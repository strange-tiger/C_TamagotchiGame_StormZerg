
#include "Common.h"
#include "PrintDotImage.h"
#include "Renderer.h"
#include "Input.h"

#define DOT_IMAGE_SIZE_X 8
#define DOT_IMAGE_SIZE_Y 8

char str[DOT_IMAGE_SIZE_Y][DOT_IMAGE_SIZE_X + 2];

void PrintDotImage_GenerateDotImage(void)
{
	for (int i = 0; i < DOT_IMAGE_SIZE_Y; i++)
	{
		for (int j = 0; j < DOT_IMAGE_SIZE_X; j++)
		{
			str[i][j] = '0';
		}

		str[i][DOT_IMAGE_SIZE_X] = '\n';
		str[i][DOT_IMAGE_SIZE_X + 1] = '\0';
	}
}

/*
void PrintDotImage_Print(void)
{
	for (int i = 0; i < DOT_IMAGE_SIZE_Y; i++)
		Renderer_DrawText(str[i], strlen(str[i]));
}
*/

#define SPACE_MOVING 2

int32 leftSpace;
int32 upSpace;
int32 leftSpaceMoving;
int32 upSpaceMoving;

void PrintDotImage_Init(void)
{
	leftSpace = 32;
	upSpace = 8;
	leftSpaceMoving = 0;
	upSpaceMoving = 0;
}

void PrintDotImage_PrintMove(void)
{
	// 화살표 키가 눌리면 SPACE_MOVING만큼 이동하도록
	if (Input_GetKey(VK_LEFT) && leftSpace >= 2)
		leftSpaceMoving = -SPACE_MOVING;
	else if (Input_GetKey(VK_RIGHT) && leftSpace <= 64)
		leftSpaceMoving = +SPACE_MOVING;
	else if (Input_GetKey(VK_UP) && upSpace >= 2)
		upSpaceMoving = -SPACE_MOVING;
	else if (Input_GetKey(VK_DOWN) && upSpace <= 16)
		upSpaceMoving = +SPACE_MOVING;

	leftSpace += leftSpaceMoving;
	upSpace += upSpaceMoving;

	for (int i = 1; i <= upSpace; i++)
	{
		Renderer_DrawText("\n", sizeof("\n"));
	}
	for (int i = 1; i < DOT_IMAGE_SIZE_Y; i++)
	{
		for (int j = 1; j <= leftSpace; j++)
		{
			Renderer_DrawText(" ", sizeof(" "));
		}
		Renderer_DrawText(str[i], strlen(str[i]));
		printf("\n");
	}

	leftSpaceMoving = 0;
	upSpaceMoving = 0;

	Sleep(50);
}