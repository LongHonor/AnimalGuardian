#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"
#include "pcHandler.h"

int main() {

	setCurrentGameBoard(0);
	removeCursor();
	drawGameBoard();
	drawInitialUI();
	//makeEnemyList();
	//makeEnemy();
	//setPCCurrentPos(10, 20);
	for (int i = 0; i < 3; i++) {
		setAnimalCurrentPos(&animalArray[i], 20 + i * 4, 1);

	}
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
	showPC(player);
	while (1) {
		pcKeyInput();
	}
	return 0;
}
