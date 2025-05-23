#include "Newton.h"          
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

Newton::Newton() {

};

void Newton::runNewton() {

    while (true) {
        setCursorPosition(52, 4);
        cout << RED "APPARENT WEIGHT" RESET;

        vector<string> arr = { "1.) Same Direction", "2.) Different Direction"};
        string choice;


        for (int i = 0; i < arr.size(); i++) {
            setCursorPosition(38, 8 + i);
            cout << YELLOW << arr[i] << RESET;
        }

        setCursorPosition(38, 15);
        cout << YELLOW "Choose from the list above: " GREEN;
        getline(cin, choice);
        cout << RESET;

        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "1" || choice == "similar") {
            clearScreen();

            Similar();
        }
        else if (choice == "2" || choice == "different") {
            clearScreen();

            Different();
        }
        else if (choice == "exit") {
            clearScreen();
            break;
        }
        else {
            setCursorPosition(35, 16);
            cout << RED "Invalid input. Please enter a valid number." << endl;
            cin.get();
            clearScreen();
        }
    }

}

void Newton::Similar() {
    bool stop = false;
    while (!stop) {
        double weight, acceleration, newton;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Similar Direction", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter Weight(N): " GREEN;
            cin >> newton;
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
            setCursorPosition(35, 11);
            cout << YELLOW "Enter acceleration: " GREEN;
            cin >> acceleration;
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

        weight = ((newton / 9.81) * acceleration) + newton;

        setCursorPosition(35, 13);
        cout << YELLOW "Weight = " << GREEN << weight << "N" RESET;

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        setCursorPosition(35, 18);
        cout << "                                     ";

        clearScreen();

        stop = true;
    }
}

void Newton::Different(){
    bool stop = false;
    while (!stop) {
        double weight, acceleration, newton;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Different Direction", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter Weight(N): " GREEN;
            cin >> newton;
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
            setCursorPosition(35, 11);
            cout << YELLOW "Enter acceleration: " GREEN;
            cin >> acceleration;
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

        weight = ((newton / 9.81) * (-1 * acceleration)) + newton;

        setCursorPosition(35, 13);
        cout << YELLOW "Weight = " << GREEN << weight << "N" RESET;

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        setCursorPosition(35, 18);
        cout << "                                     ";

        clearScreen();

        stop = true;
    }
}