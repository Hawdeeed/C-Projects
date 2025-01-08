#ifndef CITY_H
#define CITY_H
#include <string>
#include <sstream>
#include "Coordinates.h"
#include "Utility.h"
using namespace std;

class City
{
public:
    // Attributes
    string name;
    string state_or_country;
    int population;
    int yearRecorded;
    string mayor;
    string mayorAddress;
    string shortHistory;
    Coordinates coords;

    // Constructor
    City(string name, string state_or_country, int pop, int year, string mayor, string address, string history, Coordinates coords);

    // Serialize city to a string
    string serialize() const;

    // Deserialize city from a string
    static City deserialize(const string &data);
};

#endif // CITY_H