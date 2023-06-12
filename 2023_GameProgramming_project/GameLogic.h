#pragma once
// 20 X 20
//#define HORIZON 21
//#define VERTICAL 20
const int HORIZON = 21;
const int VERTICAL = 20;

// ��ġ.
typedef struct _tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _tagplayer
{
	POS tpos;       // �÷��̾��� ��ġ
	POS tNewpos;    // �÷��̾��� ����ġ
}PLAYER, * PPLAYER;

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer,
	PPOS _pStartpos, PPOS _pEndpos);
void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); // ���� ����.
void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer); // �׷��ִ�.
