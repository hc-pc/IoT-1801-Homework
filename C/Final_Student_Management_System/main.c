#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#define TotalStudentNumber 50


struct Student {
	char   StudentName[20];
	char   StudentSex;
	int    StudentScore;
	int    StudentNumber;
	int    Aviliable;
};

struct StudentGroup {
	struct Student student[TotalStudentNumber];
} StudentGroup;

struct ScoreList {
	int    Scores[10];
	int    Numbers[10];
} ScoreList;


int StudentNumberCounter = 1;

void NewStudent() {
	//新建学生
	int i = 0;
	char OverWriteFlag = '\0';
	char SecondAuthority = '\0';
	 
	if (StudentNumberCounter == TotalStudentNumber) {
		printf("人数已满，是否需要覆盖已失效学生内容(Y\\N)\n");
		scanf("%c", &OverWriteFlag);
		if (OverWriteFlag == 'N' || OverWriteFlag == 'n') {
			printf("所输入的内容将会消失，您真的确定吗\n");
			scanf("%c", &SecondAuthority);
			if (SecondAuthority == 'Y' || SecondAuthority == 'y') {
				return;
			}
		}
		else {
			for (i = 1; i < StudentNumberCounter; i++) {
				if (StudentGroup.student[i].Aviliable == 0) {
					printf("请输入学生姓名 性别(M\\F)\n");
					scanf("%s %c", StudentGroup.student[i].StudentName, &StudentGroup.student[i].StudentSex);
					StudentGroup.student[i].StudentNumber =  i;
					StudentGroup.student[i].Aviliable = 1;
				}
			}
		}
	}
	else {
		printf("请输入学生姓名 性别(M\\F)\n");
		scanf("%s %c", StudentGroup.student[StudentNumberCounter].StudentName, &StudentGroup.student[StudentNumberCounter].StudentSex);
		StudentGroup.student[StudentNumberCounter].StudentNumber =  StudentNumberCounter;
		StudentGroup.student[StudentNumberCounter].Aviliable = 1;
		StudentNumberCounter++;
	}
} 

void DeleteStudent() {
	//移除学生 
	int DeleteNumber = 0;
	
	printf("请输入要移除的学生学号(0为取消)");
	scanf("%d", &DeleteNumber);
	if (DeleteNumber == 0) return;
	StudentGroup.student[DeleteNumber].Aviliable = 0;
}

void ManageScore() {
	//管理成绩 
	int i = 1;
	int Number = 0;
	char Method = '\0';
	
	printf("是要批量修改成绩吗 (Y or N)\n");
	scanf("%c", &Method);
	if (Method == 'Y' || Method == 'y') {
		for (i = 1; i < StudentNumberCounter; i++) {
			printf("请输入新的成绩(现在学号为%d)", i);
			scanf("%d", StudentGroup.student[i].StudentScore);
		}
	}
	else {
		printf("要修改谁(学号)的成绩");
		scanf("%d", &Number);
		printf("请输入新的成绩");
		scanf("%d", StudentGroup.student[Number].StudentScore);
		printf("完成\n");
	}
} 

void PrintScore() {
	//查看成绩
	int i;
	
	printf("%10s%10s%10s%10s\n", "姓名", "学号", "性别", "成绩"); 
	for (i = 0; i < StudentNumberCounter; i++) {
		if (StudentGroup.student[i].Aviliable == 1) {
			printf("%10s%10d%10c%10d\n",StudentGroup.student[i].StudentName, 
										StudentGroup.student[i].StudentNumber, 
										StudentGroup.student[i].StudentSex, 
										StudentGroup.student[i].StudentScore);
		}
	}
}

void SortPrint() {
//  顺序输出 
// 	int i = 0;
// 	int j = 0;
// 	int Index = 0;
// 	int CurrentMax = 0;
// 	int BackupArray[5];
//
// 	for (i = 0; i < 5; i++) {
// 		BackupArray[i] = StudentScore[i];
// 	}
//
// 	CurrentMax = BackupArray[0];
//
// 	for (i = 0; i < 5; i++) {
// 		for (j = 0; j < 5; j++) {
// 			if (CurrentMax < BackupArray[j]) {
// 				CurrentMax = BackupArray[j];
// 				Index = j;
// 			}
// 		}
// 		BackupArray[Index] = 0;
// 		printf("%d:%d\n", Index + 1, CurrentMax);
// 		CurrentMax = 0;
// 	}
//  printf("\n");
}

void Extremum() {
	//最大最小 
	int i = 0;
	int max = ScoreList.Scores[0];
	int min = ScoreList.Scores[0];
	
	for (i = 0; i < 10; i++) {
		if (max <= ScoreList.Scores[i]) max = ScoreList.Scores[i];
		if (min <= ScoreList.Scores[i]) min = ScoreList.Scores[i];
	}
	printf("最高分为 %d ,最高分为 %d .\n", max, min);
}

void Average() {
	//平均成绩 
	int i = 0;
	float s = 0.0;
	
	for (i = 0; i < 10; i++) {
		s = s + ScoreList.Scores[i];
	}
	printf("平均分为 %.2f .\n", s / 10);
}

