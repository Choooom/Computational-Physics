#define NOMINMAX

#include "Measurement.h";
#include "ConsoleUtils.h";

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

using namespace std;

Measurement::Measurement() {

}

int mainMenu() {
    setCursorPosition(25, 5);
    cout << YELLOW "Length    Temp    Area   Volume    Weight    Time";
    setCursorPosition(25, 6);
    cout << GREEN "  1.       2.      3.      4.        5.       6.";

    bool goForward = false;
    while (!goForward) {
        setCursorPosition(25, 14);
        cout << YELLOW "Choose a unit from the choices above: " GREEN;
        setCursorPosition(63, 14);
        cout << "       ";
        setCursorPosition(63, 14);
        int choice;
        cin >> choice;
        cout << RESET;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setCursorPosition(25, 15);
            cout << RED "Invalid input. Please enter a number." RESET;
            Sleep(3000);
            setCursorPosition(25, 15);
            cout << "                                            ";
        }
        else {
            switch (choice) {
            case 0:
                goForward = true;
                continue;
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            case 5:
                return 5;
            case 6:
                return 6;
            default:
                setCursorPosition(25, 15);
                cout << RED "Invalid input. Choices are only 1-6." RESET;
                Sleep(3000);
                choice = 0;
                setCursorPosition(25, 15);
                cout << "                                       ";
                break;
            }
        }
    }
    return 0;
}

double meterToKilometerConverter(double amount, bool toKilo) {
    return toKilo ? amount / 1000 : amount * 1000;
}

double meterToCentimeterConverter(double amount, bool toCenti) {
    return toCenti ? amount * 100 : amount / 100;
}

double meterToMillimeterConverter(double amount, bool toMilli) {
    return toMilli ? amount * 1000 : amount / 1000;
}

double meterToMileConverter(double amount, bool toMile) {
    return toMile ? amount * 0.0006213712 : amount * 1609.344;
}

double meterToYardConverter(double amount, bool toYard) {
    return toYard ? amount * 1.0936132983 : amount * 0.9144;
}

double meterToFootConverter(double amount, bool toFoot) {
    return toFoot ? amount * 3.280839895 : amount * 0.3048;
}

double meterToInchConverter(double amount, bool toInch) {
    return toInch ? amount * 39.3700787402 : amount * 0.0254;
}

double celsiusFahrenheitConverter(double amount, bool toFahrenheit) {
    if (toFahrenheit)
        return (amount * 9.0 / 5.0) + 32;
    else
        return (amount - 32) * 5.0 / 9.0;
}

double celsiusKelvinConverter(double amount, bool toKelvin) {
    if (toKelvin)
        return amount + 273.15;
    else
        return amount - 273.15;
}

double fahrenheitKelvinConverter(double amount, bool toKelvin) {
    if (toKelvin)
        return (amount - 32) * 5.0 / 9.0 + 273.15;
    else
        return (amount - 273.15) * 9.0 / 5.0 + 32;
}

double sqmToSqkmConverter(double amount, bool toSqkm) {
    if (toSqkm)
        return amount / 1e6;
    else
        return amount * 1e6;
}

double sqmToSqmileConverter(double amount, bool toSqmile) {
    if (toSqmile)
        return amount / 2589988.11;
    else
        return amount * 2589988.11;
}

double sqmToSqfootConverter(double amount, bool toSqfoot) {
    if (toSqfoot)
        return amount / 0.092903;
    else
        return amount * 0.092903;
}

double sqmToAcreConverter(double amount, bool toAcre) {
    if (toAcre)
        return amount / 4046.8564224;
    else
        return amount * 4046.8564224;
}

double m3ToKm3Converter(double amount, bool toKm3) {
    if (toKm3)
        return amount / 1e9;
    else
        return amount * 1e9;
}

double m3ToLiterConverter(double amount, bool toLiter) {
    if (toLiter)
        return amount * 1000;   
    else
        return amount / 1000;
}

