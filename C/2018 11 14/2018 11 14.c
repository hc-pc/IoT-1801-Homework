#include <stdio.h>

/*
 *使用遍历的方法实现从一个数组中找出值的下标
 *
 *注意：
 *1.下标表示从零开始
 *2.数组共10个成员
 *
 *张洪铭 物联网 1801 2018-11-14 22：13
 *
 */

int main() {
	int array[9] = {0};
	int key;
	int i;
	for (i = 0; i < 10; i++) {
		scanf("%d", &array[i]);
	}
	printf("---------------\n");
	while (true) {
		scanf("%d", &key);
		for (i = 0; i < 10; i++) {
			if (key == array[i]) {
				printf("%d\n\n", i);
				break;
			}
			else {
				if (i == 9) {
					printf("-1\n\n");
					break;
				}
			}
		}
	}
	return 0;
}

/*    输出结果    */ 

/*
 *	1 2 3 4 5 6 7 8 9 10
 *	---------------
 *	5
 *	4
 *	
 *	13
 *	-1
 *	
 *	9
 *	8
 *	
 *	13
 *	-1
 *	
 *	10
 *	9
 *	
 *	
 */
