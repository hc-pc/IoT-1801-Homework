#include <stdio.h>
#include <String.h>

int UserInfo[2];
//卡号 密码 余额
//0    1    2


int ShowFunctions() {
	int temp;
	
	printf("请输入功能前数字来使用功能\n\n");
	printf("1.开户\t2.储蓄\t3.取款\t4.查询\n");
	printf("5.销户\t0.退出\n");
	scanf("%d", &temp);
	
	switch (temp) {
		case 0:
			return 0;
		case 1:
			printf("请输入您希望的密码（六位）\n");
			scanf("%d", &UserInfo[1]);
			printf("请输入您的开户余额\n");
			scanf("%d", &UserInfo[2]);
			printf("卡号：%d\n余额：%d\n", UserInfo[0], UserInfo[2]);
			return 1;
		case 2:
			int save;
			printf("请输入存款金额:\n");
			scanf("%d", &save);
			UserInfo[2] = UserInfo[2] + save;
			return 2;
		case 3:
			int drow;
			int tempPassword;
			printf("请输入您的密码:\n");
			scanf("%d", &tempPassword); 
			if (tempPassword == UserInfo[1]) {
				printf("请输入取款金额:\n");
				scanf("%d", &drow);
				if (drow > UserInfo[2]) {
					printf("您的余额不足\n");
				}
				else {
					UserInfo[2] = UserInfo[2] - drow;
					printf("您的余额为:%d\n", UserInfo[2]);
				}
			}
			return 3;
		case 4:
			printf("卡号：%d\n余额：%d\n", UserInfo[0], UserInfo[2]);
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
		
	printf("欢迎来到储蓄综合业务平台\n");
	char UserName[6] = "PlanC";
	char UserPassword[7] = "114514";
	char InputName[6], InputPassword[7];
	int RetryTimes = 0;
	
	for (RetryTimes = 0; RetryTimes < 3; RetryTimes++) {
		printf("请输入用户名:\n");
		scanf("%s", InputName);
		if (strcmp(InputName, UserName)) {
			printf("用户名不正确，请重试。\n");
			if (RetryTimes == 2) {
				printf("三次错误，程序退出。");
				return 1;
			}
		}
		else {
			printf("请输入密码:\n");
			scanf("%s", InputPassword);
			if (strcmp(InputPassword, UserPassword)) {
				printf("密码不正确，请重试。\n");
				if (RetryTimes == 2) {
					printf("三次错误，程序退出。");
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
