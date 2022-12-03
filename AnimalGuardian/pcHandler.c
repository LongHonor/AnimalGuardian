#include "pcHandler.h"
#include "globalVariable.h"
#include "gameItem.h"
#include "gameBoardHandler.h"
#include "detectCollision.h"
#include "npcModule.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>
//PC 초기화
PC player = { {40,20},1,2,3,0};

//bullet 초기화
int bulletCount = 10;
posStruct *dieEnemyPos = NULL;
int bulletItem = 0;
int enemySpeedItemFlag = 0;
loadFlag = 0;
dieTime = 2;
dieFlag = 0;
int animalEffectFlag = 0;

void findDieEnemy(posStruct enemyCurPos, clock_t checkdieStartTime);



void showPC(PC player) {
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	printf("●");
	setCurrentCursorPos(player.pos.X, player.pos.Y);    //cursor위치 처음 위치로 다시 설정
}

void erasePC(PC player) {
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	printf("  ");
	setCurrentCursorPos(player.pos.X, player.pos.Y);    //cursor위치 처음 위치로 다시 설정
}

void showBullet(posStruct pos) {
	setCurrentCursorPos(pos.X, pos.Y);
	printf("ο");
}
void eraseBullet(posStruct pos) {
	setCurrentCursorPos(pos.X, pos.Y);
	printf("  ");
}

