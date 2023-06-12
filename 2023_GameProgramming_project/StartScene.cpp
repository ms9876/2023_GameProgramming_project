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

void GameInfo()
{
	system("cls");
	cout << endl << endl;
	cout << "조작법" << endl;
	cout << "메뉴 선택 : 스페이스바" << endl;
	cout << "바 이동 : 방향키" << endl;

}

int MenuDraw()
{
	int x = 40;
	int y = 21;
	Gotoxy(x, y);
	cout << "게임 시작" << endl;
	Gotoxy(x, y + 1);
	cout << "게임 정보" << endl;
	Gotoxy(x, y + 2);
	cout << "종료 하기";

	while (true)
	{
		int ikey = KeyController();
		switch (ikey)
		{
		case (int)KEY::UP: {
			if (y > 12) { // y는 13~14만 가능 
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
			}
		}
						 break;
		case (int)KEY::DOWN: {
			if (y < 14) { // y는 13~14만 가능 
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
			}
		}
						   break;
		case (int)KEY::SPACEBAR: {
			return y - 12;
		}
							   break;
		default:
			break;
		}
	}
	return 0;
}
