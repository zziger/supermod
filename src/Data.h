#pragma once
#include <vector>
#include <string>

struct vector3 {
    float x;
    float y;
    float z;
};

struct vector2 {
    float x;
    float y;
};

struct vector2i {
    int x;
    int y;
};

struct vector2ui {
    uint32_t x;
    uint32_t y;
};

struct vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct matrix4x4
{
    vector4 row1;
    vector4 row2;
    vector4 row3;
    vector4 row4;
};

struct rect
{
    float left;
    float top;
    float right;
    float bottom;
};

struct rgba {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

struct VertexInfo {
    vector3 pos;
    rgba color;
    float uv;
    float uw;
};

enum textDrawType : int {
    fastToTop,
    slowToFront,
    fastToUpperRightCorner,
    fastToUpperCenter,
    slowToDown
};

struct Command {
    std::string cmd;
    std::vector<std::string> args;
    std::string rawArgs;
};