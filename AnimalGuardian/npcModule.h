#pragma once
#include <time.h>

// globalVariable로 옮겨야할 내용들입니다
//위치를 저장해주는 전역변수
int* enemyPosArray;
//enemyNpc의 spawnTime을 체크해주는 변수
clock_t checkEnemyNpcSpawnTime;
//animalNpc의 움직임을 조절하여 시간당 움직이게 해줄 변수
clock_t animalMoveTimePerSec;
//소환된 enemy의 수
int spawnedEnemyCount;
//


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
void moveAnimal();
void animalMoveSetting();
void resetEnemySpawnCount();
void enemyMoveSetting();