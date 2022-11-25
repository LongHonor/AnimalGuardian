#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"
#include "pcHandler.h"

int main() {
	
	removeCursor();
	drawGameBoard();
	//makeEnemyList();
	//makeEnemy();
	//setPCCurrentPos(10, 20);
	setAnimalCurrentPos(&animalArray, 20, 1);
	drawAnimal();
	/*while (1) {
		drawPC(player);
		drawAnimal();
		drawEnemy();
		Sleep(200);
		deletePC(player);
		deleteAnimal();
		deleteEnemy();
		Sleep(200);
	}*/

	//키보드 입력 및 pc 구현
	drawPC(player);
	while (1) {
		pcKeyInput();
	}
	return 0;
}
