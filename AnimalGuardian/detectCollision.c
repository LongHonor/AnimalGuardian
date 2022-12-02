#include "detectCollision.h"
#include "globalVariable.h"
#include "barricadeHandler.h"

//gameboard line or another enemy : 0
//장애물 or barricade : 9
//animal : 3
//not 충돌 : 1
int enemyNPCDetectCollision(int posX, int posY) {
	int x, y;
	int arrX = (posX - gBoardOx) / 2;
	int arrY = posY - gBoardOy;
	for (x = 0; x < 1; x++)
	{
		for (y = 0; y < 1; y++)
		{
			//gameBoard line or another enemy
			if (enemyModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 1 || currentGameBoard[arrY + y][arrX + x] == 2)) {
				return 0;
			}
			//장애물
			if (enemyModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 4 || currentGameBoard[arrY + y][arrX + x] == 5|| currentGameBoard[arrY+y][arrX+x] == 7)) {
				return 9;
			}
			//attack animal 
			if (enemyModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 3)) {
				return 6;
			}
		}
	}
	return 1;
}

//장애물 or gameboard line or barricade : 0
//another animal : 0
//not 충돌 : 1
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


//충돌 : 0
//not 충돌 : 1
int detectCollisionPC(int posX, int posY) {
	int arrX = (posX - gBoardOx) / 2;
	int arrY = (posY - gBoardOy);
	//pc충돌 리턴 0
	if (currentGameBoard[arrY][arrX] == 1) {
		return 0;
	}
	return 1;
}


//장애물 or gameboard line or barricade : 0
//enemy or animal : 5
//not 충돌 : 1
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
	if (currentGameBoard[arrY][arrX] == 6 || currentGameBoard[arrY][arrX] == 3) {
		return 5;
	}
	return 1;
}

//gameboard line : 0
//not empty : 9
//empty : 1
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
