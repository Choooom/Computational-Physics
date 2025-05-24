#pragma once
#include <string>
#include <vector>

class Motion {
public:
    Motion();
    void runMotion();

private:
    void similar();
    void opposite();
    void fma();
};
