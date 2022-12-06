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

    //animalNPC 정보 갱신
    setAllAnimalCount(3);
    makeAnimal();

    //enemyNPC 정보 갱신
    setAllEnemyCount(15+5*i);
    resetEnemySpawnCount();
    makeEnemyList(allEnemyCount);

    //게임보드 및 UI 출력
    drawGameBoard();
    drawInitialUI();

    //게임동작부
    while (1) {
        if (currentAnimalCount == 0) {
            //gameover
            return FALSE;
        }
        if(currentEnemyCount == 0) return TRUE;
        pcKeyInput();
        animalMoveSetting();
        enemyMoveSetting();
    }
}

void runGame() {
    boolean gameStatus = TRUE;
    int gInt;
    int i=0;
    initSetting();

    gInt = drawGameLoby();

    if(gInt != 2){
        while(1){
            gameStatus = stage(i);
            system("cls");
            if(gameStatus) i++;
            else{
                //gameOver
                //
                break;
            }
        }
    }
    else return;
}