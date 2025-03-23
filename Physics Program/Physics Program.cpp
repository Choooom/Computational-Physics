// Lab_Activity_2(Ilaida).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

#include "ConsoleUtils.h"
#include "Vectors.h"
#include "Kinematics.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#ifdef max
#undef max
#endif

using namespace std;

int main()
{
    setTerminalSize(110, 50);

    setCursorPosition(10, 1);
    for (int i = 0; i < 100; i++) {
        cout << BLUE "=";
    }

    setCursorPosition(45, 2);
    cout << GREEN "Our Lady of Fatima University" RESET;
    setCursorPosition(10, 3);
    for (int i = 0; i < 100; i++) {
        cout << BLUE "=" RESET;
    }
    setCursorPosition(19, 4);
    cout << YELLOW "VISION        " BLUE " |" RESET;

    setCursorPosition(10, 6);
    cout << GREEN "  A premiere  inclusive" BLUE " |" GREEN "\n          university   of  choice" BLUE " |" GREEN "\n          aspiring to improve man" BLUE " |" GREEN "\n          as  man  by  developing" BLUE " |" GREEN "\n          individuals  through  a" BLUE " |" GREEN "\n          legacy    of  excellent" BLUE " |" GREEN "\n          education           and" BLUE " |" GREEN "\n          compassionate     value" BLUE " |" GREEN "\n          formation.              " BLUE "|" RESET;
    setCursorPosition(34, 15); cout << BLUE "|";
    setCursorPosition(34, 16); cout << BLUE "|";
    setCursorPosition(34, 17); cout << BLUE "|";
    setCursorPosition(34, 18); cout << BLUE "|";
    setCursorPosition(34, 5); cout << BLUE "|" RESET;
    setCursorPosition(34, 6); cout << BLUE "|" RESET;
    setCursorPosition(84, 4);
    cout << BLUE "|" YELLOW "         MISSION" RESET;
    setCursorPosition(84, 5); cout << BLUE "|";
    setCursorPosition(84, 6);
    cout << BLUE "|" GREEN " The Our  Lady of Fatima";
    setCursorPosition(84, 7);
    cout << BLUE "|" GREEN " University,    together";
    setCursorPosition(84, 8);
    cout << BLUE "|" GREEN " with   Fatima   Medical";
    setCursorPosition(84, 9);
    cout << BLUE "|" GREEN " Science      Foundation";
    setCursorPosition(84, 10);
    cout << BLUE "|" GREEN " Inc.,  is dedicated  to";
    setCursorPosition(84, 11);
    cout << BLUE "|" GREEN " the  improvement of man";
    setCursorPosition(84, 12);
    cout << BLUE "|" GREEN " as  man    through  the";
    setCursorPosition(84, 13);
    cout << BLUE "|" GREEN " holistic  formation  of";
    setCursorPosition(84, 14);
    cout << BLUE "|" GREEN " individuals imbued with";
    setCursorPosition(84, 15);
    cout << BLUE "|" GREEN " knowledge,  skills  and";
    setCursorPosition(84, 16);
    cout << BLUE "|" GREEN " virtues.";
    setCursorPosition(84, 17);
    cout << BLUE "|";
    setCursorPosition(84, 18);
    cout << "|" RESET;
    setCursorPosition(52, 4);

    setCursorPosition(10, 19);
    for (int i = 0; i < 100; i++) {
        cout << BLUE "=" RESET;
    }

    for (int i = 1; i <= 19; i++) {
        setCursorPosition(9, i);
        cout << BLUE "|";
    }

    for (int i = 1; i <= 19; i++) {
        setCursorPosition(109, i);
        cout << BLUE "|" << RESET;
    }

    setCursorPosition(43, 7);
    cout << YELLOW << "WELCOME TO ILAIDA's COPH PROGRAM" << RESET;

    setCursorPosition(36, 12);
    cout << GREEN << "Press any key continue..." << RESET;

    cin.get();

    bool isExit = false;

    clearScreen();

    while (!isExit) {
        clearScreen();

        vector<string> arr = {"Lab 1: Measurements", "Lab 2: Vectors", "Lab 3: Kinematics"};

        string topic;

        for (int i = 0; i <= arr.size(); i++) {
            if (i == arr.size()) {
                setCursorPosition(40, 8 + i);
                cout << RED << "EXIT";
                continue;
            }
            setCursorPosition(40, 6+i);
            cout << YELLOW << arr[i] << RESET;
        }

        setCursorPosition(36, 15);
        cout << YELLOW << "Choose which topic to go into: " << GREEN;
        getline(cin, topic);

        transform(topic.begin(), topic.end(), topic.begin(), ::tolower);

        vector<string> lab1 = {"lab1", "lab 1", "laboratory1", "laboratory 1", "measurement", "measurements", "lab1: measurement", "lab 1: measurement", "laboratory1: measurements", "laboratory 1: measurements"};
        vector<string> lab2 = { "lab2", "lab 2", "laboratory2", "laboratory 2", "vector", "vectors", "lab2: vector", "lab 2: vectors", "laboratory 2: vector", "laboratory 2: vectors" };
        vector<string> lab3 = { "lab3", "lab 3", "laboratory3", "laboratory 3", "kinematic", "kinematics", "lab3: kinematic", "lab 3: kinematics", "laboratory 3: kinematic", "laboratory 3: kinematics" };

        if (find(lab1.begin(), lab1.end(), topic) != lab1.end()) {
            clearScreen();

            setCursorPosition(35, 7);
            cout << GREEN << "Laboratory 1: Measurement";
            cin.get();
        }
        else if (find(lab2.begin(), lab2.end(), topic) != lab2.end()) {
            clearScreen();

            Vectors vectorCalculator;

            vectorCalculator.runVectorsCalculator();

        }
        else if (find(lab3.begin(), lab3.end(), topic) != lab3.end()) {
            clearScreen();

            Kinematics kinematicsCalc;

            kinematicsCalc.runKinematics();
            
        }
        else if (topic == "exit") {
            isExit = true;
            
            clearScreen();

            setCursorPosition(54, 9);
            cout << RED << "GAME OVER..." RESET;

        }
        else {
            setCursorPosition(35, 15);
            cout << RED << "Incorrect input. Please try again.";
            cin.get();
        }
    }


    setCursorPosition(0, 20);
}
