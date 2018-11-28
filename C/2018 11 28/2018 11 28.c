#include <stdio.h>

/*
 *使用选择排序法排序数组
 *
 *注意：无
 *
 *张洪铭 物联网1801 2018-11-28 16：28
 *
 */ 

int main() {
	int n;
	int i;
	int min;
	scanf("%d",&n);
	int array[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d",&array[i]);
	}
	
	for (i = 0; i < n - 1; i++) {
  
		int j;
		int temp;
		int index = i;
		min = array[i];
    
		for (j = i + 1; j < n; j++) {
    
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
      
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
      
		}
    
	}
	
	for (i = 0; i < n; i++) {
		printf("%d ",array[i]);
	}
}

/*    输出结果    */

/*	
 * 	6
 *	64 7 67 1654 711 6
 *	6 7 64 67 711 1654
 *	--------------------------------
 *	Process exited after 10.34 seconds with return value 0
 *	请按任意键继续. . .
 */
