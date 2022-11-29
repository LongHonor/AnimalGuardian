#pragma once
#include <windows.h>

#define left 75
#define right 77
#define up 72
#define down 80
#define space 32
#define attack 82
#define item 113

#define maxBullet 10
#define initialReloadSpeed 300
#define doubleSpeed 115
#define gBoardWidth 40
#define gBoardHeight 20
#define gBoardOx 0
#define gBoardOy 0

//gameboard 2차원 배열
char gameBoardInfo[][23][42];
char currentGameBoard[23][42];

//모델
char bulletModel[2][1];
char enemyModel[1][1];
char animalModel[1][2];
char pcModel[2][1];

//색상
typedef enum color{
} enumColor;

//UI
int enemyNumber;
int bulletNumber;
int itemNumber;
int stage;

//커서
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
	int reloadSpeed;
	int lifePoint;
} pc;

//NPC - enemy
typedef struct _EnemyNPC {
	posStruct pos;
	int speed;
	int id;
	//장애물을 만났을 때 우선 왼쪽으로 틀지 오른쪽으로 틀지 정하는 값입니다. Enemy가 생성되었을 때 랜덤으로 지정 됩니다. 
	//-1은 왼쪽, 1은 오른쪽
    int direction;
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


//one-player 전역변수
pc playableCharacter;

//test용 NPC 전역변수
animalNPC animalArray[3];
enemyNPCList *enemyList;


//함수 선언부
posStruct getPCCurrentPos();
void setPCCurrentPos(int moveX, int moveY);
posStruct getEnemyCurrentPos(int enemyId);
void setEnemyCurrentPos(int enemyId, int moveX, int moveY);
posStruct getAnimalCurrentPos(animalNPC * animal);
void setAnimalCurrentPos(animalNPC * animal, int moveX, int moveY);
void setPcReloadSpeed(int reloadSpeed);
void setCurrentGameBoard(int stage);

void removeCursor();
void changeConsoleColor(int colorIndex);
void restroreConsoleColor();
void setCurrentCursorPos(int posX, int posY);
COORD getCurrentCursorPos(void);