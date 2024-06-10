#pragma once
#include <supermod/pch.hpp>

namespace sm
{
struct vector3
{
    float x;
    float y;
    float z;

    vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

    [[nodiscard]] std::string to_string() { return std::format("Vector3<{}, {}, {}>", x, y, z); }
};

struct vector2
{
    float x;
    float y;

    vector2(const float x, const float y) : x(x), y(y) {}

    [[nodiscard]] std::string to_string() { return std::format("Vector2<{}, {}>", x, y); }
};

struct vector2i
{
    int x;
    int y;
};

struct vector2ui
{
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

    rect(const float left, const float top, const float right, const float bottom)
        : left(left),
          top(top),
          right(right),
          bottom(bottom)
    {
    }

    [[nodiscard]] std::string to_string() { return std::format("Rect<{}, {}, {}, {}>", left, top, right, bottom); }
};

struct rgba
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    rgba(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) : r(r), g(g), b(b), a(a) {}

    [[nodiscard]] std::string to_string() { return std::format("RGBA<{}, {}, {}, {}>", r, g, b, a); }
};

struct VertexInfo
{
    vector3 pos;
    rgba color;
    float uv;
    float uw;
};

enum textDrawType : int
{
    fastToTop,
    slowToFront,
    fastToUpperRightCorner,
    fastToUpperCenter,
    slowToDown
};

struct Command
{
    std::string cmd;
    std::vector<std::string> args;
    std::string rawArgs;
};
} // namespace sm