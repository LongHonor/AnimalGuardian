#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


//PC 좌표 핸들러
PC getPCCurrentPos() {
	return real_pc;
}
void setPCCurrentPos(int moveX, int moveY) {
	real_pc.posX = moveX; real_pc.posY = moveY;
}

//Enemy NPC 좌표 핸들러
Pos getEnemyCurrentPos(EnemyNPC * enemyNPC) {
	Pos curPos;
	curPos.X = enemyNPC->posX; curPos.Y = enemyNPC->posY;
	return curPos;
}
void setEnemyCurrentPos(EnemyNPC * enemyNPC, int moveX, int moveY) {
	enemyNPC->posX = moveX; enemyNPC->posY = moveY;
}


//Animal NPC 좌표 핸들러
Pos getAnimalCurrentPos(AnimalNPC * animalNPC) {
	Pos curPos;
	curPos.X = animalNPC->posX; curPos.Y = animalNPC->posY;
	return curPos;
}
void setAnimalCurrentPos(AnimalNPC * animalNPC, int moveX, int moveY) {
	animalNPC->posX = moveX; animalNPC->posY = moveY;
}

//bullet 모델
char bulletModel[1][2] ={	
      {1},
		{1}	 };

//커서
int curPosX = GBOARD_O_X, curPosY = GBOARD_O_Y;

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
	curPosX = posX;
	curPosY = posY;
}
