#include <stdio.h>
#include <String.h>

int UserInfo[2];
//���� ���� ���
//0    1    2


int ShowFunctions() {
	int temp;
	
	printf("�����빦��ǰ������ʹ�ù���\n\n");
	printf("1.����\t2.����\t3.ȡ��\t4.��ѯ\n");
	printf("5.����\t0.�˳�\n");
	scanf("%d", &temp);
	
	switch (temp) {
		case 0:
			return 0;
		case 1:
			printf("��������ϣ�������루��λ��\n");
			scanf("%d", &UserInfo[1]);
			printf("���������Ŀ������\n");
			scanf("%d", &UserInfo[2]);
			printf("���ţ�%d\n��%d\n", UserInfo[0], UserInfo[2]);
			return 1;
		case 2:
			int save;
			printf("����������:\n");
			scanf("%d", &save);
			UserInfo[2] = UserInfo[2] + save;
			return 2;
		case 3:
			int drow;
			int tempPassword;
			printf("��������������:\n");
			scanf("%d", &tempPassword); 
			if (tempPassword == UserInfo[1]) {
				printf("������ȡ����:\n");
				scanf("%d", &drow);
				if (drow > UserInfo[2]) {
					printf("��������\n");
				}
				else {
					UserInfo[2] = UserInfo[2] - drow;
					printf("�������Ϊ:%d\n", UserInfo[2]);
				}
			}
			return 3;
		case 4:
			printf("���ţ�%d\n��%d\n", UserInfo[0], UserInfo[2]);
			return 4;
		case 5:
			UserInfo[0] = 10000; 
			UserInfo[1] = 000000;
			UserInfo[2] = 0;
			return 5;
	}
}

int main() {
	UserInfo[0] = 10000; 
	UserInfo[1] = 000000;
	UserInfo[2] = 0;
		
	printf("��ӭ���������ۺ�ҵ��ƽ̨\n");
	char UserName[6] = "PlanC";
	char UserPassword[7] = "114514";
	char InputName[6], InputPassword[7];
	int RetryTimes = 0;
	
	for (RetryTimes = 0; RetryTimes < 3; RetryTimes++) {
		printf("�������û���:\n");
		scanf("%s", InputName);
		if (strcmp(InputName, UserName)) {
			printf("�û�������ȷ�������ԡ�\n");
			if (RetryTimes == 2) {
				printf("���δ��󣬳����˳���");
				return 1;
			}
		}
		else {
			printf("����������:\n");
			scanf("%s", InputPassword);
			if (strcmp(InputPassword, UserPassword)) {
				printf("���벻��ȷ�������ԡ�\n");
				if (RetryTimes == 2) {
					printf("���δ��󣬳����˳���");
				}
				return 2;
			}
			else {
				break;
			}
		}
	}
	
	while (true) {
		if (ShowFunctions() == 0) {
			return 0;
		}
	}

	return 0;
}
