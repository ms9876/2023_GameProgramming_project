#pragma once
#include "define.h"
#include "Ball.h"
// ��ġ.
typedef struct _tagpos
{
	int x;
	int y;
	int width = 3;
}POS, * PPOS;

typedef struct _tagBar
{
	POS tpos;       // bar ��ġ
	POS tNewpos;    // bar ����ġ
}BAR, * PBAR;

void Init(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PPOS _pStartpos);
void Update(char _cMaze[VERTICAL][HORIZON], PBAR _pBar);
void Render(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PBallPos _pBall);

void Stage02(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PPOS _pStartpos);
void Stage03(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PPOS _pStartpos);