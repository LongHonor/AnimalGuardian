#pragma once
#include <stdio.h>
#include <Windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"

typedef enum direction {
	leftDirection = 0,
	rightDirection= 1
} direction;

void drawKingAnimal(int x, int y, int direction){
	int i, j;
	int cursorX = 2 * x;

	setCurrentCursorPos(cursorX *2, y);
	changeConsoleColor(purple);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			setCurrentCursorPos(cursorX +j*2, y + i);
			if (kingAnimalModel[direction][i][j] == 1) printf("■");
			else if (kingAnimalModel[direction][i][j] == 2) printf("▲");
			else printf("  ");
		}
	}
	restoreConsoleColor();
}

void deleteKingAnimal(int x, int y) {
	int i, j;
	int cursorX = 2 * x;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			setCurrentCursorPos(cursorX + j * 2, y + i);
			printf("  ");
		}
	}
}

void shiftKingAnimal(int startX, int direction, int distance) {
	int i;
	int sth = 0;
	int posX = startX;

	for (i = 0; i < distance; i++) {
		switch (direction) {
		case 0:
			sth = -1 * i;
			break;
		case 1:
			sth = i;
			break;
		}
		
		drawKingAnimal(posX + sth, 1, direction);
		Sleep(200);
		deleteKingAnimal(posX + sth, 1);
	}	
}

void scene1() {
	setCurrentGameBoard(3);
	drawGameBoard();

	shiftKingAnimal(18, leftDirection, 5);
	shiftKingAnimal(13, rightDirection, 10);
	shiftKingAnimal(23, leftDirection, 5);
	drawKingAnimal(18, 1, leftDirection);
}

void drawWall(int posX, int posY) {
	int i, j;
	int height = 3, width = 10;
	int cursorX = posX * 2;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			setCurrentCursorPos(cursorX+j*2, posY + i);
			if (i != height-1) {
				if (j == 0 || j == width-1) printf("■");
			}
			else {
				printf("■");
			}
		}
	}
}

void deleteWall(int posX, int posY) {
	int i, j;
	int height = 3, width = 10;
	int cursorX = posX * 2;

	for (i = 0; i < height; i++) {
		for (j = 0; j < 10; j++) {
			setCurrentCursorPos(cursorX+j*2, posY + i);
			setCurrentCursorPos(cursorX + j * 2, posY + i);
			if (i != height-1) {
				if (j == 0 || j == width-1) printf("  ");
			}
			else {
				printf("  ");
			}
		}
	}
}

void placeWall(int posX, int posY) {
	int i;
	int startX = posX, startY = posY;
	for (i = 0; i < 10; i++) {
		drawWall(startX-i, startY-i);
		Sleep(50);
		deleteWall(startX - i, startY - i);
	}
}

void drawWallEffect(int x, int y) {
	int i, j;
	int height = 4, width = 12;
	int cursorX = x * 2;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			setCurrentCursorPos(cursorX + j * 2, y + i);
			if (i != height-1) {
				if (j == 0 || j == width-1) printf("※");
			}
			else {
				printf("※");
			}
		}
	}
}

void deleteWallEffect(int x, int y) {
	int i, j;
	int height = 4, width = 12;
	int cursorX = x * 2;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			setCurrentCursorPos(cursorX + j * 2, y + i);
			if (i != height - 1) {
				if (j == 0 || j == width - 1) printf("  ");
			}
			else {
				printf("  ");
			}
		}
	}
}

void scene2() {
	int i;
	placeWall(25, 10);
	drawWall(16, 1);
	for (i = 0; i < 3; i++) {
		drawWallEffect(15, 1);
		Sleep(100);
		deleteWallEffect(15, 1);
		Sleep(100);
	}
}

void drawAnimationEnemy(int posX, int posY) {
	int cursorX = posX * 2;
	setCurrentCursorPos(cursorX, posY);
	printf("▲");
}

