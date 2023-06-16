#include<iostream>
#include <fstream>
#include <vector>
#include<Windows.h>
#include<algorithm>	
#include "GameLogic.h"
#include "console.h"

using namespace std;

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos)
{
	strcpy_s(_cMaze[0], "111111111111111111111111111111111111111111111");
	strcpy_s(_cMaze[1], "122222222222222222222222222222222222222222221");
	strcpy_s(_cMaze[2], "122222222222222222220000222222222222222222221");
	strcpy_s(_cMaze[3], "122222222222220000000000000002222222222222221");
	strcpy_s(_cMaze[4], "122222222200000000000000000000000022222222221");
	strcpy_s(_cMaze[5], "122222200000000000000000000000000000000222221");
	strcpy_s(_cMaze[6], "122222222222222222222222222222222222222222221");
	strcpy_s(_cMaze[7], "122222222222222222222222222222222222222222221");
	strcpy_s(_cMaze[8], "122222200000000000000000000000000000000222221");
	strcpy_s(_cMaze[9], "122222222200000000000000000000000022222222221");
	strcpy_s(_cMaze[10], "122222222222220000000000000002222222222222221");
	strcpy_s(_cMaze[11], "122222222222222222220000222222222222222222221");
	strcpy_s(_cMaze[12], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[13], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[14], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[15], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[16], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[17], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[18], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[19], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[20], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[21], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[22], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[23], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[24], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[25], "100000000000000000000000000000000000000000001");
	strcpy_s(_cMaze[26], "111111111111111111111111111111111111111111111");
	_pStartpos->x = 17;
	_pStartpos->y = 25;

	PLAYER tSetplayer = { *_pStartpos};
	*_pPlayer = tSetplayer;
}

void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer)
{
	// 플레이어 움직임
	_pPlayer->tNewpos = _pPlayer->tpos;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--_pPlayer->tNewpos.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++_pPlayer->tNewpos.x;

}

void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer) {
	for (int y = 0; y < VERTICAL; y++) {
		for (int x = 0; x < HORIZON; x++) {
			if (_pPlayer->tpos.x == x && _pPlayer->tpos.y == y)
				cout << "ㅡㅡㅡ";
			else if (_cMaze[y][x] == '0') {
				//SetColor(15, 15);
					cout << " ";
			}
			else if (_cMaze[y][x] == '1') {
				//SetColor(15, 15);
				cout << "■";
			}
			else if (_cMaze[y][x] == '2') {
				//SetColor(9, 9);
				cout << "▤"; 
			}
			else if (_cMaze[y][x] == '3') {
				//SetColor(15, 15);
				cout << "⊙";
			}
			
		}
		cout << endl;
	}
}