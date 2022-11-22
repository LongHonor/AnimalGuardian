#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"


int main() {
	
	removeCursor();
	drawGameBoard();

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
