#include "gameBoardHandler.h"
#include "globalVariable.h"
#include <windows.h>
#include <stdio.h>


char pcModel[2][1] = {
	{1},
	{2}
};

char animalModel[1][2] = {
	{1, 2}
};

char enemyModel[2][1] = {
	{1},
	{1}
};
//temoporary functions for waiting global functions end

void initGameBoard() {
	int posX, posY;
	for (posY = 0; posY < GBOARD_HEIGHT + 1; posY++) {
		gameBoardInfo[posY][0] = 1;
		gameBoardInfo[posY][GBOARD_WIDTH + 1] = 1;
	}
	for (posX = 0; posX < GBOARD_WIDTH + 2; posX++) {
		gameBoardInfo[GBOARD_HEIGHT][posX] = 1;
	}
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
void drawPC() {
	int posX, posY;

	//temporal code
	

	PC curPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(curPos.pos.X, curPos.pos.Y + posY);
		if (pcModel[posY][0] == 1) printf("＠");
		else printf("■");
	}
	setCurrentCursorPos(curPos.pos.X, curPos.pos.Y);
}
void deletePC() {
	int posX, posY;

	//temporal code
	

	PC curPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(curPos.pos.X, curPos.pos.Y + posY);
		printf("  ");
	}

	setCurrentCursorPos(curPos.pos.X, curPos.pos.Y);
}
void drawAnimal() {
	int posX, posY;

	//temporal code
	

	Pos curPos = getAnimalCurrentPos(&temp_animal);
	//animal npc위치 받아와서 setCurrentCursorPos()호출

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
	

	Pos curPos = getAnimalCurrentPos(&temp_animal);
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
	//setCurrentCursorPos(25, 16);

	Pos curPos = getEnemyCurrentPos(&temp_enemy);
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
	

	Pos curPos = getEnemyCurrentPos(&temp_enemy);
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(curPos.X, curPos.Y + posY);
		printf("  ");
	}

	setCurrentCursorPos(curPos.X, curPos.Y);
}
void drawUI();
