#pragma once

struct vector3 {
    float x;
    float y;
    float z;
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