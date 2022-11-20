#include "globalVariable.h"
#include "gameBoardHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//아직 구현 X
//int BulletDetectCollision(int posX, int posY, char bulletModel[2][1]) {
//	int x, y;
//	int arrX = (posX - GBOARD_O_X) / 2;
//	int arrY = posY - GBOARD_O_Y;
//	for (x = 0; x < 1; x++)
//	{
//		for (y = 0; y < 2; y++)
//		{
//			if (bulletModel[y][x] == 1 && gameBoardInfo[arrY + y][arrX + x] == 1) {
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//void drawBullet(Pos curPos) {
//	int posX, posY;
//
//	for (posY = 0; posY < 2; posY++) {
//		setCurrentCursorPos(curPos.X, curPos.Y + posY);
//		printf("▲");
//	}
//}

//충돌 0리턴
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

//좌표를 인자로 받아 gameBoardInfo 배열에 추가
void AddBlockToBoard(Pos curPos) {
	int x, y, arrCurX, arrCurY;
	for (y = 0; y < 1; y++)
	{
		for (x = 0; x < 2; x++)
		{
			arrCurX = (curPos.X - GBOARD_O_X) / 2;
			arrCurY = curPos.Y - GBOARD_O_Y;
			gameBoardInfo[arrCurY + y][arrCurX + x] = 1;
		}
	}
}

//temporal code
void drawBlock(Pos curPos) {
	int posX, posY;

	for (posX = 0; posX < 2; posX++) {
		setCurrentCursorPos(curPos.X + posX * 2, curPos.Y);
		printf("■");
	}
}


int main() {

	Pos enemyPos;
	Pos block, bullet;
	block.X = 20; block.Y = 5;
	bullet.X = 20; bullet.Y = 14;

	removeCursor();
	drawGameBoard();

	//pc,npc 시작 위치 초기화
	//test를 위해 전역변수 npc들 사용
	setPCCurrentPos(10, 19);
	setAnimalCurrentPos(&temp_animal,20, 1);
	setEnemyCurrentPos(&temp_enemy, 22, 15);

	//콘솔창에 출력
	drawPC();
	drawAnimal();
	drawEnemy();
	drawBlock(block);

	//충돌 체크를 위해 장애물 위치 gameBoard에 입력
	AddBlockToBoard(block);
	
	//move test code
	/*while (1) {
		drawEnemy();
		enemyPos = getEnemyCurrentPos(&temp_enemy);
		Sleep(500);
		deleteEnemy();
		setEnemyCurrentPos(&temp_enemy, enemyPos.X, enemyPos.Y - 1);
		Sleep(500);
	}*/

	//enemy NPC detectcollision test code
	while (1) {

		Sleep(500);

		//enemy 위치 get
		enemyPos = getEnemyCurrentPos(&temp_enemy);
		if (!enemyNPCDetectCollision(enemyPos.X, enemyPos.Y-1)) {
			setCurrentCursorPos(0, 24);
			printf("enemy 충돌");
			break;
		}

		//아직 구현 X
		/*if (!bulletNPCDetectCollision(bullet.X, bullet.Y - 1)) {
			setCurrentCursorPos(0, 24);
			printf("bullet 충돌");
			break;
		}*/

		//enemy move
		deleteEnemy();
		setEnemyCurrentPos(&temp_enemy, enemyPos.X, enemyPos.Y - 1);
		drawEnemy();
		//setEnemyCurrentPos(&temp_animal, enemyPos.X, enemyPos.Y + 1);
	}
	
	setCurrentCursorPos(0, 25);
	return 0;
}
