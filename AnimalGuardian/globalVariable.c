#include "globalVariable.h"
#include <stdlib.h>
#include <stdio.h>



//PC ÁÂÇ¥ ÇÚµé·¯
PC getPCCurrentPos() {
	return real_pc;
}
void setPCCurrentPos( int moveX, int moveY) {
	real_pc.pos.X = moveX; real_pc.pos.Y = moveY;
}

//Enemy NPC ÁÂÇ¥ ÇÚµé·¯
Pos getEnemyCurrentPos(EnemyNPC * enemyNPC) {
	Pos curPos;
	curPos.X = enemyNPC->pos.X; curPos.Y = enemyNPC->pos.Y;
	return curPos;
}
void setEnemyCurrentPos(EnemyNPC * enemyNPC, int moveX, int moveY) {
	enemyNPC->pos.X = moveX; enemyNPC->pos.Y = moveY;
}


//Animal NPC ÁÂÇ¥ ÇÚµé·¯
Pos getAnimalCurrentPos(AnimalNPC * animalNPC) {
	Pos curPos;
	curPos.X = animalNPC->pos.X; curPos.Y = animalNPC->pos.Y;
	return curPos;
}
void setAnimalCurrentPos(AnimalNPC * animalNPC, int moveX, int moveY) {
	animalNPC->pos.X = moveX; animalNPC->pos.Y = moveY;
}

//bullet ¸ðµ¨
char bulletModel[2][1] =
	{	{1},
		{1}	 };

//Ä¿¼­
int curPosX = GBOARD_O_X, curPosY = GBOARD_O_Y;

void removeCursor()
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

COORD getCurrentCursorPos(void) {
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

