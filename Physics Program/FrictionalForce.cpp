#include "FrictionalForce.h"          
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

FrictionalForce::FrictionalForce() {

};

void FrictionalForce::runFrictionalForce() {

	while (true) {
		setCursorPosition(52, 4);
		cout << RED "FRICTIONAL FORCE" RESET;

		vector<string> arr = { "1.) Force of Kinetic Friction", "2.) Coefficient of Kinetic Friction", "3.) Normal Friction", "4,) With Angle"};
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

		if (choice == "1" || choice == "force") {
            clearScreen();

            Force();
		}
        else if (choice == "2" || choice == "coefficient") {
            clearScreen();

            Coefficient();
        }
        else if (choice == "4" || choice == "angle") {
            clearScreen();

            Angle();
        }
	}
		
}

void FrictionalForce::Force() {
    bool stop = false;
    while (!stop) {
        double mass, coefficient, force;

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
            setCursorPosition(35, 11);
            cout << YELLOW "Enter coefficient: " GREEN;
            cin >> coefficient;
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

        force = coefficient * (mass * 9.81);

        setCursorPosition(35, 13);
        cout << YELLOW "Force = " << GREEN << force << RESET;

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        setCursorPosition(35, 18);
        cout << "                                     ";

        setCursorPosition(35, 9);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 10); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 11); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 12); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 14); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 15); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(38, 6);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 16); for (int i = 0; i < 45; i++) cout << " ";

        stop = true;
    }
}

void FrictionalForce::Coefficient() {
    bool stop = false;
    while (!stop) {
        double mass, acceleration, normal, friction, force;

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

        normal = mass * 9.81;

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

        friction = mass * acceleration;

        force = friction / normal;

        setCursorPosition(35, 13);
        cout << YELLOW "Coefficient of Friction = " << GREEN << (-1 * force) << RESET;

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        setCursorPosition(35, 18);
        cout << "                                     ";

        setCursorPosition(35, 9);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 10); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 11); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 12); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 14); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 15); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(38, 6);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 16); for (int i = 0; i < 45; i++) cout << " ";

        stop = true;
    }
}

void FrictionalForce::Angle() {
    bool stop = false;
    while (!stop) {
        double mass, coefficient, angle, forceX, normal, maximumforce;
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
            cout << YELLOW "Enter coefficient: " GREEN;
            cin >> coefficient;
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

        normal = (mass * 9.81) * cos((angle * M_PI / 180.0));
        forceX = ((mass * 9.81) * sin((angle * M_PI / 180.0))) - (coefficient * normal);

        setCursorPosition(35, 13);
        cout << YELLOW "NormalForce = " << GREEN << normal << RESET;

        setCursorPosition(35, 14);
        cout << YELLOW "Force = " << GREEN << forceX << RESET;

        setCursorPosition(35, 15);
        cout << YELLOW "Maximum Force = " << GREEN << normal + forceX << RESET;

        setCursorPosition(35, 18);
        cout << BLUE "Press any key to continue..." RESET;
        cin.get();
        cin.get();

        setCursorPosition(35, 18);
        cout << "                                     ";

        setCursorPosition(35, 9);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 10); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 11); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 12); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 14); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 15); for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(38, 6);  for (int i = 0; i < 45; i++) cout << " ";
        setCursorPosition(35, 16); for (int i = 0; i < 45; i++) cout << " ";

        stop = true;
    }
}