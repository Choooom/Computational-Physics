#include "Vectors.h"          
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


Vectors::Vectors() {
    
}

void Vectors::runVectorsCalculator() {
    setCursorPosition(52, 4);
    cout << RED "VECTOR CALCULATOR" RESET;
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
        cout << BLUE "|";
    }

    while (true) {
        vector<string> arr = { "Similar", "Opposite", "Perpendicular" };
        string choice;

        for (int i = 0; i < arr.size(); i++) {
            setCursorPosition(38 + (i * 15), 6);
            cout << YELLOW << arr[i] << RESET;
        }

        setCursorPosition(36, 15);
        cout << YELLOW "Choose from the list above: " GREEN;
        getline(cin, choice);
        cout << RESET;

        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "similar") {
            setCursorPosition(38, 6);
            for (int i = 0; i < 45; i++) cout << " ";
            setCursorPosition(52, 6);
            cout << YELLOW "Similar Direction" RESET;
            setCursorPosition(35, 15);
            cout << "                                                ";
            caseOne();
        }
        else if (choice == "opposite") {
            setCursorPosition(38, 6);
            for (int i = 0; i < 45; i++) cout << " ";
            setCursorPosition(51, 6);
            cout << YELLOW "Opposite Direction" RESET;
            setCursorPosition(35, 15);
            cout << "                                                 ";
            caseTwo();
        }
        else if (choice == "perpendicular") {
            setCursorPosition(38, 6);
            for (int i = 0; i < 45; i++) cout << " ";
            setCursorPosition(49, 6);
            cout << YELLOW "Perpendicular Direction" RESET;
            setCursorPosition(35, 15);
            cout << "                                                 ";
            caseThree();
        }
    }
}

void Vectors::caseOne() {
    bool stop = false;
    while (!stop) {
        double firstMovement, secondMovement;
        string measurement, direction;
        setCursorPosition(35, 9);
        cout << YELLOW "Enter the unit (eg. m, km): " GREEN;
        getline(cin, measurement);

        setCursorPosition(35, 10);
        cout << YELLOW "Enter direction (eg. N, W, E, S): " GREEN;
        getline(cin, direction);

        while (true) {
            setCursorPosition(35, 11);
            cout << YELLOW "Enter first movement: " GREEN;
            cin >> firstMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                cout << "Invalid input. Please enter a valid number.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        setCursorPosition(35, 14);
        cout << YELLOW "Final displacement: " << GREEN << (firstMovement + secondMovement)
            << measurement << ", " << direction << RESET;
        cin.get();
        setCursorPosition(35, 16);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();

        // Clear some lines
        setCursorPosition(35, 9);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 10); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 11); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 12); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 14); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(38, 6);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 16); for (int i = 0; i < 45; i++) cout << " ";

        stop = true;
    }
}

void Vectors::caseTwo() {
    bool stop = false;
    while (!stop) {
        double firstMovement, secondMovement;
        string measurement, direction;
        setCursorPosition(35, 9);
        cout << YELLOW "Enter the unit (eg. m, km): " GREEN;
        getline(cin, measurement);

        transform(measurement.begin(), measurement.end(), measurement.begin(), ::tolower);
        while (true) {
            setCursorPosition(35, 10);
            cout << YELLOW "Enter direction (eg. N, E, S, W): " GREEN;
            getline(cin, direction);
            transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
            if (direction == "n" || direction == "e" || direction == "s" || direction == "w") {
                setCursorPosition(35, 16);
                for (int i = 0; i < 49; i++) cout << " ";
                break;
            }
            else {
                setCursorPosition(35, 16);
                cout << "Invalid input. Please enter one of N, E, S, or W.";
            }
        }

        while (true) {
            setCursorPosition(35, 11);
            cout << YELLOW "Enter first movement: " GREEN;
            cin >> firstMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                cout << "Invalid input. Please enter a valid number";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        double displacement;
        string finalDirection;
        if (firstMovement >= secondMovement) {
            displacement = firstMovement - secondMovement;
            finalDirection = direction;
        }
        else {
            displacement = secondMovement - firstMovement;
            if (direction == "n")
                finalDirection = "S";
            else if (direction == "s")
                finalDirection = "N";
            else if (direction == "e")
                finalDirection = "W";
            else if (direction == "w")
                finalDirection = "E";
        }

        setCursorPosition(35, 14);
        cout << YELLOW "Final displacement: " << GREEN
            << displacement << measurement << ", " << finalDirection << RESET;
        cin.get();
        setCursorPosition(35, 16);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();

        // Clear lines
        setCursorPosition(35, 9); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 10); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 11); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 12); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 14); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(38, 6); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 16); for (int i = 0; i < 45; i++) cout << " ";

        stop = true;
    }
}

