#ifndef CITYMANAGER_H
#define CITYMANAGER_H
#include "LinkedList.h"
#include "City.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

class CityManager
{
private:
    LinkedList cities; // Stores the cities using a linked list
public:
    // Constructor
    CityManager();

    // Load cities from a file
    void loadFromFile();

    // Save cities to a file
    void saveToFile() const;

    // Add a city to the list
    void addCity(const City &city);

    // Delete a city by name and state/country
    bool deleteCity(const std::string &name, const std::string &state_or_country);

    // Display all cities or a specific city
    void displayAll() const;

    // Calculate the distance between two cities
    void calculateDistance(const std::string &name1, const std::string &state1,
                           const std::string &name2, const std::string &state2) const;

    // Modify the details of an existing city
    void modifyCity(const std::string &name, const std::string &state_or_country);

    // Sort cities by year (ascending/descending)
    void sortCitiesByYear(bool ascending);

    // Display cities by state or country
    void displayCitiesByStateOrCountry(const std::string &state_or_country) const;

    // Display cities with the same name but different states or countries
    void displayCitiesWithSameNameDifferentCountries() const;
};

#endif // CITYMANAGER_H