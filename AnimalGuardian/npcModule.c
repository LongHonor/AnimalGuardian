#include "globalVariable.h"
#include "npcModule.h"
#include "gameBoardHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

normal_enemy_start = 0;
normal_enemy_end = 0;
//start이상 end이하중 랜덤 변수 반환
int randInt(start, end) {
    srand((unsigned int)time(NULL));
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
    if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y - 1) == 1 && 
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
        if (!setDirection(enemy)) //방향 지정 실패시 갇힌 몬스터임
            return;

        else tryMove(enemy);
    }
}

void moveEnemy() {
    enemyNPC* enemy = enemyList->enemyHeader;

    while (enemy != NULL) {
        moveOneEnemy(enemy);
        enemy = enemy->next;
    }
}

void showNormalEnemy() {
    enemyNPC* enemy_npc = enemyList->enemyHeader;
    while (enemy_npc != NULL) {
        setCurrentCursorPos(enemy_npc->pos.X, enemy_npc->pos.Y);
        drawEnemy(enemy_npc->pos.X, enemy_npc->pos.Y);
        enemy_npc = enemy_npc->next;
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
    enemyNPC* enemy_npc = enemyList->enemyHeader;
    while (enemy_npc != NULL) {
        setCurrentCursorPos(enemy_npc->pos.X, enemy_npc->pos.Y);
        drawEnemy(enemy_npc->pos.X, enemy_npc->pos.Y);
        enemy_npc = enemy_npc->next;
    }
}

void makeNormalEnemy(int x) {
    enemyNPC* enemy_npc = (enemyNPC*)malloc(sizeof(enemyNPC));

    enemy_npc->pos.X = x;
    enemy_npc->pos.Y = gBoardOy + 17;
    enemy_npc->next = NULL;
    enemy_npc->direction = 0;

    if (enemyList->enemyHeader == NULL) {
        enemyList->enemyHeader = enemy_npc;
        enemy_npc = 0;
        return;
    }

    int count = 0;
    enemyNPC* last_enemy = enemyList->enemyHeader;
    while (last_enemy->next != NULL) {
        last_enemy = last_enemy->next;
        count++;
    }
    last_enemy->next = enemy_npc;
    enemy_npc->id = count;
}

void makeEnemyList(int enemyCount) {
    enemyList = (enemyNPCList*)malloc(sizeof(enemyNPCList));

    enemyList->enemyCurrentNumber = enemyCount;
    enemyList->enemyHeader = NULL;

    int* enemyPosArray = (int*)malloc(sizeof(int) * enemyCount);
    setRandomArray(enemyPosArray, 1, gBoardWidth , enemyCount);

    for (int i = 0; i < enemyCount; i++) {
        int x = enemyPosArray[i];
        makeNormalEnemy(x * 2);
    }

    free(enemyPosArray);
}

