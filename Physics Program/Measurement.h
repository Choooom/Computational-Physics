#pragma once
#include <string>


class Measurement {

public:
    Measurement();

    void runUnitConverter();
    void mainMenu();

private:
    void length();
    void temperature();
    void area();
    void volume();
    void weight();
    void timeConv();

    // Area conversion helper functions
    double sqmToSqkm(double sqm);
    double sqkmToSqm(double sqkm);

    double sqmToSqmi(double sqm);
    double sqmiToSqm(double sqmi);

    double sqmToSqft(double sqm);
    double sqftToSqm(double sqft);

    double sqmToAcre(double sqm);
    double acreToSqm(double acre);

    double sqkmToSqmi(double sqkm);
    double sqmiToSqkm(double sqmi);

    double sqkmToSqft(double sqkm);
    double sqftToSqkm(double sqft);

    double sqkmToAcre(double sqkm);
    double acreToSqkm(double acre);

    double sqmiToSqft(double sqmi);
    double sqftToSqmi(double sqft);

    double sqmiToAcre(double sqmi);
    double acreToSqmi(double acre);

    double sqftToAcre(double sqft);
    double acreToSqft(double acre);

    double toLiters(double amount, const std::string& fromUnit);

    // Convert from liters to any supported unit
    double fromLiters(double liters, const std::string& toUnit);

    // Individual converters if needed internally (option

    // Convert from any supported weight unit to kilograms
    double toKilograms(double amount, const std::string& fromUnit);

    // Convert from kilograms to any supported weight unit
    double fromKilograms(double kilograms, const std::string& toUnit);

    // Optional detailed converters if you want to break it down internally

};
