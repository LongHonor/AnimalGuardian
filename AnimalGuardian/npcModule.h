#pragma once

    
void makeEnemy();
void makeEnemyList(int enemyCount);

void moveEnemy();
void showNormalEnemy();
void showOneEnemy(enemyNPC* enemyNpc);
void deleteOneEnemy(enemyNPC* enemyNpc);
void deleteNormalEnemy();
void makeNormalEnemy();
int enemyNPCDetectCollision(int posX, int posY);
int getNextEnemy(enemyNPC* enemy);
enemyNPC* getHeaderEnemy();