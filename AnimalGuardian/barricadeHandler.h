#pragma once

//barricade ��ǥ
int barcX, barcY;
//barricade color
int barricadeColor;
//barricade model
char barcModel[1][3];

//�Լ� �����
void drawBarricade();
void deleteBarricade();
void shiftLeftBarricade();
void shiftRightBarricade();
void shiftUpBarricade();
void shiftDownBarricade();
