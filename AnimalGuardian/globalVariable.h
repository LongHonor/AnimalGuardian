#pragma once
#include <windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define SPACE 32
#define ATTACK 82
#define ITEM 81

#define DoubleSpeed 115
#define GBOARD_WIDTH 40
#define GBOARD_HEIGHT 20
#define GBOARD_O_X 4
#define GBOARD_O_Y 2

//gameboard 2차원 배열
int gameBoardInfo[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];

//모델
char bulletModel[2][1];
char enemyModel[2][1];
char animalModel[1][2];
char pcModel[2][1];

//UI
int enemyNumber;
int bulletNumber;
int itemNumber;
int score;

//커서
int curPosX, curPosY;

//Position
typedef struct _Position {
	int X;
	int Y;
} pos;

//PC
typedef struct _PC {
	pos pos;
	int speed;
	int gunLoadSpeed;
	int lifePoint;
} pc;

//NPC - enemy
typedef struct _EnemyNPC {
	pos pos;
	int speed;
	int id;
	struct _EnemyNPC *next;
} enemyNPC;

//NPC - animal
typedef struct _AnimalNPC {
	pos pos;
	int speed;
	int id;
}animalNPC;

//one-player 전역변수
pc tempPc;

//test용 NPC 전역변수
animalNPC tempAnimals[3];
enemyNPC *tempEnemies;


//함수 선언부
pos getPCCurrentPos();
void setPCCurrentPos(int moveX, int moveY);
pos getEnemyCurrentPos(enemyNPC * enemyNPC);
void setEnemyCurrentPos(enemyNPC * enemyNPC, int moveX, int moveY);
pos getAnimalCurrentPos(animalNPC * animalNPC);
void setAnimalCurrentPos(animalNPC * animalNPC, int moveX, int moveY);

void removeCursor();
void setCurrentCursorPos(int posX, int posY);
COORD getCurrentCursorPos(void);

int enemyNPCDetectCollision(int posX, int posY);
