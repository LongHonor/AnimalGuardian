#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"


int main() {
	
	removeCursor();
	drawGameBoard();
	makeEnemyList();
	makeEnemy();
	setPCCurrentPos(10, 20);
	setAnimalCurrentPos(&animalArray, 20, 1);
	
	while (1) {
		drawPC();
		drawAnimal();
		drawEnemy();
		Sleep(200);
		deletePC();
		deleteAnimal();
		deleteEnemy();
		Sleep(200);
	}

	return 0;
}
