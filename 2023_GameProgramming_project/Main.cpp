#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
#include"StartScene.h"
#include"console.h"

using namespace std;

int main() {
	while (true)
	{
		system("cls");
		GameTitle();
		int iMenu = MenuDraw();
		if (iMenu == 0)
			break;
		else if (iMenu == 1)
			GameInfo();
		else if (iMenu == 2)
		{
			// ���� ����.
			cout << "������ �����մϴ�." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;
		}
	}
}
