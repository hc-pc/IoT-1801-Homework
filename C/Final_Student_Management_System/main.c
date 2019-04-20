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
	//�½�ѧ��
	int i = 0;
	char OverWriteFlag = '\0';
	char SecondAuthority = '\0';
	 
	if (StudentNumberCounter == TotalStudentNumber) {
		printf("�����������Ƿ���Ҫ������ʧЧѧ������(Y\\N)\n");
		scanf("%c", &OverWriteFlag);
		if (OverWriteFlag == 'N' || OverWriteFlag == 'n') {
			printf("����������ݽ�����ʧ�������ȷ����\n");
			scanf("%c", &SecondAuthority);
			if (SecondAuthority == 'Y' || SecondAuthority == 'y') {
				return;
			}
		}
		else {
			for (i = 1; i < StudentNumberCounter; i++) {
				if (StudentGroup.student[i].Aviliable == 0) {
					printf("������ѧ������ �Ա�(M\\F)\n");
					scanf("%s %c", StudentGroup.student[i].StudentName, &StudentGroup.student[i].StudentSex);
					StudentGroup.student[i].StudentNumber =  i;
					StudentGroup.student[i].Aviliable = 1;
				}
			}
		}
	}
	else {
		printf("������ѧ������ �Ա�(M\\F)\n");
		scanf("%s %c", StudentGroup.student[StudentNumberCounter].StudentName, &StudentGroup.student[StudentNumberCounter].StudentSex);
		StudentGroup.student[StudentNumberCounter].StudentNumber =  StudentNumberCounter;
		StudentGroup.student[StudentNumberCounter].Aviliable = 1;
		StudentNumberCounter++;
	}
} 

void DeleteStudent() {
	//�Ƴ�ѧ�� 
	int DeleteNumber = 0;
	
	printf("������Ҫ�Ƴ���ѧ��ѧ��(0Ϊȡ��)");
	scanf("%d", &DeleteNumber);
	if (DeleteNumber == 0) return;
	StudentGroup.student[DeleteNumber].Aviliable = 0;
}

void ManageScore() {
	//����ɼ� 
	int i = 1;
	int Number = 0;
	char Method = '\0';
	
	printf("��Ҫ�����޸ĳɼ��� (Y or N)\n");
	scanf("%c", &Method);
	if (Method == 'Y' || Method == 'y') {
		for (i = 1; i < StudentNumberCounter; i++) {
			printf("�������µĳɼ�(����ѧ��Ϊ%d)", i);
			scanf("%d", StudentGroup.student[i].StudentScore);
		}
	}
	else {
		printf("Ҫ�޸�˭(ѧ��)�ĳɼ�");
		scanf("%d", &Number);
		printf("�������µĳɼ�");
		scanf("%d", StudentGroup.student[Number].StudentScore);
		printf("���\n");
	}
} 

void PrintScore() {
	//�鿴�ɼ�
	int i;
	
	printf("%10s%10s%10s%10s\n", "����", "ѧ��", "�Ա�", "�ɼ�"); 
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
//  ˳����� 
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
	//�����С 
	int i = 0;
	int max = ScoreList.Scores[0];
	int min = ScoreList.Scores[0];
	
	for (i = 0; i < 10; i++) {
		if (max <= ScoreList.Scores[i]) max = ScoreList.Scores[i];
		if (min <= ScoreList.Scores[i]) min = ScoreList.Scores[i];
	}
	printf("��߷�Ϊ %d ,��߷�Ϊ %d .\n", max, min);
}

void Average() {
	//ƽ���ɼ� 
	int i = 0;
	float s = 0.0;
	
	for (i = 0; i < 10; i++) {
		s = s + ScoreList.Scores[i];
	}
	printf("ƽ����Ϊ %.2f .\n", s / 10);
}

