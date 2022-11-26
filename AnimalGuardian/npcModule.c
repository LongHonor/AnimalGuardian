#include "globalVariable.h"
#include "npcModule.h"
#include "gameModel.h"
#include "gameBoardHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

EnemyNPC_Info* enemy_list_head = NULL;

int curPosX = gBoardOx, curPosY = gBoardOy;

void moveEnemy() {
    EnemyNPC_Info* enemyNpc = enemy_list_head;
    while (enemyNpc != NULL) {
        if (!enemyNPCDetectCollision(enemyNpc->pos.X, enemyNpc->pos.Y - 1)) {
            deleteOneEnemy(enemyNpc);
            enemyNpc->pos.Y -= 1;
            showOneEnemy(enemyNpc);

        }
        enemyNpc = enemyNpc->next;
    }
}

void showNormalEnemy() {
    EnemyNPC_Info* enemy_npc = enemy_list_head;
    while (enemy_npc != NULL) {
        setCurrentCursorPos(enemy_npc->pos.X, enemy_npc->pos.Y);
        drawEnemy(enemy_npc->pos.X, enemy_npc->pos.Y);
        enemy_npc = enemy_npc->next;
    }
}
void showOneEnemy(EnemyNPC_Info* enemyNpc) {
    setCurrentCursorPos(enemyNpc->pos.X, enemyNpc->pos.Y);
    drawEnemy(enemyNpc->pos.X, enemyNpc->pos.Y);
}
void deleteOneEnemy(EnemyNPC_Info* enemyNpc) {
    setCurrentCursorPos(enemyNpc->pos.X, enemyNpc->pos.Y);
    deleteEnemy(enemyNpc->pos.X, enemyNpc->pos.Y);
}

void deleteNormalEnemy() {
    EnemyNPC_Info* enemy_npc = enemy_list_head;
    while (enemy_npc != NULL) {
        setCurrentCursorPos(enemy_npc->pos.X, enemy_npc->pos.Y);
        drawEnemy(enemy_npc->pos.X, enemy_npc->pos.Y);
        enemy_npc = enemy_npc->next;
    }
}
int k = 4;

void makeNormalEnemy() {

    int randXpos = k;
    k += 2;
    EnemyNPC_Info* enemy_npc = (EnemyNPC_Info*)malloc(sizeof(EnemyNPC_Info));
    enemy_npc->pos.X = randXpos;
    enemy_npc->pos.Y = gBoardOy + 16;
    enemy_npc->next = NULL;
    if (enemy_list_head == NULL) {
        enemy_list_head = enemy_npc;
        return;
    }
    EnemyNPC_Info* last_enemy = enemy_list_head;
    while (last_enemy->next != NULL) {
        last_enemy = last_enemy->next;
    }
    last_enemy->next = enemy_npc;


}

int enemyNPCDetectCollision(int posX, int posY) {
    int x, y;
    int arrX = (posX - gBoardOx) / 2;
    int arrY = posY - gBoardOy;
    for (x = 0; x < 1; x++) {
        for (y = 0; y < 2; y++) {
            if (enemyModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] != 0) {
                return 1;
            }
        }
    }
    return 0;
}