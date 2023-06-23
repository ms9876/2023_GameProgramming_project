#pragma once
#include "define.h"

typedef struct Item
{
    float x;
    float y;
    bool active;
} Item;

// ������ �ʱ�ȭ
void ItemInit(Item& item);

void ItemUpdate(Item& item, char _cMaze[VERTICAL][HORIZON]);
void ItemRender(Item& item, char _cMaze[VERTICAL][HORIZON]);