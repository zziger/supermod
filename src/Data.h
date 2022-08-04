#pragma once

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