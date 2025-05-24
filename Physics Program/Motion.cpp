#include "Motion.h"          
#include "ConsoleUtils.h"     
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>              

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#ifdef max
#undef max
#endif

using namespace std;


Motion::Motion() {

}

void Motion::runMotion() {
    
    cout << RED; 
    printCentered("Law of Motion", 5);
    cout << YELLOW;

    while (true) {
        vector<string> arr = { "Similar", "Opposite", "F = ma" };
        string choice;

        for (int i = 0; i < arr.size(); i++) {
            setCursorPosition(38 + (i * 15), 7);
            cout << YELLOW << arr[i] << RESET;
        }

        setCursorPosition(36, 15);
        cout << YELLOW "Choose from the list above: " GREEN;
        getline(cin, choice);
        cout << RESET;

        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "similar") {
            clearScreen();

            similar();
        }
        else if (choice == "opposite") {
            clearScreen();      
            opposite();
        }
        else if (choice == "fma") {
            clearScreen();
            fma();
        }
        else if (choice == "exit") {
            clearScreen();

            break;
        }
    }
}

void Motion::similar() {
    bool stop = false;
    while (!stop) {
        clearScreen();
        double firstMovement, secondMovement;
        string measurement, direction;

        cout << RED;
        printCentered("Similar Direction", 5);
        cout << YELLOW;

        while (true) {
            setCursorPosition(35, 11);
            cout << YELLOW "Enter first movement: " GREEN;
            cin >> firstMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << RED "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cin.get();
                setCursorPosition(35, 16);
                cout << "                                            ";
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        while (true) {
            setCursorPosition(35, 12);
            cout << YELLOW "Enter second movement: " GREEN;
            cin >> secondMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << RED "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cin.get();
                setCursorPosition(35, 16);
                cout << "                                            ";
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        transform(direction.begin(), direction.end(), direction.begin(), ::toupper);

        setCursorPosition(35, 14);
        cout << YELLOW "Final force: " << GREEN << firstMovement + secondMovement << "N";

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        stop = true;
    }
}

void Motion::opposite() {
    bool stop = false;
    while (!stop) {
        clearScreen();
        double firstMovement, secondMovement;
        string measurement, direction;

        cout << RED;
        printCentered("Opposite Direction", 5);
        cout << YELLOW;

        while (true) {
            setCursorPosition(35, 11);
            cout << YELLOW "Enter first movement: " GREEN;
            cin >> firstMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << RED "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cin.get();
                setCursorPosition(35, 16);
                cout << "                                            ";
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        while (true) {
            setCursorPosition(35, 12);
            cout << YELLOW "Enter second movement: " GREEN;
            cin >> secondMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << RED "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cin.get();
                setCursorPosition(35, 16);
                cout << "                                            ";
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        transform(direction.begin(), direction.end(), direction.begin(), ::toupper);

        setCursorPosition(35, 14);
        cout << YELLOW "Final force: " << GREEN << firstMovement - secondMovement << "N";

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        stop = true;
    }
}

void Motion::fma() {
    bool stop = false;
    while (!stop) {
        clearScreen();
        double firstMovement, secondMovement;
        string measurement, direction;

        cout << RED;
        printCentered("F = ma", 5);
        cout << YELLOW;

        while (true) {
            setCursorPosition(35, 11);
            cout << YELLOW "Enter mass: " GREEN;
            cin >> firstMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << RED "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cin.get();
                setCursorPosition(35, 16);
                cout << "                                            ";
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        while (true) {
            setCursorPosition(35, 12);
            cout << YELLOW "Enter acceleration: " GREEN;
            cin >> secondMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << RED "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cin.get();
                setCursorPosition(35, 16);
                cout << "                                            ";
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        transform(direction.begin(), direction.end(), direction.begin(), ::toupper);

        setCursorPosition(35, 14);
        cout << YELLOW "Final force: " << GREEN << firstMovement * secondMovement << "N";

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        stop = true;
    }
}
