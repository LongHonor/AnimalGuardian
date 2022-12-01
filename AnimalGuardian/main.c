#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"
#include "pcHandler.h"
#include "npcModule.h"

int main() {
    srand((unsigned)time(NULL));
    setCurrentGameBoard(1);
    removeCursor();
	setAllEnemyCount(5);
    drawGameBoard();
    drawInitialUI();
    showPC(player);

    setAllAnimalCount(5);
    makeAnimal();

    resetEnemySpawnCount();
    
    makeEnemyList(allEnemyCount);
    while (1) {
        enemyMoveSetting();
        animalMoveSetting();
        pcKeyInput();
    }

    return 0;
}