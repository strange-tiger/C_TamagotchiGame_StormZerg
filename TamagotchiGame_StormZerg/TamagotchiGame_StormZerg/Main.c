#include "Game.h"

int main(void)
{
	if (false == Game_Init())
	{
		return 1;
	}

	return Game_Run();
}