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
    else {
        drawBoss();
        drawKing();
    }

    //enemyNPC 정보 갱신

    if (i == 2) {
        enemyModel[0][0] = 2;
        setAllEnemyCount(1);
        resetEnemySpawnCount();
        makeEnemyListStage3(allEnemyCount);
    }
    else {
        setAllEnemyCount(10+5*i);
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
            
        }
    }
    else {
        while (1) {
            if (currentAnimalCount == 0) {
                //gameover
                return FALSE;
            }
            if (boss.hp==0) return TRUE;
            pcKeyInput();
            moveBoss();
            moveEnemySettingstage3();
        }
    }

}

void runGame() {
    boolean gameStatus = TRUE;
    int gInt;
    int i=0;
    initSetting();

    gInt = drawGameLoby();

    if(gInt != 2){
        deleteBoard();
        while(1){
            gameStatus = stage(i);
            Sleep(1000);
            system("cls");

            if (gameStatus) {
                i++;
                //스테이지 클리어 화면 출력
                //if (i == 2) playAnimation();
            }
            else{
                //gameOver
                //
                break;
            }
        }
    }
    else return;
}