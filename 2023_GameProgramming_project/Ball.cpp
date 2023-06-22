#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <conio.h>
#include "console.h"
#include "GameLogic.h"
#include "Ball.h"

using namespace std;

BAR bar = { {13,25} };

void BallInit(Ball& ball)
{
    ball.x = bar.tpos.x;
    ball.y = bar.tpos.y - 1; 
    ball.dirX = 1.f;
    ball.dirY = -1.f; 
    ball.go = false;
}

void BallUpdate(Ball& ball, char _cMaze[VERTICAL][HORIZON])
{

    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        ball.go = true;

    if (!ball.go)
        return;
    else {
        ball.x += ball.dirX;
        ball.y += ball.dirY;

        float nextX = ball.x + ball.dirX;
        float nextY = ball.y + ball.dirY;

        // ������ �浹 ����
        bool wallCollision = false;

        if (nextX < 0 || nextX >= HORIZON)
        {
            ball.dirX = -ball.dirX;
            wallCollision = true;
        }

        if (nextY < 0 || nextY >= VERTICAL)
        {
            ball.dirY = -ball.dirY;
            wallCollision = true;
        }

        if (!wallCollision)
        {
            // ���� ��ġ�� ��ȿ�� ������ ������� Ȯ���ϰ� clamp ó��
            nextX = std::clamp(nextX, 0.f, static_cast<float>(HORIZON - 1));
            nextY = std::clamp(nextY, 0.f, static_cast<float>(VERTICAL - 1));
        }

        int x = static_cast<int>(nextX);
        int y = static_cast<int>(nextY);


        if (_cMaze[y][x] == '1' || _cMaze[y][x] == '2' || _cMaze[y][x] == '3' || _cMaze[y][x] == '5') { // �������

            if (_cMaze[y][x] == '5')
            {
                ball.dirX = -ball.dirX;
                ball.dirY = ball.dirY;                  
            }
            else if (_cMaze[y][x] == '1' || _cMaze[y][x] == '4' || _cMaze[y][x] == '2' || _cMaze[y][x] == '3')
            {
                ball.dirX = ball.dirX;
                ball.dirY = -ball.dirY;
            }

            if (_cMaze[y][x] == '2' || _cMaze[y][x] == '3')
                _cMaze[y][x] = '0';

        }
        /* else if (_cMaze[y][x] == '4') {
             int gameover = GameOver();

             if (gameover == 1)
                 return;

         }*/
    }
}

int StageClear()
{
    system("cls");

	SetColor(14, 0);
	wcout << L"      ______   __        ________   ______   _______   	  " << endl;
	wcout << L"     /      \ /  |      /        | /      \  /       \ 	  " << endl;
	wcout << L"    /$$$$$$  |$$ |      $$$$$$$$/ /$$$$$$  | $$$$$$$  |	  " << endl;
	SetColor(6, 0);
	wcout << L"    $$ |  $$/ $$ |      $$ |__    $$ |__$$ | $$ |__$$ |	  " << endl;
	wcout << L"    $$ |      $$ |      $$    |   $$    $$ | $$    $$< 	  " << endl;
	wcout << L"    $$ |   __ $$ |      $$$$$/    $$$$$$$$ | $$$$$$$  |	  " << endl;
	SetColor(14, 0);
	wcout << L"    $$ \__/  | $$ |_____ $$ |_____ $$ |  $$ | $$ |  $$ |	  " << endl;
	wcout << L"    $$    $$/ $$       |$$       |$$ |  $$ | $$ |  $$ |	  " << endl;
	wcout << L"     $$$$$$/  $$$$$$$$/ $$$$$$$$/ $$/   $$/  $$/   $$/ 	  " << endl;
	SetColor(0, 15);

	int x = 10;
	int y = 12;
	int num;

	Gotoxy(x, y);
	cout << "���� ���������� ���ðڽ��ϱ�? (YSE = 1 /NO = 2) : ";
	cin >> num;
	SetColor(15, 0);
	return num;
}

int GameOver()
{
    system("cls");

    SetColor(4, 0);
    wcout << L"    ______      ______    __       __  ________     ______    __     __   ________   _______    " << endl;
    wcout << L"   /      \    /      \  /  \     /  | /        |  /      \  /  |   /  | /        | /       \   " << endl;
    wcout << L"  /$$$$$$    |/$$$$$$   |$$  \   /$$ | $$$$$$$$/  /$$$$$$  | $$ |   $$ | $$$$$$$$/  $$$$$$$  |  " << endl;
    wcout << L"  $$ | _$$/  $$ |__$$  |$$$  \ /$$$ |  $$ |__     $$ |  $$ | $$ |   $$ | $$ |__     $$ |__$$ |  " << endl;
    wcout << L"  $$ |/     |$$    $$  |$$$$  /$$$$ | $$    |    $$ |  $$ | $$  \  /$$/  $$    |    $$    $$<   " << endl;
    wcout << L"  $$ |$$$$  |$$$$$$$$  |$$ $$ $$/$$ | $$$$$/     $$ |  $$ |  $$  /$$/   $$$$$/     $$$$$$$  |  " << endl;
    wcout << L"  $$ \__$$   |$$ |  $$  |$$ |$$$/ $$ | $$ |_____  $$ \_ _$$ |   $$ $$/    $$ |_____  $$ |  $$ |  " << endl;
    wcout << L"  $$    $$/  $$ |  $$  |$$ | $/  $$ | $$       | $$    $$/     $$$/     $$       | $$ |  $$ |  " << endl;
    wcout << L"   $$$$$$/   $$/   $$/  $$/      $$/  $$$$$$$$/   $$$$$$/       $/      $$$$$$$$/  $$/   $$/   " << endl;                                                                             
                 
    int num;

    cout << "�ٽ� �����Ϸ��� 1�� ��������!";

    cin >> num;

    if (num == 1) {
        return 1;
    }
    
    return num;
}
