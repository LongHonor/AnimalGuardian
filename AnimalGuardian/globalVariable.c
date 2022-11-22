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

//커서 전역변수
int curPosX = GBOARD_O_X, curPosY = GBOARD_O_Y;

//PC 좌표 핸들러
pos getPCCurrentPos() {
	return tempPc.pos;
}
void setPCCurrentPos( int moveX, int moveY) {
	tempPc.pos.X = moveX; tempPc.pos.Y = moveY;
}

//Enemy NPC 좌표 핸들러
pos getEnemyCurrentPos(enemyNPC * enemyNPC) {
	pos curPos;
	curPos.X = enemyNPC->pos.X; curPos.Y = enemyNPC->pos.Y;
	return curPos;
}
void setEnemyCurrentPos(enemyNPC * enemyNPC, int moveX, int moveY) {
	enemyNPC->pos.X = moveX; enemyNPC->pos.Y = moveY;
}


//Animal NPC 좌표 핸들러
pos getAnimalCurrentPos(animalNPC * animalNPC) {
	pos curPos;
	curPos.X = animalNPC->pos.X; curPos.Y = animalNPC->pos.Y;
	return curPos;
}
void setAnimalCurrentPos(animalNPC * animalNPC, int moveX, int moveY) {
	animalNPC->pos.X = moveX; animalNPC->pos.Y = moveY;
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

//enemyNPC 충돌 관리
int enemyNPCDetectCollision(int posX, int posY) {
	int x, y;
	int arrX = (posX - GBOARD_O_X) / 2;
	int arrY = posY - GBOARD_O_Y;
	for (x = 0; x < 1; x++)
	{
		for (y = 0; y < 2; y++)
		{
			if (enemyModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 1) {
				return 0;
			}
		}
	}
	return 1;
}
