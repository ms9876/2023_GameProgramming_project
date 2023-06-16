#pragma once
#include<Windows.h>
#define SAFE_DELETE(p) if(p) {delete p; p= nullptr;}
#define STAGE_MAX_COUNT 3
#define MAP_X 50
#define MAP_Y 10
#define RENDER_MAP_X 20
#define RENDER_MAP_Y 6

enum class STAGE_TYPE
{
	EMPTY = '0',
	WALL = '1',
	BLOCK = '2',
	ITEM = '3',
	START = '4'
};

