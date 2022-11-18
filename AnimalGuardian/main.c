#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"

//temporal function
void RemoveCursor() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
//temporal function

int main() {
	
	RemoveCursor();
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