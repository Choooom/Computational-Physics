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

void Measurement::mainMenu() {
    while (true) {
        clearScreen();

        // Frame and Title
        setCursorPosition(52, 4);
        cout << RED "UNIT CONVERTER" RESET;

        for (int i = 1; i <= 19; i++) {
            setCursorPosition(9, i);
            cout << BLUE "|";
            setCursorPosition(109, i);
            cout << BLUE "|" RESET;
        }

        setCursorPosition(10, 19);
        for (int i = 0; i < 100; i++) {
            cout << BLUE "=" RESET;
        }

        // Unit types and options
        setCursorPosition(39, 6);
        cout << YELLOW "Length  Temp  Area  Volume   Weight  Time";
        setCursorPosition(39, 7);
        cout << GREEN  "  1.     2.    3.     4.       5.     6.";

        // Input prompt
        setCursorPosition(36, 14);
        cout << YELLOW "Choose a unit from the choices above: " GREEN;

        string input;
        getline(cin, input);
        cout << RESET;

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input == "0" || input == "exit") {
            clearScreen();
            break;
        }

        if (input == "1" || input == "length") {
            clearScreen();
            length();
        }
        else if (input == "2" || input == "temp" || input == "temperature") {
            clearScreen();
            temperature();
        }
        else if (input == "3" || input == "area") {
            clearScreen();
            area();
        }
        else if (input == "4" || input == "volume") {
            clearScreen();
            volume();
        }
        else if (input == "5" || input == "weight") {
            clearScreen();
            weight();
        }
        else if (input == "6" || input == "time") {
            clearScreen();
            timeConv();
        }
        else if (input == "exit") {
            clearScreen();
            break;
        }
        else {
            setCursorPosition(36, 16);
            cout << RED "Invalid choice. Please try again." RESET;
            cin.get(); 
            clearScreen();
        }
    }
}

// Sqr. Meter <-> Others

double Measurement::sqmToSqkm(double sqm) {
    return sqm / 1'000'000.0;  // 1 sqkm = 1,000,000 sqm
}

double Measurement::sqkmToSqm(double sqkm) {
    return sqkm * 1'000'000.0;
}

double Measurement::sqmToSqmi(double sqm) {
    return sqm / 2'589'988.11;  // 1 sqmi = 2,589,988.11 sqm
}

double Measurement::sqmiToSqm(double sqmi) {
    return sqmi * 2'589'988.11;
}

double Measurement::sqmToSqft(double sqm) {
    return sqm * 10.7639;  // 1 sqm = 10.7639 sqft
}

double Measurement::sqftToSqm(double sqft) {
    return sqft / 10.7639;
}

double Measurement::sqmToAcre(double sqm) {
    return sqm / 4046.8564224;  // 1 acre = 4046.8564224 sqm
}

double Measurement::acreToSqm(double acre) {
    return acre * 4046.8564224;
}

// Sqr. Kilometer <-> Others (besides sqm which is above)

double Measurement::sqkmToSqmi(double sqkm) {
    return sqkm / 2.58999;  // 1 sqmi = 2.58999 sqkm
}

double Measurement::sqmiToSqkm(double sqmi) {
    return sqmi * 2.58999;
}

double Measurement::sqkmToSqft(double sqkm) {
    return sqkm * 10'763'910.42;  // 1 sqkm = 10,763,910.42 sqft
}

double Measurement::sqftToSqkm(double sqft) {
    return sqft / 10'763'910.42;
}

double Measurement::sqkmToAcre(double sqkm) {
    return sqkm * 247.105;  // 1 sqkm = 247.105 acres
}

double Measurement::acreToSqkm(double acre) {
    return acre / 247.105;
}

// Sqr. Mile <-> Others (besides sqm and sqkm)

double Measurement::sqmiToSqft(double sqmi) {
    return sqmi * 27'878'400;  // 1 sqmi = 27,878,400 sqft
}

double Measurement::sqftToSqmi(double sqft) {
    return sqft / 27'878'400;
}

double Measurement::sqmiToAcre(double sqmi) {
    return sqmi * 640;  // 1 sqmi = 640 acres
}

double Measurement::acreToSqmi(double acre) {
    return acre / 640;
}

// Sqr. Foot <-> Acres

double Measurement::sqftToAcre(double sqft) {
    return sqft / 43'560;  // 1 acre = 43,560 sqft
}

