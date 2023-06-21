	#include "console.h"
	#include <Windows.h>

	
	void FullScreen()
	{
		SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),
			CONSOLE_FULLSCREEN_MODE, NULL);
	}

	void Gotoxy(int x, int y)
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cur = { x,y };
		SetConsoleCursorPosition(hOut, cur);
	}

	BOOL Gotoxytest(int x, int y)
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cur = { x,y };
		return SetConsoleCursorPosition(hOut, cur);
	}

	void CursorSet(bool _bvis, DWORD _dwSize)
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO Curinfo;
		Curinfo.bVisible = _bvis;
		Curinfo.dwSize = _dwSize;
		SetConsoleCursorInfo(hOut, &Curinfo);
	}

	void SetColor(int _color, int _bgcolor)
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, _bgcolor << 4 | _color);
	}

	int GetColor()
	{
		CONSOLE_SCREEN_BUFFER_INFO info;

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hOut, &info);
		int color = info.wAttributes & 0xf;
		return color;
	}

	int GetbgColor()
	{
		CONSOLE_SCREEN_BUFFER_INFO info;

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hOut, &info);
		int color = (info.wAttributes & 0xf) >> 4;
		return color;
	}

	void fontsize(UINT _weight, UINT _sizex, UINT _sizey)
	{
		static CONSOLE_FONT_INFOEX font;
		font.cbSize = sizeof(font);
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetCurrentConsoleFontEx(hout, false, &font);
		font.FontWeight = _weight;
		font.dwFontSize.X = _sizex;
		font.dwFontSize.Y = _sizey;
		SetCurrentConsoleFontEx(hout, false, &font);
	}

