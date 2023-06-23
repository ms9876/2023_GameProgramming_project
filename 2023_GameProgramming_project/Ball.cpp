#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <conio.h>
#include <mmsystem.h>
#include "console.h"
#include "GameLogic.h"
#include "Ball.h"
#pragma comment(lib, "winmm.lib")


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

void BallUpdate(Ball& ball, char _cMaze[VERTICAL][HORIZON], Item& item)
{

    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        ball.go = true;

    if (!ball.go)
        return;
    else {
        ball.x += ball.dirX;
        ball.y += ball.dirY;

        // �밢�� �̵� �� ���� 2�� �ִ� ��� ó�� - �̰͵� �� �ǳ�
        if (ball.dirX != 0 && ball.dirY != 0)
        {
            int nextX = static_cast<int>(ball.x + ball.dirX);
            int nextY = static_cast<int>(ball.y + ball.dirY); 
            int sideX = static_cast<int>(ball.x + ball.dirX); 

            if (_cMaze[nextY][nextX] == '0' && _cMaze[nextY][sideX] == '2')
            {
                _cMaze[nextY][sideX] = '0'; 
                ball.y -= ball.dirY; 
            }
        }

        // ���� 3�� ����� �� ������ ����
        if (_cMaze[static_cast<int>(ball.y)][static_cast<int>(ball.x)] == '3')
        {
            bool _item = (_cMaze[static_cast<int>(ball.y) + 1][static_cast<int>(ball.x)] != '2');

            if (!_item)
            {
                item.x = ball.x;
                item.y = ball.y + 1;
                item.active = true;
            }
        }

#pragma region �� ������ �� ������ �ϴ� �ڵ�
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

        if (ball.y == bar.tpos.y && ball.x >= bar.tpos.x && ball.x < bar.tpos.x + bar.tpos.width)
        {
            // Reverse the ball's direction vertically
            ball.dirY = -ball.dirY;
        }

        if (!wallCollision)
        {
            nextX = std::clamp(nextX, 0.f, static_cast<float>(HORIZON - 2));
            nextY = std::clamp(nextY, 0.f, static_cast<float>(VERTICAL - 2));
        }
#pragma endregion

#pragma region �浹üũ
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

            if (_cMaze[y][x] == '2' || _cMaze[y][x] == '3') {
                

                PlaySound(TEXT("collider.wav"), NULL, SND_FILENAME | SND_ASYNC);
                SetColor(15, 0);
                _cMaze[y][x] = '0';
            }
        }
        /*else if (_cMaze[y][x] == '4') {
            int gameover = GameOver();

            if (gameover == 1)
                return;

        }*/
#pragma endregion

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
