#pragma once
#include "globalVariable.h"
#define load 114

typedef struct _Player {
	posStruct pos;
	int speed;
	int reloadSpeed;
	int lifePoint;
} PC;

//Bullet
typedef struct _Bullet {
	int speed;
	posStruct pos;
	struct _Bullet* link;
}Bullet;

//pc 전역변수
PC player;

//bullet 전역변수
extern Bullet* bullet_head;
extern int max_bullet;
extern int bulletItem;

void showPC(struct _Player player);
void erasePC(struct _Player player);
void shiftLeftPc();
void shiftRightPc();
void showBullet(struct _Position pos);
void eraseBullet(struct _Position pos);
void shootBullet();
void pcKeyInput();
void loadBullet();
void blockKeyInput();