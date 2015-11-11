#ifndef DFSA_SIMULATOR_INCLUDE_RESULT_H_
#define DFSA_SIMULATOR_INCLUDE_RESULT_H_ 1


typedef struct result 
{
	int numIteration;
	double numEmpty;
	double numCollision;
} Result;

Result initResult(int numIteration);

void printResult(Result result);

Result addResult(Result a, Result b);

Result divResult(Result a, int b);

#endif