#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PlayerNumber 50

//int Player[PlayerNumber] = {0};

struct playerno {
	int No;
	int Score[5];
};

struct PlayerList {
	struct playerno PlayerNo[PlayerNumber];
} PlayerList;

void sub_Welcome() {
	printf("+----------------------+\n");
	printf("|                      |\n");
	printf("| ��ӭ�������ֹ���ϵͳ |\n");
	printf("|                      |\n");
	printf("+----------------------+\n");
}

int sub_Login() {
	char UserName[5] = "PlanC";
	char UserPassword[6] = "114514";
	char InputName[5] = {"0"};
	char InputPassword[6] = {"0"};
	int RetryTimes = 3;
	int i = 0;

	printf("�������û���\n");
	for (RetryTimes; RetryTimes > 0; RetryTimes--) {
		scanf("%s", InputName);
		if (strcmp(UserName, InputName) == 0) {
			break;
		} else {
			if (RetryTimes == 0) {
				printf("�������δ��󣬳����Զ��˳���\n");
				return 1;
			}
			printf("δ�ҵ��û����������ԣ�ʣ�����%d��\n", RetryTimes);
		}
	}

	printf("����������\n");
	for (RetryTimes; RetryTimes > 0; RetryTimes--) {
		for (i = 0; i < 6; i++) InputPassword[i] = getch();
		InputPassword[6] = '\0';
		if (strcmp(UserPassword, InputPassword) == 0) {
			break;
		} else {
			if (RetryTimes == 0) {
				printf("�������δ������˳���\n");
				return 2;
			}
			printf("������������ԣ�ʣ�����%d��\n", RetryTimes);
		}
	}

	return 0;
}

int sub_GetScore() {
	int TempNo = 0;
	int Method;
	int i = 0;
	int j = 0;

	printf("�������������뷽ʽ(1Ϊ˳�����룬2Ϊ��������)��");
	scanf("%d", &Method);
	switch (Method) {
		case 0:
			PlayerList.PlayerNo[1].No = 1;
			PlayerList.PlayerNo[1].Score[0] = 42;
			PlayerList.PlayerNo[1].Score[1] = 76;
			PlayerList.PlayerNo[1].Score[2] = 96;
			PlayerList.PlayerNo[1].Score[3] = 12;
			PlayerList.PlayerNo[1].Score[4] = 86;
			return 0;
		case 1:
			printf("������������λ��ί�ɼ�\n");
			for (i = 0; i < PlayerNumber; i++) {
				PlayerList.PlayerNo[i].No = i;
				for (j = 0; j < 5 ; j++) scanf("%d", &PlayerList.PlayerNo[i].Score[j]);
			}
			return 0;
		case 2:
			printf("���������ѡ�ִ���\n");
			scanf("%d", &TempNo);
			printf("������������λ��ί����\n");
			PlayerList.PlayerNo[TempNo].No = TempNo;
			scanf("%d %d %d %d %d", &PlayerList.PlayerNo[TempNo].Score[0],
			      &PlayerList.PlayerNo[TempNo].Score[1],
			      &PlayerList.PlayerNo[TempNo].Score[2],
			      &PlayerList.PlayerNo[TempNo].Score[3],
			      &PlayerList.PlayerNo[TempNo].Score[4]);
			return 0;
		default:
			printf("δ�ҵ����������롣\n");
			return 1;
	}
}

int sub_Operate() {
	system("cls");

	printf("+-----------------------+\n");
	printf("|                       |\n");
	printf("| 1.��߷��� 2.��ͷ��� |\n");
	printf("| 3.ƽ������ 4.��ѯ���� |\n");
	printf("| 0.�˳�ϵͳ            |\n");
	printf("|                       |\n");
	printf("+-----------------------+\n");

	int i;
	int Index;
	int max = 0, min = 0;
	int maxIndex = 0, minIndex = 0;
	int TempNo;
	float TotalScore = 0.0;

	scanf("%d", &Index);
	switch (Index) {
		case 0: //�˳�ϵͳ
			return 0;
		case 1: //��߷���
			printf("������Ҫ��ѯ��ѡ�ֵĴ���\n");
			scanf("%d", &TempNo);
			max = PlayerList.PlayerNo[TempNo].Score[0];
			for (i = 1; i < 5; i++) {
				if (max < PlayerList.PlayerNo[TempNo].Score[i]) max = PlayerList.PlayerNo[TempNo].Score[i];
			}
			printf("��߷�Ϊ%d\n", max);
			return 1;
		case 2: //��ͷ���
			printf("������Ҫ��ѯ��ѡ�ֵĴ���\n");
			scanf("%d", &TempNo);
			min = PlayerList.PlayerNo[TempNo].Score[0];
			for (i = 1; i < 5; i++) {
				if (min > PlayerList.PlayerNo[TempNo].Score[i]) min = PlayerList.PlayerNo[TempNo].Score[i];
			}
			printf("��ͷ�Ϊ%d\n", min);
			return 2;
		case 3: //
			printf("������Ҫ��ѯ��ѡ�ֵĴ���\n");
			scanf("%d", &TempNo);
			max = PlayerList.PlayerNo[TempNo].Score[0];
			for (i = 1; i < 5; i++) {
				if (max < PlayerList.PlayerNo[TempNo].Score[i]) {
					max = PlayerList.PlayerNo[TempNo].Score[i];
					maxIndex = i;
				}
			}
			min = PlayerList.PlayerNo[TempNo].Score[0];
			for (i = 1; i < 5; i++) {
				if (min > PlayerList.PlayerNo[TempNo].Score[i]) {
					min = PlayerList.PlayerNo[TempNo].Score[i];
					minIndex = i;
				}
			}
			for (i = 0; i < 5; i++) {
				if (i == maxIndex || i == minIndex) {
					continue;
				}
				else {
					TotalScore = TotalScore + PlayerList.PlayerNo[TempNo].Score[i];
				}
			}
			printf("�ܷ�Ϊ%.2f\n", TotalScore); 
			printf("ƽ����Ϊ%.2f\n", TotalScore / 3);
			return 3;
		case 4:
			printf("������Ҫ��ѯ��ѡ�ֵĴ���\n");
			scanf("%d", &TempNo);
			for (i = 0; i < 5; i++) {
				printf("�� %d λ��ί \t %d \n", i, PlayerList.PlayerNo[TempNo].Score[i]);
			}
			return 4;
	}
}

int main() {

	sub_Welcome();

	if (sub_Login() != 0) {
		return 1;
	}
	system("cls");

	while (1) {
		if (sub_GetScore() == 0) {
			break;
		}
	}
	system("cls");

	while (1) {
		if (sub_Operate() == 0) {
			break;
		}
		else {
			printf("\n�밴���������...\n");
			getch();
		}
	}
	system("cls");

	return 0;
}
