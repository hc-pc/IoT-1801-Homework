#include <stdio.h>

#define RELEASE

int compare(int *number1, int *number2) {

	if (number1 - number2 > 0) return 1;	if (number1 - number2 == 0) return 0;

	if (number1 - number2 < 0) return -1;

}

int main() {

	int i = 0;

	int array1[5] = {0};

	int array2[5] = {0};

	int combinearray[10] = {0};

	int *array1pointer = &array1[0];

	int *array2pointer = &array2[0];

	int *combinepointer = &combinearray[0];

#ifdef RELEASE

	for (i = 0; i < 5; i++) scanf("%d", &array1[i]);

	for (i = 0; i < 5; i++) scanf("%d", &array2[i]);

#endif

#ifdef DEBUG

	for (i = 1; i < 6; i++) {

		array1[i - 1] = i * i;//1 4 9 16 25

		array2[i - 1] = i + 1;//2 3 4  5  6

	}

	for (i = 0; i < 5; i++) printf("%5d", array1[i]);

	printf("\n");

	for (i = 0; i < 5; i++) printf("%5d", array2[i]);

	printf("\n");

#endif

	while (*array1pointer && *array2pointer) {

		if (*array1pointer < *array2pointer) *combinepointer++ = *array1pointer++;

		if (*array1pointer == *array2pointer) {

			*combinepointer++ = *array1pointer++;

			*combinepointer++ = *array2pointer++;

		}

		if (*array1pointer > *array2pointer) *combinepointer++ = *array2pointer++;

	}

	while (*array1pointer != array1[5]) *combinepointer++ = *array1pointer++;

	while (*array2pointer != array2[5]) *combinepointer++ = *array2pointer++;

	printf("\n");

	for (i = 0; i < 10; i++) printf("%5d", combinearray[i]);

	return 0;

}
