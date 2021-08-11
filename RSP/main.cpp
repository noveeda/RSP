// [도구] -> [옵션] -> [디버깅] > [디버깅이 중지되면 자동으로 콘솔창 닫기.]
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
	// 콘솔창 사이즈를 가로 80 세로 40칸으로
	system("mode con cols=80 lines=40 | title 가위바위보");
	// 전적 구조체
	struct rsp stats;

	char str[7];

	int xy[3][2] = { {30, 14}, {30, 16}, {30,18} };
	int xy1[2][2] = { { 31, 14}, {31, 16} };

	while (1) {
		option = 0;
		system("cls");

		gotoxy(30, 14);
		puts("1) 게 임 시 작");
		gotoxy(30, 16);
		puts("2) 승 률");
		gotoxy(30, 18);
		puts("3) 게 임 종 료");
		gotoxy(28, 30);
		puts("↑");
		gotoxy(28, 31);
		puts("↓");
		gotoxy(26, 31);
		puts("←");
		gotoxy(30, 31);
		puts("→ 을 사용하여 조작");

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
		// 게임 모드 선택
		if (option == 0) {
			unsigned int mode = 0;
			system("cls");
			gotoxy(29, 12);
			puts("모드를 선택해주세요.");

			gotoxy(31, 14);
			printf("1)삼 세 판");
			gotoxy(31, 16);
			printf("2)일 반");
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
		// 전적 검색
		else if (option == 1) {
			Rate(&stats);
			Pause();
		}
		// 게임 종료
		else if (option == 2) {
			ShutDown();
		}
	}
	return 0;
}

void ShutDown() {
	// 선택 및 커서 좌표
	int xy[2][2]	= { {30, 22}, {45, 22} };
	int select		= 0;

	// 출력
	system("cls");

	gotoxy(26, 14);
	printf("정말로 종료하시겠습니까?");
	
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

	// 0은 Y 1은 N
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

// 가위바위보
void RSP(unsigned int mode, struct rsp* rspPtr) {
	// Clear Screen
	system("cls");
	srand(time(0));


	int myScore = 0;
	int comScore = 0;
	char str[7];

	// 삼세판 모드
	if (mode == 0) {

		while (1) {

			// 난수 생성
			int random = rand() % 3;

			printf("가위바위보중에 하나를 입력하세요 (나가기를 원한다면 나가기를 입력하세요)\n");
			scanf_s("%s", str, sizeof(str));

			// 나가기
			if (strcmp(str, "나가기") == 0) break;


			if (!strcmp(str, "가위")) {
				if (random == 0) {
					comScore++;
					printf("\nCOM은 바위를 냈습니다.\n당신이 졌습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 1) {
					printf("\nCOM은 가위를 냈습니다.\n당신은 비겼습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 2) {
					myScore++;
					printf("\nCOM은 보를 냈습니다.\n당신이 이겼습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
			}
			else if (!strcmp(str, "바위")) {
				if (random == 0) {
					printf("\nCOM은 바위를 냈습니다.\n당신은 비겼습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 1) {
					myScore++;
					printf("\nCOM은 가위를 냈습니다.\n당신이 이겼습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 2) {
					comScore++;
					printf("\nCOM은 보를 냈습니다.\n당신이 졌습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
			}
			else if (!strcmp(str, "보")) {
				if (random == 0) {
					myScore++;
					printf("\nCOM은 바위를 냈습니다.\n당신이 이겼습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 1) {
					comScore++;
					printf("\nCOM은 가위를 냈습니다.\n당신이 졌습니다.\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
				else if (random == 2) {
					printf("\nCOM은 보를 냈습니다.\n당신은 비겼습니다\n\n");
					printf("(Player)%d : %d(COM)\n\n", myScore, comScore);
				}
			}
			else
				printf("잘못된 입력입니다.\n\n");

			//Check Score
			if (myScore >= 3) {
				puts("당신의 승리!");
				puts("Enter를 눌러 초기화면으로 돌아가기...");
				break;
			}
			if (comScore >= 3) {
				puts("COM의 승리!");
				puts("Enter를 눌러 초기화면으로 돌아가기...");
				break;
			}
		}
	}

	// 일반 모드
	else if (mode == 1) {

		while (1) {

			int random = rand() % 3;

			printf("가위바위보중에 하나를 입력하세요 (나가기를 원한다면 나가기를 입력하세요)\n");
			scanf_s("%s", str, sizeof(str));

			if (!strcmp(str, "가위")) {
				rspPtr->games++;
				if (random == 0) {
					printf("\nCOM은 바위를 냈습니다.\n당신이 졌습니다.\n\n");
					rspPtr->lose++;
				}
				else if (random == 1) {
					printf("\nCOM은 가위를 냈습니다.\n당신은 비겼습니다.\n\n");
					rspPtr->draw++;
				}
				else if (random == 2) {
					printf("\nCOM은 보를 냈습니다.\n당신이 이겼습니다.\n\n");
					rspPtr->scissor++;
					rspPtr->win++;
				}
			}
			else if (!strcmp(str, "바위")) {
				rspPtr->games++;
				if (random == 0) {
					printf("\nCOM은 바위를 냈습니다.\n당신은 비겼습니다.\n\n");
					rspPtr->draw++;
				}
				else if (random == 1) {
					printf("\nCOM은 가위를 냈습니다.\n당신이 이겼습니다.\n\n");
					rspPtr->rock++;
					rspPtr->win++;
				}
				else if (random == 2) {
					printf("\nCOM은 보를 냈습니다.\n당신이 졌습니다.\n\n");
					rspPtr->lose++;
				}
			}
			else if (!strcmp(str, "보")) {
				rspPtr->games++;
				if (random == 0) {
					printf("\n\nCOM은 바위를 냈습니다.\n당신이 이겼습니다.\n\n");
					rspPtr->paper++;
					rspPtr->win++;
				}
				else if (random == 1) {
					printf("\nCOM은 가위를 냈습니다.\n당신이 졌습니다.\n\n");
					rspPtr->lose++;
				}
				else if (random == 2) {
					printf("\nCOM은 보를 냈습니다.\n당신은 비겼습니다\n\n");
					rspPtr->draw++;
				}
			}
			else if (!strcmp(str, "나가기"))
				break;
			else
				printf("잘못된 입력입니다.\n\n");
		}
	}
}

// 전적
void Rate(struct rsp* rspPtr) {

	for (int i = 0; i < 3; i++) {

		system("cls");

		gotoxy(32, 8);

		printf("전적 검색중");

		for (int j = 0; j <= i; j++) printf(".");

		Sleep(600);
	}

	system("cls");
	gotoxy(34, 8);
	puts("[ 전 적 ]");

	// 일반모드로 한 게임이 없을 시
	if (rspPtr->games == 0) {
		gotoxy(31, 14);
		printf("전적이 없습니다.");
	}

	// 전적 검색
	else {
		gotoxy(34, 12);
		printf("[ 승 률 ]");
		gotoxy(31, 14);
		printf("가위: %d%%", rspPtr->scissor * 100 / rspPtr->games);
		gotoxy(31, 15);
		printf("바위: %d%%", rspPtr->rock * 100 / rspPtr->games);
		gotoxy(31, 16);
		printf("보:   %d%%", rspPtr->paper * 100 / rspPtr->games);
		gotoxy(31, 18);
		printf("%d승 %d패 %d무 %d전", rspPtr->win, rspPtr->lose, rspPtr->draw, rspPtr->games);
		gotoxy(23, 30);
		printf("Enter를 눌러 초기화면으로 돌아가기.");
	}
}