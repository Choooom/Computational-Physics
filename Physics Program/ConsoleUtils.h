#pragma once
#include <windows.h>
#include <string> 

void setCursorPosition(int x, int y);
void setTerminalSize(int width, int height);
void clearScreen();
void printCentered(const std::string& text, int y, int consoleWidth = 85, int xStart = 36);

#pragma once
