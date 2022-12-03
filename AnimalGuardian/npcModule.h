#pragma once
#include <time.h>
//스테이지별로 마릿수를 지정해줄 전역변수입니다
int allAnimalCount;
int allEnemyCount;

double enemyMoveSpeed;
//게임 오버/클리어 조건 변수들
int currentEnemyCount;
int currentAnimalCount;

//enemy가 스폰되는 간격 변수
int enemySpawnTime;

bossStruct boss;

//enemy위치를 저장해주는 배열
int* enemyPosArray;
//enemyNpc의 spawnTime을 체크해주는 변수
clock_t checkEnemyNpcSpawnTime;
//animalNpc의 움직임을 조절하여 시간당 움직이게 해줄 변수
clock_t animalMoveTimePerSec;
//enemyNpc의 움직임을 조절하여 시간당 움직이게 해줄 변수
clock_t enemyMoveTimePerSec;
//bossEnemy의 움직임 조절하여 시간당 움직이게 해줄 변수
clock_t bossEnemyMoveTimePerSec;
//배열을 돌 index
int spawnedEnemyCount;


int randInt(start, end);
//랜덤함수, start-end사이의 임의의 값을 반환해주는 함수입니다

int isInArray(const int arr[], int val, int len);
// 배열을 돌며, 같은 값이 들어있다면, 값으로 지정하지 않는 함수입니다

void setRandomArray(int* arr, const int start, const int end, const int count);
// 배열을 하나 만들어서 그 배열 방에 각각의 pos값을 지정해줍니다(만약 같은 값이라면 들어가지 않습니다)

int setDirection(enemyNPC* enemy);
// 방향을 지정해주는 함수입니다. 

int tryMove(enemyNPC* enemy);
// 움직임을 시도하는 함수입니다. 방향을 지정할 수 없다면, 움직이지 않게 됩니다.

void moveOneEnemy(enemyNPC* enemy);
// enemy객체 하나를 움직이는 함수입니다

void moveEnemy();
// moveOneEnemy를 스폰된 enemy개수만큼 움직여주는 함수입니다.

void showNormalEnemy();
// 일반 enemy를 전부 보여주는 함수입니다.

void showOneEnemy(enemyNPC* enemyNpc);
//enemy 객체 하나만 보여주는 함수입니다

void deleteOneEnemy(enemyNPC* enemyNpc);
//enemy 객체 하나만 지우는 함수입니다

void deleteAndFreeAllEnemy();
//생성된 enemy전체를 free해주고 지우는 함수입니다. gameOver시 사용됩니다.

void makeNormalEnemy(int x);
//enemy객체 하나를 만들어주는 함수입니다.

void makeEnemyList(int enemyCount);
//enemy List를 만들어주는 함수입니다. 개체수를 정할 수 있습니다.

void makeAnimal();
// Animal을 만들어주는 함수입니다.

void moveAnimal();
// Animal 전체를 움직이는 함수입니다.

void animalMoveSetting();
//Animal의 움직임 전체를 컨트롤해주는 함수입니다. 여기에서 움직임 속도를 변화시킬 수 있습니다.

void resetEnemySpawnCount();
// Enemy의 배열을 돌 전역변수를 0으로 초기화해줍니다.

void enemyMoveSetting();
// Enemy의 움직임 전체를 컨트롤해주는 함수입니다. 스폰 속도, 움직임 속도를 시간조절을 통하여 변화시킬 수 있습니다.

void setAllAnimalCount(int count);
//전역변수 allAnimalCount 를 초기화해줍니다

void setAllEnemyCount(int count);
//전역변수 allEnemyCount 를 초기화해줍니다

void moveBoss();
//bossEnemy를 움직여주는 함수입니다

int bossEnemyDetectCollision(int posX, int posY);
//bossEnemy의 충돌을 검사하는 함수입니다.