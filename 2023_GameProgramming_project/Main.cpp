#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#include"StartScene.h"
#include"console.h"
#include "GameLogic.h"
#include "Ball.h"

using namespace std;

int main() {
	char cMaze[VERTICAL][HORIZON] = {};
	PLAYER tPlayer = {};
	POS tStartpos = {};
	Ball ball{};
	Init(cMaze, &tPlayer, &tStartpos);	

	while (true)
	{
		system("cls");
		GameTitle();
		int iMenu = MenuDraw();
		if (iMenu == 0)
			break;
		else if (iMenu == 1)
		{
			// 게임 종료.
			cout << "게임을 종료합니다." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}

	system("cls");
	Render(cMaze, &tPlayer);
	while (true)
	{
		Gotoxy(0, 0);
		Update(cMaze, &tPlayer);
		Sleep(1000);

		BallInit(ball);
		BallUpdate(ball);
		BallUpdate(ball);
	}

}
