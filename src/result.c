#include "result.h"
#include <stdio.h>

Result initResult(int numIteration)
{
	Result result;
	result.numIteration = numIteration;
	result.numCollision = 0;
	result.numEmpty = 0;

	return result;
}

void printResult(Result result)
{
	printf("Number of iteration: %d \nNumber of empty slots: %lf \nNumber of collision: %lf \nNumero total de slots: %lf\n", result.numIteration, result.numEmpty, result.numCollision, result.numIteration+result.numCollision+result.numEmpty);
}

Result addResult(Result a, Result b)
{
	Result result = initResult(a.numIteration);
	result.numEmpty = a.numEmpty + b.numEmpty;
	result.numCollision = a.numCollision + b.numCollision;

	return result;
}

Result divResult(Result a, int b)
{
	Result result = initResult(a.numIteration);
	result.numEmpty = a.numEmpty / b;
	result.numCollision = a.numCollision / b;

	return result;
}
