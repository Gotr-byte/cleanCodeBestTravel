#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size;

void generateSubArraysSummariseThem(int* input, int* current, int currentSize, int index, int n, int *result, int maxSum, int *isValidFlag) {
    int tmpSum;
	tmpSum = 0;
	if (currentSize == n) {
        for (int i = 0; i < currentSize; i++) {
			tmpSum = current[i] + tmpSum;
	
        }
		if (*result == -1 ||
		(tmpSum <= maxSum &&
		tmpSum > *result)){
			*result = tmpSum;
		}
		if(tmpSum <= maxSum){
			*isValidFlag = 1;
		}
        return;
    }

    // Generate arrays recursively
    for (int i = index; i < size; i++) {
        // Add the current element to the current array
        current[currentSize] = input[i];

        // Generate arrays with the next element
        generateSubArraysSummariseThem(input, current, currentSize + 1, i + 1, n, result, maxSum, isValidFlag);
    }
}
static int isFunctionValid(maxSum, numTownsVisit){
	if (maxSum < 0 ||
	numTownsVisit < 1 ||
	numTownsVisit > size)
		return 0;
	else
		return 1;
}
// Returns result
int *chooseBestSum(int maxSum, int numTownsVisit, int *input){
	if(!isFunctionValid)
		return NULL;
	// if (maxSum < 0)
	// 	return NULL;
	// if (numTownsVisit < 1)
	// 	return NULL;
	// if (numTownsVisit > size)
	// 	return NULL;

	int* current = (int*)malloc(numTownsVisit * sizeof(int));
	int* result = (int*)malloc(sizeof(int));
	*result = -1;
	int* isValidFlag = (int*)malloc(sizeof(int));
	*isValidFlag = 0;

    // Generate arrays starting from index 0
    generateSubArraysSummariseThem(input, current, 0, 0, numTownsVisit, result, maxSum, isValidFlag);
	printf("result=%d\n", *result);

	free(isValidFlag);
    free(current);
	
	if (isValidFlag == 0){
		free(result);
		return(NULL);
	}
	else{
		return(result);
	}
}

int main() {
	int input[] = {50, 55, 56, 57, 58};
    int n = 3;  // Number of elements in each generated array
	int maxSum = 163;
	size = sizeof(input) / sizeof(input[0]);

	chooseBestSum(maxSum, n, input);
    return 0;
}
