#include "globalVariable.h"
#include "gameBoardHandler.h"
#include <stdio.h>
#include <conio.h>


void drawBarricade() {
	int posX, posY;
	posStruct barricadePos = { curPosX,curPosY };
	for (posX = 0; posX < 3; posX++) {
		setCurrentCursorPos(barricadePos.X + posX * 2, barricadePos.Y);
		printf("��");
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
	//���� �ٸ����̵� ��ǥ
	//���Ӻ��� �������� ���ͷ� �����ͼ� ��ġ �������� Ȯ��
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
	//�ѵ��� ���� 0

	if (!DetectCollision(curPosX - 2, curPosY)) {
		return;
	}
	deleteBarricade();
	curPosX -= 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}
void shiftRightBarricade() {
	//�ѵ��� ���� 0

	if (!DetectCollision(curPosX + 2, curPosY)) {
		return;
	}
	deleteBarricade();
	curPosX += 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}
void shiftUpBarricade() {
	//�ѵ��� ���� 0

	if (!DetectCollision(curPosX, curPosY - 1)) {
		return;
	}
	deleteBarricade();
	curPosY -= 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}
void shiftDownBarricade() {
	//�ѵ��� ���� 0

	if (!DetectCollision(curPosX, curPosY + 1)) {
		return;
	}
	deleteBarricade();
	curPosY += 1;
	setCurrentCursorPos(curPosX, curPosY);
	drawBarricade();
}



void placeBarricade() {
	//�ٸ����̵� ��ġ
	//���� �ð� ����

	//�ٸ����̵� �׸���
	//�Է� ���
	//��ġ Ű ������ ��ġ �������� Ȯ��
	//��ġ �����ϸ� ���Ӻ��� ����
	//�Ұ����ϸ� ��� �޽��� ���
	//�̵�Ű ������ �ٸ����̵� ��ġ �̵�
	int key;
	while (1) {
		drawBarricade();
		drawGameBoard();
		for (int i = 0; i < 20; i++) {
			//_kbhit �� �Է½� 1 ����
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