#include <stdio.h>
#define DEBUG

int main() {
	int i = 0;
	int j = 0;
	int k = 0;
	int array1[5] = {0};
	int array2[5] = {0};
	int finalArray[10] = {0};

#ifdef DEBUG
	for (i = 1; i < 6; i++) {
		array1[i - 1] = i * i * i;//1 8 27 64 125
		array2[i - 1] = i + i + i;//3 6  9 12  15
	}
	for (i = 0; i < 5; i++) printf("%-5d", array1[i]);
	printf("\n");
	for (i = 0; i < 5; i++) printf("%-5d", array2[i]);
	printf("\n");
#endif

#ifdef RELEASE
	for (i = 0; i < 5; i++) scanf("%d", &array1[i]);
	for (i = 0; i < 5; i++) scanf("%d", &array2[i]);
#endif

	for (i = 0; i < 10;) {
		if (array1[j] < array2[k]) {
			finalArray[i++] = array1[j++];
		}
		if (array1[j] == array2[k]) {
			finalArray[i++] = array1[j++];
			finalArray[i++] = array2[k++];
		}
		if (array1[j] > array2[k]) {
			finalArray[i++] = array2[k++];
		}
		if (j == 5 || k == 5) break;
	}

	for (j; j < 5; j++) finalArray[i++] = array1[j];
	for (k; k < 5; k++) finalArray[i++] = array2[k];

	for (i = 0; i < 10; i++) printf("%-5d ", finalArray[i]);

	return 0;
}
