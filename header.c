#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

char bulletModel[1][2] = {
   	{1},
    {1}   
};

PC* NewPC(int initX, int initY) {
   PC* pc = (PC*)malloc(sizeof(PC));
   pc->posX = initX; pc->posY = initY;
   pc->speed = 10;
   pc->life_point = 5;
   pc->gun_load_speed = 3;
   return pc;
}

PC getPCCurrentPos() {
   
   return real_pc;
}

void setPCCurrentPos(int moveX,int moveY) {
   real_pc.posX = moveX;
   real_pc.posY = moveY;
}

EnemyNPC* newEnemyNPC(int initX, int initY) {
   EnemyNPC* enemyNPC = (EnemyNPC*)malloc(sizeof(EnemyNPC));
   enemyNPC->posX = initX; enemyNPC->posY = initY;
   enemyNPC->speed = 10;
   return enemyNPC;
}

COORD getEnemyCurrentPos(EnemyNPC * enemyNPC) {
   COORD curPos;
   curPos.X = enemyNPC->posX; curPos.Y = enemyNPC->posY;
   return curPos;
}

void setEnemyCurrentPos(EnemyNPC * enemyNPC, int moveX, int moveY) {
   enemyNPC->posX = moveX; enemyNPC->posY = moveY;
}

SpecialEnemyNPC* newSpecialEnemyNPC(int initX, int initY) {
   SpecialEnemyNPC* sEnemyNPC = (SpecialEnemyNPC*)malloc(sizeof(SpecialEnemyNPC));
   sEnemyNPC->posX = initX; sEnemyNPC->posY = initY;
   sEnemyNPC->speed = 20;
   return sEnemyNPC;
}

COORD getSpecialEnemyCurrentPos(SpecialEnemyNPC * sEnemyNPC) {
   COORD curPos;
   curPos.X = sEnemyNPC->posX; curPos.Y = sEnemyNPC->posY;
   return curPos;
}

void setSpecialEnemyCurrentPos(SpecialEnemyNPC * sEnemyNPC, int moveX, int moveY) {
   sEnemyNPC->posX = moveX; sEnemyNPC->posY = moveY;
}

AnimalNPC* newAnimalNPC(int initX, int initY) {
   AnimalNPC* animalNPC = (AnimalNPC*)malloc(sizeof(AnimalNPC));
   animalNPC->posX = initX; animalNPC->posY = initY;
   animalNPC->speed = 7;
   return animalNPC;
}

COORD getAnimalCurrentPos(AnimalNPC * animalNPC) {
   COORD curPos;
   curPos.X = animalNPC->posX; curPos.Y = animalNPC->posY;
   return curPos;
}

void setAnimalCurrentPos(AnimalNPC * animalNPC, int moveX, int moveY) {
   animalNPC->posX = moveX; animalNPC->posY = moveY;
}
