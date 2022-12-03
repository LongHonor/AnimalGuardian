#pragma once

#include <stdio.h>
#include <windows.h>
#include "globalVariable.h"
#include "gameBoardHandler.h"
#include "gameItem.h"
#include "pcHandler.h"
#include "npcModule.h"
#include "stage3Animation.h"

void initSetting() {
    removeCursor();                     //커서 표시 지우기
    srand((unsigned)time(NULL));        //프로그램 전체를 위한 랜덤시드값 배정
}

boolean stage1() {
    //스테이지1 설정
    //맵 설정
    setCurrentGameBoard(0);

    //PC출력
    showPC(player);

    //animalNPC 정보 갱신
    setAllAnimalCount(3);
    makeAnimal();

    //enemyNPC 정보 갱신
    setAllEnemyCount(15);
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
void stage2() {
    //맵 설정
    setCurrentGameBoard(1);

    //PC출력
    showPC(player);

    //animalNPC 정보 갱신
    setAllAnimalCount(3);
    makeAnimal();

    //enemyNPC 정보 갱신
    setAllEnemyCount(20);
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
        if (currentEnemyCount == 0) return TRUE;
        pcKeyInput();
        animalMoveSetting();
        enemyMoveSetting();
    }
}

void runGame() {
    initSetting();

    stage1();
    system("cls");
    Sleep(30);
    stage2();
}