void deleteAnimationEnemy(int posX, int posY) {
	int cursorX = posX * 2;
	setCurrentCursorPos(cursorX, posY);
	printf("  ");
}

void drawAnimationBossEnemy(int posX, int posY) {
	int cursorX = posX * 2;
	int i, j;
	int width = 6, height = 6;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			setCurrentCursorPos(cursorX + j * 2, posY + i);
			switch (i) {
			case 0:
				if (j == 0 || j == width - 1) printf("◆");
				else printf("▲");
				break;
			case 1:
				if (j == 0) printf("◀");
				else if (j == 1) printf("■");
				else if (j == width - 2) printf("■");
				else if (j == width - 1)printf("▶");
				else printf("─");
				break;
			case 2:
				if (j == 0) printf("◀");
				else if (j == 2) printf("\\");
				else if (j == 3) printf("/");
				else if (j == width - 1)printf("▶");
				else printf("│");
				break;
			case 3:
				if (j == 0) printf("◀");
				else if (j == 2 || j == 3) printf("■");
				else if (j == width - 1)printf("▶");
				else printf("│");
				break;
			case 4:
				if (j == 0) printf("◀");
				else if (j == 1) printf("■");
				else if (j == width - 2) printf("■");
				else if (j == width - 1)printf("▶");
				else printf("─");
				break;
			case 5:
				if (j == 0 || j == width - 1) printf("◆");
				else printf("▼");
				break;
			}
		}
	}
}

void deleteAnimationBossEnemy(int posX, int posY) {
	int cursorX = posX * 2;
	int i, j;
	int width = 6, height = 6;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			setCurrentCursorPos(cursorX + j * 2, posY + i);
			printf("  ");
		}
	}
}

void drawEnemyLine(int dy) {
	int i, j, posX;
	for (i = 0; i <= dy; i++) {
		for (j = 1; j < 20; j++) {
			if (j > 7 && j < 12) continue;
			if (i % 2 == 0) posX = 2 * j;
			else posX = 2 * j + 1;

			drawAnimationEnemy(posX, 18 - i);
		}
	}
}

void deleteEnemyLine(int dy) {
	int i, j, posX;
	for (i = 0; i <= dy; i++) {
		for (j = 1; j < 20; j++) {
			if (j > 7 && j < 12) continue;
			if (i % 2 == 0) posX = 2 * j;
			else posX = 2 * j + 1;

			deleteAnimationEnemy(posX, 18 - i);
		}
	}
}

void scene3() {
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j <= i; j++) {
			drawEnemyLine(i);
			drawAnimationBossEnemy(17,13 - i);
		}
		Sleep(500);
		if (i == 3) break;
		for (j = 0; j <= i; j++) {
			deleteEnemyLine(i);
			deleteAnimationBossEnemy(17, 13 - i);
		}
		Sleep(500);
	}
}

char planeModel[5][5] = {
	{0,2,1,0,0},
	{0,3,0,0,0},
	{1,2,2,2,1},
	{0,3,0,0,0},
	{0,2,1,0,0}
};

void drawPlane(int posX, int posY) {
	int i, j;
	int cursorX = posX * 2;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			setCurrentCursorPos(cursorX + j * 2, posY + i);
			if (planeModel[i][j] == 1) printf(">");
			else if (planeModel[i][j] == 2) printf("─");
			else if (planeModel[i][j] == 3) printf("│");
		}
	}
}

void deletePlane(int posX, int posY) {
	int i, j;
	int cursorX = posX * 2;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			setCurrentCursorPos(cursorX + j * 2, posY + i);
			printf("  ");
		}
	}
}

void movePlane() {
	int startX = 1, startY = 5;
	int i;
	for (i = 0; i < 35; i++) {
		drawPlane(startX + i, startY);
		Sleep(40);
		deletePlane(startX + i, startY);
	}
}

