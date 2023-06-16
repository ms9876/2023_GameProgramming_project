#pragma once
// 20 X 20
//#define HORIZON 21
//#define VERTICAL 20
const int HORIZON = 50;
const int VERTICAL = 150;

// 위치.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _tagplayer
{
	POS tpos;       // 플레이어의 위치
	POS tNewpos;    // 플레이어의 새위치
}PLAYER, * PPLAYER;

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos);
void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); 
void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); 
