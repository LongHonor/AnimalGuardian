﻿#include "globalVariable.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

//이차원 배열 모델
char gameBoardInfo[23][42] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,4,0,0,0,0,0,0,0,1},
	{1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,4,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,1},
	{1,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,4,0,1},
	{1,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,4,0,1},
	{1,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,4,0,0,0,0,5,5,5,0,0,4,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1},
	{1,0,0,0,0,0,0,4,0,0,0,0,5,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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
enemyNumber = 0;
bulletNumber = 0;
itemNumber=0;
score = 0;;

//커서 전역변수
int curPosX = gBoardOx, curPosY = gBoardOy;

//PC 초기화
pc player = { {40,20},1,3,3 };

//bullet 초기화
int max_bullet = 10;
Bullet* bullet_head = NULL;
int bulletItem = 0;

//PC 좌표 핸들러
posStruct getPCCurrentPos() {
	return playableCharacter.pos;
}
void setPCCurrentPos( int moveX, int moveY) {
	playableCharacter.pos.X = moveX;
	playableCharacter.pos.Y = moveY;
}

//Enemy NPC 좌표 핸들러
posStruct getEnemyCurrentPos(int enemyId) {
	enemyNPC *findEnemy = enemyList->enemyHeader;

	//enemy 존재하지 않을 때 반환값, 추후 변경 가능
	posStruct curPos = { -1,-1 };

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
	enemyNPC *findEnemy = enemyList->enemyHeader;
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
posStruct getAnimalCurrentPos(animalNPC * animal) {
	posStruct curPos;
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

//현재 커서 위치 설정
void setCurrentCursorPos(int posX, int posY)
{
	COORD curPoint = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curPoint);
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