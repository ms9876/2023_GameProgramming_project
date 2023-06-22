#include<iostream>
#include<fstream>
#include<vector>
#include<Windows.h>
#include <algorithm>
#include"GameLogic.h"
#include"console.h"
#include "Ball.h"

using namespace std;

void Init(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer, PPOS _pStartpos)
{
	system("mode con cols=100 lines=350");
	strcpy_s(_cMaze[0],  "1111111111111111111111111111");
	strcpy_s(_cMaze[1],  "5222222222222222222222322225");
	strcpy_s(_cMaze[2],  "5222223222220000222222222225");
	strcpy_s(_cMaze[3],  "5222220000000000000002222225");
	strcpy_s(_cMaze[4],  "5200000000000000000000000025");
	strcpy_s(_cMaze[5],  "5000000000000000000000000005");
	strcpy_s(_cMaze[6],  "5222222222232222222222222225");
	strcpy_s(_cMaze[7],  "5223222222222222222222322225");
	strcpy_s(_cMaze[8],  "5000000000000000000000000005");
	strcpy_s(_cMaze[9],  "5200000000000000000000000025");
	strcpy_s(_cMaze[10], "5222230000000000000002223225");
	strcpy_s(_cMaze[11], "5222222222220000222222222225");
	strcpy_s(_cMaze[12], "5000000000000000000000000005");
	strcpy_s(_cMaze[13], "5000000000000000000000000005");
	strcpy_s(_cMaze[14], "5000000000000000000000000005");
	strcpy_s(_cMaze[15], "5000000000000000000000000005");
	strcpy_s(_cMaze[16], "5000000000000000000000000005");
	strcpy_s(_cMaze[17], "5000000000000000000000000005");
	strcpy_s(_cMaze[18], "5000000000000000000000000005");
	strcpy_s(_cMaze[19], "5000000000000000000000000005");
	strcpy_s(_cMaze[20], "5000000000000000000000000005");
	strcpy_s(_cMaze[21], "5000000000000000000000000005");
	strcpy_s(_cMaze[22], "5000000000000000000000000005");
	strcpy_s(_cMaze[23], "5000000000000000000000000005");
	strcpy_s(_cMaze[24], "5000000000000000000000000005");
	strcpy_s(_cMaze[25], "50000000000000000000000005");
	strcpy_s(_cMaze[26], "5444444444444444444444444445");
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

	/*if (ball.y == _pBar->tpos.y - 1 && ball.x >= _pBar->tpos.x && ball.x < _pBar->tpos.x + _pBar->tpos.width) {
		ball.dirY = -ball.dirY;
	}*/

	_pPlayer->tNewpos.x = std::clamp(_pPlayer->tNewpos.x, 0, HORIZON - 2);

	if (_cMaze[_pPlayer->tNewpos.y][_pPlayer->tNewpos.x] != '1')
	{
		_pPlayer->tpos = _pPlayer->tNewpos;
	}


}

void Render(char _cMaze[VERTICAL][HORIZON], PBAR _pBar, PBallPos _pBall) {
	for (int y = 0; y < VERTICAL; y++) {
		for (int x = 0; x < HORIZON; x++) {
			if (_pBar->tpos.x == x && _pBar->tpos.y == y) {
				SetColor(15, 8);
				cout << "ㅡㅡㅡ";
				continue;
			}
			if (_pBall->x == x && _pBall->y == y)
			{
				cout << " O";
				continue;
			}
			// 볼을 찍어주면 되는데.
			if (_cMaze[y][x] == '0') {
				SetColor(15, 0);
				cout << "  ";
			}
			else if (_cMaze[y][x] == '1' || _cMaze[y][x] == '4' || _cMaze[y][x] == '5') {
				SetColor(15, 0);
				cout << "■";
			}
			else if (_cMaze[y][x] == '2' || _cMaze[y][x] == '3') {
				SetColor(6, 15);
				cout << "▤";
			}

		}
		cout << endl;
	}

	cout << "스페이스 바를 누르면 시작!" << endl;
}

