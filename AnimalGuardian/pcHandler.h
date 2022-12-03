#pragma once
#include <time.h>
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
	int id;
	posStruct pos;
}Bullet;

//pc 전역변수
PC player;

//bullet 전역변수
extern int bulletCount;
extern int bulletItem;

clock_t checkLoadStartTime;
clock_t checkdieStartTime;
extern int loadFlag;
extern int dieFlag;
int dieTime;

//PC 그리기
void showPC(struct _Player player);
//PC 지우기
void erasePC(struct _Player player);
//PC 왼쪽 이동
void shiftLeftPc();
//PC 오른쪾 이동
void shiftRightPc();
//총알 그리기
void showBullet(struct _Position pos);
//총알 지우기
void eraseBullet(struct _Position pos);
//총알 발사
void shootBullet();
//키 입력 받기
void pcKeyInput();
//총알수 리셋
void loadBullet();