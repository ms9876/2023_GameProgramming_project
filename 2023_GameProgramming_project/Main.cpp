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

	CursorSet(false, 0);

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
				// ���� ����.
				cout << "������ �����մϴ�... ������ �� ������̤�" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << '\r' << 3 - i << "...";
					Sleep(1000);
				}
				return 0;
			}
		}

		while (true)
		{
			cout << "stage1 : 1 " << endl;
			cout << "stage1 : 2 " << endl;
			cout << "stage1 : 3 " << endl;
			cout << "���ϴ� ���������� �Է��ϼ���  : ";


			int stageSelect;
			cin >> stageSelect;

			if (stageSelect == 1) {
				Init(cMaze, &tPlayer, &tStartpos);
				break;
			}
			else if (stageSelect == 2) {
				Stage02(cMaze, &tPlayer, &tStartpos);
				break;
			}
			else if (stageSelect == 3) {
				Stage03(cMaze, &tPlayer, &tStartpos);
				break;
			}
			else {
				cout << "�ٽ� �Է��ϼ���! : ";
			}
		}

		system("cls");
		int over;
		while (true)
		{
			Gotoxy(0, 0);
			over = BallUpdate(ball, cMaze, tItem);
			if (over == 1)
				break;
			Update(cMaze, &tPlayer, ball, tPlayer);
			ItemUpdate(tItem, cMaze);

			Render(cMaze, &tPlayer, &ball, tItem);

			Sleep(100);
		}
} 