#include "pcHandler.h"
#include "globalVariable.h"
#include "detectCollisionPC.h"
#include <stdio.h>
#include <conio.h>

void drawPC(pc player) {
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	printf("��");
	setCurrentCursorPos(player.pos.X, player.pos.Y);    //cursor��ġ ó�� ��ġ�� �ٽ� ����
}

void deletePC(pc player) {
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	printf("  ");
	setCurrentCursorPos(player.pos.X, player.pos.Y);    //cursor��ġ ó�� ��ġ�� �ٽ� ����
}

void showBullet(posStruct pos) {
	setCurrentCursorPos(pos.X, pos.Y);
	printf("��");
}
void deleteBullet(posStruct pos) {
	setCurrentCursorPos(pos.X, pos.Y);
	printf("  ");
}

void shiftLeftPc() {
	//�ѵ��� ���� 0
	if (!detectCollisionPC(player.pos.X - 2, player.pos.Y)) {
		return;
	}
	deletePC(player);
	player.pos.X -= 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	drawPC(player);
}
void shiftRightPc() {
	//�ѵ��� ���� 0
	if (!detectCollisionPC(player.pos.X + 2, player.pos.Y)) {
		return;
	}
	deletePC(player);
	player.pos.X += 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	drawPC(player);
}
void shootBullet() {
	Bullet* curr = bullet_head;
	Bullet* first_bullet = bullet_head;
	while (1) {
		if (curr == NULL) {
			curr = first_bullet;
		}
		//�Ϲ� ���
		if (bulletItem == 0) {
			if (!detectCollisionBullet(curr->pos.X, curr->pos.Y - 1)) {
				first_bullet = curr->link;
			}
			else if (!detectCollisionBullet(curr->pos.X, curr->pos.Y - 2)) {
				curr->pos.Y -= 1;
				showBullet(curr->pos);
				Sleep(curr->speed);
				deleteBullet(curr->pos);
			}
			else {
				curr->pos.Y -= 2;
				showBullet(curr->pos);
				Sleep(curr->speed);
				deleteBullet(curr->pos);
			}
		}
		//���� ���
		else if (bulletItem == 1) {
			curr->pos.Y -= 2;
			if (detectCollisionBullet(curr->pos.X, curr->pos.Y)) {
				showBullet(curr->pos);
				Sleep(curr->speed);
				deleteBullet(curr->pos);
			}
			else {
				Sleep(curr->speed);
			}
		}
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
void pcKeyInput() {
	int key;
	for (int i = 0; i < 20; i++) {
		//_kbhit �� �Է½� 1 ����
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
			}
		}
		Sleep(20);
	}
}