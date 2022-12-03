#include "runGame.h"

int main() {
<<<<<<< HEAD
    runGame();
=======
	int stage = 0;
    removeCursor();
    srand((unsigned)time(NULL));
    setCurrentGameBoard(stage);
    
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
		if (currentEnemyCount == 0) {
			if (stage == 2) return;
			system("cls");
			Sleep(3); stage += 1;
			setCurrentGameBoard(stage);
			drawGameBoard();
			setAllEnemyCount(5);
			setAllAnimalCount(5);

			showPC(player);

			makeAnimal();
			resetEnemySpawnCount();
			makeEnemyList(allEnemyCount);
		}
    }
>>>>>>> origin/main
    return 0;
}