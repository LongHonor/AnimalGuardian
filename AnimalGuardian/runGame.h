#pragma once

#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"
#include "pcHandler.h"
#include "npcModule.h"
#include "stage3Animation.h"
#include "gameLoby.h"
#include "sound.h"


void initSetting() {
    removeCursor();                     //커서 표시 지우기
    srand((unsigned)time(NULL));        //프로그램 전체를 위한 랜덤시드값 배정
}

boolean stage(int i) {
    //스테이지 설정
    //맵 설정
    setCurrentGameBoard(i);

    //PC출력
    showPC(player);
    loadBullet();

    //animalNPC 정보 갱신
    setAllAnimalCount(3);
    if (i < 2) {
        makeAnimal();
    }

    //enemyNPC 정보 갱신

    if (i == 2) {
        enemyModel[0][0] = 2;
        resetBossStatus();
        setAllEnemyCount(20);
        resetEnemySpawnCount();
        makeEnemyListStage3(allEnemyCount);
    }
    else {
        enemyModel[0][0] = 1;
        setAllEnemyCount(10+ 5*i);
        resetEnemySpawnCount();
        makeEnemyList(allEnemyCount);
    }

    //게임보드 및 UI 출력
    drawGameBoard();
    drawInitialUI();

    //게임동작부
    if (i < 2) {
        while (1) {
            if (currentAnimalCount == 0) {
                //gameover
                return FALSE;
            }
            if (currentEnemyCount == 0) return TRUE;
            pcKeyInput();
            animalMoveSetting();
            enemyMoveSetting();
        }
    }
    else {
        while (1) {
            if (currentAnimalCount == 0) {
                deleteBoss();
                return FALSE;
            }
            if (boss.hp == 0) {
                deleteBoss();
                return FALSE;
            }

            if (boss.hp==0) return TRUE;

            pcKeyInput();
            moveKing();
            moveBoss();
            moveEnemySettingstage3();
        }
    }

}

void runGame() {
    boolean gameStatus = TRUE;
    int gInt;
    int i=0;
    int retryFlag = 0;
    initSetting();
	Init();
    while (1) {
        system("cls");
		Sound_Play(0);
		VolumeSetSound();
        gInt = drawGameLoby();
        i = 0;
        stageNumber = i;

        if (gInt != 2) {
            deleteBoard();
            while (1) {
                gameStatus = stage(i);
                Sleep(1000);
                system("cls");

                if (gameStatus) {
                    if (i == 2) {
                        drawGameClear();
                        Sleep(3000);
                        system("cls");
                        break;
                    }

                    else {
                        //스테이지 클리어 화면 출력
                        drawStageClear();
                        Sleep(1000);
                        system("cls");
                        i++;
                        stageNumber = i;
                        if (i == 2) playAnimation();
                    }
                }
                else {
                    //gameOver
                    system("cls");
                    retryFlag = drawGameOver();
                    if (retryFlag == 0) {
                        i = 0;
                        stageNumber = i;
                        system("cls");
                        continue;
                    }
                    else
                        break;
                }
            }
        }
        else {
            system("cls");
            return;
        }
		SoundUpdate();
    }
   
}