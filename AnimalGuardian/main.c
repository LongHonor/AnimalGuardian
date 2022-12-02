#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"
#include "pcHandler.h"
#include "npcModule.h"
#include "stage3Animation.h"

int main() {
    removeCursor();
    playAnimation();
    /*srand((unsigned)time(NULL));
    setCurrentGameBoard(1);
    
	setAllEnemyCount(5);
    drawGameBoard();
    showPC(player);

    setAllAnimalCount(5);
    makeAnimal();

    resetEnemySpawnCount();
    
    makeEnemyList(allEnemyCount);
    while (1) {
        drawInitialUI();
        enemyMoveSetting();
        animalMoveSetting();
        pcKeyInput();
    }*/

    return 0;
}