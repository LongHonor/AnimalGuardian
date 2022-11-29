#include "gameBoardHandler.h"
#include "globalVariable.h"
#include <windows.h>
#include <stdio.h>


//void initGameBoard() {
//	int posX, posY;
//	for (posY = 0; posY < gBoardHeight + 3; posY++) {
//		gameBoardInfo[posY][0] = 1;
//		gameBoardInfo[posY][gBoardWidth + 1] = 1;
//	}
//	for (posX = 0; posX < gBoardWidth + 2; posX++) {
//		gameBoardInfo[gBoardHeight][posX] = 1;
//	}
//}

void drawGameBoard() {
	int posX, posY;
	int pcAreaLine = 19;

	setCurrentGameBoard(0);

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
			if (currentGameBoard[posY][posX] == 1) {
				setCurrentCursorPos(posX * 2, posY);
				printf("─");
			}
			else if (currentGameBoard[posY][posX] == 4) {
				setCurrentCursorPos(posX * 2, posY);
				printf("♣");
			}
			else if (currentGameBoard[posY][posX] == 5) {
				setCurrentCursorPos(posX * 2, posY);
				printf("■");
			}
		}
	}
	setCurrentCursorPos(10, 19);
}

//좌표를 인자로 받아 gameBoardInfo에 추가
void AddBlockToBoard(posStruct barricadeCurPos) {

	int x, y, arrCurX, arrCurY;
	arrCurX = (barricadeCurPos.X - gBoardOx) / 2;
	arrCurY = barricadeCurPos.Y - gBoardOy;
	for (y = 0; y < 1; y++)
	{
		for (x = 0; x < 3; x++)
		{
			currentGameBoard[arrCurY + y][arrCurX + x] = 5;
		}
	}
}

void drawPC() {
	int posX, posY;

	posStruct pcCurPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(pcCurPos.X, pcCurPos.Y + posY);
		if (pcModel[posY][0] == 1) printf("＠");
		else printf("■");
	}
	setCurrentCursorPos(pcCurPos.X, pcCurPos.Y);
}
void deletePC() {
	int posX, posY;

	posStruct pcCurPos = getPCCurrentPos();
	//pc위치 받아와서 setCurrentCursorPos()호출

	for (posY = 0; posY < 2; posY++) {
		setCurrentCursorPos(pcCurPos.X, pcCurPos.Y + posY);
		printf("  ");
	}
	setCurrentCursorPos(pcCurPos.X, pcCurPos.Y);
}


void drawAnimal() {
	int posX, posY;

	for (int i = 0; i < 3; i++) {
		//animalNPC 위치 받아와서 setCurrentCursorPos()호출
		posStruct animalCurPos = getAnimalCurrentPos(&animalArray[i]);

		for (posX = 0; posX < 2; posX++) {
			setCurrentCursorPos(animalCurPos.X + posX*2, animalCurPos.Y);
			if (animalModel[0][posX] == 1) printf("♧");
			else printf("■");
		}
		setCurrentCursorPos(animalCurPos.X, animalCurPos.Y);
	}
}
void deleteAnimal() {
	int posX, posY;
	for (int i = 0; i < 3; i++) {
		//animalNPC 위치 받아와서 setCurrentCursorPos()호출
		posStruct animalCurPos = getAnimalCurrentPos(&animalArray[i]);

		for (posX = 0; posX < 2; posX++) {
			setCurrentCursorPos(animalCurPos.X + posX*2, animalCurPos.Y);
			printf("  ");
		}
		setCurrentCursorPos(animalCurPos.X, animalCurPos.Y);
	}
}


void drawEnemy() {
	int posX, posY;
	enemyNPC * search = enemyList->enemyHeader;

	while (search != NULL) {
		posStruct enemyCurPos = getEnemyCurrentPos(search->id);
		//enemyNPC 위치 받아와서 setCurrentCursorPos()호출

		for (posY = 0; posY < 1; posY++) {
			setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y + posY);
			if (enemyModel[posY][0] == 1) printf("▲");
		}
		setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y);
		search = search->next;
	}
}
void deleteEnemy() {
	int posX, posY;

	enemyNPC * search = enemyList->enemyHeader;
	while (search != NULL) {
		posStruct enemyCurPos = getEnemyCurrentPos(search->id);
		//enemyNPC 위치 받아와서 setCurrentCursorPos()호출

		for (posY = 0; posY < 1; posY++) {
			setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y + posY);
			printf("  ");
		}

		setCurrentCursorPos(enemyCurPos.X, enemyCurPos.Y);
		search = search->next;
	}
}

void drawUI();
