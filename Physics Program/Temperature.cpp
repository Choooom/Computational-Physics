#include "Temperature.h"          
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

Temperature::Temperature() {

};

double calculateCelsius(double fahrenheit) {
    return ((fahrenheit - 32) * 5) / 9;
}

double calculateFahrenheit(double celsius) {
    return (celsius * 9) / 5 + 32;
}

void Temperature::runTemperature() {

    while (true) {
        setCursorPosition(52, 4);
        cout << RED "TEMPERATURE" RESET;

        vector<string> arr = { "1.) Celsius -> Fahrenheit", "2.) Fahrenheit -> Celsius" };
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

        if (choice == "1" || choice == "momentum") {
            clearScreen();

            computeFahrenheit();
        }
        else if (choice == "2" || choice == "impulse") {
            clearScreen();

            computeCelsius();
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

void Temperature::computeCelsius() {
    bool stop = false;
    while (!stop) {
        double fahrenheit, celsius;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Fahrenheit -> Celsius", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter temperature(F): " GREEN;
            cin >> fahrenheit;
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

        celsius = calculateCelsius(fahrenheit);

        setCursorPosition(35, 13);
        cout << YELLOW "Celsius = " << GREEN << celsius << " degrees" RESET;

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

void Temperature::computeFahrenheit() {
    bool stop = false;
    while (!stop) {
        double celsius, fahrenheit;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Celsius -> Fahrenheit ", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter temperature(C): " GREEN;
            cin >> celsius;
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

        fahrenheit = calculateFahrenheit(celsius);

        setCursorPosition(35, 13);
        cout << YELLOW "Fahrenheit = " << GREEN << fahrenheit << " degrees" RESET;

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

