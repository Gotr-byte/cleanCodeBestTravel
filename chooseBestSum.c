#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chooseBestSum.h"

void compareSums(t_variables *variables, int currentSize, int maxSum, int *result){
	int tmpSum = 0;
	 for (int i = 0; i < currentSize; i++) {
		tmpSum = variables->current[i] + tmpSum;
	}
	if (*result == -1 ||
	(tmpSum <= maxSum &&
	tmpSum > *result)){
		*result = tmpSum;
	}
	if(tmpSum <= maxSum){
		*variables->isValidFlag = 1;
	}
}

void addSubArrayElement(t_variables *variables, const int* input, int currentSize, int i){
	variables->current[currentSize] = input[i];
}

void generateSubArraysSummariseThem(const int* input, t_variables *variables, int currentSize, int index, int numTownsVisit, int *result, int maxSum) {
	if (currentSize == numTownsVisit) {
		compareSums(variables, currentSize, maxSum, result);
        return;
    }
    for (int i = index; i < size; i++) {
		addSubArrayElement(variables, input, currentSize, i);
        generateSubArraysSummariseThem(input, variables, currentSize + 1, i + 1, numTownsVisit, result, maxSum);
    }
}

static int isFunctionValid(int maxSum, int numTownsVisit){
	if (maxSum < 0 ||
	numTownsVisit < 1 ||
	numTownsVisit > size)
		return 0;
	else
		return 1;
}

t_variables* initializeVariables(int numTownsVisit) {
    t_variables* variables = (t_variables*)malloc(sizeof(t_variables));
    variables->current = (int*)malloc(numTownsVisit * sizeof(int));
    variables->isValidFlag = (int*)malloc(sizeof(int));
    *(variables->isValidFlag) = 0;
    return variables;
}

void freeVariables(t_variables *variables){
	free(variables->isValidFlag);
    free(variables->current);
	free(variables);
}

int *chooseBestSum(int maxSum, int numTownsVisit, const int *input){
	if(!isFunctionValid(maxSum, numTownsVisit))
		return NULL;
	t_variables *variables = initializeVariables(numTownsVisit);
	
 	int *result = (int*)malloc(sizeof(int));
    *(result) = -1;

    generateSubArraysSummariseThem(input, variables, 0, 0, numTownsVisit, result, maxSum);
	printf("result=%d\n", (*result));
	freeVariables(variables);

	if (variables->isValidFlag == 0){
		free(variables->result);
		return(NULL);
	}
	else{
		return(result);
	}
}

int main() {
	const int input[] = {50, 55, 56, 57, 58};
    int n = 3;  // Number of elements in each generated array
	int maxSum = 163;
	size = sizeof(input) / sizeof(input[0]);

	chooseBestSum(maxSum, n, input);
    return 0;
}