void drawBombEffect(int posX, int posY, int area) {
	int i, j;
	int cursorX = (posX) * 2;
	int cursorY = (posY);
	for (i = 0; i < area; i++) {
		for (j = 0; j < area; j++) {
			setCurrentCursorPos(cursorX + j * 2, cursorY + i);
			printf("＃");
		}
	}
}

void deleteBombEffect(int posX, int posY, int area) {
	int i, j;
	int cursorX = (posX) * 2;
	int cursorY = (posY);
	for (i = 0; i < area; i++) {
		for (j = 0; j < area; j++) {
			setCurrentCursorPos(cursorX + j * 2, cursorY + i);
			printf("  ");
		}
	}
}

void drawbombedBossEnemy(int posX, int posY) {
	int cursorX = posX * 2;
	int i, j;
	int width = 4, height = 4;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			setCurrentCursorPos(cursorX + j * 2, posY + i);
			switch (i) {
			case 0:
				if (j == 0) printf("■");
				else if (j == width - 1)printf("■");
				else printf("■");
				break;
			case 1:
				if (j == 0 || j == width - 1) printf("■");
				else printf(" X");
				break;
			case 2:
				if (j == 1 || j == 2) printf("■");
				else printf("─");
				break;
			case 3:
				if(j==0)printf("■");
				else if (j == width - 1) printf("■");
				else printf("■");
				break;
			}
		}
	}
}

void clearBoard() {
	int i, j;
	int curPosY = 10;

	for (i = 0; i < 20; i++) {
		for (j = 1; j < gBoardWidth; j++) {
			setCurrentCursorPos(j * 2, curPosY+i);
			printf("  ");
		}
	}
}

void scene4() {
	int i,j ;
	movePlane();
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			drawBombEffect(4 + 8 * i, 13, j);
			Sleep(50);
			deleteBombEffect(4 + 8 * i, 13, j);
			Sleep(50);
		}
	}

	clearBoard();
	drawGameBoard();
	Sleep(500);
	drawbombedBossEnemy(19,15);
}

void placeAnimationBarricade() {
	int leftX = 18;
	int rightX = 23;
	int posY = 4, posX;
	int i, j;

	for (i = 0; i < 15; i++) {
		setCurrentCursorPos(leftX*2, posY+i);
		printf("■");
		setCurrentCursorPos(rightX*2, posY + i);
		printf("■");
	}
	posX = 19*2; posY = 4;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			setCurrentCursorPos(posX + j * 2, posY + i);
			printf("□");
		}
	}
}

void drawBarricadeEffect() {
	int i;
	int leftX = 17, rightX = 24, posY = 4;
	for (i = 0; i < 15; i++) {
		setCurrentCursorPos(leftX * 2, posY + i);
		printf("※");
		setCurrentCursorPos(rightX * 2, posY + i);
		printf("※");
	}
	Sleep(200);
	for (i = 0; i < 15; i++) {
		setCurrentCursorPos(leftX * 2, posY + i);
		printf("  ");
		setCurrentCursorPos(rightX * 2, posY + i);
		printf("  ");
	}
	Sleep(200);
	leftX--; rightX++;
	for (i = 0; i < 15; i++) {
		setCurrentCursorPos(leftX * 2, posY + i);
		printf("X");
		setCurrentCursorPos(rightX * 2, posY + i);
		printf("X");
	}
	Sleep(200);
	for (i = 0; i < 15; i++) {
		setCurrentCursorPos(leftX * 2, posY + i);
		printf("  ");
		setCurrentCursorPos(rightX * 2, posY + i);
		printf("  ");
	}
}

void scene5() { 
	placeAnimationBarricade();
	drawBarricadeEffect();
}

void playAnimation() {
	//scene1 kingAnimal 주변을 배회
	scene1();
	//scene2 kingAnimal 주변에 벽 세워짐
	scene2();
	//scene3 bossEnemy와 잡몹 등장 앞으로 진격
	scene3();
	//scene4 융단 폭격
	scene4();
	//scene5 바리케이드 설치
	scene5();
	//애니메이션 종료
	system("cls");
	return;
}