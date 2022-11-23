#pragma once

#define LEFT 75
#define RIGHT 77
#define UP 72
#define SPACE 32
#define ATTACK 82
#define ITEM 81
#define LEFT 75
#define RIGHT 77

#define DoubleSpeed 115
#define GBOARD_O_X 0
#define GBOARD_O_Y 0
#define gameBoardWidth 40
#define gameBoardHeight 20
#define GBOARD_WIDTH 40
#define GBOARD_HEIGHT 20

//gameboard 2차원 배열
extern int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];

//Position
typedef struct _Position {
	int X;
	int Y;
} Pos;

//BULLET
typedef struct _Bullet {
	int speed;
	Pos pos;
	struct _Bullet* link;
}Bullet;

extern Bullet* bullet_head;
extern int max_bullet;
extern char bulletModel[][1];

//PC
typedef struct _PC {
	int speed;
	int gun_load_speed;
	Pos pos;
	int life_point;
} PC;
extern char pcModel[][1];

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


//UI
extern int enemy_number;
extern int bullet_number;
extern int item_number;
extern int score;

//one-player 전역변수
extern PC pc;

//커서
extern int curPosX, curPosY;

//함수 선언부
//PC getPCCurrentPos();
//void setPCCurrentPos(int moveX, int moveY);
Pos getEnemyCurrentPos(EnemyNPC* enemyNPC);
void setEnemyCurrentPos(EnemyNPC* enemyNPC, int moveX, int moveY);
Pos getAnimalCurrentPos(AnimalNPC* animalNPC);
void setAnimalCurrentPos(AnimalNPC* animalNPC, int moveX, int moveY);

void removeCursor(void);
void setCurrentCursorPos(int posX, int posY);
void initGameBoard();
//void drawPC();
void drawGameBoard();
void showPc(PC pc);
void deletePc(PC pc);
int detectCollisionPC(int posX, int posY, char blockModel[][1]);
int shiftLeftPc();
int shiftRightPc();
void processKeyInput();
void showBullet(Pos pos);
void deleteBullet(Pos pos);
void shootBullet();
