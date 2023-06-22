#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include "console.h"
#include "StartScene.h";
#include <Windows.h>

using namespace std;

void GameTitle()
{
	int icurmade = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << endl << endl << endl;
	SetColor(4, 0);
	wcout << L"  !  @  !,  .!  #  ;        .@@  *!  !!    @@@$!   #**@#@!!. !; ;  -#@*!;;. !!   " << endl;
	SetColor(12, 0);
	wcout << L" .@  @  @~  ~@  #  $        .@@  =@,.@@   ,@.        *@  #@. @; @       $@, @@   " << endl;
	SetColor(6, 0);
	wcout << L" ,@==@=#@-  *@*#@*@!        .@@$*@@~~@=   !@         @$  #@. @, @       $$  @@   " << endl;
	SetColor(14, 0);
	wcout << L" ~@  @  #,  @@  @  #        .@*  @@,,@~   $@        ;@.  #=. @$#@      .#=  @$   " << endl;
	SetColor(2, 0);
	wcout << L" ;@  @  #.  @@  @  #        .@:  @@@@@    #@        #@   #*  @, @      -@=  @!   " << endl;
	SetColor(10, 0);
	wcout << L" *@@@@!@$   @@@@@$@~        .@$$@#* .@    @@=$##$  .!!   @*. @, @      ~@*  @;   " << endl;
	SetColor(1, 0);
	wcout << L"  .$$ @~     !@  @                  ,@      ;@            ~, @, @        .  @~   " << endl;
	SetColor(11, 0);
	wcout << L"  *@# @=;.  .#@  @!-              :::$@;  !!#@*!!                                " << endl;
	SetColor(5, 0);
	wcout << L"  !*  -.    .!*  @                   .@;  !$,,.                                  " << endl;
	SetColor(12, 0);
	wcout << L"   *@@@$     -@@#@*                  ~@;   $#@@$.                                " << endl;
	SetColor(6, 0);
	wcout << L"  -@- ,@:    *#  *#.                 -*;   ~~~=@.                                " << endl;
	SetColor(14, 0);
	wcout << L"  -@  .#*    *#  !#.                       @@@@@.                                " << endl;
	SetColor(2, 0);
	wcout << L"  .##!*@     ~@*!#=                        @,  .~                                " << endl;
	SetColor(10, 0);
	wcout << L"    ##$,      ,##!                        ,######                                " << endl;
	wcout << endl << endl;
	_setmode(_fileno(stdout), _O_TEXT);
}

int KeyController()
{
	int ichk = _getch();
	if (ichk == 224) {
		ichk = _getch();

		switch (ichk)
		{
		case 75:
			break;
		case 77:
			break;
		default:
			break;
		}
	}
	return -1;
}

int MenuDraw()
{
	int key;
	int x = 35;
	int y = 21;
	Gotoxy(x, y);
	SetColor(0, 15);
	cout << "1. 게임 시작" << endl;
	Gotoxy(x, y + 1);
	cout << "2. 종료 하기";

	while (true)
	{
		Gotoxy(x, y + 3);
		SetColor(15, 0);
		cout << "입력 : ";
		cin >> key;

		if (key == 49)  // 1번을 누른 경우 (ASCII 코드 49는 '1'을 나타냄)
		{ 
			return 1;  // 게임 시작
		}
		else if (key == 50)  // 2번을 누른 경우 (ASCII 코드 50 = '2'를 나타냄)
		{
			return 2;  // 종료
		}
		else {
			break;
		}
	}

	return key;
}


