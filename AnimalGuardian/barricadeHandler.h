#pragma once

//barricade 좌표
int barcX, barcY;
//barricade color
int barricadeColor;
//barricade model
char barcModel[1][3];

//함수 선언부
void drawBarricade();
void deleteBarricade();
void shiftLeftBarricade();
void shiftRightBarricade();
void shiftUpBarricade();
void shiftDownBarricade();
