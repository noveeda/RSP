#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

struct rsp {
	int rock	= 0;
	int scissor	= 0;
	int paper	= 0;
	int win		= 0;
	int lose	= 0;
	int draw	= 0;
	int games	= 0;
};

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// Pausing before input enter.
void Pause() {
	int keyboard;
	while (1) {
		keyboard = _getch();
		if (keyboard == 13) return;
	}
}

void RSP(char* mode, struct rsp *rspPtr) {
	// Clear Screen
	system("cls");
	srand(time(0));
	
	
	int myScore		= 0;
	int comScore	= 0;
	char str[7];

	// �＼�� ���
	if (!strcmp(mode, "�＼��")) {

		while (1) {
			int random = rand() % 3;
			printf("�����������߿� �ϳ��� ������ (�����⸦ ���Ѵٸ� �����⸦ �Է��ϼ���)\n");
			scanf_s("%s", str, sizeof(str));
			if (strcmp(str, "������") == 0) break;
			if (!strcmp(str, "����")) {
				if (random == 0) {
					comScore++;
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 1) {
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 2) {
					myScore++;
					printf("\nCOM�� ���� �½��ϴ�.\n����� �̰���ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
			}
			else if (!strcmp(str, "����")) {
				if (random == 0) {
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 1) {
					myScore++;
					printf("\nCOM�� ������ �½��ϴ�.\n����� �̰���ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 2) {
					comScore++;
					printf("\nCOM�� ���� �½��ϴ�.\n����� �����ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
			}
			else if (!strcmp(str, "��")) {
				if (random == 0) {
					myScore++;
					printf("\nCOM�� ������ �½��ϴ�.\n����� �̰���ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 1) {
					comScore++;
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 2) {
					printf("\nCOM�� ���� �½��ϴ�.\n����� �����ϴ�\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
			}
			else
				printf("�߸��� �Է��Դϴ�.\n\n");
			
			//Check Score
			if (myScore >= 3) {
				puts("����� �¸�!");
				puts("Enter�� ���� �ʱ�ȭ������ ���ư���...");
				break;
			}
			if (comScore >= 3) {
				puts("COM�� �¸�!");
				puts("Enter�� ���� �ʱ�ȭ������ ���ư���...");
				break;
			}
		}
	}

	// �Ϲ� ���
	else if(strcmp(mode, "�Ϲ�") == 0){
		while (1) {
			int random = rand() % 3;
			printf("�����������߿� �ϳ��� ������ (�����⸦ ���Ѵٸ� �����⸦ �Է��ϼ���)\n");
			scanf_s("%s", str, sizeof(str));
			
			if (!strcmp(str, "����")) {
				rspPtr->games++;
				if (random == 0) {
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					rspPtr->lose++;
				}
				else if (random == 1) {
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					rspPtr->draw++;
				}
				else if (random == 2) {
					printf("\nCOM�� ���� �½��ϴ�.\n����� �̰���ϴ�.\n\n");
					rspPtr->scissor++;
					rspPtr->win++;
				}
			}
			else if (!strcmp(str, "����")) {
				rspPtr->games++;
				if (random == 0) {
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					rspPtr->draw++;
				}
				else if (random == 1) {
					printf("\nCOM�� ������ �½��ϴ�.\n����� �̰���ϴ�.\n\n");
					rspPtr->rock++;
					rspPtr->win++;
				}
				else if (random == 2) {
					printf("\nCOM�� ���� �½��ϴ�.\n����� �����ϴ�.\n\n");
					rspPtr->lose++;
				}
			}
			else if (!strcmp(str, "��")) {
				rspPtr->games++;
				if (random == 0) {
					printf("\n\nCOM�� ������ �½��ϴ�.\n����� �̰���ϴ�.\n\n");
					rspPtr->paper++;
					rspPtr->win++;
				}
				else if (random == 1) {
					printf("\nCOM�� ������ �½��ϴ�.\n����� �����ϴ�.\n\n");
					rspPtr->lose++;
				}
				else if (random == 2) {
					printf("\nCOM�� ���� �½��ϴ�.\n����� �����ϴ�\n\n");
					rspPtr->draw++;
				}
			}
			else if (!strcmp(str, "������"))
				break;
			else
				printf("�߸��� �Է��Դϴ�.\n\n");
		}
	}
}

void Rate(struct rsp *rspPtr) {
	for (int i = 0; i < 3; i++) {
		system("cls");
		gotoxy(32, 8);
		printf("���� �˻���");
		for (int j = 0; j <= i; j++) {
			printf(".");
		}
		Sleep(600);
	}

	system("cls");
	gotoxy(33, 8);
	puts("[ �� �� ]");
	
	// �Ϲݸ��� �� ������ ���� ��
	if (rspPtr->games == 0) {
		gotoxy(30, 14);
		printf("������ �����ϴ�.");
	}
		
	// ���� �˻�
	else
	printf("����: %d%%\n����: %d%%\n��:   %d%%\n%d�� %d�� %d�� %d��",	rspPtr->scissor * 100		 / rspPtr->games, 
																		rspPtr->rock * 100			 / rspPtr->games, 
																		rspPtr->paper * 100			 / rspPtr->games, 
																		rspPtr->win, 
																		rspPtr->lose, 
																		rspPtr->draw, 
																		rspPtr->games);
}

int main() {
	system("mode con cols=80 lines=40 | title ����������");
	// ���� ����ü
	struct rsp stats;
	
	char str[7];
	int option;

	while (1) {
		main:
		system("cls");
		
		gotoxy(30, 14);
		puts("1) �� �� �� ��");
		gotoxy(30, 16);
		puts("2) �� ��");
		gotoxy(30, 18);
		puts("3) �� �� �� ��");

		gotoxy(37, 19);
		option = _getch();

		// ���� ��� ����
		if (option == 49) {

			system("cls");
			puts("��带 �������ּ���.\n\n�＼��\n�Ϲ�\n");
			scanf_s("%s", str, sizeof(str));
			RSP(str, &stats);
			Pause();

		}
		// ���� �˻�
		else if (option == 50) {
			Rate(&stats);
			Pause();
		}
		// ���� ����
		else if (option == 51) {
			system("cls");
			printf("�����մϴ�...");
			exit(1);
		}
		
		
	}
	return 0;
}