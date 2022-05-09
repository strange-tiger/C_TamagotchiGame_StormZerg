#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define ARROW_KEY 224
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define UP_KEY 72
#define DOWN_KEY 80
#define SPACE_MOVING 2

int main(void)
{
	int monHP;
	int monHealth;
	int leftSpace = 32;
	int upSpace = 8;
	int monSpace = 32;
	int displayMenu = 0;
	// Display Position Test
	// 메뉴에 따라 if문으로 구분

	while (1)
	{
		system("cls");
		if (displayMenu == 0) // Main Display
		{
			int leftSpaceMoving = 0;
			int upSpaceMoving = 0;
			if (_kbhit())	// _kbhit() : 콘솔에서 키보드 입력을 확인
			{
				int key = _getch();

				if (key == ARROW_KEY || key == 0) {	// 화살표 키가 눌리면 SPACE_MOVING만큼 이동하도록
					key = _getch();
					switch (key) {
					case LEFT_KEY:
						if(leftSpace >= 2)
						leftSpaceMoving = - SPACE_MOVING;
						break;

					case RIGHT_KEY:
						if (leftSpace <= 64)
						leftSpaceMoving = + SPACE_MOVING;
						break;

					case UP_KEY:
						if (upSpace >= 2)
						upSpaceMoving = - SPACE_MOVING;
						break;

					case DOWN_KEY:
						if (upSpace <= 16)
						upSpaceMoving = + SPACE_MOVING;
						break;
					}

				}
				
				//for (int i = 1; i <= 16; i++)
				//{
				//    for (int j = 1; j <= LeftSpace; j++)
				//    {
				//        printf(" ");
				//        //+Monster Image
				//    }
				//    for (int j = 1; j <= MonSpace; j++)
				//    {
				//        printf("0");
				//        //+Monster Image
				//    }
				//    printf("\n");
				//}
				//if (LeftSpace < 4)
				//{
				//    SpaceMoving = 2;
				//}
				//else if (LeftSpace > 30)
				//{
				//    SpaceMoving = -2;
				//}
				//LeftSpace += SpaceMoving;
				//Sleep(500);
			}

			else if (displayMenu == 1) // Status Display
			{
				int StatusMenuDisplay = 0;
				if (StatusMenuDisplay == 0)
				{
					printf("몸무게, HP 정보 표기");
					printf("키 입력 가능해야함");
					Sleep(3000);
				}
				else if (StatusMenuDisplay == 1)
				{
					printf("배고픔 정도 표시");
					printf("키 입력 가능해야함");
					Sleep(3000);
				}
			}

			leftSpace += leftSpaceMoving;
			upSpace += upSpaceMoving;

			for (int i = 1; i <= upSpace; i++)
			{
				/*if (upSpace >= 80 || upSpace == 1)
				{
					continue;
				}*/
				printf("\n");
			}
			for (int i = 1; i <= 16; i++)
			{
				for (int j = 1; j <= leftSpace; j++)
				{
					/*if (leftSpace >= 80 || leftSpace == 1)
					{
						break;
					}*/
					printf(" ");
					//+Monster Image
				}
				for (int j = 1; j <= monSpace; j++)
				{
					printf("0");
					//+Monster Image
				}
				printf("\n");
			}

			Sleep(100);
		}
	}
	return 0;
}