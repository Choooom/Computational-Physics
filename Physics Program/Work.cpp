#include "Work.h"          
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

Work::Work() {

};

void Work::runWork() {

    while (true) {
        setCursorPosition(52, 4);
        cout << RED "WORK" RESET;

        vector<string> arr = { "1.) Work", "2.) Distance", "3.) Work with Angle"};
        string choice;

        setCursorPosition(38, 6);
        cout << GREEN << "What is missing? " << RESET;

        for (int i = 0; i < arr.size(); i++) {
            setCursorPosition(38, 8 + i);
            cout << YELLOW << arr[i] << RESET;
        }

        setCursorPosition(38, 15);
        cout << YELLOW "Choose from the list above: " GREEN;
        getline(cin, choice);
        cout << RESET;

        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "1" || choice == "work") {
            clearScreen();

            Works();
        }
        else if (choice == "2" || choice == "distance") {
            clearScreen();

            Distance();
        }
        else if (choice == "3" || choice == "angle") {
            clearScreen();

            Angle();
        }
    }

}

void Work::Works() {
    bool stop = false;
    while (!stop) {
        double force, distance, work;

        while (true) {
            setCursorPosition(35, 9);
            cout << YELLOW "Enter Force(N): " GREEN;
            cin >> force;
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
            cout << YELLOW "Enter distance: " GREEN;
            cin >> distance;
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

        work = force * distance;

        setCursorPosition(35, 13);
        cout << YELLOW "Work = " << GREEN << work <<"J" RESET;

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

void Work::Distance() {
    bool stop = false;
    while (!stop) {
        double force, distance, work;

        while (true) {
            setCursorPosition(35, 9);
            cout << YELLOW "Enter Force(N): " GREEN;
            cin >> force;
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
            cout << YELLOW "Enter Work(J): " GREEN;
            cin >> work;
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

        distance = work / force;

        setCursorPosition(35, 13);
        cout << YELLOW "Distance = " << GREEN << distance << "m" RESET;

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

void Work::Angle() {
    bool stop = false;
    while (!stop) {
        double mass, force, angle, distance, work;
        double M_PI = 3.14159265358979323846;

        while (true) {
            setCursorPosition(35, 9);
            cout << YELLOW "Enter mass(kg): " GREEN;
            cin >> mass;
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
            setCursorPosition(35, 10);
            cout << YELLOW "Enter force: " GREEN;
            cin >> force;
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
            cout << YELLOW "Enter angle: " GREEN;
            cin >> angle;
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
            cout << YELLOW "Enter distance: " GREEN;
            cin >> distance;
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

        work = (force * distance) * cos((angle * M_PI / 180.0));

        setCursorPosition(35, 13);
        cout << YELLOW "Work = " << GREEN << work <<"N" RESET;

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