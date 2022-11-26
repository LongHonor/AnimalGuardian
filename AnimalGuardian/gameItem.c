#include "gameItem.h"
#include "globalVariable.h"

void reduceEnemySpeed() {
	//enemy배열 받아와서 속도 값 세팅
	enemyNPC* p = NULL;
	int reducedSpeed = 0;

	if (enemyList == NULL) return;
	while (p != NULL) {
		p->speed = reducedSpeed;
		p = p->next;
	}
}

void restoreEnemySpeed() {
	//enemy배열 받아와서 속도 값 초기상태로 세팅
	enemyNPC* p = NULL;
	int restoredSpeed = 0;

	if (enemyList == NULL) return;
	while (p != NULL) {
		p->speed = restoredSpeed;
		p = p->next;
	}
}

void modifyReloadSpeed(int status) {
	//status에 따라 재장전 속도 증감
	//증가 : 1, 감소 : 0;

	int increasedSpeed = 20, decreasedSpeed = 5;
	if (status == 1) setPcReloadSpeed(increasedSpeed);
	else setPcReloadSpeed(decreasedSpeed);
}

void restoreReloadSpeed() {
	//재장전 속도 초기상태로 세팅
	setPcReloadSpeed(initialReloadSpeed);
}

int isBarricadePlaceable(int barcX, int barcY) {
	//인자 바리케이드 좌표
	//게임보드 전역변수 게터로 가져와서 설치 가능한지 확인
	// 0 : false 1 : true
	return 0;
}

void placeBarricade() {
	//바리케이드 설치
	//게임 시간 정지

	//바리케이드 그리기
	//입력 대기
	//설치 키 누르면 설치 가능한지 확인
	//설치 가능하면 게임보드 갱신
	//불가능하면 경고 메시지 출력
	//이동키 누르면 바리케이드 위치 이동
}