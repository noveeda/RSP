// [����] -> [�ɼ�] -> [�����] > [������� �����Ǹ� �ڵ����� �ܼ�â �ݱ�.]
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

unsigned int option = 0;

struct rsp {
	int rock		= 0;
	int scissor		= 0;
	int paper		= 0;
	int win			= 0;
	int lose		= 0;
	int draw		= 0;
	int games		= 0;
};

// function prototype
void gotoxy(int, int);
void Pause();
void RSP(unsigned int, struct rsp*);
void Rate(struct rsp*);
void ShutDown();
void Tutorial();


int main() {
	// �ܼ�â ����� ���� 80 ���� 40ĭ����
	system("mode con cols=80 lines=40 | title ����������");
	// ���� ����ü
	struct rsp stats;

	char str[7];

	int xy[3][2] = { {30, 14}, {30, 16}, {30,18} };
	int xy1[2][2] = { { 31, 14}, {31, 16} };

	while (1) {
		option = 0;
		system("cls");

		gotoxy(30, 14);
		puts("1) �� �� �� ��");
		gotoxy(30, 16);
		puts("2) �� ��");
		gotoxy(30, 18);
		puts("3) �� �� �� ��");
		gotoxy(28, 30);
		puts("��");
		gotoxy(28, 31);
		puts("��");
		gotoxy(26, 31);
		puts("��");
		gotoxy(30, 31);
		puts("�� �� ����Ͽ� ����");

		gotoxy(30, 14);
		while (1) {
			int cursor = _getch();
			if (option == 0 && cursor == 72) continue;
			if (option == 2 && cursor == 80) continue;
			if (cursor == 72) {
				option--;
				gotoxy(xy[option][0], xy[option][1]);
			}
			if (cursor == 80) {
				option++;
				gotoxy(xy[option][0], xy[option][1]);
			}
			if (cursor == 13) break;
		}
		// ���� ��� ����
		if (option == 0) {
			unsigned int mode = 0;
			system("cls");
			gotoxy(29, 12);
			puts("��带 �������ּ���.");

			gotoxy(31, 14);
			printf("1)�� �� ��");
			gotoxy(31, 16);
			printf("2)�� ��");
			gotoxy(31, 14);
			while (1) {
				int cursor = _getch();
				if (mode == 0 && cursor == 72) continue;
				if (mode == 1 && cursor == 80) continue;
				if (cursor == 72) {
					mode--;
					gotoxy(xy1[mode][0], xy1[mode][1]);
				}
				if (cursor == 80) {
					mode++;
					gotoxy(xy1[mode][0], xy1[mode][1]);
				}
				if (cursor == 13) break;
			}
			RSP(mode, &stats);
			Pause();

		}
		// ���� �˻�
		else if (option == 1) {
			Rate(&stats);
			Pause();
		}
		// ���� ����
		else if (option == 2) {
			ShutDown();
		}
	}
	return 0;
}

void ShutDown() {
	// ���� �� Ŀ�� ��ǥ
	int xy[2][2]	= { {30, 22}, {45, 22} };
	int select		= 0;

	// ���
	system("cls");

	gotoxy(26, 14);
	printf("������ �����Ͻðڽ��ϱ�?");
	
	gotoxy(30, 22);
	printf("Y");
	
	gotoxy(38, 22);
	printf("/");

	gotoxy(45, 22);
	printf("N");

	gotoxy(30, 22);
	while (1) {
		int keyboard = _getch();

		if (select == 0 && keyboard == 75) continue;
		if (select == 1 && keyboard == 77) continue;


		if (keyboard == 75) {
			select--;
			gotoxy(xy[select][0], xy[select][1]);
		}
		if (keyboard == 77) {
			select++;
			gotoxy(xy[select][0], xy[select][1]);
		}
		if (keyboard == 13) break;
	}

	// 0�� Y 1�� N
	if (select == 0) {
		system("cls");
		exit(0);
	}
	if (select == 1) return;
}
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

// ����������
void RSP(unsigned int mode, struct rsp* rspPtr) {
	// Clear Screen
	system("cls");
	srand(time(0));


	int myScore = 0;
	int comScore = 0;
	char str[7];

	// �＼�� ���
	if (mode == 0) {

		while (1) {

			// ���� ����
			int random = rand() % 3;

			printf("�����������߿� �ϳ��� �Է��ϼ��� (�����⸦ ���Ѵٸ� �����⸦ �Է��ϼ���)\n");
			scanf_s("%s", str, sizeof(str));

			// ������
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
	else if (mode == 1) {

		while (1) {

			int random = rand() % 3;

			printf("�����������߿� �ϳ��� �Է��ϼ��� (�����⸦ ���Ѵٸ� �����⸦ �Է��ϼ���)\n");
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

// ����
void Rate(struct rsp* rspPtr) {

	for (int i = 0; i < 3; i++) {

		system("cls");

		gotoxy(32, 8);

		printf("���� �˻���");

		for (int j = 0; j <= i; j++) printf(".");

		Sleep(600);
	}

	system("cls");
	gotoxy(34, 8);
	puts("[ �� �� ]");

	// �Ϲݸ��� �� ������ ���� ��
	if (rspPtr->games == 0) {
		gotoxy(31, 14);
		printf("������ �����ϴ�.");
	}

	// ���� �˻�
	else {
		gotoxy(34, 12);
		printf("[ �� �� ]");
		gotoxy(31, 14);
		printf("����: %d%%", rspPtr->scissor * 100 / rspPtr->games);
		gotoxy(31, 15);
		printf("����: %d%%", rspPtr->rock * 100 / rspPtr->games);
		gotoxy(31, 16);
		printf("��:   %d%%", rspPtr->paper * 100 / rspPtr->games);
		gotoxy(31, 18);
		printf("%d�� %d�� %d�� %d��", rspPtr->win, rspPtr->lose, rspPtr->draw, rspPtr->games);
		gotoxy(23, 30);
		printf("Enter�� ���� �ʱ�ȭ������ ���ư���.");
	}
}