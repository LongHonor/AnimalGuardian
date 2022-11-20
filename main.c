#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
#include "header.h"

//void removeCursor();
//void initGameBoard();
//void drawGameBoard();
//void drawPC();
//void drawAnimal();
//void drawEnemy();
//void drawUI();

int main(int argc, char* argv[]) {
	removeCursor();
	initGameBoard();
	setCurrentCursorPos(pc.pos.X, pc.pos.Y);
	showPc(pcModel, pc);
	while (1) {
		processKeyInput();
	}
	getchar();

	return 0;
}

//void drawAnimal();
//void drawEnemy();
//void drawUI();
