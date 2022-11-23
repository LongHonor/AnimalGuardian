#include "globalVariable.h"

#include <stdlib.h>
#include <stdio.h>


//모델
char bulletModel[2][1] ={ 
	{1},
	{1} 
};

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

//UI
enemyNumber = 10;
bulletNumber = 0;
itemNumber=0;
score = 0;;


//커서 전역변수
int curPosX = gBoardOx, curPosY = gBoardOy;

//PC 좌표 핸들러
posn getPCCurrentPos() {
	return tempPc.pos;
}
void setPCCurrentPos( int moveX, int moveY) {
	tempPc.pos.X = moveX; tempPc.pos.Y = moveY;
}

//Enemy NPC 좌표 핸들러
posn getEnemyCurrentPos(int enemyId) {
	enemyNPC *findEnemy = tempEnemies->enemyHeader;
	posn curPos = { -1,-1 };

	if (findEnemy == NULL) {
		return curPos;
	}
	while (findEnemy != NULL) {
		if (findEnemy->id == enemyId) {
			curPos.X = findEnemy->pos.X; curPos.Y = findEnemy->pos.Y;
			return curPos;
		}
		findEnemy = findEnemy->next;
	}
	
	return curPos;
}
void setEnemyCurrentPos(int enemyId, int moveX, int moveY) {
	enemyNPC *findEnemy = tempEnemies->enemyHeader;
	if (findEnemy == NULL) {
		return ;
	}
	while (findEnemy != NULL) {
		if (findEnemy->id == enemyId) {

			findEnemy->pos.X = moveX; findEnemy->pos.Y = moveY;
			return ;
		}
		findEnemy = findEnemy->next;
	}
}


//Animal NPC 좌표 핸들러
posn getAnimalCurrentPos(animalNPC * animal) {
	posn curPos;
	curPos.X = animal->pos.X; curPos.Y = animal->pos.Y;
	return curPos;
}
void setAnimalCurrentPos(animalNPC * animal, int moveX, int moveY) {
	animal->pos.X = moveX; animal->pos.Y = moveY;
}

//커서 삭제
void removeCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

//커서 위치 설정
void setCurrentCursorPos(int posX, int posY)
{
	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	curPosX = posX;
	curPosY = posY;
}

//현재 커서 위치 반환
COORD getCurrentCursorPos(void) {
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

//enemyList 동적할당 구현부
void makeEnemyList() {
	tempEnemies = (enemyNPCList*)malloc(sizeof(enemyNPCList));
	tempEnemies->enemyCurrentNumber = 0;
	tempEnemies->enemyHeader = NULL;
}

void freeEnemuList() {
	enemyNPC *freeEnemy = NULL, *freeEnemyNext = freeEnemy;
	while (freeEnemyNext != NULL) {
		freeEnemy = freeEnemyNext;
		freeEnemyNext = freeEnemyNext->next;
		free(freeEnemy);
	}
	free(tempEnemies);
}
