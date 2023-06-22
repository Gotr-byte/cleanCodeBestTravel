#ifndef BESTSUM_H
#define BESTSUM_H

int size;

typedef struct s_variables {
    int* current;
    int* result;
    int* isValidFlag;
	int	 currentSize;
	int	 i;
} t_variables;

//Operational
void compareSums(t_variables *variables, int currentSize, int maxSum, int *result);
void addSubArrayElement(t_variables *variables, const int* input, int currentSize, int i);
void generateSubArraysSummariseThem(const int* input, t_variables *variables, int currentSize, int index, int numTownsVisit, int *result, int maxSum);
#endif