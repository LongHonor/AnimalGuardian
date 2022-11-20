#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<conio.h>


int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2] = { {0} };
//PC 초기화


//PC 좌표 핸들러
//PC getPCCurrentPos() {
//	return real_pc;
//}
//void setPCCurrentPos(int moveX, int moveY) {
//	real_pc.pos.X = moveX; real_pc.pos.Y = moveY;
//}

//Enemy NPC 좌표 핸들러
Pos getEnemyCurrentPos(EnemyNPC* enemyNPC) {
	Pos curPos;
	curPos.X = enemyNPC->pos.X; curPos.Y = enemyNPC->pos.Y;
	return curPos;
}
void setEnemyCurrentPos(EnemyNPC* enemyNPC, int moveX, int moveY) {
	enemyNPC->pos.X = moveX; enemyNPC->pos.Y = moveY;
}


//Animal NPC 좌표 핸들러
Pos getAnimalCurrentPos(AnimalNPC* animalNPC) {
	Pos curPos;
	curPos.X = animalNPC->pos.X; curPos.Y = animalNPC->pos.Y;
	return curPos;
}
void setAnimalCurrentPos(AnimalNPC* animalNPC, int moveX, int moveY) {
	animalNPC->pos.X = moveX; animalNPC->pos.Y = moveY;
}

//bullet: 숫자3
char bulletModel[][1] = { {3} };

int enemy_number = 1;
int bullet_number = 1;
int item_number = 1;
int score = 1;

//커서
int curPosX = GBOARD_O_X, curPosY = GBOARD_O_Y;

PC pc = { 1,3,{GBOARD_O_X + 40,GBOARD_O_Y + 19},3};
char pcModel[][1] = { {2} };	//PC: 숫자2

void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void setCurrentCursorPos(int posX, int posY)
{
	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawGameBoard() {
	int posX, posY;
	int pcAreaLine = 18;

	for (posY = 0; posY < gameBoardHeight + 1; posY++) {
		setCurrentCursorPos(GBOARD_O_X + 0, GBOARD_O_Y + posY);
		if (posY == gameBoardHeight) printf("└");
		else if (posY == 0) printf("┌");
		else if (posY == pcAreaLine) printf("├");
		else printf("│");
		setCurrentCursorPos(GBOARD_O_X + (gameBoardWidth + 1) * 2, GBOARD_O_Y + posY);
		if (posY == gameBoardHeight) printf("┘");
		else if (posY == 0) printf("┐");
		else if (posY == pcAreaLine) printf("┤");
		else printf("│");


		if (posY == gameBoardHeight || posY == pcAreaLine || posY == 0) {
			for (posX = 2; posX <= gameBoardWidth * 2; posX += 2) {
				setCurrentCursorPos(GBOARD_O_X + posX, GBOARD_O_Y + posY);
				printf("─");
			}
		}
	}

	setCurrentCursorPos(0, 0);
}
//void drawPC() {
//	//전역변수 핸들러로 pc좌표 가져오기
//	int i;
//	for (i = 1; i <= 40; i++) {
//		setCurrentCursorPos(i * 2, 19);
//		printf("★");
//		Sleep(100);
//		setCurrentCursorPos(i * 2, 19);
//		printf("  ");
//	}
//}
void showPc(char modelinfo[][1],PC pc) {
	setCurrentCursorPos(pc.pos.X, pc.pos.Y);
	printf("●");
	setCurrentCursorPos(pc.pos.X, pc.pos.Y);    //cursor위치 처음 위치로 다시 설정
}
void deletePc(char modelinfo[][1], PC pc) {
	setCurrentCursorPos(pc.pos.X, pc.pos.Y);
	printf("  ");
	setCurrentCursorPos(pc.pos.X, pc.pos.Y);    //cursor위치 처음 위치로 다시 설정
}
int detectCollisionPC(int posX, int posY, char blockModel[][1]) {
	//gameboardinfo 좌표로 조정
	int arrx = (posX - GBOARD_O_X) / 2;
	int arry = (posY - GBOARD_O_Y);
	//pc총돌 리턴 0
	if (blockModel[0][0] == 2 && gameBoardInfo[arry][arrx] == 1) {
		return 0;
	}
	return 1;
}
int shiftLeftPc() {
	//총돌시 리턴 0
	if (!detectCollisionPC(pc.pos.X - 2, pc.pos.Y, pcModel)) {
		return 0;
	}
	//deletePcFromBoard();
	deletePc(pcModel,pc);
	pc.pos.X -= 2;
	setCurrentCursorPos(pc.pos.X, pc.pos.Y);
	showPc(pcModel, pc);
	//addPctoBoard();
	return 1;
}
int shiftRightPc() {
	//총돌시 리턴 0
	if (!detectCollisionPC(pc.pos.X + 2, pc.pos.Y, pcModel)) {
		return 0;
	}
	//deletePcFromBoard();
	deletePc(pcModel,pc);
	pc.pos.X += 2;
	setCurrentCursorPos(pc.pos.X, pc.pos.Y);
	showPc(pcModel,pc);
	//addPctoBoard();
	return 1;
}
void processKeyInput() {
	int key;
	for (int i = 0; i < 20; i++) {
		//_kbhit 은 입력시 1 리턴
		if (_kbhit() != 0) {
			key = _getch();
			switch (key) {
			case LEFT:
				shiftLeftPc();
				break;
			case RIGHT:
				shiftRightPc();
				break;
			}
		}
		Sleep(20);
	}
}
void initGameBoard() {
	//맵, pc, animal, enemy, UI 출력 

	int posX, posY;

	for (posY = 0; posY < gameBoardHeight + 1; posY++) {
		gameBoardInfo[posY][0] = 1;
		gameBoardInfo[posY][gameBoardWidth + 1] = 1;
	}
	for (posX = 0; posX < gameBoardWidth + 2; posX++) {
		gameBoardInfo[0][posX] = 1;
		gameBoardInfo[gameBoardHeight][posX] = 1;
	}

	drawGameBoard();
	//drawPC();

}
