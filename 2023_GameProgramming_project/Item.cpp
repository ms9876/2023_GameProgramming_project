#include "Item.h"
#include "console.h"

void ItemInit(Item& item)
{
    item.x = 0.0f;
    item.y = 0.0f;
    item.active = false;
}

void ItemUpdate(Item& item, char _cMaze[VERTICAL][HORIZON])
{
    if (item.active)
    {
        item.y += 1.0f; // 아이템 이동

        if (item.y >= VERTICAL - 1)
        {
            item.active = false;
        }
    }
}