void Save() {
	//保存更改 
	int i = 1;
	char SavePath[100] = {'\0'};
	char DefaultPath[10] = ".\\Students";
	
	printf("请输入保存目录，默认为当前路径\n");
	scanf("%s", SavePath);
	if (strcmp(SavePath, NULL) == 0) strcpy(SavePath, DefaultPath);
	FILE *FilePointer = fopen(SavePath, "w+");
	for (i = 1; i < StudentNumberCounter; i++) {
		fprintf(FilePointer, "%s", StudentGroup.student[i].StudentName);
		fputc('\t', FilePointer);
		fprintf(FilePointer, "%d", StudentGroup.student[i].StudentNumber);
		fputc('\t', FilePointer);
		fprintf(FilePointer, "%c", StudentGroup.student[i].StudentSex);
		fputc('\t', FilePointer);
		fprintf(FilePointer, "%d", StudentGroup.student[i].StudentScore);
		fputc('\t', FilePointer);
		fprintf(FilePointer, "%d", StudentGroup.student[i].Aviliable);
		fputc('\n', FilePointer);
	}
	fclose(FilePointer);
}

void Search(char Method, char *NAME, int NUMBER) {
	//查询功能 
	int i = 1;
	char TempName[20] = {""};
	
	while (*(NAME+i) != '\0') {
		TempName[i] = *(NAME + i);
		i++;
	}
	
	if (Method == 'N') {
		for (i = 1; i < StudentNumberCounter; i++) {
			if (strcmp(StudentGroup.student[i].StudentName, TempName) == 0) {
				printf("学号为%d", StudentGroup.student[i].StudentNumber);
				return;
			}
		}
		printf("未检索到相关内容，请检查您的输入。");
	}
	else {
		for (i = 1; i < StudentNumberCounter; i++) {
			if (StudentGroup.student[i].StudentNumber == NUMBER) {
				printf("名字为%s", StudentGroup.student[i].StudentName);
				return;
			}
		}
		printf("未检索到相关内容，请检查您的输入。");
	}
}

int FunctionList() {
	system("cls");
	printf("+----------------------------------------+\n");
	printf("| 1.新建学生    2.移除学生    3.成绩管理 |\n");
	printf("| 4.查看成绩    5.最大最小    6.平均成绩 |\n");
	printf("| 7.保存修改    8.姓名查询    9.成绩查询 |\n");
	printf("|----------------------------------------|\n");
	printf("|               0.退出系统               |\n");
	printf("+----------------------------------------+\n");
	printf("请输入功能代号:");

	int useless = 0;
	int FunctionIndex = 0;
	int SearchNumber = 0;
	char SearchName[20] = {""};
	
	scanf("%d", &FunctionIndex);
	switch (FunctionIndex) {
		case 0: //退出系统
			return 0;
			
		case 1: //新建学生
			NewStudent();
			printf("请按任意键继续......\n");
			useless = getch();
			return 1;
			
		case 2: //移除学生
			DeleteStudent();
			printf("请按任意键继续......\n");
			useless = getch();
			return 2;
			
		case 3: //成绩管理
			ManageScore();
			printf("请按任意键继续......\n");
			useless = getch();
			return 3;
			
		case 4: //查看成绩
			PrintScore();
			printf("请按任意键继续......\n");
			useless = getch();
			return 4;
			
		case 5: //最大最小
			Extremum();
			printf("请按任意键继续......\n");
			useless = getch();
			return 5;
			
		case 6: //平均成绩
			Average();
			printf("请按任意键继续......\n");
			useless = getch();
			return 6;
			
		case 7: //保存修改
			Save();
			printf("请按任意键继续......\n");
			useless = getch();
			return 7;
			
		case 8: //姓名查询
			printf("请输入您要查询的姓名\n");
			scanf("%s", SearchName);
			Search('N', SearchName, 0);
			printf("请按任意键继续......\n");
			useless = getch();
			return 8;
			
		case 9: //学号查询
			printf("请输入您要查询的学号\n");
			scanf("%d", &SearchNumber);
			Search('n', "", SearchNumber); 
			printf("请按任意键继续......\n");
			useless = getch();
			return 9;
			
		default:
			printf("未找到该功能，请重新核对功能表\n");
			printf("请按任意键继续......\n");
			useless = getch();
			return 255;
	}
	return -1;
}

int main() {
	char UserName[5] = "PlanC";
	char UserPassword[6] = "114514";
	char InputName[5] = {"0"};
	char InputPassword[6] = {"0"};
	int RetryTimes = 0;
	int i;

	printf("+----------------------+\n");
	printf("| 欢迎来到学生管理系统 |\n");
	printf("+----------------------+\n");

	printf("请输入账号\n");
	for (RetryTimes; RetryTimes < 3; RetryTimes++) {
		scanf("%s", InputName);
		if (strcmp(UserName, InputName)) {
			printf("账号错误，请重试，剩余机会%d\n", 2 - RetryTimes);
			if (RetryTimes == 2) {
				printf("三次错误,程序退出");
				return 1;
			}
		} else {
			break;
		}
	}

	printf("请输入密码");
	for (RetryTimes; RetryTimes < 3; RetryTimes++) {
		for (i = 0; i < 6; i++) {
			InputPassword[i] = getch();
			InputPassword[6] = '\0';
			printf("*");
		}
		if (strcmp(UserPassword, InputPassword)) {
			printf("\n密码错误,请重试,剩余机会%d\n", 2 - RetryTimes);
			if (RetryTimes == 2) {
				printf("三次错误,程序退出");
				return 2;
			}
		} else {
			break;
		}
	}

	system("cls");
	while (1) {
		if (FunctionList() == 0) {
			return 0;
		}
	}
	return 3;
}
