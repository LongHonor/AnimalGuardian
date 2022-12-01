#include "detectCollision.h"
#include "globalVariable.h"
#include "barricadeHandler.h"

//enemyNPC 충돌 관리
int enemyNPCDetectCollision(int posX, int posY) {
	int x, y;
	int arrX = (posX - gBoardOx) / 2;
	int arrY = posY - gBoardOy;
	for (x = 0; x < 1; x++)
	{
		for (y = 0; y < 1; y++)
		{
			//gameBoard line or another animal
			if (enemyModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 1 || currentGameBoard[arrY + y][arrX + x] == 2)) {
				return 0;
			}
			//장애물
			if (enemyModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 4 || currentGameBoard[arrY + y][arrX + x] == 5|| currentGameBoard[arrY+y][arrX+x] == 7)) {
				return 9;
			}
			//attack animal 
			if (enemyModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 3)) {
				return 3;
			}
		}
	}
	return 1;
}
int animalNPCdetectCollision(int posX, int posY) {
	int x, y;
	int arrX = (posX - gBoardOx) / 2;
	int arrY = posY - gBoardOy;
	for (x = 0; x < 2; x++)
	{
		for (y = 0; y < 1; y++)
		{
			//gameBoard line
			if (animalModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 1)) {
				return 0;
			}
			//another animal
			if (animalModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 3)) {
				return 0;
			}
		}
	}
	return 1;
}

int detectCollisionPC(int posX, int posY) {
	int arrX = (posX - gBoardOx) / 2;
	int arrY = (posY - gBoardOy);
	//pc충돌 리턴 0
	if (currentGameBoard[arrY][arrX] == 1) {
		return 0;
	}
	return 1;
}

int detectCollisionBullet(int posX, int posY) {
	int arrX = (posX - gBoardOx) / 2;
	int arrY = (posY - gBoardOy);

	//장애물
	if (currentGameBoard[arrY][arrX] == 4 || currentGameBoard[arrY][arrX] == 5) {
		return 0;
	}
	//gameboard line
	if (currentGameBoard[arrY][arrX] == 1) {
		return 0;
	}
	//barricade
	if (currentGameBoard[arrY][arrX] == 7) {
		return 0;
	}
	//enemy or animal
	if (currentGameBoard[arrY][arrX] == 2 || currentGameBoard[arrY][arrX] == 3) {
		return 5;
	}
	return 1;
}

int detectCollisionBarricade(int posX, int posY) {
	int x, y;
	int arrX = (posX - gBoardOx) / 2;
	int arrY = posY - gBoardOy;
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 1; y++)
		{	//gameboard line
			if (barcModel[y][x] != 0 && currentGameBoard[arrY + y][arrX + x] == 1) {
				return 0;
			}
			//not empty
			else if (barcModel[y][x] != 0 && currentGameBoard[arrY + y][arrX + x] != 0) {
				return 9;
			}
		}
	}
	//empty
	return 1;
}
