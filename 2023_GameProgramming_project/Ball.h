#pragma once
struct Ball
{
    float x;
    float y;
    float dirX;
    float dirY;
    bool go;
};

struct BallVector
{
    float x;
    float y;
};

void BallInit(Ball& ball);
void BallUpdate(Ball& ball);
void BallRender(const Ball& ball);

float dotProduct(const BallVector& v1, const BallVector& v2);
BallVector subtract(const BallVector& v1, const BallVector& v2);
float length(const BallVector& v);
BallVector normalize(const BallVector& v);
float calculateReflectionAngle(const BallVector &surfaceNormal, const BallVector& incidentVector);