void shiftLeftPc() {
	if (!detectCollisionPC(player.pos.X - 2, player.pos.Y)) {
		return;
	}
	erasePC(player);
	player.pos.X -= 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	showPC(player);
}
void shiftRightPc() {
	if (!detectCollisionPC(player.pos.X + 2, player.pos.Y)) {
		return;
	}
	erasePC(player);
	player.pos.X += 2;
	setCurrentCursorPos(player.pos.X, player.pos.Y);
	showPC(player);
}
posStruct findDieAnimal(int bullet_x) {
	posStruct temp = { 0,0 };
	for (int i = 0; i < 3; i++) {
		if (animalArray[i].activeStatus == TRUE) {
			//animalNPC 위치 받아와서 setCurrentCursorPos()호출
			posStruct animalCurPos = getAnimalCurrentPos(&animalArray[i]);
			int arrX = (animalCurPos.X - gBoardOx) / 2;
			int arrY = (animalCurPos.Y - gBoardOy);
			if (arrX == bullet_x / 2 || arrX + 1 == bullet_x / 2) {
				animalArray[i].activeStatus = FALSE;
				animalEffectFlag = 1;
				checkEffectAnimalDyingTime = clock();
				return animalCurPos;
			}
		}
	}
	return temp;
}
void shootBullet() {
	Bullet* newbullet = (Bullet*)malloc(sizeof(Bullet));
	newbullet->pos = player.pos;
	newbullet->pos.Y -= 2;
	newbullet->speed = 25;
	bulletCount--;
	printBulletCount();
	while (1) {
		//일반 모드
		if (bulletItem == 0) {
			//enemy 충돌 검사
			if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 5) {
				itemDrop();
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				checkdieStartTime = clock(); dieFlag = 1;
				findDieEnemy(newbullet->pos, checkdieStartTime);
				drawDieEnemyEffect(newbullet->pos);
				printEnemyCount();
				return;
			}
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 5) {
				itemDrop();
				newbullet->pos.Y -= 1;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				checkdieStartTime = clock(); dieFlag = 1;
				findDieEnemy(newbullet->pos, checkdieStartTime);
				drawDieEnemyEffect(newbullet->pos);
				printEnemyCount();
				return;
			}
			//animal 충돌 검사
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 6) {
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				drawDieAnimalEffect(findDieAnimal(newbullet->pos.X));
				return;
			}
			//바로 위 충돌
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 0) {
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			//위위 충돌
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 0) {
				newbullet->pos.Y -= 1;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				return;
			}
			//충돌 하지 않은 경우
			else {
				newbullet->pos.Y -= 2;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
			}
		}
		//관통 모드
		else if (bulletItem == 1) {
			//게임보드 상단 충돌
			//npc충돌
			if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 5) {
				itemDrop();
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				checkdieStartTime = clock(); dieFlag = 1;
				findDieEnemy(newbullet->pos, checkdieStartTime);
				drawDieEnemyEffect(newbullet->pos);
				printEnemyCount();
				return;
			}
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 5) {
				itemDrop();
				newbullet->pos.Y -= 1;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				checkdieStartTime = clock(); dieFlag = 1;
				findDieEnemy(newbullet->pos, checkdieStartTime);
				drawDieEnemyEffect(newbullet->pos);
				printEnemyCount();
				return;
			}
			//animal 충돌 검사
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 6) {
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
				drawDieAnimalEffect(findDieAnimal(newbullet->pos.X));
				return;
			}
			else if (detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 1) == 0 || detectCollisionBullet(newbullet->pos.X, newbullet->pos.Y - 2) == 0) {
				if (newbullet->pos.Y - 1 == gBoardOy || newbullet->pos.Y - 2 == gBoardOy) {
					newbullet->pos.Y = gBoardOy + 1;
					showBullet(newbullet->pos);
					Sleep(newbullet->speed);
					eraseBullet(newbullet->pos);
					return;
				}
				else {
					newbullet->pos.Y -= 2;
					Sleep(newbullet->speed);
				}
			}
			else {
				newbullet->pos.Y -= 2;
				showBullet(newbullet->pos);
				Sleep(newbullet->speed);
				eraseBullet(newbullet->pos);
			}
		}

	}
}
void findDieEnemy(posStruct enemyCurPos, clock_t checkdieStartTime) {
	enemyNPC * search = enemyList->enemyHeader;

	while (search != NULL) {
		if (search->activeStatus == TRUE) {
			if (search->pos.X == enemyCurPos.X && search->pos.Y == enemyCurPos.Y - 1) {
				search->activeStatus = FALSE;
				search->deadPos.X = search->pos.X;
				search->deadPos.Y = search->pos.Y;
				search->deadTime = checkdieStartTime;
				currentEnemyCount -= 1;
			}
		}
		search = search->next;
	}
}
void loadBullet() {
	bulletCount = 10;
}
void pcKeyInput() {
	int key;
	for (int i = 0; i < 20; i++) {
		//_kbhit 은 입력시 1 리턴
		if (_kbhit() != 0) {
			key = _getch();
			switch (key) {
			case left:
				shiftLeftPc();
				break;
			case right:
				shiftRightPc();
				break;
			case space:
				if (loadFlag == 0 && bulletCount > 0) {
					shootBullet();
				}
				break;
			case load:
				checkLoadStartTime = clock();
				loadFlag = 1;
				break;
			case item:
				if (player.itemNum == 1) {
					//에네미 속도 감소
					enemySpeedItemFlag = 1;
					enemyMoveSpeed = 1;
					checkSlowEnemySpeedTime = clock();
				}
				if (player.itemNum == 2) {
					player.reloadSpeed = 1;
					checkLoadStartTime = clock();
					loadFlag = 1;
				}
				if (player.itemNum == 3) {
					placeBarricade();
					drawGameBoard();
					player.itemNum = 0;
					printCurrentItem();
				}
				//아이템 종류당 번호 할당
				//번호에 해당하는 아이템 사용
				break;
			}
		}
		//장전2초
		if (loadFlag == 1 && (double)(clock() - checkLoadStartTime) / 1000 >= player.reloadSpeed) {
			if (player.reloadSpeed == 1) {
				player.reloadSpeed = 2;
				player.itemNum = 0;
				printCurrentItem();
			}
			loadBullet();
			printBulletCount();
			loadFlag = 0;
		}
		//enemy 속도 감소 아이템 적용 체크
		if (enemySpeedItemFlag == 1 && (double)(clock() - checkSlowEnemySpeedTime) / 1000 >= 5) {
			player.itemNum = 0;
			enemySpeedItemFlag = 0;
			enemyMoveSpeed = 0.5;
			printCurrentItem();
		}
		//effect 효과 2초
		if (animalEffectFlag == 1 && (double)(clock() - checkEffectAnimalDyingTime) / CLOCKS_PER_SEC >= 2) {
			deleteDieAnimalEffect();
			animalEffectFlag = 0;
		}

		deleteDieEnemyEffect();

		Sleep(20);
	}
}
void itemDrop() {
	int result = rand() % 10;
	setCurrentCursorPos(44 * 2, 5);
	switch (result) {
	case 1:
		player.itemNum = 1;	//에네미 속도 감소
		printCurrentItem();
		break;
	case 2:
		player.itemNum = 2;	//장전 속도 감소
		printCurrentItem();
		break;
	case 3:
		player.itemNum = 3;	//바리게이트 설치
		printCurrentItem();
		break;
	default:
		break;
	}
}
void printCurrentItem() {
	int i, j;
	int curX = 44 * 2, curY = 15;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			setCurrentCursorPos(curX + j * 2, curY + i);
			if (i == 0) {
				if (j == 0) printf("┌");
				else if (j == 2) printf("┐");
				else printf("─");
			}
			else if (i == 2) {
				if (j == 0) printf("└");
				else if (j == 2) printf("┘");
				else printf("─");
			}
			else {
				if (j == 1) {
					switch (player.itemNum) {
					case 1:
						printf(" S");
						break;
					case 2:
						printf(" R");
						break;
					case 3:
						printf(" B");
						break;
					default:
						printf("  ");
						break;
					}
				}
				else printf("│");
			}
		}
	}
}