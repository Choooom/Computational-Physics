#include "Momentum.h"          
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

Momentum::Momentum() {

};

double calculateMomentum(double mass, double velocity) {
    return mass * velocity;
}

double calculateImpulse(double force, double time) {
    return force * time;
}

double calculateImpulseFromMomentum(double initialMomentum, double finalMomentum) {
    return finalMomentum - initialMomentum;
}

void elasticCollision(double m1, double v1, double m2, double v2, double& v1Final, double& v2Final) {
    v1Final = ((m1 - m2) / (m1 + m2)) * v1 + ((2 * m2) / (m1 + m2)) * v2;
    v2Final = ((2 * m1) / (m1 + m2)) * v1 + ((m2 - m1) / (m1 + m2)) * v2;
}

double perfectlyInelasticCollision(double m1, double v1, double m2, double v2) {
    // final velocity after collision
    return (m1 * v1 + m2 * v2) / (m1 + m2);
}

double calculateRecoilVelocity(double bulletMass, double bulletVelocity, double gunMass) {
    // conservation of momentum: gun recoil velocity is negative to bullet
    return -(bulletMass * bulletVelocity) / gunMass;
}

double calculateInelasticWithNoV2(double m1, double v1, double m2, double v2, string missing) {

    if (missing == "Vi2") {
        return ((m1 * v1) + (m2 * 0)) / (m1 + m2);
    }
    else if (missing == "vi") {
        return ((m1 * v1) + (m2 * 0) - (m2 * v2)) / m1;
    }
}

void Momentum::runMomentum() {

    while (true) {
        setCursorPosition(52, 4);
        cout << RED "MOMENTUM & IMPULSE" RESET;

        vector<string> arr = { "1.) Momentum", "2.) Impulse (F*T)", "3.) Impulse (initial & final momentum)", "4.) Inelastic Collision", "5.) Recoil Velocity"};
        string choice;

        setCursorPosition(38, 6);
        cout << GREEN << "What to solve for? " << RESET;

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

            Momentums();
        }
        else if (choice == "2" || choice == "impulse") {
            clearScreen();

            Impulse();
        }
        else if (choice == "3" || choice == "impulse with momentum") {
            clearScreen();

            Impulse_Momentum();
        }
        else if (choice == "4" || choice == "elastic") {
            clearScreen();

            Inellastic();
        }
        else if (choice == "5" || choice == "recoil") {
            clearScreen();

            Recoil();
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

void Momentum::Momentums() {
    bool stop = false;
    while (!stop) {
        double mass, velocity, momentum;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Momentum", 5);
            cout << YELLOW;
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
            cout << YELLOW "Enter velocity(m/s): " GREEN;
            cin >> velocity;
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

        momentum = calculateMomentum(mass, velocity);

        setCursorPosition(35, 13);
        cout << YELLOW "Momentum = " << GREEN << momentum << "kg m/s" RESET;

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

void Momentum::Impulse() {
    bool stop = false;
    while (!stop) {
        double force, time, impulse;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Impulse", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter force(N): " GREEN;
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
            cout << YELLOW "Enter time(s): " GREEN;
            cin >> time;
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

        impulse = calculateImpulse(force, time);

        setCursorPosition(35, 13);
        cout << YELLOW "Impulse = " << GREEN << impulse << "Ns" RESET;

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

void Momentum::Impulse_Momentum() {
    bool stop = false;
    while (!stop) {
        double initial_momentum, final_momentum, impulse;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Impulse (Pi & Pf)", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter initilial momentum: " GREEN;
            cin >> initial_momentum;
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
            cout << YELLOW "Enter final momentum: " GREEN;
            cin >> final_momentum;
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

        impulse = calculateImpulseFromMomentum(initial_momentum, final_momentum);

        setCursorPosition(35, 13);
        cout << YELLOW "Impulse = " << GREEN << impulse << "kg m/s" RESET;

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

void Momentum::Recoil() {
    bool stop = false;
    while (!stop) {
        double mass1, mass2, velocity1, recoil;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Recoil", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter first mass: " GREEN;
            cin >> mass1;
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
            cout << YELLOW "Enter first velocity: " GREEN;
            cin >> velocity1;
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
            cout << YELLOW "Enter second mass: " GREEN;
            cin >> mass2;
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

        recoil = calculateRecoilVelocity(mass1, velocity1, mass2);

        setCursorPosition(35, 13);
        cout << YELLOW "Impulse = " << GREEN << recoil << "m/s" RESET;

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

void Momentum::Inellastic() {
    bool stop = false;
    while (!stop) {
        double mass1, mass2, initial_velocity1, initial_velocity2, final_velocity, answer;

        while (true) {
            clearScreen();
            cout << RED;
            printCentered("Inellastic Collision", 5);
            cout << YELLOW;
            setCursorPosition(35, 9);
            cout << YELLOW "Enter first mass(kg): " GREEN;
            cin >> mass1;
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
            cout << YELLOW "Enter initial velocity(m/s): " GREEN;
            cin >> initial_velocity1;
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
            cout << YELLOW "Enter second mass(kg): " GREEN;
            cin >> mass2;
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
            cout << YELLOW "Enter final velocity(m/s): " GREEN;
            cin >> final_velocity;
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

        if (final_velocity != 0) {
            answer = calculateInelasticWithNoV2(mass1, initial_velocity1, mass2, final_velocity, "vi");
        }
        else {
            answer = calculateInelasticWithNoV2(mass1, initial_velocity1, mass2, final_velocity, "Vi2");
        }

        setCursorPosition(35, 13);
        cout << YELLOW "Impulse = " << GREEN << answer << "m/s" RESET;

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