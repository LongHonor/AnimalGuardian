#include "pcHandler.h"
#include "globalVariable.h"
#include <stdio.h>
#include <conio.h>
//PC 초기화
PC player = { {40,20},1,200,3 };

//bullet 초기화
int max_bullet = 10;
Bullet* bullet_head = NULL;
int bulletItem = 0;

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
	/*if (!detectCollisionPC(player.pos.X - 2, player.pos.Y)) {
		return;
	}*/
	erasePC(player);
	player.pos.X -= 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	showPC(player);
}
void shiftRightPc() {
	/*if (!detectCollisionPC(player.pos.X + 2, player.pos.Y)) {
		return;
	}*/
	erasePC(player);
	player.pos.X += 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	showPC(player);
}
void shootBullet() {
	Bullet* curr = bullet_head;
	Bullet* first_bullet = bullet_head;
	while (1) {
		if (curr == NULL) {
			curr = first_bullet;
		}
		//일반 모드
		if (bulletItem == 0) {
			curr->pos.Y -= 2;
			showBullet(curr->pos);
			Sleep(curr->speed);
			eraseBullet(curr->pos);
			/*if (!detectCollisionBullet(curr->pos.X, curr->pos.Y - 1)) {
				first_bullet = curr->link;
			}
			else if (!detectCollisionBullet(curr->pos.X, curr->pos.Y - 2)) {
				curr->pos.Y -= 1;
				showBullet(curr->pos);
				Sleep(curr->speed);
				eraseBullet(curr->pos);
			}
			else {
				curr->pos.Y -= 2;
				showBullet(curr->pos);
				Sleep(curr->speed);
				eraseBullet(curr->pos);
			}*/
		}
		//관통 모드
		/*else if (bulletItem == 1) {
			curr->pos.Y -= 2;
			if (detectCollisionBullet(curr->pos.X, curr->pos.Y)) {
				showBullet(curr->pos);
				Sleep(curr->speed);
				eraseBullet(curr->pos);
			}
			else {
				Sleep(curr->speed);
			}
		}*/
		if (_kbhit() != 0) {
			int key = _getch();
			switch (key) {
			case left:
				shiftLeftPc();
				break;
			case right:
				shiftRightPc();
				break;
			case space:
				if (max_bullet > 0) {
					Bullet* newbullet = (Bullet*)malloc(sizeof(Bullet));
					newbullet->pos = player.pos;
					newbullet->speed = 40;
					newbullet->link = NULL;
					curr->link = newbullet;
					max_bullet--;
				}
				break;
			}
		}
		if (curr->pos.Y - 3 < gBoardOy) {
			first_bullet = curr->link;
		}
		if (first_bullet == NULL) {
			break;
		}
		curr = curr->link;
	}
}
void loadBullet() {
	max_bullet = 10;
}
void blockKeyInput() {
	int t = 0;
	int key;
	while (t < player.reloadSpeed) {
		if (_kbhit()) {
			key = _getch();
		}
		Sleep(10);
		t++;
	}
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
				if (max_bullet > 0) {
					Bullet* newbullet = (Bullet*)malloc(sizeof(Bullet));
					newbullet->pos = player.pos;
					newbullet->speed = 40;
					newbullet->link = NULL;
					bullet_head = newbullet;
					max_bullet--;
					shootBullet();
				}
				break;
			case load:
				loadBullet();
				blockKeyInput();
				break;
			}
		}
		Sleep(20);
	}
}