double m3ToMilliliterConverter(double amount, bool toMilliliter) {
    if (toMilliliter)
        return amount * 1e6;    
    else
        return amount / 1e6;
}

double m3ToUSGallonConverter(double amount, bool toGallon) {
    if (toGallon)
        return amount / 0.003785411784;
    else
        return amount * 0.003785411784;
}

double m3ToUSPintConverter(double amount, bool toPint) {
    if (toPint)
        return amount / 0.000473176473;
    else
        return amount * 0.000473176473;
}

double kgToGramConverter(double amount, bool toGram) {
    if (toGram)
        return amount * 1000;
    else
        return amount / 1000;
}

double kgToMilligramConverter(double amount, bool toMilligram) {
    if (toMilligram)
        return amount * 1e6;
    else
        return amount / 1e6;
}

double kgToPoundConverter(double amount, bool toPound) {
    if (toPound)
        return amount * 2.20462262185;
    else
        return amount / 2.20462262185;
}

double kgToOunceConverter(double amount, bool toOunce) {
    if (toOunce)
        return amount * 35.2739619496;
    else
        return amount / 35.2739619496;
}

double secToMinConverter(double amount, bool toMin) {
    if (toMin)
        return amount / 60;
    else
        return amount * 60;
}

double secToHourConverter(double amount, bool toHour) {
    if (toHour)
        return amount / 3600;
    else
        return amount * 3600;
}

double secToDayConverter(double amount, bool toDay) {
    if (toDay)
        return amount / 86400;
    else
        return amount * 86400;
}

