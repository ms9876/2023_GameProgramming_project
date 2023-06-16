#include <iostream>
#include <Windows.h>
#include "Ball.h"

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 24;


void BallInit(Ball& ball)
{
    ball.x = SCREEN_WIDTH / 2.f;
    ball.y = SCREEN_HEIGHT / 2.f;
    ball.dirX = 1.f;
    ball.dirY = 1.f;
    ball.go = false;


}

void BallUpdate(Ball& ball)
{
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        ball.go = true;

    if (!ball.go)
        return;
    else {
        ball.x += ball.dirX;
        ball.y += ball.dirY;

        if (ball.x <= 0 || ball.x >= SCREEN_WIDTH - 1)
            ball.dirX *= -1;
        if (ball.y <= 0 || ball.y >= SCREEN_HEIGHT - 1)
            ball.dirY *= -1;
    }
    
}

void BallRender(const Ball& ball)
{
    std::string screenBuffer;

    for (int y = 0; y < SCREEN_HEIGHT; ++y)
    {
        for (int x = 0; x < SCREEN_WIDTH; ++x)
        {
            if (x == static_cast<int>(ball.x) && y == static_cast<int>(ball.y))
                screenBuffer += "¤·";
            else
                screenBuffer += " ";
        }

        screenBuffer += "\n";
    }

    system("cls"); 

    std::cout << screenBuffer;
}

float dotProduct(const BallVector& v1, const BallVector& v2)
{
    return v1.x * v2.x + v1.y + v2.y;
}

BallVector subtract(const BallVector& v1, const BallVector& v2)
{
    BallVector bv;
    bv.x = v1.x - v2.x;
    bv.y = v1.y - v2.y;
    return bv;
}

float length(const BallVector& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

BallVector normalize(const BallVector& v)
{
    BallVector bv;
    float len = length(v);

    bv.x = v.x / len;
    bv.y = v.y / len;
    return bv;
}


float calculateReflectionAngle(const BallVector& surfaceNormal, const BallVector& incidentVector)
{
    float dot = dotProduct(surfaceNormal, incidentVector);
    float surfaceNormalLength = length(surfaceNormal);
    float incidentVectorLength = length(incidentVector);
    float cosTheta = dot / (surfaceNormalLength * incidentVectorLength);
    float reflectionAngle = 2 * std::acos(cosTheta);
    return reflectionAngle;
}

