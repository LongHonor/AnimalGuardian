#pragma once
#include <windows.h>

#define left 75
#define right 77
#define up 72
#define space 32
#define attack 82
#define item 81

#define doubleSpeed 115
#define gBoardWidth 40
#define gBoardHeight 20
#define gBoardOx 0
#define gBoardOy 0

//gameboard 2���� �迭


//��

char bulletModel[2][1];
char enemyModel[2][1];
char animalModel[1][2];
char pcModel[2][1];

//UI
int enemyNumber;
int bulletNumber;
int itemNumber;
int score;

//Ŀ��
int curPosX, curPosY;

//Position
typedef struct _Position {
	int X;
	int Y;
} posStruct;

//PC

typedef struct _PC {
	posStruct pos;
	int speed;
	int gunLoadSpeed;
	int lifePoint;
} pc;

//NPC - enemy
typedef struct _EnemyNPC {
	posStruct pos;
	int speed;
	int id;
	struct _EnemyNPC *next;
} enemyNPC;

//NPC - enemylist
typedef struct _EnemyNPCList {
	int enemyCurrentNumber;
	enemyNPC *enemyHeader;
} enemyNPCList;

//NPC - animal
typedef struct _AnimalNPC {
	posStruct pos;
	int speed;
	int id;
}animalNPC;

//one-player ��������
pc tempPc;

//test�� NPC ��������
animalNPC tempAnimals[3];
animalNPC tempAnimal;
enemyNPCList *tempEnemies;


//�Լ� �����
posStruct getPCCurrentPos();
void setPCCurrentPos(int moveX, int moveY);
posStruct getEnemyCurrentPos(int enemyId);
void setEnemyCurrentPos(int enemyId, int moveX, int moveY);
posStruct getAnimalCurrentPos(animalNPC * animal);
void setAnimalCurrentPos(animalNPC * animal, int moveX, int moveY);

void removeCursor();
void setCurrentCursorPos(int posX, int posY);
COORD getCurrentCursorPos(void);

void makeEnemyList();
void freeEnemyList();
void makeEnemy();
void dieEnemy(enemyNPC * deadEnemyNPC);