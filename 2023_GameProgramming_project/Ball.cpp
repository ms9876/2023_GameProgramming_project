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

int BallUpdate(Ball& ball, char _cMaze[VERTICAL][HORIZON], Item& item)
{
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        ball.go = true; 
    }
    if (!ball.go)
        return 0;
    else {
        ball.x += ball.dirX;
        ball.y += ball.dirY;

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

            if (item.active)
            {
                item.y += 1.0f; // ������ �̵�

                if (item.y >= VERTICAL - 1)
                {
                    item.active = false;
                }
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
        else if (_cMaze[y][x] == '4') {
            //int gameover = 
            PlaySound(TEXT("Gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
            GameOver();

            Sleep(1500);
            return 1;

        }
#pragma endregion

    }
}

int StageClear()
{
    system("cls");
    PlaySound(TEXT("Gameclear.wav"), NULL, SND_FILENAME | SND_ASYNC);
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

	SetColor(15, 0);
	return 1;
}

void GameOver()
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
                 
   /* int x = 35;
    int y = 12;
    int num;
    SetColor(4, 15);
    Gotoxy(x, y);
    cout << "�ٽ� �����ϱ� : 1 ";
    Gotoxy(x, y + 1);
    cout << "    ������ : 2   ";
    Gotoxy(x, y + 2);
    cout << "�Է� : ";
    cin >> num;

    if (num == 1) {
        return 1;
    }
    
    return num;*/
}
