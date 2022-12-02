#pragma once
#include <time.h>
//스테이지별로 마릿수를 지정해줄 전역변수입니다
int allAnimalCount;
int allEnemyCount;
int currentEnemyCount;


//enemy위치를 저장해주는 배열
int* enemyPosArray;
//enemyNpc의 spawnTime을 체크해주는 변수
clock_t checkEnemyNpcSpawnTime;
//animalNpc의 움직임을 조절하여 시간당 움직이게 해줄 변수
clock_t animalMoveTimePerSec;
//enemyNpc의 움직임을 조절하여 시간당 움직이게 해줄 변수
clock_t enemyMoveTimePerSec;
//배열을 돌 index
int spawnedEnemyCount;


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
void deleteAndFreeAllEnemy();
void makeNormalEnemy(int x);
void makeEnemyList(int enemyCount);
void makeAnimal();
void moveAnimal();
void animalMoveSetting();
void resetEnemySpawnCount();
void enemyMoveSetting();
void setAllAnimalCount(int count);
void setAllEnemyCount(int count);