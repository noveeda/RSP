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

	// 삼세판 모드
	if (!strcmp(mode, "삼세판")) {

		while (1) {
			int random = rand() % 3;
			printf("가위바위보중에 하나를 내세요 (나가기를 원한다면 나가기를 입력하세요)\n");
			scanf_s("%s", str, sizeof(str));
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
	else if(strcmp(mode, "일반") == 0){
		while (1) {
			int random = rand() % 3;
			printf("가위바위보중에 하나를 내세요 (나가기를 원한다면 나가기를 입력하세요)\n");
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

void Rate(struct rsp *rspPtr) {
	for (int i = 0; i < 3; i++) {
		system("cls");
		gotoxy(32, 8);
		printf("전적 검색중");
		for (int j = 0; j <= i; j++) {
			printf(".");
		}
		Sleep(600);
	}

	system("cls");
	gotoxy(33, 8);
	puts("[ 전 적 ]");
	
	// 일반모드로 한 게임이 없을 시
	if (rspPtr->games == 0) {
		gotoxy(30, 14);
		printf("전적이 없습니다.");
	}
		
	// 전적 검색
	else
	printf("가위: %d%%\n바위: %d%%\n보:   %d%%\n%d승 %d패 %d무 %d전",	rspPtr->scissor * 100		 / rspPtr->games, 
																		rspPtr->rock * 100			 / rspPtr->games, 
																		rspPtr->paper * 100			 / rspPtr->games, 
																		rspPtr->win, 
																		rspPtr->lose, 
																		rspPtr->draw, 
																		rspPtr->games);
}

int main() {
	system("mode con cols=80 lines=40 | title 가위바위보");
	// 전적 구조체
	struct rsp stats;
	
	char str[7];
	int option;

	while (1) {
		main:
		system("cls");
		
		gotoxy(30, 14);
		puts("1) 게 임 시 작");
		gotoxy(30, 16);
		puts("2) 승 률");
		gotoxy(30, 18);
		puts("3) 게 임 종 료");

		gotoxy(37, 19);
		option = _getch();

		// 게임 모드 선택
		if (option == 49) {

			system("cls");
			puts("모드를 선택해주세요.\n\n삼세판\n일반\n");
			scanf_s("%s", str, sizeof(str));
			RSP(str, &stats);
			Pause();

		}
		// 전적 검색
		else if (option == 50) {
			Rate(&stats);
			Pause();
		}
		// 게임 종료
		else if (option == 51) {
			system("cls");
			printf("종료합니다...");
			exit(1);
		}
		
		
	}
	return 0;
}