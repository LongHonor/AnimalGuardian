#pragma once

void initGameBoard();
void drawGameBoard();	
void AddBlockToBoard(struct _Position barricadeCurPos);
void dieEnemy(struct _Position enemyCurPos);

void drawPC();	
void deletePC();
void drawAnimal();
void deleteAnimal();
void drawEnemy();
void deleteEnemy();

void drawInitialUI();
void printBulletCount();
void printEnemyCount();
