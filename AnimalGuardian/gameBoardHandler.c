#include "gameBoardHandler.h"
#include "globalVariable.h"
#include <windows.h>
#include <stdio.h>

//temoporary functions for waiting global functions start
void setCurrentCursorPos(int posX, int posY) {
	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD getCurrentCursorPos(void) {
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

char pcModel[2][1] = {
	{1},
	{2}
};

char animalModel[1][2] = {
	{1, 2}
};

char enemyModel[2][1] = {
	{1},
	{2}
};
//temoporary functions for waiting global functions end

void initGameBoard() {
	int posX, posY;
}
void drawGameBoard() {
	int posX, posY;
	int pcAreaLine = 18;

	for (posY = 0; posY < GBOARD_HEIGHT + 2; posY++) {
		setCurrentCursorPos(0, posY);
		if (posY == GBOARD_HEIGHT + 1) printf("└");
		else if (posY == 0) printf("┌");
		else if (posY == pcAreaLine) printf("├");
		else printf("│");
		setCurrentCursorPos((GBOARD_WIDTH + 1) * 2, posY);
		if (posY == GBOARD_HEIGHT + 1) printf("┘");
		else if (posY == 0) printf("┐");
		else if (posY == pcAreaLine) printf("┤");
		else printf("│");


		if (posY == GBOARD_HEIGHT + 1 || posY == pcAreaLine || posY == 0) {
			for (posX = 2; posX <= GBOARD_WIDTH * 2; posX += 2) {
				setCurrentCursorPos(posX, posY);
				printf("─");
			}
		}
	}

	setCurrentCursorPos(10, 19);
}
void drawPC(){
	int posX, posY;

	//temporal code
	setCurrentCursorPos(10, 19);

	COORD curPos = getCurrentCursorPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(curPos.X, curPos.Y + posY);
		if (pcModel[posY][0] == 1) printf("＠");
		else printf("■");
	}
	setCurrentCursorPos(curPos.X, curPos.Y);
}
void deletePC() {
	int posX, posY;

	//temporal code
	setCurrentCursorPos(10, 19);

	COORD curPos = getCurrentCursorPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(curPos.X, curPos.Y + posY);
		printf("  ");
	}

	setCurrentCursorPos(curPos.X, curPos.Y);
}
void drawAnimal() {
	int posX, posY;

	//temporal code
	setCurrentCursorPos(20, 1);
	
	COORD curPos = getCurrentCursorPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posX = 0; posX < 2; posX++) {
		setCurrentCursorPos(curPos.X + posX, curPos.Y);
		if (animalModel[0][posX] == 1) printf("♧");
		else printf("■");
	}
	setCurrentCursorPos(curPos.X, curPos.Y);
}
void deleteAnimal() {
	int posX, posY;

	//temporal code
	setCurrentCursorPos(20, 1);

	COORD curPos = getCurrentCursorPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posX = 0; posX < 2; posX++) {
		setCurrentCursorPos(curPos.X + posX, curPos.Y);
		printf("  ");
	}
	setCurrentCursorPos(curPos.X, curPos.Y);
}
void drawEnemy() {
	int posX, posY;

	//temporal code
	setCurrentCursorPos(25, 16);

	COORD curPos = getCurrentCursorPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(curPos.X, curPos.Y + posY);
		if (pcModel[posY][0] == 1) printf("▲");
		else printf("■");
	}
	setCurrentCursorPos(curPos.X, curPos.Y);
}
void deleteEnemy() {
	int posX, posY;

	//temporal code
	setCurrentCursorPos(25, 16);

	COORD curPos = getCurrentCursorPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(curPos.X, curPos.Y + posY);
		printf("  ");
	}

	setCurrentCursorPos(curPos.X, curPos.Y);
}
void drawUI();