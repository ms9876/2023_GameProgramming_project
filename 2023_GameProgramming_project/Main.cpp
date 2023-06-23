#include<iostream>
#include<Windows.h>
#include"StartScene.h"
#include"console.h"
#include "GameLogic.h"
#include "Ball.h"
#include "Item.h"

using namespace std;

int main() {
	char cMaze[VERTICAL][HORIZON] = {};
	BAR tPlayer = {};
	POS tStartpos = {};
	Ball ball{};
	PBALL tball = {}; 
	Item tItem = {};

	Init(cMaze, &tPlayer, &tStartpos);
	BallInit(ball);
	while (true)
	{
		system("cls");
		GameTitle();
		int iMenu = MenuDraw();
		if (iMenu == 1)
			break;
		else if (iMenu == 2)
		{
			// 게임 종료.
			cout << "게임을 종료합니다... 다음에 또 만나요ㅜㅜ" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}

	system("cls");
	while (true)
	{
		Gotoxy(0, 0);
		BallUpdate(ball, cMaze, tItem);
		Update(cMaze, &tPlayer, ball, tPlayer);
		ItemUpdate(tItem, cMaze);

		Render(cMaze, &tPlayer, &ball, tItem);
		Sleep(100);
	}
} 