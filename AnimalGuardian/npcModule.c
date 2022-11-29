#include "globalVariable.h"
#include "npcModule.h"
#include "gameBoardHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//start이상 end이하중 랜덤 변수 반환
int randInt(start, end) {
    int length = end - start + 1;
    return (int)(rand() % length) + start;
}

int isInArray(const int arr[], int val, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == val) return 1;
    }
    return 0;
}

//start 부터 end 사이에서 count 개수만큼의 좌표를 가진 배열을 return 합니다. 동적할당 되어있으므로
//다 쓰고 free 해주어야 함
void setRandomArray(int* arr, const int start, const int end, const int count) {
    for (int i = 0; i < count; i++) {
        int pos = randInt(start, end);
        while (isInArray(arr, pos, i)) {
            pos = randInt(start, end);
        }

        arr[i] = pos;
    }
}

//적의 이동방향을 재설정합니다. 위 좌 우 다막혔을 경우 0을 return 합니다.
int setDirection(enemyNPC* enemy) {
    if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y - 1) == 1) {
        enemy->direction = 0;
        return 1;
    }

    int randomDirection;
    if (randInt(1, 2) == 1) randomDirection = -1;
    else randomDirection = 1;

    if (enemyNPCDetectCollision(enemy->pos.X + 2 * randomDirection, enemy->pos.Y) == 1) {
        enemy->direction = randomDirection;
        return 1;
    }

    if(enemyNPCDetectCollision(enemy->pos.X - 2 * randomDirection, enemy->pos.Y) == 1) {
        enemy->direction = -randomDirection;
        return 1;
    }

    return 0;
}

//지정된 방향으로 움직입니다 성공여부를 반환합니다.
int tryMove(enemyNPC* enemy) {
    if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y - 1)==1 && 
        enemy->direction == 0) {

        deleteEnemy(enemy);
        enemy->pos.Y -= 1;
        showOneEnemy(enemy);

        return 1;
    }

    if (enemyNPCDetectCollision(enemy->pos.X + (2 * (enemy->direction)), enemy->pos.Y) == 1 &&
        enemy->direction != 0) {
        if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y - 1) == 1) {

            deleteEnemy(enemy);
            enemy->pos.Y -= 1;
            showOneEnemy(enemy);

            return 1;
        }
        deleteOneEnemy(enemy);
        enemy->pos.X += 2 * (enemy->direction);
        showOneEnemy(enemy);

        return 1;
    }
    return 0;
}

void moveOneEnemy(enemyNPC* enemy) {
    if (!tryMove(enemy)) {
        if (!setDirection(enemy)) //방향 지정 실패시 갇힌 몬스터이다.
            return;
        else tryMove(enemy);
    }
}

void moveEnemy() {
    enemyNPC* enemyNpc = enemyList->enemyHeader;

    while (enemyNpc != NULL) {
        moveOneEnemy(enemyNpc);
        enemyNpc = enemyNpc->next;
    }
}

void showNormalEnemy() {
    enemyNPC* enemyNpc = enemyList->enemyHeader;
    while (enemyNpc != NULL) {
        setCurrentCursorPos(enemyNpc->pos.X, enemyNpc->pos.Y);
        drawEnemy(enemyNpc->pos.X, enemyNpc->pos.Y);
        enemyNpc = enemyNpc->next;
    }
}

void showOneEnemy(enemyNPC* enemyNpc) {
    setCurrentCursorPos(enemyNpc->pos.X, enemyNpc->pos.Y);
    drawEnemy(enemyNpc->pos.X, enemyNpc->pos.Y);
}

void deleteOneEnemy(enemyNPC* enemyNpc) {
    setCurrentCursorPos(enemyNpc->pos.X, enemyNpc->pos.Y);
    deleteEnemy(enemyNpc->pos.X, enemyNpc->pos.Y);
}

void deleteNormalEnemy() {
    enemyNPC* enemyNpc = enemyList->enemyHeader;
    while (enemyNpc != NULL) {
        setCurrentCursorPos(enemyNpc->pos.X, enemyNpc->pos.Y);
        drawEnemy(enemyNpc->pos.X, enemyNpc->pos.Y);
        enemyNpc = enemyNpc->next;
    }
}

