#include "pcHandler.h"
#include "globalVariable.h"
#include "gameItem.h"
#include "gameBoardHandler.h"
#include "detectCollision.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
//PC 초기화
PC player = { {40,20},1,200,3 };

//bullet 초기화
int bulletCount = 10;
Bullet* bullet_head = NULL;
int bulletItem = 0;

loadFlag = 0;
loadTime = 2;

void showPC(PC player) {
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	printf("●");
	setCurrentCursorPos(player.pos.X, player.pos.Y);    //cursor위치 처음 위치로 다시 설정
}

void erasePC(PC player) {
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	printf("  ");
	setCurrentCursorPos(player.pos.X, player.pos.Y);    //cursor위치 처음 위치로 다시 설정
}

void showBullet(posStruct pos) {
	setCurrentCursorPos(pos.X, pos.Y);
	printf("ο");
}
void eraseBullet(posStruct pos) {
	setCurrentCursorPos(pos.X, pos.Y);
	printf("  ");
}

void shiftLeftPc() {
	if (!detectCollisionPC(player.pos.X - 2, player.pos.Y)) {
		return;
	}
	erasePC(player);
	player.pos.X -= 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	showPC(player);
}
void shiftRightPc() {
	if (!detectCollisionPC(player.pos.X + 2, player.pos.Y)) {
		return;
	}
	erasePC(player);
	player.pos.X += 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	showPC(player);
}
void shootBullet() {
	Bullet* newbullet = (Bullet*)malloc(sizeof(Bullet));
	newbullet->pos = player.pos;
	newbullet->pos.Y -= 2;
	newbullet->speed = 25;
	newbullet->link = NULL;
	bulletCount--;
	while (1) {
		//일반 모드
		if (bulletItem == 0) {
			//바로 위 충돌
			if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 0) {
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			//위위 충돌
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 0) {
				newbullet->pos.Y -= 1;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			//npc 충돌 검사
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 5) {
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 5) {
				newbullet->pos.Y -= 1;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			//충돌 하지 않은 경우
			else {
				newbullet->pos.Y -= 2;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
			}
		}
		//관통 모드
		else if (bulletItem == 1) {
			//게임보드 상단 충돌
			if (newbullet->pos.Y - 2 == gBoardOy) {
				newbullet->pos.Y = gBoardOy + 1;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 0 || detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 0) {
				newbullet->pos.Y -= 2;
				Sleep(newbullet->speed);
			}
			//npc충돌
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 5) {
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 5) {
				newbullet->pos.Y -= 1;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			else {
				newbullet->pos.Y -= 2;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
			}
		}
	}
}
void loadBullet() {
	bulletCount = 10;
}
void pcKeyInput() {
	int key;
	for (int i = 0; i < 20; i++) {
		//_kbhit 은 입력시 1 리턴
		if (_kbhit() != 0) {
			key = _getch();
			switch (key) {
			case left:
				shiftLeftPc();
				break;
			case right:
				shiftRightPc();
				break;
			case space:
				if (loadFlag == 0 && bulletCount > 0) {
					shootBullet();
				}
				break;
			case load:
				checkLoadStartTime = clock();
				loadFlag = 1;
				break;
			case item:
				placeBarricade();
				drawGameBoard();
				//아이템 종류당 번호 할당
				//번호에 해당하는 아이템 사용
				break;
			}
		}
		//장전2초
		if (loadFlag == 1 && (double)(clock() - checkLoadStartTime) / 1000 >= loadTime) {
			loadBullet();
			loadFlag = 0;
		}
		Sleep(20);
	}
}