void length() {
    
    for (int i = 0; i < 49; i++) {
        setCursorPosition(25 + i, 5); cout << " ";
        setCursorPosition(25 + i, 6); cout << " ";
    }
    setCursorPosition(47, 5);
    cout << YELLOW "Length";
    setCursorPosition(25, 14);
    cout << "                                          ";

    vector<string> arr = { "Meter", "Kilometer", "Centimeter", "Millimeter", "Mile", "Yard", "Foot", "Inch" };
    int columns = 4, rows = 2, startX = 25, startY = 7, spacing = 12;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int index = i * columns + j;
            if (index < arr.size()) {
                setCursorPosition(startX + j * spacing, startY + i);
                cout << arr[index];
            }
        }
    }

    string from, input, to;
    bool stop = false;
    double amount;
    while (!stop) {
        // Clear input area
        for (int y = 12; y <= 17; y++) {
            setCursorPosition(25, y);
            cout << "                                             ";
        }
        setCursorPosition(25, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Type a number.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            continue;
        }
        setCursorPosition(25, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;
        setCursorPosition(25, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        setCursorPosition(25, 16);
        cout << GREEN;
        if ((from == "meter" || from == "m") &&
            (to == "kilometer" || to == "km")) {
            cout << amount << "m = " << fixed << setprecision(2)
                << meterToKilometerConverter(amount, true) << "km";
            stop = true;
        }
        else if ((from == "kilometer" || from == "km") &&
            (to == "meter" || to == "m")) {
            cout << amount << "km = " << fixed << setprecision(2)
                << meterToKilometerConverter(amount, false) << "m";
            stop = true;
        }
        // ... (other length if branches similar to your original code)
        else {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }
        if (stop) {
            setCursorPosition(25, 17);
            cout << YELLOW "Press any key to continue...";
            cin.get(); cin.get();
        }
    }
}

void temperature() {
    // Clear header area and display heading
    for (int i = 0; i < 49; i++) {
        setCursorPosition(25 + i, 5); cout << " ";
        setCursorPosition(25 + i, 6); cout << " ";
    }
    setCursorPosition(47, 5);
    cout << YELLOW "Temperature";
    setCursorPosition(25, 14);
    cout << "                                             ";

    vector<string> arr = { "Celsius", "Fahrenheit", "Kelvin" };
    int columns = 3, startX = 25, startY = 7, spacing = 15;
    for (int i = 0; i < arr.size(); i++) {
        setCursorPosition(startX + i * spacing, startY);
        cout << arr[i];
    }

    string from, input, to;
    bool stop = false;
    double amount;
    while (!stop) {
        for (int y = 12; y <= 17; y++) {
            setCursorPosition(25, y);
            cout << "                                             ";
        }
        setCursorPosition(25, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Type a number.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            continue;
        }
        setCursorPosition(25, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;
        setCursorPosition(25, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        setCursorPosition(25, 16);
        cout << GREEN;
        if ((from == "celsius" || from == "c") && (to == "fahrenheit" || to == "f")) {
            cout << amount << "°C = " << fixed << setprecision(2)
                << celsiusFahrenheitConverter(amount, true) << "°F";
            stop = true;
        }
        else if ((from == "fahrenheit" || from == "f") && (to == "celsius" || to == "c")) {
            cout << amount << "°F = " << fixed << setprecision(2)
                << celsiusFahrenheitConverter(amount, false) << "°C";
            stop = true;
        }
        else if ((from == "celsius" || from == "c") && (to == "kelvin" || to == "k")) {
            cout << amount << "°C = " << fixed << setprecision(2)
                << celsiusKelvinConverter(amount, true) << "K";
            stop = true;
        }
        else if ((from == "kelvin" || from == "k") && (to == "celsius" || to == "c")) {
            cout << amount << "K = " << fixed << setprecision(2)
                << celsiusKelvinConverter(amount, false) << "°C";
            stop = true;
        }
        else if ((from == "fahrenheit" || from == "f") && (to == "kelvin" || to == "k")) {
            cout << amount << "°F = " << fixed << setprecision(2)
                << fahrenheitKelvinConverter(amount, true) << "K";
            stop = true;
        }
        else if ((from == "kelvin" || from == "k") && (to == "fahrenheit" || to == "f")) {
            cout << amount << "K = " << fixed << setprecision(2)
                << fahrenheitKelvinConverter(amount, false) << "°F";
            stop = true;
        }
        else {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }
        if (stop) {
            setCursorPosition(25, 17);
            cout << YELLOW "Press any key to continue...";
            cin.get(); cin.get();
        }
    }
}

void area() {
    // Clear header area and display heading
    for (int i = 0; i < 49; i++) {
        setCursorPosition(25 + i, 5); cout << " ";
        setCursorPosition(25 + i, 6); cout << " ";
    }
    setCursorPosition(47, 5);
    cout << YELLOW "Area";
    setCursorPosition(25, 14);
    cout << "                                             ";

    vector<string> arr = { "Sqr. Meter", "Sqr. Kilometer", "Sqr. Mile", "Sqr. Foot", "Acre" };
    int columns = 3, rows = 2, startX = 25, startY = 7, spacing = 18;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int index = i * columns + j;
            if (index < arr.size()) {
                setCursorPosition(startX + j * spacing, startY + i);
                cout << arr[index];
            }
        }
    }

    string from, input, to;
    bool stop = false;
    double amount;
    while (!stop) {
        for (int y = 12; y <= 17; y++) {
            setCursorPosition(25, y);
            cout << "                                             ";
        }
        setCursorPosition(25, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Type a number.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            continue;
        }
        setCursorPosition(25, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;
        setCursorPosition(25, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);
        setCursorPosition(25, 16);
        cout << GREEN;
        // Example branch: Sqr. Meter <-> Sqr. Kilometer
        if ((from == "sqr. meter" || from == "sqm" || from == "square meter") &&
            (to == "sqr. kilometer" || to == "sqkm" || to == "square kilometer")) {
            cout << amount << " sqm = " << fixed << setprecision(2)
                << sqmToSqkmConverter(amount, true) << " sqkm";
            stop = true;
        }
        else if ((from == "sqr. kilometer" || from == "sqkm" || from == "square kilometer") &&
            (to == "sqr. meter" || to == "sqm" || to == "square meter")) {
            cout << amount << " sqkm = " << fixed << setprecision(2)
                << sqmToSqkmConverter(amount, false) << " sqm";
            stop = true;
        }
        // Add additional branches for Sqr. Mile, Sqr. Foot, and Acre conversions similarly...
        else {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }
        if (stop) {
            setCursorPosition(25, 17);
            cout << YELLOW "Press any key to continue...";
            cin.get(); cin.get();
        }
    }
}

void volume() {
    // Clear header area and display heading
    for (int i = 0; i < 49; i++) {
        setCursorPosition(25 + i, 5); cout << " ";
        setCursorPosition(25 + i, 6); cout << " ";
    }
    setCursorPosition(47, 5);
    cout << YELLOW "Volume";
    setCursorPosition(25, 14);
    cout << "                                             ";

    vector<string> arr = { "Cubic Meter", "Cubic Kilometer", "Liter", "Milliliter", "US Gallon", "US Pint" };
    int columns = 3, rows = 2, startX = 25, startY = 7, spacing = 16;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int index = i * columns + j;
            if (index < arr.size()) {
                setCursorPosition(startX + j * spacing, startY + i);
                cout << arr[index];
            }
        }
    }

    string from, input, to;
    bool stop = false;
    double amount;
    while (!stop) {
        for (int y = 12; y <= 17; y++) {
            setCursorPosition(25, y);
            cout << "                                             ";
        }
        setCursorPosition(25, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Type a number.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            continue;
        }
        setCursorPosition(25, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;
        setCursorPosition(25, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);
        setCursorPosition(25, 16);
        cout << GREEN;
        // Example branch: Cubic Meter <-> Liter
        if ((from == "cubic meter" || from == "m3") &&
            (to == "liter" || to == "l")) {
            cout << amount << " m3 = " << fixed << setprecision(2)
                << m3ToLiterConverter(amount, true) << " L";
            stop = true;
        }
        else if ((from == "liter" || from == "l") &&
            (to == "cubic meter" || to == "m3")) {
            cout << amount << " L = " << fixed << setprecision(2)
                << m3ToLiterConverter(amount, false) << " m3";
            stop = true;
        }
        // Add additional branches for Cubic Kilometer, Milliliter, US Gallon, and US Pint conversions...
        else {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }
        if (stop) {
            setCursorPosition(25, 17);
            cout << YELLOW "Press any key to continue...";
            cin.get(); cin.get();
        }
    }
}

void weight() {
    // Clear header area and display heading
    for (int i = 0; i < 49; i++) {
        setCursorPosition(25 + i, 5); cout << " ";
        setCursorPosition(25 + i, 6); cout << " ";
    }
    setCursorPosition(47, 5);
    cout << YELLOW "Weight";
    setCursorPosition(25, 14);
    cout << "                                             ";

    vector<string> arr = { "Kilogram", "Gram", "Milligram", "Pound", "Ounce" };
    int columns = 3, rows = 2, startX = 25, startY = 7, spacing = 16;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int index = i * columns + j;
            if (index < arr.size()) {
                setCursorPosition(startX + j * spacing, startY + i);
                cout << arr[index];
            }
        }
    }

    string from, input, to;
    bool stop = false;
    double amount;
    while (!stop) {
        for (int y = 12; y <= 17; y++) {
            setCursorPosition(25, y);
            cout << "                                             ";
        }
        setCursorPosition(25, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Type a number.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            continue;
        }
        setCursorPosition(25, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;
        setCursorPosition(25, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);
        setCursorPosition(25, 16);
        cout << GREEN;
        // Example branch: Kilogram <-> Gram
        if ((from == "kilogram" || from == "kg") &&
            (to == "gram" || to == "g")) {
            cout << amount << " kg = " << fixed << setprecision(2)
                << kgToGramConverter(amount, true) << " g";
            stop = true;
        }
        else if ((from == "gram" || from == "g") &&
            (to == "kilogram" || to == "kg")) {
            cout << amount << " g = " << fixed << setprecision(2)
                << kgToGramConverter(amount, false) << " kg";
            stop = true;
        }
        // Add additional branches for Milligram, Pound, and Ounce conversions...
        else {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }
        if (stop) {
            setCursorPosition(25, 17);
            cout << YELLOW "Press any key to continue...";
            cin.get(); cin.get();
        }
    }
}

