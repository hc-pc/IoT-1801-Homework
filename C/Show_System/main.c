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
	printf("| 欢迎来到歌手管理系统 |\n");
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

	printf("请输入用户名\n");
	for (RetryTimes; RetryTimes > 0; RetryTimes--) {
		scanf("%s", InputName);
		if (strcmp(UserName, InputName) == 0) {
			break;
		} else {
			if (RetryTimes == 0) {
				printf("连续三次错误，程序自动退出。\n");
				return 1;
			}
			printf("未找到用户名，请重试，剩余机会%d。\n", RetryTimes);
		}
	}

	printf("请输入密码\n");
	for (RetryTimes; RetryTimes > 0; RetryTimes--) {
		for (i = 0; i < 6; i++) InputPassword[i] = getch();
		InputPassword[6] = '\0';
		if (strcmp(UserPassword, InputPassword) == 0) {
			break;
		} else {
			if (RetryTimes == 0) {
				printf("连续三次错误，已退出。\n");
				return 2;
			}
			printf("密码错误，请重试，剩余机会%d。\n", RetryTimes);
		}
	}

	return 0;
}

int sub_GetScore() {
	int TempNo = 0;
	int Method;
	int i = 0;
	int j = 0;

	printf("请设置评分输入方式(1为顺序输入，2为乱序输入)。");
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
			printf("请依次输入五位评委成绩\n");
			for (i = 0; i < PlayerNumber; i++) {
				PlayerList.PlayerNo[i].No = i;
				for (j = 0; j < 5 ; j++) scanf("%d", &PlayerList.PlayerNo[i].Score[j]);
			}
			return 0;
		case 2:
			printf("请先输入该选手代号\n");
			scanf("%d", &TempNo);
			printf("请依次输入五位评委评分\n");
			PlayerList.PlayerNo[TempNo].No = TempNo;
			scanf("%d %d %d %d %d", &PlayerList.PlayerNo[TempNo].Score[0],
			      &PlayerList.PlayerNo[TempNo].Score[1],
			      &PlayerList.PlayerNo[TempNo].Score[2],
			      &PlayerList.PlayerNo[TempNo].Score[3],
			      &PlayerList.PlayerNo[TempNo].Score[4]);
			return 0;
		default:
			printf("未找到，请检查输入。\n");
			return 1;
	}
}

int sub_Operate() {
	system("cls");

	printf("+-----------------------+\n");
	printf("|                       |\n");
	printf("| 1.最高分数 2.最低分数 |\n");
	printf("| 3.平均分数 4.查询分数 |\n");
	printf("| 0.退出系统            |\n");
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
		case 0: //退出系统
			return 0;
		case 1: //最高分数
			printf("请输入要查询的选手的代号\n");
			scanf("%d", &TempNo);
			max = PlayerList.PlayerNo[TempNo].Score[0];
			for (i = 1; i < 5; i++) {
				if (max < PlayerList.PlayerNo[TempNo].Score[i]) max = PlayerList.PlayerNo[TempNo].Score[i];
			}
			printf("最高分为%d\n", max);
			return 1;
		case 2: //最低分数
			printf("请输入要查询的选手的代号\n");
			scanf("%d", &TempNo);
			min = PlayerList.PlayerNo[TempNo].Score[0];
			for (i = 1; i < 5; i++) {
				if (min > PlayerList.PlayerNo[TempNo].Score[i]) min = PlayerList.PlayerNo[TempNo].Score[i];
			}
			printf("最低分为%d\n", min);
			return 2;
		case 3: //
			printf("请输入要查询的选手的代号\n");
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
			printf("总分为%.2f\n", TotalScore); 
			printf("平均分为%.2f\n", TotalScore / 3);
			return 3;
		case 4:
			printf("请输入要查询的选手的代号\n");
			scanf("%d", &TempNo);
			for (i = 0; i < 5; i++) {
				printf("第 %d 位评委 \t %d \n", i, PlayerList.PlayerNo[TempNo].Score[i]);
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
			printf("\n请按任意键结束...\n");
			getch();
		}
	}
	system("cls");

	return 0;
}