void Vectors::caseThree() {
    bool stop = false;
    const double PI = 3.14159265358979323846;
    while (!stop) {
        double firstMovement, secondMovement;
        string measurement, directionOne, directionTwo;
        setCursorPosition(35, 9);
        cout << YELLOW "Enter the unit (eg. m, km): " GREEN;
        getline(cin, measurement);

        while (true) {
            setCursorPosition(35, 10);
            cout << YELLOW "Enter first direction (eg. N, E, S, W): " GREEN;
            getline(cin, directionOne);
            transform(directionOne.begin(), directionOne.end(), directionOne.begin(), ::tolower);
            if (directionOne == "n" || directionOne == "e" || directionOne == "s" || directionOne == "w") {
                break;
            }
            else {
                setCursorPosition(35, 16);
                cout << "Invalid input. Please enter one of N, E, S, or W.";
            }
        }

        while (true) {
            setCursorPosition(35, 11);
            cout << YELLOW "Enter first movement: " GREEN;
            cin >> firstMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << "\nInvalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (true) {
            setCursorPosition(35, 12);
            cout << YELLOW "Enter second direction (eg. N, E, S, W): " GREEN;
            getline(cin, directionTwo);
            transform(directionTwo.begin(), directionTwo.end(), directionTwo.begin(), ::tolower);
            if (directionTwo == "n" || directionTwo == "e" || directionTwo == "s" || directionTwo == "w") {
                if ((directionOne == "n" || directionOne == "s") && (directionTwo == "e" || directionTwo == "w"))
                    break;
                else if ((directionOne == "e" || directionOne == "w") && (directionTwo == "n" || directionTwo == "s"))
                    break;
                else {
                    setCursorPosition(35, 16);
                    cout << "Invalid combination. The second direction must be perpendicular to the first." << endl;
                }
            }
            else {
                setCursorPosition(35, 16);
                cout << "Invalid input. Please enter one of N, E, S, or W.";
            }
        }

        while (true) {
            setCursorPosition(35, 13);
            cout << YELLOW "Enter second movement: " GREEN;
            cin >> secondMovement;
            if (cin.fail()) {
                setCursorPosition(35, 16);
                cout << "\nInvalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                setCursorPosition(35, 16);
                for (int i = 0; i < 45; i++) cout << " ";
                break;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        double displacement = sqrt(firstMovement * firstMovement + secondMovement * secondMovement);
        double angle = atan(secondMovement / firstMovement) * 180.0 / PI;
        transform(directionOne.begin(), directionOne.end(), directionOne.begin(), ::toupper);
        transform(directionTwo.begin(), directionTwo.end(), directionTwo.begin(), ::toupper);
        setCursorPosition(35, 15);
        cout << YELLOW "Final displacement: " << GREEN
            << displacement << measurement << ", "
            << angle << " degrees " << directionTwo << " of " << directionOne << RESET;
        cin.get();
        setCursorPosition(35, 16);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();

        // Clear lines
        for (int line : {9, 10, 11, 12, 13, 15, 16}) {
            setCursorPosition(35, line);
            for (int i = 0; i < 45; i++) cout << " ";
        }
        setCursorPosition(38, 6);
        for (int i = 0; i < 45; i++) cout << " ";
        stop = true;
    }
}
