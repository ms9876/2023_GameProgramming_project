#pragma once
#include "Ball.h";

const int HORIZON = 29;
const int VERTICAL = 28;

// 위치.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _tagBar
{
	POS tpos;       // 플레이어의 위치
	POS tNewpos;    // 플레이어의 새위치
}BAR, * PBAR;

void Init(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer, PPOS _pStartpos);
void Update(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer);
void Render(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer);
