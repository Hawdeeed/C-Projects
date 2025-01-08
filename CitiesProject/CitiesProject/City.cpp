#include "City.h"

// Constructor implementation
City::City(string name, string state_or_country, int pop, int year, string mayor, string address, string history, Coordinates coords)
    : name(name), state_or_country(state_or_country), population(pop), yearRecorded(year),
      mayor(mayor), mayorAddress(address), shortHistory(history), coords(coords) {}

// Serialize city to a string
string City::serialize() const
{
    ostringstream out;
    out << name << "," << state_or_country << "," << population << "," << yearRecorded << "," << mayor << ","
        << mayorAddress << "," << shortHistory << "," << coords.latitude << "," << coords.longitude;
    return out.str();
}

// Deserialize city from a string
City City::deserialize(const string &data)
{
    istringstream in(data);
    string name, state_or_country, mayor, mayorAddress, shortHistory;
    int population, yearRecorded;
    double latitude, longitude;
    // Read the comma-separated fields
    getline(in, name, ',');
    getline(in, state_or_country, ',');
    in >> population;
    in.ignore(); // Ignore the comma
    in >> yearRecorded;
    in.ignore(); // Ignore the comma
    getline(in, mayor, ',');
    getline(in, mayorAddress, ',');
    getline(in, shortHistory, ',');
    in >> latitude;
    in.ignore(); // Ignore the comma
    in >> longitude;
    // Return a new City object constructed from the parsed data
    return City(name, state_or_country, population, yearRecorded, mayor, mayorAddress, shortHistory, Coordinates(latitude, longitude));
}