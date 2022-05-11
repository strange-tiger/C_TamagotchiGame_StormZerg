#include "Common.h"
#include "Random.h"

#define RANDOM_NUMBER_RANGE (max - min)

void Random_Init(void)
{
	srand(time(NULL));
}

int32 Random_GetIntegerNumFromRange(int32 min, int32 max)
{
	int32 randomNum = 0;

	randomNum = (rand() * (rand() + rand())) % RANDOM_NUMBER_RANGE + min;

	return randomNum;
}


float Random_GetFloatNumFromRange(float min, float max)
{
	float frandomNum = 0.0f;

	frandomNum = RANDOM_NUMBER_RANGE * rand() / RAND_MAX + min;
	
	return frandomNum;
}