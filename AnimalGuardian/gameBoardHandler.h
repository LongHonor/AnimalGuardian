#pragma once
#include "globalVariable.h"

void drawGameBoard();	
void AddBlockToBoard(posStruct barricadeCurPos);
void drawDieEnemyEffect(posStruct enemyCurPos);
void deleteDieEnemyEffect();
void drawDieAnimalEffect(posStruct animalCurPos);
void deleteDieAnimalEffect();

void drawPC();	
void deletePC();
void drawAnimal();
void deleteAnimal();
void drawEnemy();
void deleteEnemy();
void drawBoss();
void deleteBoss();
void drawKing();
void deleteKing();


void drawInitialUI();
void printBulletCount();
void printEnemyCount();
void printCurrentItem();