#pragma once
#include <time.h>
#include "globalVariable.h"
#define load 114

typedef struct _Player {
	posStruct pos;
	int speed;
	int reloadSpeed;
	int lifePoint;
	int itemNum;
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
clock_t checkSlowEnemySpeedTime;
clock_t checkEffectAnimalDyingTime;
clock_t checkKeyInputTime;
clock_t checkStopPC;
clock_t checkMessageTime;

extern int loadFlag;
extern int dieFlag;
float dieTime;

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
//아이템 드롭
void itemDrop();
//아이템 표시
void printCurrentItem();
//총알 이동
void moveBullet(struct _Bullet* bullet);
//에네미 죽는 효과
void checkDyingEnemy(Bullet* newbullet);
//보스 바리케이드 그리는 함수
void drawBossBarricade();
//보스 바리케이드 지우는 함수
void deleteBossBarricade();
//보스 공격 함수
void bossAttack();
//적 처치 안내 메시지 출력
void printKillingEnemyMessage();
//게임 안내 메시지 지우기
void deleteGameStatusMessage();
//동물 처치 안내 메시지 출력
void printKillingAnimalMessage();
//메세지 리셋
void resetMessage();