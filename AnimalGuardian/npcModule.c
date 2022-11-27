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
//start�̻� end������ ���� ���� ��ȯ
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

//start ���� end ���̿��� count ������ŭ�� ��ǥ�� ���� �迭�� return �մϴ�. �����Ҵ� �Ǿ������Ƿ�
//�� ���� free ���־�� ��
void setRandomArray(int* arr, const int start, const int end, const int count) {
    for (int i = 0; i < count; i++) {
        int pos = randInt(start, end);
        while (isInArray(arr, pos, i)) {
            pos = randInt(start, end);
        }

        arr[i] = pos;
    }
}

//���� �̵������� �缳���մϴ�. �� �� �� �ٸ����� ��� 0�� return �մϴ�.
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

//������ �������� �����Դϴ� �������θ� ��ȯ�մϴ�.
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
        if (!setDirection(enemy)) //���� ���� ���н� ���� ������
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

void makeNormalEnemy(int x) {
    enemyNPC* enemyNpc = (enemyNPC*)malloc(sizeof(enemyNPC));

    enemyNpc->pos.X = x;
    enemyNpc->pos.Y = gBoardOy + 17;
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
int animalNPCdetectCollision(int posX, int posY) {
    int x, y;
    int arrX = (posX - gBoardOx) / 2;
    int arrY = posY - gBoardOy;
    for (x = 0; x < 2; x++)
    {
        for (y = 0; y < 1; y++)
        {
            if (animalModel[y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 1)) {
                return 0;
            }
        }
    }
    return 1;
}
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
    //�����ϰ� ���� ����
    int direction = randInt(-1, 1);

    //direction �� 0 �̸� �׳� return
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

void moveAnimal() {
    moveOneAnimal(0);
    moveOneAnimal(1);
    moveOneAnimal(2);
}

void DrawAnimal() {
    int posX, posY;

    for (int i = 0; i < 3; i++) {
        posStruct animalCurPos = getAnimalCurrentPos(&animalArray[i]);

        for (posX = 0; posX < 2; posX++) {
            setCurrentCursorPos(animalCurPos.X + posX, animalCurPos.Y);
            if (animalModel[0][posX] == 1) printf("��");
            else printf("��");
        }
        setCurrentCursorPos(animalCurPos.X + posX, animalCurPos.Y);
    }
}
void DeleteAnimal() {
    int posX, posY;
    for (int i = 0; i < 3; i++) {
        posStruct animalCurPos = getAnimalCurrentPos(&animalArray[i]);

        for (posX = 0; posX < 2; posX++) {
            setCurrentCursorPos(animalCurPos.X + posX, animalCurPos.Y);
            printf("  ");
        }
        setCurrentCursorPos(animalCurPos.X + posX, animalCurPos.Y);
    }
}