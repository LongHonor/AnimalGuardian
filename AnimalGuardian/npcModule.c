#include "globalVariable.h"
#include "npcModule.h"
#include "pcHandler.h"
#include "detectCollision.h"
#include "gameBoardHandler.h"
#include "barricadeHandler.h"
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

int animalRandInt() {
    int arr[3] = { -1,0,1 };
    int index = randInt(0, 2);
    return arr[index];
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
    if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 1) {
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
    if (enemy->type == 1) {
        if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 1 &&
            enemy->direction == 0) {

            enemy->pos.Y += 1;

            return 1;
        }

        if (enemyNPCDetectCollision(enemy->pos.X + (2 * (enemy->direction)), enemy->pos.Y) == 1 &&
            enemy->direction != 0) {
            if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 1) {

                enemy->pos.Y += 1;

                return 1;
            }
            enemy->pos.X += 2 * (enemy->direction);

            return 1;
        }
        return 0;
    }
    else if(enemy->type == 2) {

        if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 1 &&
            enemy->direction == 0) {

            enemy->pos.Y += 1;

            return 1;
        }
        else if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 9 &&
            enemy->direction == 0) {
            int i = 1;
            while (1) {
                if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + i) == 1) {
                    break;
                }
                i++;
            }
            enemy->pos.Y += i;
            return 1;
        }
        if (enemyNPCDetectCollision(enemy->pos.X + (2 * (enemy->direction)), enemy->pos.Y) == 1 &&
            enemy->direction != 0) {
            if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 1) {

                enemy->pos.Y += 1;

                return 1;
            }
            enemy->pos.X += 2 * (enemy->direction);

            return 1;
        }
    }
    else if (enemy->type == 3) {
        if (enemy->pos.X == player.pos.X && enemy->dodgeCount > 0 && enemy->pos.Y < player.pos.Y - 2) {
            if (enemyNPCDetectCollision(enemy->pos.X + 2, enemy->pos.Y) == 9
                || enemyNPCDetectCollision(enemy->pos.X + 2, enemy->pos.Y) == 0) {
                int flag = 0;
                for (int i = enemy->pos.Y + 1; i < player.pos.Y; i++) {
                    if (enemyNPCDetectCollision(enemy->pos.X, i) == 9) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    enemy->pos.X -= 2;
                    enemy->dodgeCount -= 1;
                    return 1;
                }
            }
            else if (enemyNPCDetectCollision(enemy->pos.X - 2, enemy->pos.Y) == 9
                || enemyNPCDetectCollision(enemy->pos.X - 2, enemy->pos.Y) == 0) {
                int flag = 0;
                for (int i = enemy->pos.Y + 1; i < player.pos.Y; i++) {
                    if (enemyNPCDetectCollision(enemy->pos.X, i) == 9) {
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    enemy->pos.X += 2;
                    enemy->dodgeCount -= 1;
                    return 1;
                }
            }
            else {
                if (enemyNPCDetectCollision(enemy->pos.X + 4 * enemy->dodgeDirection, enemy->pos.Y) == 9
                    || enemyNPCDetectCollision(enemy->pos.X + 4 * enemy->dodgeDirection, enemy->pos.Y) == 0 ) {
                    int flag = 0;
                    for (int i = enemy->pos.Y + 1; i < player.pos.Y; i++) {
                        if (enemyNPCDetectCollision(enemy->pos.X, i) == 9) {
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        enemy->pos.X -= 2 * enemy->dodgeDirection;
                        enemy->dodgeDirection *= -1;
                        enemy->dodgeCount -= 1;
                        return 1;
                    }
                }
                else {
                    int flag = 0;
                    for (int i = enemy->pos.Y + 1; i < player.pos.Y; i++) {
                        if (enemyNPCDetectCollision(enemy->pos.X,i) == 9) {
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        enemy->pos.X += 4 * enemy->dodgeDirection;
                        enemy->dodgeDirection *= -1;
                        enemy->dodgeCount -= 1;
                        return 1;
                    }
                }
            }
        }
        if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 1 &&
            enemy->direction == 0) {

            enemy->pos.Y += 1;

            return 1;
        }

        if (enemyNPCDetectCollision(enemy->pos.X + (2 * (enemy->direction)), enemy->pos.Y) == 1 &&
            enemy->direction != 0) {
            if (enemyNPCDetectCollision(enemy->pos.X, enemy->pos.Y + 1) == 1) {

                enemy->pos.Y += 1;

                return 1;
            }
            enemy->pos.X += 2 * (enemy->direction);

            return 1;
        }
        return 0;
    }

    return 0;
}

void moveOneEnemy(enemyNPC* enemy) {
    if (!tryMove(enemy)) {
        if (!setDirection(enemy)) {
            return;
        } //방향 지정 실패시 갇힌 몬스터이다.
        else tryMove(enemy);
    }
}

void moveEnemy() {
    enemyNPC* enemyNpc = enemyList->enemyHeader;
    while (enemyNpc != NULL) {
        if (enemyNpc->activeStatus == TRUE) {
            moveOneEnemy(enemyNpc);
        }
        enemyNpc = enemyNpc->next;
    }
}

//메모리 해제 함수 만들것

//x위치값을 가져와서 그 pos에 enemy를 만듭니다.
//enemyID는 생성된 순서대로 1,2..allEnemyCount까지입니다.
//불필요한 enemy메모리로의 접근을 없애기 위하여, enemy각 객체의 ID를 검사하여 draw,delete, move함수를 실행할지 결정합니다.
void makeNormalEnemy(int x) {
    enemyNPC* enemyNpc = (enemyNPC*)malloc(sizeof(enemyNPC));

    enemyNpc->pos.X = x;
    enemyNpc->pos.Y = gBoardOy + 1;
    enemyNpc->next = NULL;
    enemyNpc->direction = 0;
    enemyNpc->dodgeDirection = 1;
    enemyNpc->id = 1;
    enemyNpc->dodgeCount = 5;
    enemyNpc->type = 3;
    enemyNpc->activeStatus = TRUE;
	enemyNpc->dieFlag = FALSE;
    if (enemyList->enemyHeader == NULL) {
        enemyList->enemyHeader = enemyNpc;
        enemyNpc = 0;
        return;
    }

    int count = 2;
    enemyNPC* lastEnemy = enemyList->enemyHeader;
    while (lastEnemy->next != NULL) {
        lastEnemy = lastEnemy->next;
        count++;
    }

    lastEnemy->next = enemyNpc;
    enemyNpc->id = count;
    enemyNpc->type = 1;
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
    int randPos = 10;
    for (int i = 0; i < allAnimalCount; i++) {
        animalArray[i].speed = 1;
        animalArray[i].activeStatus = TRUE;
        setAnimalCurrentPos(animalArray + i,randPos, 18);
        randPos += 7;
    }
}

int moveOneAnimal(int index) {
    //랜덤하게 방향 지정
    int direction = animalRandInt();
    if (direction == 0) {
        return;
    }
    //direction 이 0 이면 그냥 return
    if (animalNPCdetectCollision(animalArray[index].pos.X + 2, animalArray[index].pos.Y) == 0) {
        direction = -1;
        return direction;
    }
    if (animalNPCdetectCollision(animalArray[index].pos.X - 2, animalArray[index].pos.Y) == 0) {
        direction = 1;
        return direction;
    }
    return direction;
}
//enemy, Animal 총 마릿수를 지정해주는 함수
void setAllEnemyCount(int count) {
    allEnemyCount = count;
    currentEnemyCount = count;
}
void setAllAnimalCount(int count) {
    allAnimalCount = count;
    currentAnimalCount = count;
}
int direction1, direction2, direction3;
//추후 i값의 조정으로 전부 움직일 수 있게 한다
void moveAnimal() {
    for (int i = 0; i < 3; i++) {
        if (animalArray[i].activeStatus == TRUE) {
            animalArray[i].pos.X += animalArray[i].direction;
        }
    }
}

//enemyPosArray배열을 돌 index입니다. 초기값을 0으로 초기화해줍니다.
void resetEnemySpawnCount() {
    spawnedEnemyCount = 0;
    enemyMoveSpeed = 0.5;
}

//enemy의 움직임을 총괄해주는 함수입니다. 전역으로 설정된 enemyPosArray에 있는 enemySpawnCount 인덱스 방이 가리키는 값으로 스폰합니다.
void enemyMoveSetting() {
    if ((double)(clock() - checkEnemyNpcSpawnTime) / CLOCKS_PER_SEC >= 3) {//여기있는 5를 변경하여 스폰시간을 제어할 수 있습니다.
        if (spawnedEnemyCount < allEnemyCount) {//여기의 3은 총 enemy 개수값과 동일하게 들어갑니다.   
            makeNormalEnemy((*(enemyPosArray + spawnedEnemyCount)) * 2);
            spawnedEnemyCount++;
            checkEnemyNpcSpawnTime = clock();
        }
        checkEnemyNpcSpawnTime = clock();
    }
    
    if ((double)(clock() - enemyMoveTimePerSec) / CLOCKS_PER_SEC >= enemyMoveSpeed) {
        deleteEnemy();
        moveEnemy();
        enemyMoveTimePerSec = clock();
        drawEnemy();
    }
}
//animalMove를 총괄해주는 함수입니다.
void animalMoveSetting() {
    if ((double)(clock() - animalMoveTimePerSec) / CLOCKS_PER_SEC >= 0.5) {
        for (int i = 0; i < 3; i++) {
            animalArray[i].direction = moveOneAnimal(i);
        }
        deleteAnimal();
        animalMoveTimePerSec = clock();
        moveAnimal();
        drawAnimal();
    }
    for (int i = 0; i < 3; i++) {
        if (animalArray[i].activeStatus == TRUE) {
            if (animalNPCdetectCollision(animalArray[i].pos.X, animalArray[i].pos.Y - 1) == 2 ||
                animalNPCdetectCollision(animalArray[i].pos.X + 2, animalArray[i].pos.Y) == 2 ||
                animalNPCdetectCollision(animalArray[i].pos.X - 2, animalArray[i].pos.Y) == 2) {
                deleteAnimal();
                animalArray[i].activeStatus = FALSE;
                drawAnimal();
                currentAnimalCount--;
            }
        }
    }
}
bossStruct boss = { {38,15},1,10,TRUE };
kingStruct king = { {38,1},1 };
posStruct barricadePos = { 38,6 };
int barricadeDetectCount = 0;

void makeEnemyListStage3(int enemyCount) {
    enemyList = (enemyNPCList*)malloc(sizeof(enemyNPCList));

    enemyList->enemyCurrentNumber = enemyCount;
    enemyList->enemyHeader = NULL;

    enemyPosArray = (int*)malloc(sizeof(int) * enemyCount);
    setRandomArrayStage3(enemyPosArray, enemyCount);
}
void setRandomArrayStage3(int* arr, const int count) {
    int posArray[20];
    for (int i = 0; i < 20;i+=2) {
        posArray[i] = randInt(1, 15);
        posArray[i + 1] = randInt(27, 40);
    }
    for (int i = 0; i < count; i++) {
        arr[i] = posArray[i];
    }
}
void makeNormalEnemyStage3(int x) {
    enemyNPC* enemyNpc = (enemyNPC*)malloc(sizeof(enemyNPC));

    enemyNpc->pos.X = x;
    enemyNpc->pos.Y = gBoardOy + 18;
    enemyNpc->next = NULL;
    enemyNpc->direction = 0;
    enemyNpc->id = 1;
    enemyNpc->activeStatus = TRUE;
    enemyNpc->dieFlag = FALSE;
    if (enemyList->enemyHeader == NULL) {
        enemyList->enemyHeader = enemyNpc;
        enemyNpc = 0;
        return;
    }

    int count = 2;
    enemyNPC* lastEnemy = enemyList->enemyHeader;
    while (lastEnemy->next != NULL) {
        lastEnemy = lastEnemy->next;
        count++;
    }
    lastEnemy->next = enemyNpc;
    enemyNpc->id = count;
}
void moveEnemyStage3() {
    enemyNPC* enemyNpc = enemyList->enemyHeader;
    while (enemyNpc != NULL) {
        if (enemyNpc->activeStatus == TRUE&&enemyNpc->pos.Y>1) {
            enemyNpc->pos.Y -= 1;
            if (enemyNpc->pos.Y == 1) {
                currentAnimalCount--;
            }
        }
        else if(enemyNpc->pos.Y==1) {
            enemyNpc->activeStatus = FALSE;
            enemyNpc->dieFlag = TRUE;
        }
        enemyNpc = enemyNpc->next;
    }
}
void moveEnemySettingstage3() {
    if ((double)(clock() - checkEnemyNpcSpawnTime) / CLOCKS_PER_SEC >= 2) {
        if (spawnedEnemyCount < allEnemyCount) {  
            makeNormalEnemyStage3((*(enemyPosArray + spawnedEnemyCount))*2);
            spawnedEnemyCount++;
            checkEnemyNpcSpawnTime = clock();
        }
        checkEnemyNpcSpawnTime = clock();
    }
    if ((double)(clock() - enemyMoveTimePerSec) / CLOCKS_PER_SEC >= enemyMoveSpeed) {
        
        deleteEnemy();
        moveEnemyStage3();
        enemyMoveTimePerSec = clock();
        drawEnemy();
    }
}
void moveBoss() {
    int posX, PosY;
	
    if (boss.pos.Y == 3) {
        return;
    }
    if ((double)(clock() - bossEnemyMoveTimePerSec) / CLOCKS_PER_SEC >= 2) {
        if (bossEnemyDetectCollision(boss.pos.X, boss.pos.Y - 1) == 1) {
            deleteBoss();
            boss.pos.Y -= 1;
            bossEnemyMoveTimePerSec = clock();
            drawBoss();
        }
        else if (bossEnemyDetectCollision(boss.pos.X, boss.pos.Y - 1) == 0) {
			if (barricadeDetectCount == 2) {
				deleteDamagedBarricade(barricadePos); 
				barricadeDetectCount = 0;
				barricadePos.Y -= 1;
			}
			else {
				drawDamagedBarricade(barricadePos);
				barricadeDetectCount += 1;
			}
            deleteBoss();
            boss.pos.Y += 2;
            bossEnemyMoveTimePerSec = clock();
            drawBoss();
        }
    }
}

void moveKing() {
    if ((double)(clock() - kingAnimalMoveTimePerSec) / CLOCKS_PER_SEC >= 1) {
        if (kingAnimalDetectCollision(king.pos.X + 2, king.pos.Y) == 0) {
            king.direction *= -1;
            deleteKing();
            king.pos.X += king.direction * 2;
            kingAnimalMoveTimePerSec = clock();
            drawKing();
        }
        else if (kingAnimalDetectCollision(king.pos.X - 2, king.pos.Y) == 0) {
            king.direction *= -1;
            deleteKing();
            king.pos.X += king.direction * 2;
            kingAnimalMoveTimePerSec = clock();
            drawKing();
        }
        else {
            deleteKing();
            king.pos.X += king.direction*2;
            kingAnimalMoveTimePerSec = clock();
            drawKing();
        }
    }
}


int kingAnimalDetectCollision(int posX, int posY) {
    int x, y;
    int arrX = (posX - gBoardOx)/2;
    int arrY = posY - gBoardOy;
    for (x = 0; x < 4; x++)
    {
        for (y = 0; y < 2; y++)
        {
            //gameBoard line
            if (kingAnimalModel[0][y][x] != 0 && (currentGameBoard[arrY + y][arrX + x] == 5)) {
                return 0;
            }


        }
    }
    return 1;
}