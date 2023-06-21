#include<iostream>
#include<fstream>
#include<vector>
#include<Windows.h>
#include <algorithm>
#include"GameLogic.h"
#include"console.h"

using namespace std;

void Init(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer, PPOS _pStartpos)
{
	system("mode con cols=100 lines=350");
	strcpy_s(_cMaze[0],  "1111111111111111111111111111");
	strcpy_s(_cMaze[1],  "1222222222222222222222222221");
	strcpy_s(_cMaze[2],  "1222222222220000222222222221");
	strcpy_s(_cMaze[3],  "1222220000000000000002222221");
	strcpy_s(_cMaze[4],  "1200000000000000000000000021");
	strcpy_s(_cMaze[5],  "1000000000000000000000000001");
	strcpy_s(_cMaze[6],  "1222222222222222222222222221");
	strcpy_s(_cMaze[7],  "1222222222222222222222222221");
	strcpy_s(_cMaze[8],  "1000000000000000000000000001");
	strcpy_s(_cMaze[9],  "1200000000000000000000000021");
	strcpy_s(_cMaze[10], "1222220000000000000002222221");
	strcpy_s(_cMaze[11], "1222222222220000222222222221");
	strcpy_s(_cMaze[12], "1000000000000000000000000001");
	strcpy_s(_cMaze[13], "1000000000000000000000000001");
	strcpy_s(_cMaze[14], "1000000000000000000000000001");
	strcpy_s(_cMaze[15], "1000000000000000000000000001");
	strcpy_s(_cMaze[16], "1000000000000000000000000001");
	strcpy_s(_cMaze[17], "1000000000000000000000000001");
	strcpy_s(_cMaze[18], "1000000000000000000000000001");
	strcpy_s(_cMaze[19], "1000000000000000000000000001");
	strcpy_s(_cMaze[20], "1000000000000000000000000001");
	strcpy_s(_cMaze[21], "1000000000000000000000000001");
	strcpy_s(_cMaze[22], "1000000000000000000000000001");
	strcpy_s(_cMaze[23], "1000000000000000000000000001");
	strcpy_s(_cMaze[24], "1000000000000000000000000001");
	strcpy_s(_cMaze[25], "10000000000000000000000001");
	strcpy_s(_cMaze[26], "1111111111111111111111111111");
	_pStartpos->x = 13;
	_pStartpos->y = 25;

	BAR tSetplayer = { *_pStartpos};
	*_pPlayer = tSetplayer;
	srand((unsigned int)time(NULL));
}

void Update(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer)
{
	// 플레이어 움직임
	_pPlayer->tNewpos = _pPlayer->tpos;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--_pPlayer->tNewpos.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++_pPlayer->tNewpos.x;

	_pPlayer->tNewpos.x = std::clamp(_pPlayer->tNewpos.x, 0, HORIZON - 1);

	if (_cMaze[_pPlayer->tNewpos.y][_pPlayer->tNewpos.x] != '1')
	{
		_pPlayer->tpos = _pPlayer->tNewpos;
	}
}

void Render(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer) {
	for (int y = 0; y < VERTICAL; y++) {
		for (int x = 0; x < HORIZON; x++) {
			if (_pPlayer->tpos.x == x && _pPlayer->tpos.y == y) {
				SetColor(15, 8);
				cout << "ㅡㅡㅡ";
			}
			else if (_cMaze[y][x] == '0') {
				SetColor(15, 0);
				cout << "  ";
			}
			else if (_cMaze[y][x] == '1') {
				SetColor(15, 0);
				cout << "■";
			}
			else if (_cMaze[y][x] == '2') {
				SetColor(6, 15);
				cout << "▤";
			}
			else if (_cMaze[y][x] == '3') {
				SetColor(15, 0);
				cout << "⊙";
			}
			
		}
		cout << endl;
	}

}