void Stage02(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer, PPOS _pStartpos)
{
	system("mode con cols=100 lines=350");
	strcpy_s(_cMaze[0],  "1111111111111111111111111111");
	strcpy_s(_cMaze[1],  "1002222222222222222222200221");
	strcpy_s(_cMaze[2],  "1200222222222222222222000021");
	strcpy_s(_cMaze[3],  "1220022222222222222220022001");
	strcpy_s(_cMaze[4],  "1222002223222222222200222201");
	strcpy_s(_cMaze[5],  "1222200222222223222002222221");
	strcpy_s(_cMaze[6],  "1222220022222222220022222221");
	strcpy_s(_cMaze[7],  "1222222002222222200222222221");
	strcpy_s(_cMaze[8],  "1222322200222222002223222221");
	strcpy_s(_cMaze[9],  "1222222220022220022222222221");
	strcpy_s(_cMaze[10], "1222222222002200222222222221");
	strcpy_s(_cMaze[11], "1222222222200002222222232221");
	strcpy_s(_cMaze[12], "1222222232200002222222222221");
	strcpy_s(_cMaze[13], "1222222222220022222232222221");
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
	strcpy_s(_cMaze[26], "1444444444444444444444444441");
	_pStartpos->x = 13;
	_pStartpos->y = 25;

	BAR tSetplayer = { *_pStartpos };
	*_pPlayer = tSetplayer;
	srand((unsigned int)time(NULL));
}

void Stage03(char _cMaze[VERTICAL][HORIZON], PBAR _pPlayer, PPOS _pStartpos)
{
	system("mode con cols=100 lines=350");
	strcpy_s(_cMaze[0],  "1111111111111111111111111111");
	strcpy_s(_cMaze[1],  "1222222222222322222222222221");
	strcpy_s(_cMaze[2],  "1000000000000000000000000001");
	strcpy_s(_cMaze[3],  "1002222222222222222232222221");
	strcpy_s(_cMaze[4],  "1002322222222222222222222221");
	strcpy_s(_cMaze[5],  "1000000000000000000000000001");
	strcpy_s(_cMaze[6],  "1000000000000000000000000001");
	strcpy_s(_cMaze[7],  "1222222222222222232222222001");
	strcpy_s(_cMaze[8],  "1222222222222222222232222001");
	strcpy_s(_cMaze[9],  "1000000000000000000000000001");
	strcpy_s(_cMaze[10], "1000000000000000000000000001");
	strcpy_s(_cMaze[11], "1002232222222222222222222221");
	strcpy_s(_cMaze[12], "1002222222222222223222222221");
	strcpy_s(_cMaze[13], "1000000000000000000000000001");
	strcpy_s(_cMaze[14], "1000000000000000000000000001");
	strcpy_s(_cMaze[15], "1002222222222002222322222001");
	strcpy_s(_cMaze[16], "1002222222222002222222222001");
	strcpy_s(_cMaze[17], "1222222222222222222223222221");
	strcpy_s(_cMaze[18], "1222322222222222222222222221");
	strcpy_s(_cMaze[19], "1000000000000000000000000001");
	strcpy_s(_cMaze[20], "1000000000000000000000000001");
	strcpy_s(_cMaze[21], "1000000000000000000000000001");
	strcpy_s(_cMaze[22], "1000000000000000000000000001");
	strcpy_s(_cMaze[23], "1000000000000000000000000001");
	strcpy_s(_cMaze[24], "1000000000000000000000000001");
	strcpy_s(_cMaze[25], "10000000000000000000000001");
	strcpy_s(_cMaze[26], "1444444444444444444444444441");
	_pStartpos->x = 13;
	_pStartpos->y = 25;

	BAR tSetplayer = { *_pStartpos };
	*_pPlayer = tSetplayer;
	srand((unsigned int)time(NULL));
}