void timeConv() {
    // (Renamed function as time() conflicts with std::time)
    for (int i = 0; i < 49; i++) {
        setCursorPosition(25 + i, 5); cout << " ";
        setCursorPosition(25 + i, 6); cout << " ";
    }
    setCursorPosition(47, 5);
    cout << YELLOW "Time";
    setCursorPosition(25, 14);
    cout << "                                             ";

    vector<string> arr = { "Second", "Minute", "Hour", "Day" };
    int columns = 4, startX = 25, startY = 7, spacing = 12;
    for (int i = 0; i < arr.size(); i++) {
        setCursorPosition(startX + i * spacing, startY);
        cout << arr[i];
    }

    string from, input, to;
    bool stop = false;
    double amount;
    while (!stop) {
        for (int y = 12; y <= 17; y++) {
            setCursorPosition(25, y);
            cout << "                                             ";
        }
        setCursorPosition(25, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Type a number.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            continue;
        }
        setCursorPosition(25, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;
        setCursorPosition(25, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);
        setCursorPosition(25, 16);
        cout << GREEN;
        // Example branch: Second <-> Minute
        if ((from == "second" || from == "s") &&
            (to == "minute" || to == "min")) {
            cout << amount << " s = " << fixed << setprecision(2)
                << secToMinConverter(amount, true) << " min";
            stop = true;
        }
        else if ((from == "minute" || from == "min") &&
            (to == "second" || to == "s")) {
            cout << amount << " min = " << fixed << setprecision(2)
                << secToMinConverter(amount, false) << " s";
            stop = true;
        }
        else if ((from == "second" || from == "s") &&
            (to == "hour" || to == "h")) {
            cout << amount << " s = " << fixed << setprecision(2)
                << secToHourConverter(amount, true) << " h";
            stop = true;
        }
        else if ((from == "hour" || from == "h") &&
            (to == "second" || to == "s")) {
            cout << amount << " h = " << fixed << setprecision(2)
                << secToHourConverter(amount, false) << " s";
            stop = true;
        }
        else if ((from == "second" || from == "s") &&
            (to == "day" || to == "d")) {
            cout << amount << " s = " << fixed << setprecision(2)
                << secToDayConverter(amount, true) << " d";
            stop = true;
        }
        else if ((from == "day" || from == "d") &&
            (to == "second" || to == "s")) {
            cout << amount << " d = " << fixed << setprecision(2)
                << secToDayConverter(amount, false) << " s";
            stop = true;
        }
        
        else {
            setCursorPosition(25, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }
        if (stop) {
            setCursorPosition(25, 17);
            cout << YELLOW "Press any key to continue...";
            cin.get(); cin.get();
        }
    }
}

void Measurement::runUnitConverter() {
    while (true) {
        for (int i = 0; i < 49; i++) {
            setCursorPosition(25 + i, 7);
            cout << " ";
            setCursorPosition(25 + i, 8);
            cout << " ";
        }
        for (int y = 12; y <= 17; y++) {
            setCursorPosition(25, y);
            cout << "                                             ";
        }
        switch (mainMenu()) {
        case 1:
            length();
            break;
        case 2:
            temperature();
            break;
        case 3:
            area();
            break;
        case 4:
            volume();
            break;
        case 5:
            weight();
            break;
        case 6:
            timeConv();
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}