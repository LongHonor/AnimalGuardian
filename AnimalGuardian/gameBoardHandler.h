#pragma once

void initGameBoard();
void drawGameBoard();	
void AddBlockToBoard(struct _Position barricadeCurPos);
void drawDieEnemyEffect(struct _Position enemyCurPos);
void deleteDieEnemyEffect();

void drawPC();	
void deletePC();
void drawAnimal();
void deleteAnimal();
void drawEnemy();
void deleteEnemy();

void drawInitialUI();
void printBulletCount();
void printEnemyCount();
