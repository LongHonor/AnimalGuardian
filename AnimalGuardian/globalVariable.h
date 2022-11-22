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

//Position
typedef struct _Position {
	int X;
	int Y;
} Pos;

//PC
typedef struct _PC {
	int speed;
	int gun_load_speed;
	Pos pos;
	int life_point;
} PC;

//NPC - enemy
typedef struct _EnemyNPC {
	int speed;
	Pos pos;
	int id;
} EnemyNPC;


//NPC - animal
typedef struct _AnimalNPC {
	int speed;
	Pos pos;
	int id;
}AnimalNPC;

//bullet
char bulletModel[2][1];

//UI
int enemy_number;
int bullet_number;
int item_number;
int score;

//one-player 전역변수
PC real_pc;

//test용 NPC 전역변수
AnimalNPC temp_animal;
EnemyNPC temp_enemy;

//커서
int curPosX ,curPosY;

//함수 선언부
PC getPCCurrentPos();
void setPCCurrentPos(int moveX, int moveY);
Pos getEnemyCurrentPos(EnemyNPC * enemyNPC);
void setEnemyCurrentPos(EnemyNPC * enemyNPC, int moveX, int moveY);
Pos getAnimalCurrentPos(AnimalNPC * animalNPC);
void setAnimalCurrentPos(AnimalNPC * animalNPC, int moveX, int moveY);

void removeCursor();
void setCurrentCursorPos(int posX, int posY);
COORD getCurrentCursorPos(void);
