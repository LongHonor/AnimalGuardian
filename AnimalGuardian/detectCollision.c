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
			//gameBoard line
			if (enemyModel[y][x] != 0 && currentGameBoard[arrY + y][arrX + x] == 1) {
				return 0;
			}
			//장애물 return값 9
			if (enemyModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 4 || currentGameBoard[arrY + y][arrX + x] == 5)) {
				return 9;
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
			if (animalModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 1)) {
				return 0;
			}
		}
	}
	return 1;
}

int detectCollisionPC(int posX, int posY) {
	int arrx = (posX - gBoardOx) / 2;
	int arry = (posY - gBoardOy);
	//pc총돌 리턴 0
	if (currentGameBoard[arry][arrx] == 1) {
		return 0;
	}
	return 1;
}

int detectCollisionBullet(int posX, int posY) {
	int arrx = (posX - gBoardOx) / 2;
	int arry = (posY - gBoardOy);
	if (currentGameBoard[arry][arrx] == 4 || currentGameBoard[arry][arrx] == 5) {
		return 0;
	}
	if (currentGameBoard[arry][arrx] == 1) {
		return 0;
	}
	if (currentGameBoard[arry][arrx] == 7) {
		return 0;
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
		{
			//empty
			if (barcModel[y][x] != 0 && currentGameBoard[arrY + y][arrX + x] == 1) {
				return 0;
			}
			else if (barcModel[y][x] != 0 && currentGameBoard[arrY + y][arrX + x] != 0) {
				return 9;
			}
		}
	}
	return 1;
}
