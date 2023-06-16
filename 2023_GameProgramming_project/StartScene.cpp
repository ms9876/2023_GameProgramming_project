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
	wcout << L"  !  @  !,  .!  #  ;        .@@  *!  !!    @@@$!   #**@#@!!. !; ;  -#@*!;;. !!   " << endl;
	wcout << L" .@  @  @~  ~@  #  $        .@@  =@,.@@   ,@.        *@  #@. @; @       $@, @@   " << endl;
	wcout << L" ,@==@=#@-  *@*#@*@!        .@@$*@@~~@=   !@         @$  #@. @, @       $$  @@   " << endl;
	wcout << L" ~@  @  #,  @@  @  #        .@*  @@,,@~   $@        ;@.  #=. @$#@      .#=  @$   " << endl;
	wcout << L" ;@  @  #.  @@  @  #        .@:  @@@@@    #@        #@   #*  @, @      -@=  @!   " << endl;
	wcout << L" *@@@@!@$   @@@@@$@~        .@$$@#* .@    @@=$##$  .!!   @*. @, @      ~@*  @;   " << endl;
	wcout << L"  .$$ @~     !@  @                  ,@      ;@            ~, @, @        .  @~   " << endl;
	wcout << L"  *@# @=;.  .#@  @!-              :::$@;  !!#@*!!                                " << endl;
	wcout << L"  !*  -.    .!*  @                   .@;  !$,,.                                  " << endl;
	wcout << L"   *@@@$     -@@#@*                  ~@;   $#@@$.                                " << endl;
	wcout << L"  -@- ,@:    *#  *#.                 -*;   ~~~=@.                                " << endl;
	wcout << L"  -@  .#*    *#  !#.                       @@@@@.                                " << endl;
	wcout << L"  .##!*@     ~@*!#=                        @,  .~                                " << endl;
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
	cout << "1. 게임 시작" << endl;
	Gotoxy(x, y + 1);
	cout << "2. 종료 하기";

	while (true)
	{
		key = KeyController();

		if (key == 49)  // 1번을 누른 경우 (ASCII 코드 49는 '1'을 나타냄)
		{
			return 1;  // 게임 시작
		}
		else if (key == 50)  // 2번을 누른 경우 (ASCII 코드 50는 '2'를 나타냄)
		{
			return 2;  // 종료
		}
		else {
			break;
		}
	}

	return 0;
}