double Measurement::acreToSqft(double acre) {
    return acre * 43'560;
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

double minToHourConverter(double value, bool minToHr) {
    return minToHr ? value / 60.0 : value * 60.0;
}

double minToDayConverter(double value, bool minToDay) {
    return minToDay ? value / 1440.0 : value * 1440.0;  // 1440 min = 1 day
}

double hourToDayConverter(double value, bool hrToDay) {
    return hrToDay ? value / 24.0 : value * 24.0;
}


double Measurement::toLiters(double amount, const std::string& fromUnit) {
    if (fromUnit == "cubic meter" || fromUnit == "m3") {
        return amount * 1000.0;
    }
    else if (fromUnit == "cubic kilometer" || fromUnit == "km3") {
        return amount * 1e12; // 1 km^3 = 1e12 liters
    }
    else if (fromUnit == "liter" || fromUnit == "l") {
        return amount;
    }
    else if (fromUnit == "milliliter" || fromUnit == "ml") {
        return amount / 1000.0;
    }
    else if (fromUnit == "us gallon" || fromUnit == "gallon") {
        return amount * 3.78541;
    }
    else if (fromUnit == "us pint" || fromUnit == "pint") {
        return amount * 0.473176;
    }
    else {
        return -1; // invalid unit
    }
}

double Measurement::fromLiters(double liters, const std::string& toUnit) {
    if (toUnit == "cubic meter" || toUnit == "m3") {
        return liters / 1000.0;
    }
    else if (toUnit == "cubic kilometer" || toUnit == "km3") {
        return liters / 1e12;
    }
    else if (toUnit == "liter" || toUnit == "l") {
        return liters;
    }
    else if (toUnit == "milliliter" || toUnit == "ml") {
        return liters * 1000.0;
    }
    else if (toUnit == "us gallon" || toUnit == "gallon") {
        return liters / 3.78541;
    }
    else if (toUnit == "us pint" || toUnit == "pint") {
        return liters / 0.473176;
    }
    else {
        return -1; // invalid unit
    }
}

double Measurement::toKilograms(double amount, const std::string& fromUnit) {
    if (fromUnit == "kilogram" || fromUnit == "kg") {
        return amount;
    }
    else if (fromUnit == "gram" || fromUnit == "g") {
        return amount / 1000.0;
    }
    else if (fromUnit == "milligram" || fromUnit == "mg") {
        return amount / 1e6;
    }
    else if (fromUnit == "pound" || fromUnit == "lb") {
        return amount * 0.453592;
    }
    else if (fromUnit == "ounce" || fromUnit == "oz") {
        return amount * 0.0283495;
    }
    else {
        return -1; // invalid unit
    }
}

double Measurement::fromKilograms(double kilograms, const std::string& toUnit) {
    if (toUnit == "kilogram" || toUnit == "kg") {
        return kilograms;
    }
    else if (toUnit == "gram" || toUnit == "g") {
        return kilograms * 1000.0;
    }
    else if (toUnit == "milligram" || toUnit == "mg") {
        return kilograms * 1e6;
    }
    else if (toUnit == "pound" || toUnit == "lb") {
        return kilograms / 0.453592;
    }
    else if (toUnit == "ounce" || toUnit == "oz") {
        return kilograms / 0.0283495;
    }
    else {
        return -1; // invalid unit
    }
}


void Measurement::length() {
    // Helper lambdas inside the function or you can make them class/private functions
    auto toMeters = [](double value, const std::string& unit) -> double {
        if (unit == "meter" || unit == "m") return value;
        if (unit == "kilometer" || unit == "km") return value * 1000.0;
        if (unit == "centimeter" || unit == "cm") return value / 100.0;
        if (unit == "millimeter" || unit == "mm") return value / 1000.0;
        if (unit == "mile") return value * 1609.34;
        if (unit == "yard") return value * 0.9144;
        if (unit == "foot" || unit == "ft") return value * 0.3048;
        if (unit == "inch" || unit == "in") return value * 0.0254;
        return -1; // invalid unit
        };

    auto fromMeters = [](double meters, const std::string& unit) -> double {
        if (unit == "meter" || unit == "m") return meters;
        if (unit == "kilometer" || unit == "km") return meters / 1000.0;
        if (unit == "centimeter" || unit == "cm") return meters * 100.0;
        if (unit == "millimeter" || unit == "mm") return meters * 1000.0;
        if (unit == "mile") return meters / 1609.34;
        if (unit == "yard") return meters / 0.9144;
        if (unit == "foot" || unit == "ft") return meters / 0.3048;
        if (unit == "inch" || unit == "in") return meters / 0.0254;
        return -1; // invalid unit
        };

    bool stop = false;
    while (!stop) {
        setCursorPosition(58, 5);
        cout << RED;
        printCentered("Length", 5);
        cout << YELLOW;

        vector<string> arr = { "Meter", "Kilometer", "Centimeter", "Millimeter", "Mile", "Yard", "Foot", "Inch" };
        int columns = 4, rows = 2, startX = 36, startY = 7, spacing = 12;
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
        double amount;

        setCursorPosition(36, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(36, 17);
            cout << RED "Invalid input. Type a number.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            clearScreen();
            continue;
        }

        setCursorPosition(36, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;
        setCursorPosition(36, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;

        // Convert input units to lowercase for matching
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        setCursorPosition(36, 16);
        cout << GREEN;

        double meters = toMeters(amount, from);
        if (meters < 0) {
            setCursorPosition(36, 17);
            cout << RED "Invalid 'from' unit." RESET;
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        double result = fromMeters(meters, to);
        if (result < 0) {
            setCursorPosition(36, 17);
            cout << RED "Invalid 'to' unit." RESET;
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        cout << amount << " " << from << " = " << fixed << setprecision(4) << result << " " << to;
        stop = true;

        if (stop) {
            setCursorPosition(36, 17);
            cout << YELLOW "Press any key to continue...";
            cin.get(); cin.get();
        }
    }
}

void Measurement::temperature() {
    vector<string> arr = { "Celsius", "Fahrenheit", "Kelvin" };
    int columns = static_cast<int>(arr.size()), startX = 36, startY = 7, spacing = 15;

    bool stop = false;
    while (!stop) {
        clearScreen();  // wipe the input/output area like in length()

        // Print header, centered at y=5, xStart=36
        cout << RED;
        printCentered("Temperature", 5);
        cout << YELLOW;

        // Print unit options
        for (int i = 0; i < columns; i++) {
            setCursorPosition(40 + i * spacing, startY);
            cout << arr[i];
        }

        string from, input, to;
        double amount;

        // Prompt and input amount
        setCursorPosition(startX, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument&) {
            setCursorPosition(startX, 17);
            cout << RED "Invalid input. Type a number." RESET;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            continue;
        }

        // Prompt and input 'from' unit
        setCursorPosition(startX, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;

        // Prompt and input 'to' unit
        setCursorPosition(startX, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;

        // Normalize input to lowercase
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        // Perform conversion and display result
        setCursorPosition(startX, 16);
        cout << GREEN;

        if ((from == "celsius" || from == "c") && (to == "fahrenheit" || to == "f")) {
            cout << amount << " C = " << fixed << setprecision(2)
                << celsiusFahrenheitConverter(amount, true) << " F";
            stop = true;
        }
        else if ((from == "fahrenheit" || from == "f") && (to == "celsius" || to == "c")) {
            cout << amount << " F = " << fixed << setprecision(2)
                << celsiusFahrenheitConverter(amount, false) << " C";
            stop = true;
        }
        else if ((from == "celsius" || from == "c") && (to == "kelvin" || to == "k")) {
            cout << amount << " C = " << fixed << setprecision(2)
                << celsiusKelvinConverter(amount, true) << "K";
            stop = true;
        }
        else if ((from == "kelvin" || from == "k") && (to == "celsius" || to == "c")) {
            cout << amount << "K = " << fixed << setprecision(2)
                << celsiusKelvinConverter(amount, false) << " C";
            stop = true;
        }
        else if ((from == "fahrenheit" || from == "f") && (to == "kelvin" || to == "k")) {
            cout << amount << " F = " << fixed << setprecision(2)
                << fahrenheitKelvinConverter(amount, true) << "K";
            stop = true;
        }
        else if ((from == "kelvin" || from == "k") && (to == "fahrenheit" || to == "f")) {
            cout << amount << "K = " << fixed << setprecision(2)
                << fahrenheitKelvinConverter(amount, false) << " F";
            stop = true;
        }
        else {
            setCursorPosition(startX, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }

        if (stop) {
            setCursorPosition(startX, 17);
            cout << YELLOW "Press any key to continue..." RESET;
            cin.get(); cin.get();
        }
    }
}

void Measurement::area() {
    vector<string> arr = { "Sqr. Meter", "Sqr. Kilometer", "Sqr. Mile", "Sqr. Foot", "Acre" };
    int columns = 3, rows = 2, startX = 36, startY = 7, spacing = 18;

    bool stop = false;
    while (!stop) {
        clearScreen();  // Clear input/output area same as length()

        // Print header, centered at y=5
        cout << RED;
        printCentered("Area", 5);
        cout << YELLOW;

        // Print unit options in 2 rows, 3 columns max
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
        double amount;

        // Prompt for amount
        setCursorPosition(startX, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument&) {
            setCursorPosition(startX, 17);
            cout << RED "Invalid input. Type a number." RESET;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            continue;
        }

        // Prompt for 'from' unit
        setCursorPosition(startX, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;

        // Prompt for 'to' unit
        setCursorPosition(startX, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;

        // Normalize inputs to lowercase
        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        setCursorPosition(startX, 16);
        cout << GREEN;

        // Conversion pairs (area units)

        // For convenience, define shorthand checks:
        auto isFrom = [&](const vector<string>& options) {
            return find(options.begin(), options.end(), from) != options.end();
            };
        auto isTo = [&](const vector<string>& options) {
            return find(options.begin(), options.end(), to) != options.end();
            };

        // Unit groups with possible input strings
        vector<string> sqmUnits = { "sqr. meter", "sqm", "square meter", "square meters" };
        vector<string> sqkmUnits = { "sqr. kilometer", "sqkm", "square kilometer", "square kilometers" };
        vector<string> sqmiUnits = { "sqr. mile", "sqmi", "square mile", "square miles" };
        vector<string> sqftUnits = { "sqr. foot", "sqft", "square foot", "square feet" };
        vector<string> acreUnits = { "acre", "acres" };

        // Now check all combinations and convert accordingly
        // Conversions between sqm and others
        if (isFrom(sqmUnits) && isTo(sqkmUnits)) {
            cout << amount << " sqm = " << fixed << setprecision(4) << sqmToSqkm(amount) << " sqkm";
            stop = true;
        }
        else if (isFrom(sqkmUnits) && isTo(sqmUnits)) {
            cout << amount << " sqkm = " << fixed << setprecision(4) << sqkmToSqm(amount) << " sqm";
            stop = true;
        }
        else if (isFrom(sqmUnits) && isTo(sqmiUnits)) {
            cout << amount << " sqm = " << fixed << setprecision(4) << sqmToSqmi(amount) << " sqmi";
            stop = true;
        }
        else if (isFrom(sqmiUnits) && isTo(sqmUnits)) {
            cout << amount << " sqmi = " << fixed << setprecision(4) << sqmiToSqm(amount) << " sqm";
            stop = true;
        }
        else if (isFrom(sqmUnits) && isTo(sqftUnits)) {
            cout << amount << " sqm = " << fixed << setprecision(4) << sqmToSqft(amount) << " sqft";
            stop = true;
        }
        else if (isFrom(sqftUnits) && isTo(sqmUnits)) {
            cout << amount << " sqft = " << fixed << setprecision(4) << sqftToSqm(amount) << " sqm";
            stop = true;
        }
        else if (isFrom(sqmUnits) && isTo(acreUnits)) {
            cout << amount << " sqm = " << fixed << setprecision(4) << sqmToAcre(amount) << " acres";
            stop = true;
        }
        else if (isFrom(acreUnits) && isTo(sqmUnits)) {
            cout << amount << " acres = " << fixed << setprecision(4) << acreToSqm(amount) << " sqm";
            stop = true;
        }

        // Convert between sqkm and others (except sqm handled above)
        else if (isFrom(sqkmUnits) && isTo(sqmiUnits)) {
            cout << amount << " sqkm = " << fixed << setprecision(4) << sqkmToSqmi(amount) << " sqmi";
            stop = true;
        }
        else if (isFrom(sqmiUnits) && isTo(sqkmUnits)) {
            cout << amount << " sqmi = " << fixed << setprecision(4) << sqmiToSqkm(amount) << " sqkm";
            stop = true;
        }
        else if (isFrom(sqkmUnits) && isTo(sqftUnits)) {
            cout << amount << " sqkm = " << fixed << setprecision(4) << sqkmToSqft(amount) << " sqft";
            stop = true;
        }
        else if (isFrom(sqftUnits) && isTo(sqkmUnits)) {
            cout << amount << " sqft = " << fixed << setprecision(4) << sqftToSqkm(amount) << " sqkm";
            stop = true;
        }
        else if (isFrom(sqkmUnits) && isTo(acreUnits)) {
            cout << amount << " sqkm = " << fixed << setprecision(4) << sqkmToAcre(amount) << " acres";
            stop = true;
        }
        else if (isFrom(acreUnits) && isTo(sqkmUnits)) {
            cout << amount << " acres = " << fixed << setprecision(4) << acreToSqkm(amount) << " sqkm";
            stop = true;
        }

        // Convert between sqmi and others (except sqm and sqkm handled above)
        else if (isFrom(sqmiUnits) && isTo(sqftUnits)) {
            cout << amount << " sqmi = " << fixed << setprecision(4) << sqmiToSqft(amount) << " sqft";
            stop = true;
        }
        else if (isFrom(sqftUnits) && isTo(sqmiUnits)) {
            cout << amount << " sqft = " << fixed << setprecision(4) << sqftToSqmi(amount) << " sqmi";
            stop = true;
        }
        else if (isFrom(sqmiUnits) && isTo(acreUnits)) {
            cout << amount << " sqmi = " << fixed << setprecision(4) << sqmiToAcre(amount) << " acres";
            stop = true;
        }
        else if (isFrom(acreUnits) && isTo(sqmiUnits)) {
            cout << amount << " acres = " << fixed << setprecision(4) << acreToSqmi(amount) << " sqmi";
            stop = true;
        }

        // Convert between sqft and acres
        else if (isFrom(sqftUnits) && isTo(acreUnits)) {
            cout << amount << " sqft = " << fixed << setprecision(4) << sqftToAcre(amount) << " acres";
            stop = true;
        }
        else if (isFrom(acreUnits) && isTo(sqftUnits)) {
            cout << amount << " acres = " << fixed << setprecision(4) << acreToSqft(amount) << " sqft";
            stop = true;
        }
        else {
            setCursorPosition(startX, 17);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }

        if (stop) {
            setCursorPosition(startX, 17);
            cout << YELLOW "Press any key to continue..." RESET;
            cin.get(); cin.get();
        }
    }
}


void Measurement::volume() {
    bool stop = false;
    double amount;

    while (!stop) {
        cout << RED;
        printCentered("Volume", 5);
        cout << YELLOW;

        vector<string> arr = { "Cubic Meter", "Cubic Kilometer", "Liter", "Milliliter", "US Gallon", "US Pint" };
        int columns = 3, rows = 2, startX = 36, startY = 7, spacing = 18;
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

        setCursorPosition(36, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(36, 17);
            cout << RED "Invalid input. Type a number." RESET;
            cin.get(); cin.get();
            continue;
        }

        setCursorPosition(36, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;

        setCursorPosition(36, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;

        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        setCursorPosition(36, 16);
        cout << GREEN;

        double liters = toLiters(amount, from);
        if (liters < 0) {
            setCursorPosition(36, 17);
            cout << RED "Invalid 'from' unit." RESET;
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        double result = fromLiters(liters, to);
        if (result < 0) {
            setCursorPosition(36, 17);
            cout << RED "Invalid 'to' unit." RESET;
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        cout << amount << " " << from << " = " << fixed << setprecision(4) << result << " " << to;

        stop = true;

        setCursorPosition(36, 17);
        cout << YELLOW "Press any key to continue...";
        cin.get(); cin.get();
    }
}


void Measurement::weight() {
    bool stop = false;
    double amount;

    while (!stop) {
        cout << RED; 
        printCentered("Weight", 5);
        cout << YELLOW;

        vector<string> arr = { "Kilogram", "Gram", "Milligram", "Pound", "Ounce" };
        int columns = 3, rows = 2, startX = 36, startY = 7, spacing = 18;
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

        setCursorPosition(36, 12);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;
        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(36, 17);
            cout << RED "Invalid input. Type a number." RESET;
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        setCursorPosition(36, 13);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;

        setCursorPosition(36, 14);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;

        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        setCursorPosition(36, 16);
        cout << GREEN;

        double kilograms = toKilograms(amount, from);
        if (kilograms < 0) {
            setCursorPosition(36, 17);
            cout << RED "Invalid 'from' unit." RESET;
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        double result = fromKilograms(kilograms, to);
        if (result < 0) {
            setCursorPosition(36, 17);
            cout << RED "Invalid 'to' unit." RESET;
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        cout << amount << " " << from << " = " << fixed << setprecision(4) << result << " " << to;

        stop = true;

        setCursorPosition(36, 17);
        cout << YELLOW "Press any key to continue...";
        cin.get(); cin.get();
    }
}

void Measurement::timeConv() {

    bool stop = false;
    double amount;

    while (!stop) {
        setCursorPosition(47, 3);
        cout << RED;
        printCentered("Time", 5);
        cout << YELLOW;

        vector<string> arr = { "Second", "Minute", "Hour", "Day" };
        int spacing = 12, startX = 40, startY = 7;
        for (int i = 0; i < arr.size(); i++) {
            setCursorPosition(startX + i * spacing, startY);
            cout << arr[i];
        }

        string from, input, to;

        setCursorPosition(36, 10);
        cout << YELLOW "Enter amount: " GREEN;
        cin >> input;

        try {
            amount = stod(input);
        }
        catch (const invalid_argument& e) {
            setCursorPosition(36, 16);
            cout << RED "Invalid input. Type a number." RESET;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); cin.get();
            clearScreen();
            continue;
        }

        setCursorPosition(36, 11);
        cout << YELLOW "Convert from (enter unit): " GREEN;
        cin >> from;

        setCursorPosition(36, 12);
        cout << YELLOW "Convert to (enter unit): " GREEN;
        cin >> to;

        transform(from.begin(), from.end(), from.begin(), ::tolower);
        transform(to.begin(), to.end(), to.begin(), ::tolower);

        setCursorPosition(36, 14);
        cout << GREEN;

        // Conversion logic unchanged...

        if ((from == "second" || from == "s") && (to == "minute" || to == "min")) {
            cout << amount << " s = " << fixed << setprecision(2)
                << secToMinConverter(amount, true) << " min";
            stop = true;
        }
        else if ((from == "minute" || from == "min") && (to == "second" || to == "s")) {
            cout << amount << " min = " << fixed << setprecision(2)
                << secToMinConverter(amount, false) << " s";
            stop = true;
        }
        else if ((from == "second" || from == "s") && (to == "hour" || to == "hr")) {
            cout << amount << " s = " << fixed << setprecision(2)
                << secToHourConverter(amount, true) << " hr";
            stop = true;
        }
        else if ((from == "hour" || from == "hr") && (to == "second" || to == "s")) {
            cout << amount << " hr = " << fixed << setprecision(2)
                << secToHourConverter(amount, false) << " s";
            stop = true;
        }
        else if ((from == "second" || from == "s") && (to == "day" || to == "d")) {
            cout << amount << " s = " << fixed << setprecision(2)
                << secToDayConverter(amount, true) << " d";
            stop = true;
        }
        else if ((from == "day" || from == "d") && (to == "second" || to == "s")) {
            cout << amount << " d = " << fixed << setprecision(2)
                << secToDayConverter(amount, false) << " s";
            stop = true;
        }
        else if ((from == "minute" || from == "min") && (to == "hour" || to == "hr")) {
            cout << amount << " min = " << fixed << setprecision(2)
                << minToHourConverter(amount, true) << " hr";
            stop = true;
        }
        else if ((from == "hour" || from == "hr") && (to == "minute" || to == "min")) {
            cout << amount << " hr = " << fixed << setprecision(2)
                << minToHourConverter(amount, false) << " min";
            stop = true;
        }
        else if ((from == "minute" || from == "min") && (to == "day" || to == "d")) {
            cout << amount << " min = " << fixed << setprecision(4)
                << minToDayConverter(amount, true) << " d";
            stop = true;
        }
        else if ((from == "day" || from == "d") && (to == "minute" || to == "min")) {
            cout << amount << " d = " << fixed << setprecision(2)
                << minToDayConverter(amount, false) << " min";
            stop = true;
        }
        else if ((from == "hour" || from == "hr") && (to == "day" || to == "d")) {
            cout << amount << " hr = " << fixed << setprecision(4)
                << hourToDayConverter(amount, true) << " d";
            stop = true;
        }
        else if ((from == "day" || from == "d") && (to == "hour" || to == "hr")) {
            cout << amount << " d = " << fixed << setprecision(2)
                << hourToDayConverter(amount, false) << " hr";
            stop = true;
        }
        else {
            setCursorPosition(36, 16);
            cout << RED "Invalid input. Try again" RESET;
            cin.get(); cin.get();
        }

        if (stop) {
            setCursorPosition(36, 16);
            cout << YELLOW "Press any key to continue..." RESET;
            cin.get(); cin.get();
        }
    }
}

