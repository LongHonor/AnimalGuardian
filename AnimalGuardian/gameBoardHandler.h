#pragma once
#include "globalVariable.h"

void drawGameBoard();	
void AddBlockToBoard(posStruct barricadeCurPos);
void drawDieEnemyEffect(posStruct enemyCurPos);
void deleteDieEnemyEffect();

void drawPC();	
void deletePC();
void drawAnimal();
void deleteAnimal();
void drawEnemy();
void deleteEnemy();
void drawBoss();
void deleteBoss();

void drawInitialUI();
void printBulletCount();
void printEnemyCount();
