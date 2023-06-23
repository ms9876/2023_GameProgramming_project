#pragma once
#include "define.h"
#include "Item.h";

typedef struct Ball
{
     float x;
     float y;
     float dirX;
     float dirY;
     bool go;
}BallPos, * PBallPos;

typedef struct BallVector
{
     Ball tpos;     
     Ball tNewpos;
}BALL, * PBALL;

void BallInit(Ball& ball);
void BallUpdate(Ball& ball, char _cMaze[VERTICAL][HORIZON], Item& item);
int StageClear();
int GameOver();