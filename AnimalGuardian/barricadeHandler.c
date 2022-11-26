#include "globalVariable.h"
#include "gameBoardHandler.h"
#include <stdio.h>
#include <conio.h>


void drawBarricade() {
	int posX, posY;
	posStruct barricadePos = { curPosX,curPosY };
	for (posX = 0; posX < 3; posX++) {
		setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y);
		printf("□");
	}
	setCurrentCursorPos(barricadePos.X, barricadePos.Y);
}
void deleteBarricade() {
	int posX, posY;
	posStruct barricadePos = { curPosX,curPosY };
	for (posX = 0; posX < 3; posX++) {
		setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y);
		printf("  ");
	}
	setCurrentCursorPos(barricadePos.X, barricadePos.Y);
}

int isBarricadePlaceable(int posX, int posY) {
	//인자 바리케이드 좌표
	//게임보드 전역변수 게터로 가져와서 설치 가능한지 확인
	int arrX = (posX - gBoardOx) / 2;
	int arrY = posY - gBoardOy;
	int x, y;
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 1; y++)
		{
			if (gameBoardInfo[arrY + y][arrX + x] != 0) {
				return 0;
			}
		}
	}

	// 0 : false 1 : true
	return 1;
}
void shiftLeftBarricade() {
	//총돌시 리턴 0

	if (!DetectCollision(curPosX - 2, curPosY)) {
		return;
	}
	deleteBarricade();
	curPosX -= 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}
void shiftRightBarricade() {
	//총돌시 리턴 0

	if (!DetectCollision(curPosX + 2, curPosY)) {
		return;
	}
	deleteBarricade();
	curPosX += 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}
void shiftUpBarricade() {
	//총돌시 리턴 0

	if (!DetectCollision(curPosX, curPosY - 1)) {
		return;
	}
	deleteBarricade();
	curPosY -= 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}
void shiftDownBarricade() {
	//총돌시 리턴 0

	if (!DetectCollision(curPosX, curPosY + 1)) {
		return;
	}
	deleteBarricade();
	curPosY += 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}



void placeBarricade() {
	//바리케이드 설치
	//게임 시간 정지

	//바리케이드 그리기
	//입력 대기
	//설치 키 누르면 설치 가능한지 확인
	//설치 가능하면 게임보드 갱신
	//불가능하면 경고 메시지 출력
	//이동키 누르면 바리케이드 위치 이동
	int key;
	while (1) {
		drawBarricade();
		drawGameBoard();
		for (int i = 0; i < 20; i++) {
			//_kbhit 은 입력시 1 리턴
			if (_kbhit() != 0) {
				key = _getch();
				switch (key) {
				case left:
					shiftLeftBarricade();
					break;
				case right:
					shiftRightBarricade();
					break;
				case up:
					shiftUpBarricade();
					break;
				case down:
					shiftDownBarricade();
					break;
				case space:
					if (isBarricadePlaceable(curPosX, curPosY) == 1) {
						posStruct barricadeCurPos = { curPosX,curPosY };
						AddBlockToBoard(barricadeCurPos);
						return;
					}
					break;
				}
			}
			Sleep(20);
		}
	}
}