#include "ConsoleUtils.h"

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, pos);
}

void setTerminalSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void clearScreen() {
    for (int i = 4; i <= 18; i++) {
        for (int j = 35; j <= 83; j++) {
            setCursorPosition(j, i);
            cout << " ";
        }
    }
}

void printCentered(const std::string& text, int y, int consoleWidth, int xStart) {
    int printableWidth = consoleWidth - xStart;
    int textLength = static_cast<int>(text.length());
    int xPosition = xStart + (printableWidth - textLength) / 2;

    setCursorPosition(xPosition, y);
    std::cout << text;
}
