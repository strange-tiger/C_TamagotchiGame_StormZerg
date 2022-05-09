#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main(void)
{
    int Mon_HP;
    int Mon_Health;
    int LeftSpace = 32;
    int Display_menu = 0;
    int SpaceMoving;
    // Display Position Test
    // 메뉴에 따라 if문으로 구분

    while (1)
    {
        system("cls");
        if (Display_menu == 0) // Main Display
        {
            for (int i = 1; i <= 16; i++)
            {
                for (int j = 1; j <= LeftSpace; j++)
                {
                    printf("0");
                    //+Monster Image
                }
                printf("\n");
            }
            if (LeftSpace < 4)
            {
                SpaceMoving = 2;
            }
            else if (LeftSpace > 30)
            {
                SpaceMoving = -2;
            }
            LeftSpace += SpaceMoving;
            Sleep(500);
        }
        else if (Display_menu == 1) // Status Display
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
    }
    return 0;
}