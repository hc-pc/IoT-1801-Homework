#include <stdio.h>
#define DEBUG

int main() {
	int i = 0;
	int array1[5] = {0};
	int array2[5] = {0};
	int combinearray[10] = {0};
	int *array1pointer = array1;
	int *array2pointer = array2;
	int *combinepointer = combinearray;

#ifdef RELEASE
	for (i = 0; i < 5; i++) scanf("%d", &array1[i]);
	for (i = 0; i < 5; i++) scanf("%d", &array2[i]);
#endif

#ifdef DEBUG
	for (i = 1; i < 6; i++) {
		array1[i - 1] = i * i * i;//1 8 27 64 125
		array2[i - 1] = i + i + i;//3 6  9 12  15
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
