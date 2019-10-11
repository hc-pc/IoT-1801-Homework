#include <stdio.h>
#include <strings.h>

/*
 *
 *
 *ע�⣺
 *
 *�ź��� ������ 1801 2018-11-23 22��49
 *
 */

int main() {
	char operation[9];
	scanf("%s",&operation);
	char alphabetUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alphabetLower[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	if (operation == "encode") {
		char toDecode[100];
		scanf("%s",&toDecode);
		int i;
		int key;
		int temp;
		scanf("%d",&key);
		if (key < 3 || key > 26) {
			printf("��������");
			return 1;
		}
		for (i = 0; i < strlen(toDecode); i++) {
			//��д���
			if ((int)toDecode[i] > 64 && (int)toDecode[i] < 91) {
				printf("%c", alphabetUpper[(int)toDecode[i] + 65 - key]);
			}
			//Сд���
			else if ((int)toDecode[i] > 96 && (int)toDecode[i] < 123) {
				printf("%c", alphabetLower[(int)toDecode[i] + 97 - key]);
			}
			//����ĸ���
			else {
				printf("���벻�Ϸ�");
				return 1;
			}
		}
		printf("\n");
		return 0;
	} 
	else if (operation == "decode") {
		char toEncode[100];
		scanf("%s", &toEncode);
		int i;
		int key;
		int temp;
		scanf("%d", &key);
		if (key < 3 || key > 26) {
			printf("��������");
			return 1;
		}
		for (i = 0; i < strlen(toEncode); i++) {
			//��д���
			if ((int)toEncode[i] > 64 && (int)toEncode[i] < 91) {
				printf("%c", alphabetUpper[(int)toEncode[i] - 65 + key]);
			}
			//Сд���
			else if ((int)toEncode[i] > 96 && (int)toEncode[i] < 123) {
				printf("%c", alphabetLower[(int)toEncode[i] - 97 + key]);
			}
			//����ĸ���
			else {
				printf("���벻�Ϸ�");
				return 1;
			}
		}
		printf("\n");
		return 0;
	}
	else {
		return 1;
	}
	return 0;
}

/*    ������    */