void Save() {
	//������� 
	int i = 1;
	char SavePath[100] = {'\0'};
	char DefaultPath[10] = ".\\Students";
	
	printf("�����뱣��Ŀ¼��Ĭ��Ϊ��ǰ·��\n");
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
	//��ѯ���� 
	int i = 1;
	char TempName[20] = {""};
	
	while (*(NAME+i) != '\0') {
		TempName[i] = *(NAME + i);
		i++;
	}
	
	if (Method == 'N') {
		for (i = 1; i < StudentNumberCounter; i++) {
			if (strcmp(StudentGroup.student[i].StudentName, TempName) == 0) {
				printf("ѧ��Ϊ%d", StudentGroup.student[i].StudentNumber);
				return;
			}
		}
		printf("δ������������ݣ������������롣");
	}
	else {
		for (i = 1; i < StudentNumberCounter; i++) {
			if (StudentGroup.student[i].StudentNumber == NUMBER) {
				printf("����Ϊ%s", StudentGroup.student[i].StudentName);
				return;
			}
		}
		printf("δ������������ݣ������������롣");
	}
}

int FunctionList() {
	system("cls");
	printf("+----------------------------------------+\n");
	printf("| 1.�½�ѧ��    2.�Ƴ�ѧ��    3.�ɼ����� |\n");
	printf("| 4.�鿴�ɼ�    5.�����С    6.ƽ���ɼ� |\n");
	printf("| 7.�����޸�    8.������ѯ    9.�ɼ���ѯ |\n");
	printf("|----------------------------------------|\n");
	printf("|               0.�˳�ϵͳ               |\n");
	printf("+----------------------------------------+\n");
	printf("�����빦�ܴ���:");

	int useless = 0;
	int FunctionIndex = 0;
	int SearchNumber = 0;
	char SearchName[20] = {""};
	
	scanf("%d", &FunctionIndex);
	switch (FunctionIndex) {
		case 0: //�˳�ϵͳ
			return 0;
			
		case 1: //�½�ѧ��
			NewStudent();
			printf("�밴���������......\n");
			useless = getch();
			return 1;
			
		case 2: //�Ƴ�ѧ��
			DeleteStudent();
			printf("�밴���������......\n");
			useless = getch();
			return 2;
			
		case 3: //�ɼ�����
			ManageScore();
			printf("�밴���������......\n");
			useless = getch();
			return 3;
			
		case 4: //�鿴�ɼ�
			PrintScore();
			printf("�밴���������......\n");
			useless = getch();
			return 4;
			
		case 5: //�����С
			Extremum();
			printf("�밴���������......\n");
			useless = getch();
			return 5;
			
		case 6: //ƽ���ɼ�
			Average();
			printf("�밴���������......\n");
			useless = getch();
			return 6;
			
		case 7: //�����޸�
			Save();
			printf("�밴���������......\n");
			useless = getch();
			return 7;
			
		case 8: //������ѯ
			printf("��������Ҫ��ѯ������\n");
			scanf("%s", SearchName);
			Search('N', SearchName, 0);
			printf("�밴���������......\n");
			useless = getch();
			return 8;
			
		case 9: //ѧ�Ų�ѯ
			printf("��������Ҫ��ѯ��ѧ��\n");
			scanf("%d", &SearchNumber);
			Search('n', "", SearchNumber); 
			printf("�밴���������......\n");
			useless = getch();
			return 9;
			
		default:
			printf("δ�ҵ��ù��ܣ������º˶Թ��ܱ�\n");
			printf("�밴���������......\n");
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
	printf("| ��ӭ����ѧ������ϵͳ |\n");
	printf("+----------------------+\n");

	printf("�������˺�\n");
	for (RetryTimes; RetryTimes < 3; RetryTimes++) {
		scanf("%s", InputName);
		if (strcmp(UserName, InputName)) {
			printf("�˺Ŵ��������ԣ�ʣ�����%d\n", 2 - RetryTimes);
			if (RetryTimes == 2) {
				printf("���δ���,�����˳�");
				return 1;
			}
		} else {
			break;
		}
	}

	printf("����������");
	for (RetryTimes; RetryTimes < 3; RetryTimes++) {
		for (i = 0; i < 6; i++) {
			InputPassword[i] = getch();
			InputPassword[6] = '\0';
			printf("*");
		}
		if (strcmp(UserPassword, InputPassword)) {
			printf("\n�������,������,ʣ�����%d\n", 2 - RetryTimes);
			if (RetryTimes == 2) {
				printf("���δ���,�����˳�");
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
