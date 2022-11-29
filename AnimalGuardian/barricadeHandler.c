#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "barricadeHandler.h"
#include "detectCollision.h"
#include <stdio.h>

char barcModel[1][3] = { {1,1,1} };
int barcX = 4, barcY = 10;
int barricadeColor = 7;

void drawBarricade() {
	int posX, posY;
	posStruct barricadePos = { barcX,barcY };
	for (posX = 0; posX < 3; posX++) {
		setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y);
		printf("¡à");
	}
	setCurrentCursorPos(barricadePos.X, barricadePos.Y);
}
void deleteBarricade() {
	int posX, posY;
	posStruct barricadePos = { barcX,barcY };
	for (posX = 0; posX < 3; posX++) {
		setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y);
		printf("  ");
	}
	setCurrentCursorPos(barricadePos.X, barricadePos.Y);
}


void shiftLeftBarricade() {
	//ÃÑµ¹½Ã ¸®ÅÏ 0
	
	if (!detectCollisionBarricade(barcX - 2, barcY)) {
		return;
	}
	else if (detectCollisionBarricade(barcX - 2, barcY) == 9) {
		barricadeColor = 4;

	}
	else {
		barricadeColor = 7;
	}
	deleteBarricade();
	barcX -= 2;
	restoreConsoleColor();
	drawGameBoard();
	setCurrentCursorPos(barcX, barcY);
	changeConsoleColor(barricadeColor);
	drawBarricade();
}
void shiftRightBarricade() {
	//ÃÑµ¹½Ã ¸®ÅÏ 0

	if (!detectCollisionBarricade(barcX + 2, barcY)) {
		return;
	}
	else if (detectCollisionBarricade(barcX + 2, barcY) == 9) {
		barricadeColor = 4;
	}
	else {
		barricadeColor = 7;
	}
	deleteBarricade();
	barcX += 2;
	restoreConsoleColor();
	drawGameBoard();
	setCurrentCursorPos(barcX, barcY);
	changeConsoleColor(barricadeColor);
	drawBarricade();
}
void shiftUpBarricade() {
	//ÃÑµ¹½Ã ¸®ÅÏ 0

	if (!detectCollisionBarricade(barcX, barcY-1)) {
		return;
	}
	else if (detectCollisionBarricade(barcX, barcY-1) == 9) {
		barricadeColor = 4;
	}
	else {
		barricadeColor = 7;
	}
	deleteBarricade();
	barcY -= 1;
	restoreConsoleColor();
	drawGameBoard();
	setCurrentCursorPos(barcX, barcY);
	changeConsoleColor(barricadeColor);
	drawBarricade();
}
void shiftDownBarricade() {
	//ÃÑµ¹½Ã ¸®ÅÏ 0

	if (!detectCollisionBarricade(barcX , barcY+1)) {
		return;
	}
	else if (detectCollisionBarricade(barcX, barcY+1) == 9) {
		barricadeColor = 4;
	}
	else {
		barricadeColor = 7;
	}
	deleteBarricade();
	barcY += 1;
	restoreConsoleColor();
	drawGameBoard();
	setCurrentCursorPos(barcX, barcY);
	changeConsoleColor(barricadeColor);
	drawBarricade();
}