//x위치값을 가져와서 그 pos에 enemy를 만듭니다.
void makeNormalEnemy(int x) {
    enemyNPC* enemyNpc = (enemyNPC*)malloc(sizeof(enemyNPC));

    enemyNpc->pos.X = x;
    enemyNpc->pos.Y = gBoardOy + 18;
    enemyNpc->next = NULL;
    enemyNpc->direction = 0;

    if (enemyList->enemyHeader == NULL) {
        enemyList->enemyHeader = enemyNpc;
        enemyNpc = 0;
        return;
    }

    int count = 0;
    enemyNPC* lastEnemy = enemyList->enemyHeader;
    while (lastEnemy->next != NULL) {
        lastEnemy = lastEnemy->next;
        count++;
    }
    lastEnemy->next = enemyNpc;
    enemyNpc->id = count;
}

//enemyCount의 조절로 enemy의 수를 변경할 수 있습니다.
void makeEnemyList(int enemyCount) {
    enemyList = (enemyNPCList*)malloc(sizeof(enemyNPCList));

    enemyList->enemyCurrentNumber = enemyCount;
    enemyList->enemyHeader = NULL;

    enemyPosArray = (int*)malloc(sizeof(int) * enemyCount);
    setRandomArray(enemyPosArray, 1, gBoardWidth , enemyCount);
}


//추후 i값의 조절로 animal의 개수를 늘릴수 있고, pos값의 변경으로 animal의 위치를 변경할 수 있습니다.
void makeAnimal() {
    int animalPos = 20;
    for (int i = 0; i < 3; i++) {
        animalArray[i].id = i;
        animalArray[i].speed = 1;
        setAnimalCurrentPos(animalArray + i,animalPos , 1);
        drawAnimal();
        animalPos += 15;
    }
}

void moveOneAnimal(int index) {
    //랜덤하게 방향 지정
    int direction = randInt(-1, 1);

    //direction 이 0 이면 그냥 return
    if (direction == 0) return;

    if (animalNPCdetectCollision(animalArray[index].pos.X+(direction*2), animalArray[index].pos.Y)==0) {
        direction *= -1;
    }
    else {
        animalArray[index].pos.X += direction*2;
        return;
    }

    if (animalNPCdetectCollision(animalArray[index].pos.X + (direction * 2), animalArray[index].pos.Y) == 1) {
        animalArray[index].pos.X += direction*2;
    }
}

//추후 i값의 조정으로 전부 움직일 수 있게 한다
void moveAnimal() {
    for (int i = 0; i < 3; i++) {
        moveOneAnimal(i);
    }
}


//enemyPosArray의 index입니다. 초기값을 0으로 초기화해줍니다.
void resetEnemySpawnCount() {
    spawnedEnemyCount = 0;
}

//enemy의 움직임을 총괄해주는 함수입니다. 전역으로 설정된 enemyPosArray에 있는 enemySpawnCount 인덱스 방이 가리키는 값으로 스폰합니다.
void enemyMoveSetting() {
    if ((double)(clock() - checkEnemyNpcSpawnTime) / CLOCKS_PER_SEC >= 5) {//여기있는 5를 변경하여 스폰시간을 제어할 수 있습니다.
        if (spawnedEnemyCount < 3) {//여기의 3은 총 enemy 개수값과 동일하게 들어갑니다.
            makeNormalEnemy((*(enemyPosArray + spawnedEnemyCount)) * 2);
            spawnedEnemyCount++;
            checkEnemyNpcSpawnTime = clock();
        }
        checkEnemyNpcSpawnTime = clock();
    }
    if ((double)(clock() - animalMoveTimePerSec) / CLOCKS_PER_SEC >= 0.5) {
        deleteEnemy();
        moveEnemy();
        enemyMoveTimePerSec = clock();
        drawEnemy();
    }
}
//animalMove를 총괄해주는 함수입니다.
void animalMoveSetting() {
    if ((double)(clock() - animalMoveTimePerSec) / CLOCKS_PER_SEC >= 0.5) {
        deleteAnimal();
        moveAnimal();
        animalMoveTimePerSec = clock();
        drawAnimal();
    }
}
