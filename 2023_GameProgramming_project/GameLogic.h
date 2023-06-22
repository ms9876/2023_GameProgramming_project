#pragma once
#include "define.h"
#include "Ball.h"
// 위치.
typedef struct _tagpos
{
	int x;
	int y;
	int width = 3;
}POS, * PPOS;

typedef struct _tagBar
{
	POS tpos;       // bar 위치
	POS tNewpos;    // bar 새위치
}BAR, * PBAR;

void Init(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PPOS _pStartpos);
void Update(char _cMaze[VERTICAL][HORIZON], PBAR _pBar);
void Render(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PBallPos _pBall);

void Stage02(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PPOS _pStartpos);
void Stage03(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PPOS _pStartpos);