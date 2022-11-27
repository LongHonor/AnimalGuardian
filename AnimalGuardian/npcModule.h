#pragma once


int randInt(start, end);
int isInArray(const int arr[], int val, int len);
void setRandomArray(int* arr, const int start, const int end, const int count);
int setDirection(enemyNPC* enemy);
int tryMove(enemyNPC* enemy);
void moveOneEnemy(enemyNPC* enemy);
void moveEnemy();
void showNormalEnemy();
void showOneEnemy(enemyNPC* enemyNpc);
void deleteOneEnemy(enemyNPC* enemyNpc);
void deleteNormalEnemy();
void makeNormalEnemy(int x);
void makeEnemyList(int enemyCount);
void makeAnimal();