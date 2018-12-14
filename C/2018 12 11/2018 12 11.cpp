#include <stdio.h>

/*
 *使用冒泡排序法排序一个数组
 *
 *注意：
 *1.先输入数组元素数
 *
 *张洪铭 物联网 1801 2018-12-14 22：49
 *
 */

int main() {
	int n;
	int i;
	scanf("%d", &n);
	int array[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	int j;
	int temp;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
