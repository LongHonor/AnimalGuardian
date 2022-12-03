#pragma once
#include "globalVariable.h"

//barricade ��ǥ
int barcX, barcY;
//barricade color
int barricadeColor;
//barricade model
char barcModel[1][3];

//�Լ� �����
void drawBarricade();
void deleteBarricade();
void drawDamagedBarricade(posStruct barricadePos);
void deleteDamagedBarricade(posStruct barricadePos);

void shiftLeftBarricade();
void shiftRightBarricade();
void shiftUpBarricade();
void shiftDownBarricade();
