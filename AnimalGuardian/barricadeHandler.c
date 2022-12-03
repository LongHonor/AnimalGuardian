#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "barricadeHandler.h"
#include "detectCollision.h"
#include <stdio.h>

char barcModel[1][3] = { {1,1,1} };
int barcX = 4, barcY = 10;
int barricadeColor = white;

void drawBarricade() {
	int posX, posY;
	posStruct barricadePos = { barcX,barcY };
	for (posX = 0; posX < 3; posX++) {
		setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y);
		printf("бр");
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
void drawDamagedBarricade(posStruct barricadePos) {
	int posX, posY;
	
	for (posX = 0; posX < 4; posX++) {
		for (posY = 0; posY < 3; posY++) {
			setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y + posY);
			printf("в╞");
		}
	}
	setCurrentCursorPos(barricadePos.X, barricadePos.Y);
}

void deleteDamagedBarricade(posStruct barricadePos) {
	int posX, posY;

	for (posX = 0; posX < 4; posX++) {
		for (posY = 0; posY < 3; posY++) {
			setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y + posY);
			printf("  ");
		}
	}
	setCurrentCursorPos(barricadePos.X, barricadePos.Y);
}

void shiftLeftBarricade() {

	
	if (!detectCollisionBarricade(barcX - 2, barcY)) {
		return;
	}
	else if (detectCollisionBarricade(barcX - 2, barcY) == 9) {
		barricadeColor = red;

	}
	else {
		barricadeColor = lightYellow;
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


	if (!detectCollisionBarricade(barcX + 2, barcY)) {
		return;
	}
	else if (detectCollisionBarricade(barcX + 2, barcY) == 9) {
		barricadeColor = red;
	}
	else {
		barricadeColor = lightYellow;
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
	if (barcY == 2) return;

	if (!detectCollisionBarricade(barcX, barcY-1)) {
		return;
	}
	else if (detectCollisionBarricade(barcX, barcY-1) == 9) {
		barricadeColor = red;
	}
	else {
		barricadeColor = lightYellow;
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
	if (barcY == 18) return;

	if (!detectCollisionBarricade(barcX , barcY+1)) {
		return;
	}
	else if (detectCollisionBarricade(barcX, barcY+1) == 9) {
		barricadeColor = red;
	}
	else {
		barricadeColor = lightYellow;
	}
	deleteBarricade();
	barcY += 1;
	restoreConsoleColor();
	drawGameBoard();
	setCurrentCursorPos(barcX, barcY);
	changeConsoleColor(barricadeColor);
	drawBarricade();
}



