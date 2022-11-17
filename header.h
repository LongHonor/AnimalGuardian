#pragma once

#define LEFT 75
#define RIGHT 77
#define UP 72
#define SPACE 32
#define DoubleSpeed 115
#define GBOARD_WIDTH 10
#define GBOARD_HEIGHT 20
#define GBOARD_O_X 4
#define GBOARD_O_Y 2

//gameboard 2차원 배열
int gameBoardInfo[GBOARD_HEIGHT + 1][GBOARD_WIDTH + 2];



//PC
typedef struct _PC {
   int speed;
   int gun_load_speed;
   int posX, posY;
   int life_point;

} PC;



//bullet
char bulletModel[1][2];

//NPC - enemy
typedef struct _EnemyNPC{
   int speed;
   int posX, posY;
   int id;
} EnemyNPC;

typedef struct _SpecialEnemyNPC {
   int speed;
   int posX, posY;
   int id;
}SpecialEnemyNPC;

//NPC - animal

typedef struct _AnimalNPC {
   int speed;
   int posX, posY;
   int id;
}AnimalNPC;

//UI
int enemy_number;
int bullet_number;
int item_number;
int score;

PC getPCCurrentPos();
PC real_pc;
