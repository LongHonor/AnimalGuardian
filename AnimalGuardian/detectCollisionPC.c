#include "detectCollisionPC.h"
#include "globalVariable.h"

int detectCollisionPC(int posX, int posY) {
	int arrx = (posX - gBoardOx) / 2;
	int arry = (posY - gBoardOy);
	//pc√—µπ ∏Æ≈œ 0
	if (gameBoardInfo[arry][arrx] == 1) {
		return 0;
	}
	return 1;
}

int detectCollisionBullet(int posX, int posY) {
	int arrx = (posX - gBoardOx) / 2;
	int arry = (posY - gBoardOy);
	//pc√—µπ ∏Æ≈œ 0
	/*if (gameBoardInfo[arry][arrx] == 1) {
		return 0;
	}*/
	if (gameBoardInfo[arry][arrx] == 4) {
		return 0;
	}
	if (gameBoardInfo[arry][arrx] == 5) {
		return 0;
	}
	return 1;
}