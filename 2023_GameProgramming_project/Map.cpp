#include <iostream>
#include <fstream>
#include "GameLogic.h"

using namespace std;

void LoadMap(const string& filename, int map[VERTICAL][HORIZON]) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open map file: " << filename << endl;
        return;
    }

    for (int y = 0; y < VERTICAL; y++) {
        for (int x = 0; x < HORIZON; x++) {
            file >> map[y][x];
        }
    }

    file.close();
}

void RenderMap(const int map[VERTICAL][HORIZON]) {
    for (int y = 0; y < VERTICAL; y++) {
        for (int x = 0; x < HORIZON; x++) {
            switch (map[y][x]) {
            case 0:  // 빈 공간
                cout << ' ';
                break;
            case 1:  // 벽
                cout << '#';
                break;
            case 2:  // 깨져야 되는 블록
                cout << 'X';
                break;
            case 3:  // 아이템
                cout << 'O';
                break;
            default:
                cout << '?';
                break;
            }
        }
        cout << endl;
    }
}
