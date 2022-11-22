#include "gameBoardHandler.h"
#include "globalVariable.h"
#include "gameModel.h"
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
	{2}
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
	int pcAreaLine = 19;

	for (posY = 0; posY < GBOARD_HEIGHT + 3; posY++) {
		setCurrentCursorPos(0, posY);
		if (posY == GBOARD_HEIGHT + 2) printf("└");
		else if (posY == 0) printf("┌");
		else if (posY == pcAreaLine) printf("├");
		else printf("│");
		setCurrentCursorPos((GBOARD_WIDTH + 1) * 2, posY);
		if (posY == GBOARD_HEIGHT + 2) printf("┘");
		else if (posY == 0) printf("┐");
		else if (posY == pcAreaLine) printf("┤");
		else printf("│");

		for (posX = 1; posX < GBOARD_WIDTH + 1; posX++) {
			if (gameBoardInfo[posY][posX] == 1) {
				setCurrentCursorPos(posX * 2, posY);
				printf("─");
			}
			else if (gameBoardInfo[posY][posX] == 4) {
				setCurrentCursorPos(posX * 2, posY);
				printf("♣");
			}
			else if (gameBoardInfo[posY][posX] == 5) {
				setCurrentCursorPos(posX * 2, posY);
				printf("■");
			}
		}
	}

	setCurrentCursorPos(10, 19);
}
void drawPC() {
	int posX, posY;

	//temporal code
	

	PC pcCurPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(pcCurPos.pos.X, pcCurPos.pos.Y + posY);
		if (pcModel[posY][0] == 1) printf("＠");
		else printf("■");
	}
	//좌표 전역변수 활용에 맞게 수정가능성 있음
	setCurrentCursorPos(pcCurPos.pos.X, pcCurPos.pos.Y);
	curPosX = pcCurPos.pos.X;
	curPosY = pcCurPos.pos.Y;
}
void deletePC() {
	int posX, posY;

	//temporal code
	

	PC pcCurPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(pcCurPos.pos.X, pcCurPos.pos.Y + posY);
		printf("  ");
	}

	setCurrentCursorPos(pcCurPos.pos.X, pcCurPos.pos.Y);
	curPosX = pcCurPos.pos.X;
	curPosY = pcCurPos.pos.Y;
}
void drawAnimal() {
	int posX, posY;

	//temporal code
	

	Pos animalCurPos = getAnimalCurrentPos(&temp_animal);
	//animal npc위치 받아와서 setCurrentCursorPos()호출

	for (posX = 0; posX < 2; posX++) {
		setCurrentCursorPos(animalCurPos.X + posX, animalCurPos.Y);
		if (animalModel[0][posX] == 1) printf("♧");
		else printf("■");
	}
	setCurrentCursorPos(animalCurPos.X, animalCurPos.Y);
	curPosX = animalCurPos.X;
	curPosY = animalCurPos.Y;
}
void deleteAnimal() {
	int posX, posY;

	//temporal code
	

	Pos animalCurPos = getAnimalCurrentPos(&temp_animal);
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posX = 0; posX < 2; posX++) {
		setCurrentCursorPos(animalCurPos.X + posX, animalCurPos.Y);
		printf("  ");
	}
	setCurrentCursorPos(animalCurPos.X, animalCurPos.Y);
	curPosX = animalCurPos.X;
	curPosY = animalCurPos.Y;
}
void drawEnemy() {
	int posX, posY;

	//temporal code
	//setCurrentCursorPos(25, 16);

	Pos enemyCurPos = getEnemyCurrentPos(&temp_enemy);
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y + posY);
		if (enemyModel[posY][0] == 1) printf("▲");
		else printf("■");
	}
	setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y);
	curPosX = enemyCurPos.X;
	curPosY = enemyCurPos.Y;
}
void deleteEnemy() {
	int posX, posY;

	//temporal code
	

	Pos enemyCurPos = getEnemyCurrentPos(&temp_enemy);
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y + posY);
		printf("  ");
	}

	setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y);
	curPosX = enemyCurPos.X;
	curPosY = enemyCurPos.Y;
}
void drawUI();
