#include "gameBoardHandler.h"
#include "globalVariable.h"
#include <windows.h>
#include <stdio.h>

extern char gameBoardInfo[23][42];

void initGameBoard() {
	int posX, posY;
	for (posY = 0; posY < gBoardHeight + 3; posY++) {
		gameBoardInfo[posY][0] = 1;
		gameBoardInfo[posY][gBoardWidth + 1] = 1;
	}
	for (posX = 0; posX < gBoardWidth + 2; posX++) {
		gameBoardInfo[gBoardHeight][posX] = 1;
	}
}

void drawGameBoard() {
	int posX, posY;
	int pcAreaLine = 19;

	for (posY = 0; posY < gBoardHeight + 3; posY++) {
		setCurrentCursorPos(0, posY);
		if (posY == gBoardHeight + 2) printf("└");
		else if (posY == 0) printf("┌");
		else if (posY == pcAreaLine) printf("├");
		else printf("│");
		setCurrentCursorPos((gBoardWidth + 1) * 2, posY);
		if (posY == gBoardHeight + 2) printf("┘");
		else if (posY == 0) printf("┐");
		else if (posY == pcAreaLine) printf("┤");
		else printf("│");

		for (posX = 1; posX < gBoardWidth + 1; posX++) {
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
	

	posStruct pcCurPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(pcCurPos.X, pcCurPos.Y + posY);
		if (pcModel[posY][0] == 1) printf("＠");
		else printf("■");
	}
	//좌표 전역변수 활용에 맞게 수정가능성 있음
	setCurrentCursorPos(pcCurPos.X, pcCurPos.Y);
	curPosX = pcCurPos.X;
	curPosY = pcCurPos.Y;
}
void deletePC() {
	int posX, posY;

	//temporal code
	

	posStruct pcCurPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(pcCurPos.X, pcCurPos.Y + posY);
		printf("  ");
	}

	setCurrentCursorPos(pcCurPos.X, pcCurPos.Y);
	curPosX = pcCurPos.X;
	curPosY = pcCurPos.Y;
}
void drawAnimal() {
	int posX, posY;

	//temporal code
	

	posStruct animalCurPos = getAnimalCurrentPos(&tempAnimal);
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
	

	posStruct animalCurPos = getAnimalCurrentPos(&tempAnimal);
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
	enemyNPC * search = tempEnemies->enemyHeader;
	//temporal code
	//setCurrentCursorPos(25, 16);

	while (search != NULL) {
		posStruct enemyCurPos = getEnemyCurrentPos(search->id);
		//pc위치 받아와서 setCurrentCursorPos()호출

		for (posY = 0; posY < 2; posY++) {
			setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y + posY);
			if (enemyModel[posY][0] == 1) printf("▲");
			else printf("■");
		}
		setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y);
		curPosX = enemyCurPos.X;
		curPosY = enemyCurPos.Y;
		search = search->next;
	}
}
void deleteEnemy() {
	int posX, posY;

	//temporal code
	
	enemyNPC * search = tempEnemies->enemyHeader;
	while (search != NULL) {
		posStruct enemyCurPos = getEnemyCurrentPos(search->id);
		//pc위치 받아와서 setCurrentCursorPos()호출

		for (posY = 0; posY < 2; posY++) {
			setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y + posY);
			printf("  ");
		}

		setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y);
		curPosX = enemyCurPos.X;
		curPosY = enemyCurPos.Y;
		search = search->next;
	}
}
void drawUI();