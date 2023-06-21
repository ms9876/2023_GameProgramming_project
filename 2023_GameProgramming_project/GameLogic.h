#pragma once
#include "Ball.h";

const int HORIZON = 29;
const int VERTICAL = 28;

// ��ġ.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _tagBar
{
	POS tpos;       // �÷��̾��� ��ġ
	POS tNewpos;    // �÷��̾��� ����ġ
}BAR, * PBAR;

void Init(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer, PPOS _pStartpos);
void Update(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer);
void Render(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer);
