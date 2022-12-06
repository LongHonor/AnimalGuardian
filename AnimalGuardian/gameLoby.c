#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "gameLoby.h"
#include "globalVariable.h"

int titleColor[7] = { 4,6,14,2,1,9,5 };
char gameBoardTitle[][23][42] = {
	//0:게임 로비
	//1:게임 오버
	//2:스테이지1
	//3:스테이지2
	//4:스테이지3
	//5:클리어 스테이지
	{//game loby title
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,1,0,1,1,0,1,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0},
	{0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,0},
	{0,0,1,0,1,1,0,1,0,0,1,0,1,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,0},
	{0,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{//game over title
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{//stage1 title
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},
	{//stage2 title
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	},{//stage3 title
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	}
};
//check game title character
void initCheckGameTitle() {
	for (int i = 0; i < 15; i++) {
		checkGameTitle [i] = 0;
	}
}
void showStartDirectionInLoby() {
	setCurrentCursorPos(35, 13);
	printf("▶");
}
void deleteStartDirectionInLoby() {
	setCurrentCursorPos(35, 13);
	printf("  ");
}
void showInsrtuctionDirectionInLoby() {
	setCurrentCursorPos(35, 16);
	printf("▶");
}
void deleteInstructionDirectionInLoby() {
	setCurrentCursorPos(35, 16);
	printf("  ");
}
void showExitDirectionInLoby() {
	setCurrentCursorPos(35, 19);
	printf("▶");
}
void deleteExitDirectionInLoby() {
	setCurrentCursorPos(35, 19);
	printf("  ");
}

void showRestartDirectionGameOver() {
	setCurrentCursorPos(35, 15);
	printf("▶");
}
void deleteRestartDirectionGameOver() {
	setCurrentCursorPos(35, 15);
	printf("  ");
}
void showExitDirectionGameOver() {
	setCurrentCursorPos(35, 19);
	printf("▶");
}
void deleteExitDirectionGameOver() {
	setCurrentCursorPos(35, 19);
	printf("  ");
}

void deleteBoard() {	//보드 지우기
	for (int y = 0; y < gBoardHeight + 2; y++) {
		for (int x = 0; x < gBoardWidth + 1; x++) {
			setCurrentCursorPos(2 * x, y);
			printf("  ");
		}
	}
}
void drawSide() {
	int posX, posY;
	//테두리 그리기
	for (posY = 0; posY < gBoardHeight + 3; posY++) {
		setCurrentCursorPos(0, posY);
		if (posY == gBoardHeight + 2) printf("└");
		else if (posY == 0) printf("┌");
		else printf("│");
		setCurrentCursorPos((gBoardWidth + 1) * 2, posY);
		if (posY == gBoardHeight + 2) printf("┘");
		else if (posY == 0) printf("┐");
		else printf("│");
		if (posY == 0 || posY == gBoardHeight + 2) {
			for (posX = 1; posX < gBoardWidth + 1; posX++) {
				setCurrentCursorPos(posX * 2, posY);
				printf("─");
			}
		}
	}
}
void showTitleChracter(int startX,int startY,int sizeWidth,int sizeHeight) {
	for (int y = 0; y < sizeHeight; y++) {
		for (int x = 0; x < sizeWidth; x++) {
			if (gameBoardTitle[0][startY + y][startX + x] == 1) {
				setCurrentCursorPos((startX+x)*2, startY + y);
				printf("■");
			}
		}
	}
}
void showTitle(char g[23][42]) {
	for (int x = 0; x < gBoardWidth; x++) {
		for (int y = 0; y < gBoardHeight; y++) {
			if (g[y][x] == 1) {
				setCurrentCursorPos(2 * x, y);
				printf("■");
			}
		}
	}
}
int changeColorText(int i,int check[], int startX, int startY, int sizeWidth, int sizeHeight) {
	clock_t startTime = clock();
	double settime = 0.2;
	returnkeyShowLobyTitle = 0;
	while (check[i] == 0 && (double)(clock() - startTime) / CLOCKS_PER_SEC <= settime) {
		changeConsoleColor(titleColor[(i - 1) % 7]);
		showTitleChracter(startX, startY, sizeWidth, sizeHeight);
		if (_kbhit() != 0) {
			returnkeyShowLobyTitle = _getch();
		}
	}
	check[i] = 1;
	restoreConsoleColor();
	return returnkeyShowLobyTitle;
}
int showLobyTitle() {
	clock_t startTime = clock();
	double settime = 0.5;
	int key;
	while (1) {
		if (checkGameTitle[0] == 0) {	//reset title color 
			showTitle(gameBoardTitle[0]);
			checkGameTitle[0] = 1;
		}
		if (changeColorText(1, checkGameTitle, 7, 2, 5, 4)!=0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(2, checkGameTitle, 13, 2, 4, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(3, checkGameTitle, 18, 2, 1, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(4, checkGameTitle, 20, 2, 5, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(5, checkGameTitle, 26, 2, 5, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(6, checkGameTitle, 32, 2, 4, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(7, checkGameTitle, 2, 7, 4, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(8, checkGameTitle, 7, 7, 4, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(9, checkGameTitle, 12, 7, 5, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(10, checkGameTitle, 18, 7, 4, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(11, checkGameTitle, 23, 7, 4, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(12, checkGameTitle, 28, 7, 1, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		if (changeColorText(13, checkGameTitle, 30, 7, 5, 4) != 0) {
			return returnkeyShowLobyTitle;
		}
		changeColorText(14, checkGameTitle, 36, 7, 4, 4);
		initCheckGameTitle();
		restoreConsoleColor();
	}
}
int drawGameLoby() {
	drawSide();
	initCheckGameTitle();
	setCurrentCursorPos(38, 13);
	printf("시작하기");
	setCurrentCursorPos(38, 16);
	printf("게임 설명");
	setCurrentCursorPos(38, 19);
	printf("게임 종료");
	showStartDirectionInLoby();
	int directionY = 13;
	int gameModeNum = 0;	//0:게임 시작, 1:게임 설명, 2:게임 종료
	while (1) {
		int key = showLobyTitle();
		if (key == down) {
			if (directionY == 13) {
				deleteStartDirectionInLoby();
				showInsrtuctionDirectionInLoby();
				gameModeNum = 1;
				directionY += 3;
			}
			else if (directionY == 16) {
				deleteInstructionDirectionInLoby();
				showExitDirectionInLoby();
				gameModeNum = 2;
				directionY += 3;
			}
		}
		else if (key == up) {
			if (directionY == 19) {
				deleteExitDirectionInLoby();
				showInsrtuctionDirectionInLoby();
				gameModeNum = 1;
				directionY -= 3;
			}
			else if (directionY == 16) {
				deleteInstructionDirectionInLoby();
				showStartDirectionInLoby();
				gameModeNum = 0;
				directionY -= 3;
			}
		}
		else if (key == space) {
			if (gameModeNum == 1) {
				deleteBoard();
				return drawInstruction();
			}
			else {
				return gameModeNum;
			}
		}
	}
}
void drawSquare(int x,int y) {
	setCurrentCursorPos(x, y);
	printf("┌");
	setCurrentCursorPos(x + 2, y);
	printf("─");
	setCurrentCursorPos(x + 4, y);
	printf("┐");
	setCurrentCursorPos(x, y + 1);
	printf("│");
	setCurrentCursorPos(x + 4, y + 1);
	printf("│");
	setCurrentCursorPos(x, y + 2);
	printf("└");
	setCurrentCursorPos(x + 2, y + 2);
	printf("─");
	setCurrentCursorPos(x + 4, y + 2);
	printf("┘");
}
void drawRectangle(int x, int y) {
	for (int a = 0; a <= 2; a++) {
		for (int b = 0; b <= 8; b+=2) {
			if (b != 0 && b != 8) {
				if (a != 1) {
					setCurrentCursorPos(x + b, y + a);
					printf("─");
				}
			}
			else {
				if (a == 1) {
					setCurrentCursorPos(x + b, y + a);
					printf("│");
				}
			}
		}
	}
	setCurrentCursorPos(x, y);
	printf("┌");
	setCurrentCursorPos(x + 8, y);
	printf("┐");
	setCurrentCursorPos(x, y + 2);
	printf("└");
	setCurrentCursorPos(x + 8, y + 2);
	printf("┘");
}
int drawInstruction() {
	drawSide();
	setCurrentCursorPos(36 , 1);
	printf("<게임 스토리>");
	setCurrentCursorPos(8, 3);
	printf("정체를 알 수 없는 괴물들이 지구의 멸종위기 동물들을 납치하려 한다...");
	setCurrentCursorPos(10, 5);
	printf("특급요원 J는 위기에 빠진 동물들을 구하라는 명을 받게 되는데...");
	setCurrentCursorPos(20, 8);
	printf("<게임 방법>");
	int directionKeyX = 14, directionKeyY = 10;
	setCurrentCursorPos(directionKeyX + 2, directionKeyY + 1);
	printf("←");
	drawSquare(directionKeyX, directionKeyY);
	directionKeyX = 20, directionKeyY = 10;
	setCurrentCursorPos(directionKeyX + 2, directionKeyY + 1);
	printf("→");
	drawSquare(directionKeyX, directionKeyY);
	directionKeyX = 26, directionKeyY = 10;
	setCurrentCursorPos(directionKeyX, directionKeyY + 1);
	printf(": PC 좌우 이동");
	int bulletKeyX = 16, bulletKeyY = 13;
	drawRectangle(bulletKeyX, bulletKeyY);
	setCurrentCursorPos(bulletKeyX + 2, bulletKeyY + 1);
	printf("SPACE");
	setCurrentCursorPos(bulletKeyX + 10, bulletKeyY + 1);
	printf(": 총알 발사");
	int loadKeyX = 20, loadKeyY = 16;
	drawSquare(loadKeyX, loadKeyY);
	setCurrentCursorPos(loadKeyX + 2, loadKeyY + 1);
	printf("R");
	setCurrentCursorPos(loadKeyX + 6, loadKeyY + 1);
	printf(": 장전");
	int itemKeyX = 20, itemKeyY = 19;
	drawSquare(itemKeyX, itemKeyY);
	setCurrentCursorPos(itemKeyX + 2, itemKeyY + 1);
	printf("Q");
	setCurrentCursorPos(itemKeyX + 6, itemKeyY + 1);
	printf(": 아이템 사용");
	
	setCurrentCursorPos(50, 8);
	printf("<아이템 종류>");
	setCurrentCursorPos(46, 11);
	printf("□□□ : 바리게이트 설치");
	setCurrentCursorPos(46, 13);
	printf("E↓ : 괴물 속도 감소");
	setCurrentCursorPos(46, 15);
	printf("R↓ : 장전 속도 감소");
	setCurrentCursorPos(74, 21);
	printf("▶ Back");
	while (1) {
		int key = _getch();
		if (key == space) {
			deleteBoard();
			return drawGameLoby();
		}
	}
}
//게임 오버
void drawGameOver() {
	drawSide();
	showTitle(gameBoardTitle[1]);
	setCurrentCursorPos(38, 15);
	printf("다시 시작");
	setCurrentCursorPos(38, 19);
	printf("게임 종료");
	showRestartDirectionGameOver();
	int gameModeNum = 0;
	while (_kbhit() != 0) {
		int key = _getch();
		if (key == down) {
			deleteRestartDirectionGameOver();
			showExitDirectionGameOver();
			gameModeNum = 1;	
		}
		else if (key == up) {
			deleteExitDirectionGameOver();
			showRestartDirectionGameOver();
			gameModeNum = 0;
		}
		else if (key == space) {
			return gameModeNum;	//0:다시 시작 1: 종료
		}
	}
}
//stagenum = 1 -> stage1
//stagenum = 2 -> stage2
//stagenum = 3 -> stage3
void drawStageLoby(int stagenum) {
	drawSide();
	showTitle(gameBoardTitle[stagenum + 1]);
}