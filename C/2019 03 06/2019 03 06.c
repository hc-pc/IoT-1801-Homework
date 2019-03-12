#include <stdio.h>
#include <stdlib.h>
#include <String.h>

	int StudentScore[5];
	//int StudentScore[5] = {12, 34, 53, 74, 86};

void SortPrint() {
	int i = 0;
	int j = 0;
	int Index = 0;
	int CurrentMax = 0;
	int BackupArray[5];
	
	for (i = 0; i < 5; i++) {
		BackupArray[i] = StudentScore[i];
	}
	
	CurrentMax = BackupArray[0];
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (CurrentMax < BackupArray[j]) {
				CurrentMax = BackupArray[j];
				Index = j;
			}
		}
		BackupArray[Index] = 0;
		printf("%d:%d\n", Index + 1, CurrentMax);
		CurrentMax = 0;
	}
	printf("\n");
}

int FunctionList() {
	int i = 0;
	int FunctionIndex = 0;
	int max = StudentScore[0];
	int min = StudentScore[0];
	float TotalScore = 0;
	
	printf("\n");
	printf("+--------------------------------+\n");
	printf("| 1.查  询   2.最高分   3.最低分 |\n");
	printf("| 4.平均分              0.退  出 |\n");
	printf("+--------------------------------+\n");
	scanf("%d", &FunctionIndex);
	
	switch (FunctionIndex) {
		case 0: //退出 
			return 0;
		case 1: //查询
			printf("分数表为\n");
			SortPrint();
			return 1;
		case 2: //最高分 
			for (i = 1; i < 5; i++) {
				if (max < StudentScore[i]) {
					max = StudentScore[i];
				}
			}
			printf("最大值为%d\n", max);
			return 2;
		case 3: //最低分 
			for (i = 1; i < 5; i++) {
				if (min > StudentScore[i]) {
					min = StudentScore[i];
				}
			}
			printf("最小值为%d\n", min);
			return 3;
		case 4: //平均分 
			for (i = 0; i < 5; i++) {
				TotalScore = TotalScore + StudentScore[i];
			}
			printf("平均分为%.2f", TotalScore / 5);
			return 4;
		default:
			printf("错误输入，请重新核对功能表");
			return 5;
	}
}

int main() {
	char UserName[6] = "PlanC";
	char UserPassword[7] = "114514";
	char InputName[6] = {"0"};
	char InputPassword[7] = {"0"};
	int RetryTimes = 0;

	printf("+--------------------+\n");
	printf("|欢迎来到学生管理系统|\n");
	printf("+--------------------+\n");

	printf("请输入用户名\n");
	for (RetryTimes = 0; RetryTimes < 3; RetryTimes++) {
		scanf("%s", InputName);
		if (strcmp(UserName, InputName)) {
			printf("密码错误，请重试，剩余机会%d\n", 2 - RetryTimes);
			if (RetryTimes == 3) {
				printf("三次错误，程序退出");
				return 1;
			}
		} else {
			printf("请输入密码\n");
			scanf("%s", InputPassword);
			if (strcmp(UserPassword, InputPassword)) {
				printf("密码错误，请重试，剩余机会%d\n", 2 - RetryTimes);
				if (RetryTimes == 3) {
					printf("三次错误，程序退出");
					return 2;
				}
			}
			else {
				break;
			}
		}
	}

	system("cls");
	
	int i = 0;
	printf("请输入五位学生成绩\n");
	for (i = 0; i < 5; i++) {
		scanf("%d", &StudentScore[i]);
	}
	
	system("cls");
	
	while (true) {
		if (FunctionList() == 0) {
			return 0;
		}
	}
}
