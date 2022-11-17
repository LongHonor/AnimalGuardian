#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

#define gameBoardWidth 40
#define gameBoardHeight 20

void removeCursor();
void initGameBoard();
void drawGameBoard();
void drawPC();
void drawAnimal();
void drawEnemy();
void drawUI();

void setCurrentCursorPos(int posX, int posY) {
	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//int gameBoardInfo[gameBoardHeight + 2][gameBoardWidth + 2] = { 0 };

int main(int argc, char *argv[]) {
	int i,j;
	
	setPCCurrentPos(10,20);
	PC fakePC = getPCCurrentPos();
	printf("%d %d\n", fakePC.posX, fakePC.posY);
	
	
	return 0;
}

void removeCursor() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void initGameBoard() {
	//맵, pc, animal, enemy, UI 출력 
	
	int posX, posY;

	for (posY = 0; posY < gameBoardHeight; posY++) {
		gameBoardInfo[posY][0] = 1;
		gameBoardInfo[posY][gameBoardWidth + 1] = 1;
	}
	for (posX = 0; posX < gameBoardWidth + 2; posX++){
		gameBoardInfo[0][posX] = 1;
		gameBoardInfo[gameBoardHeight][posX] = 1;
	}
	
	drawGameBoard();
	drawPC();
	 
		
}

void drawGameBoard(){
	int posX, posY;
	int pcAreaLine = 18;
	
	for(posY = 0; posY < gameBoardHeight + 2; posY++){
		setCurrentCursorPos(0,posY);
		if(posY == gameBoardHeight+1) printf("└");
		else if(posY == 0) printf("┌");
		else if(posY == pcAreaLine) printf("├");
		else printf("│");
		setCurrentCursorPos((gameBoardWidth + 1)*2, posY);
		if (posY == gameBoardHeight+1) printf("┘");
		else if(posY == 0) printf("┐");
		else if(posY == pcAreaLine) printf("┤");
		else printf("│");

		
		if(posY == gameBoardHeight+1 || posY == pcAreaLine|| posY == 0){
			for(posX = 2 ; posX <= gameBoardWidth *2; posX += 2){
				setCurrentCursorPos(posX, posY);
				printf("─");
			}
		}
	}

	setCurrentCursorPos(0,0);
}

void drawPC(){
	//전역변수 핸들러로 pc좌표 가져오기
	int i;
	for(i = 1; i<=40; i++){
			setCurrentCursorPos(i*2,19);
			printf("★");
			Sleep(100);
			setCurrentCursorPos(i*2,19);
			printf("  ");
	}
}

void drawAnimal();
void drawEnemy();
void drawUI();
