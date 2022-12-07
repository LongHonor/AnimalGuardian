#pragma once
int flag;
int checkGameTitle[15];
int returnkeyShowLobyTitle;

//로비 화면 화살표
void showStartDirectionInLoby();
void deleteStartDirectionInLoby();
void showInsrtuctionDirectionInLoby();
void deleteInstructionDirectionInLoby();
void showExitDirectionInLoby();
void deleteExitDirectionInLoby();
//게임 오버 화면 화살표
void showRestartDirectionGameOver();
void deleteRestartDirectionGameOver();
void showExitDirectionGameOver();
void deleteExitDirectionGameOver();
//로비 화면 생성
int drawGameLoby();
//게임설명서 화면 생성
int drawInstruction();
//게임 오버 화면 생성
int drawGameOver();
//화면 지우기
void deleteBoard();
//스테이지 화면 생성
void drawStageLoby(int stagenum);
//테두리 그리기
void drawSide();
//한 글자씩 그리기
void showTitleCharacter(int startX, int startY, int sizeWidth, int sizeHeight);
//화면 전체 타이틀 그리기
void showTitle(char g[23][42]);
//글자 색상 바꾸기
int changeColorText(int i, int check[], int startX, int startY, int sizeWidth, int sizeHeight);
//로비 화면 타이틀 생성 -> 이펙트 구현
int showLobyTitle();

void drawSquare();
void drawRectangle();
//타이틀 색상 여부 확인
void initCheckGameTitle();