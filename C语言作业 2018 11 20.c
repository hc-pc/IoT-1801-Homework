#include <stdio.h>
#include <strings.h>

/*
 *使用遍历加密一段英文字符串
 *
 *注意：仅支持英文字母的转换。拒绝输入一切非英文字符
 *
 *张洪铭 物联网 1801 2018-11-23 22：49
 *
 */ 

int main() {
	char alphabetUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphabetLower[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	
	char toEncode[100];
	scanf("%s", &toEncode);
	
	//printf("%s", toEncode);
	
	int i;
	int key;
	int temp;
	
	scanf("%d", &key);
	
	if (key < 3 || key > 26) {
		printf("输入有误");
		return 1;
	}
	
	for (i = 0; i < strlen(toEncode); i++) {
		
		//大写情况 
		if ((int)toEncode[i] > 64 && (int)toEncode[i] < 91) {
			printf("%c", alphabetUpper[(int)toEncode[i] - 65 + key]);
		}

		//小写情况 
		else if ((int)toEncode[i] > 96 && (int)toEncode[i] < 123) {
			printf("%c", alphabetLower[(int)toEncode[i] - 97 + key]);
		}

		//非字母情况
		else {
			printf("输入不合法");
			return 1;
		}
	}
	
	//printf("_");
	
	printf("\n");
	return 0;
}

/*    输出结果    */ 

/*
 *	ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *	6
 *	GHIJKLMNOPQRSTUVWXYZABCDEF
 *	
 *	--------------------------------
 *	Process exited after 15.72 seconds with return value 0
 *	请按任意键继续. . .
 *
 */

/*
 *	abcdefghijklmnopqrstuvwxyz
 *	9
 *	jklmnopqrstuvwxyzabcdefghi
 *	
 *	--------------------------------
 *	Process exited after 12.78 seconds with return value 0
 *	请按任意键继续. . .
 *
 */
