#include "CityManager.h"
using namespace std;

// Constructor
CityManager::CityManager() : cities() {}

// Load cities from file
void CityManager::loadFromFile()
{
    ifstream inFile("cities.txt");
    if (!inFile)
    {
        cerr << "Error: Could not open file cities.txt for reading.\n";
        return;
    }
    string line;
    while (getline(inFile, line))
    {
        try
        {
            City city = City::deserialize(line);
            cities.loaded(city);
        }
        catch (const exception &e)
        {
            cerr << "Error: Invalid data format in file. " << e.what() << endl;
        }
    }
    cout << "Data loaded into memory.\n";
    inFile.close();
}

// Save cities to file
void CityManager::saveToFile() const
{
    ofstream outFile("cities.txt");
    if (!outFile)
    {
        cerr << "Error: Could not open file cities.txt for writing.\n";
        return;
    }
    Node *current = cities.getHead(); // Start from the head of the linked list
    while (current)
    {
        outFile << current->data.serialize() << "\n";
        current = current->next; // Move to the next node
    }
    cout << "Data successfully saved to cities.txt.\n";
}

// Add a city to the list
void CityManager::addCity(const City &city)
{
    // Prevent duplicate entries
    Node *current = cities.getHead();
    while (current)
    {
        if (current->data.name == city.name && current->data.state_or_country == city.state_or_country)
        {
            cout << "Duplicate city detected: " << city.name << " in " << city.state_or_country << ". Not added.\n";
            return;
        }
        current = current->next;
    }
    cities.add(city);
    cout << "City " << city.name << " (" << city.state_or_country << ") added successfully!\n";
}

// Delete a city
bool CityManager::deleteCity(const string &name, const string &state_or_country)
{
    Node *current = cities.getHead();
    Node *prev = nullptr;
    while (current)
    {
        if (trim(current->data.name) == trim(name) &&
            trim(current->data.state_or_country) == trim(state_or_country))
        {
            if (prev)
            {
                prev->next = current->next; // Bypass the current node
            }
            else
            {
                cities.setHead(current->next); // Update head using setter
            }

            delete current; // Free memory
            cout << "City " << name << " (" << state_or_country << ") deleted successfully!\n";
            return true;
        }
        prev = current;
        current = current->next;
    }
    cout << "City " << name << " (" << state_or_country << ") not found!\n";
    return false;
}

// Display all cities
void CityManager::displayAll() const
{
    string choice;
    cout << "Do you want to see all cities or a specific city by name? (Enter 'all' or 'name'): ";
    getline(cin, choice);
    if (choice == "all")
    {
        string fields;
        cout << "Enter the fields you want to see (e.g., 'name', 'population', 'mayor', 'all' for all fields): ";
        getline(cin, fields);
        if (!cities.getHead())
        {
            cout << "No cities available to display.\n";
            return;
        }
        cout << "\nDisplaying cities:\n";
        Node *current = cities.getHead();
        while (current)
        {
            const City &city = current->data;
            cout << "\n---------------------------------" << endl;
            if (fields == "name" || fields == "all")
                cout << "Name: " << city.name << endl;
            if (fields == "state" || fields == "all")
                cout << "State/Country: " << city.state_or_country << endl;
            if (fields == "population" || fields == "all")
                cout << "Population: " << city.population << endl;
            if (fields == "year" || fields == "all")
                cout << "Year Recorded: " << city.yearRecorded << endl;
            if (fields == "mayor" || fields == "all")
                cout << "Mayor: " << city.mayor << endl;
            if (fields == "mayor_address" || fields == "all")
                cout << "Mayor Address: " << city.mayorAddress << endl;
            if (fields == "history" || fields == "all")
                cout << "Short History: " << city.shortHistory << endl;
            if (fields == "latitude" || fields == "all")
                cout << "Latitude: " << city.coords.latitude << endl;
            if (fields == "longitude" || fields == "all")
                cout << "Longitude: " << city.coords.longitude << endl;
            current = current->next; // Move to the next node
        }
        cout << "---------------------------------\n";
    }
    else if (choice == "name")
    {
        string cityName, stateOrCountry;
        cout << "Enter the name of the city you want to see: ";
        getline(cin, cityName);
        cout << "Enter the state or country of the city: ";
        getline(cin, stateOrCountry);
        string fields;
        cout << "Enter the fields you want to see (e.g., 'name', 'population', 'mayor', 'all' for all fields): ";
        getline(cin, fields);
        Node *current = cities.getHead();
        while (current)
        {
            const City &city = current->data;
            if (city.name == cityName && city.state_or_country == stateOrCountry)
            {
                cout << "\n---------------------------------" << endl;

                if (fields == "name" || fields == "all")
                    cout << "Name: " << city.name << endl;
                if (fields == "state" || fields == "all")
                    cout << "State/Country: " << city.state_or_country << endl;
                if (fields == "population" || fields == "all")
                    cout << "Population: " << city.population << endl;
                if (fields == "year" || fields == "all")
                    cout << "Year Recorded: " << city.yearRecorded << endl;
                if (fields == "mayor" || fields == "all")
                    cout << "Mayor: " << city.mayor << endl;
                if (fields == "mayor_address" || fields == "all")
                    cout << "Mayor Address: " << city.mayorAddress << endl;
                if (fields == "history" || fields == "all")
                    cout << "Short History: " << city.shortHistory << endl;
                if (fields == "latitude" || fields == "all")
                    cout << "Latitude: " << city.coords.latitude << endl;
                if (fields == "longitude" || fields == "all")
                    cout << "Longitude: " << city.coords.longitude << endl;

                cout << "---------------------------------\n";
                return;
            }
            current = current->next;
        }
        cout << "City not found.\n";
    }
    else
    {
        cout << "Invalid choice. Please enter 'all' or 'name'.\n";
    }
}

void CityManager::calculateDistance(const string &name1, const string &state1, const string &name2, const string &state2) const
{
    const double earthRadius = 6371.0; // Earth's mean radius in kilometers
    // Find the two cities in the linked list
    const City *city1 = nullptr;
    const City *city2 = nullptr;
    Node *current = cities.getHead();
    while (current)
    {
        const City &city = current->data;
        if (city.name == name1 && city.state_or_country == state1)
        {
            city1 = &city;
        }
        if (city.name == name2 && city.state_or_country == state2)
        {
            city2 = &city;
        }
        current = current->next; // Move to the next node
    }
    if (!city1 || !city2)
    {
        cout << "One or both cities not found.\n";
        return;
    }
    // Convert degrees to radians
    auto toRadians = [](double degrees)
    {
        return degrees * M_PI / 180.0;
    };
    double phi1 = toRadians(city1->coords.latitude);
    double phi2 = toRadians(city2->coords.latitude);
    double lambda1 = toRadians(city1->coords.longitude);
    double lambda2 = toRadians(city2->coords.longitude);
    // Custom clamp implementation
    auto clamp = [](double value, double min, double max)
    {
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    };
    // Calculate angular distance (in radians)
    double cos_d = sin(phi1) * sin(phi2) + cos(phi1) * cos(phi2) * cos(lambda1 - lambda2);
    cos_d = clamp(cos_d, -1.0, 1.0); // Clamp to avoid errors due to floating-point precision
    double d = acos(cos_d);
    // Convert angular distance to linear distance
    double distance = earthRadius * d;
    // Display result
    cout << fixed << setprecision(2);
    cout << "The distance between " << name1 << ", " << state1 << " and " << name2 << ", " << state2
         << " is " << distance << " kilometers.\n";
}

void CityManager::modifyCity(const string &name, const string &state_or_country)
{
    // Traverse the linked list to find the city
    Node *current = cities.getHead();
    while (current)
    {
        City &city = current->data;
        if (city.name == name && city.state_or_country == state_or_country)
        {
            // Display the current details of the city
            cout << "Current details of the city:\n";
            cout << "1. Name: " << city.name << "\n";
            cout << "2. State/Country: " << city.state_or_country << "\n";
            cout << "3. Population: " << city.population << "\n";
            cout << "4. Year Recorded: " << city.yearRecorded << "\n";
            cout << "5. Mayor: " << city.mayor << "\n";
            cout << "6. Mayor Address: " << city.mayorAddress << "\n";
            cout << "7. Short History: " << city.shortHistory << "\n";
            cout << "8. Latitude: " << city.coords.latitude << "\n";
            cout << "9. Longitude: " << city.coords.longitude << "\n";
            cout << "\nEnter the number of the field you want to update (or 0 to cancel): ";
            int field;
            cin >> field;
            cin.ignore(); // Clear newline from input buffer
            if (field == 0)
            {
                cout << "Update cancelled.\n";
                return;
            }
            switch (field)
            {
            case 1:
            {
                cout << "Enter new name: ";
                string newName;
                getline(cin, newName);
                city.name = trim(newName);
                break;
            }
            case 2:
            {
                cout << "Enter new state/country: ";
                string newState;
                getline(cin, newState);
                city.state_or_country = trim(newState);
                break;
            }
            case 3:
            {
                cout << "Enter new population: ";
                int newPopulation;
                cin >> newPopulation;
                cin.ignore();
                city.population = newPopulation;
                break;
            }
            case 4:
            {
                cout << "Enter new year: ";
                int newYear;
                cin >> newYear;
                cin.ignore();
                city.yearRecorded = newYear;
                break;
            }
            case 5:
            {
                cout << "Enter new mayor: ";
                string newMayor;
                getline(cin, newMayor);
                city.mayor = trim(newMayor);
                break;
            }
            case 6:
            {
                cout << "Enter new mayor address: ";
                string newAddress;
                getline(cin, newAddress);
                city.mayorAddress = trim(newAddress);
                break;
            }
            case 7:
            {
                cout << "Enter new short history: ";
                string newHistory;
                getline(cin, newHistory);
                city.shortHistory = trim(newHistory);
                break;
            }
            case 8:
            {
                cout << "Enter new latitude: ";
                double newLatitude;
                cin >> newLatitude;
                cin.ignore();
                city.coords.latitude = newLatitude;
                break;
            }
            case 9:
            {
                cout << "Enter new longitude: ";
                double newLongitude;
                cin >> newLongitude;
                cin.ignore();
                city.coords.longitude = newLongitude;
                break;
            }
            default:
                cout << "Invalid field number. Update cancelled.\n";
                return;
            }
            cout << "City details updated successfully.\n";
            return;
        }

        current = current->next; // Move to the next node
    }

    cout << "City not found.\n";
}

void CityManager::sortCitiesByYear(bool ascending)
{
    // Bubble Sort Algorithm to sort cities based on the year
    if (!cities.getHead())
        return; // If the list is empty, no need to sort
    Node *current = cities.getHead();
    while (current)
    {
        Node *nextNode = current->next;
        while (nextNode)
        {
            bool condition = ascending ? current->data.yearRecorded > nextNode->data.yearRecorded
                                       : current->data.yearRecorded < nextNode->data.yearRecorded;
            if (condition)
            {
                // Swap data between nodes
                City temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
    cout << "\nCities sorted by year.\n";
}

void CityManager::displayCitiesByStateOrCountry(const string &state_or_country) const
{
    bool found = false;
    Node *current = cities.getHead();
    while (current)
    {
        if (current->data.state_or_country == state_or_country)
        {
            const City &city = current->data;
            cout << fixed << setprecision(2);
            cout << "------------------------------------\n";
            cout << "Name: " << city.name << ", State/Country: " << city.state_or_country
                 << ", Population: " << city.population << ", Year: " << city.yearRecorded
                 << ", Mayor: " << city.mayor << ", Address: " << city.mayorAddress
                 << ", Short History: " << city.shortHistory << ", Latitude: "
                 << city.coords.latitude << ", Longitude: " << city.coords.longitude << endl;
            cout << "------------------------------------\n";
            found = true;
        }
        current = current->next;
    }
    if (!found)
    {
        cout << "No cities found in " << state_or_country << ".\n";
    }
}

void CityManager::displayCitiesWithSameNameDifferentCountries() const
{
    bool found = false;
    Node *current1 = cities.getHead();
    while (current1)
    {
        Node *current2 = current1->next;
        while (current2)
        {
            // If the cities have the same name but are located in different states or countries
            if (current1->data.name == current2->data.name &&
                current1->data.state_or_country != current2->data.state_or_country)
            {
                if (!found)
                {
                    cout << "Cities with the same name in different countries/states:\n";
                    found = true;
                }
                // Display the details of both cities
                cout << "-------------------------------------------\n";
                cout << "Name: " << current1->data.name << ", State/Country: " << current1->data.state_or_country
                     << ", Population: " << current1->data.population << ", Year: " << current1->data.yearRecorded
                     << ", Mayor: " << current1->data.mayor << ", Address: " << current1->data.mayorAddress
                     << ", Short History: " << current1->data.shortHistory << ", Latitude: "
                     << current1->data.coords.latitude << ", Longitude: " << current1->data.coords.longitude << endl;
                cout << "Name: " << current2->data.name << ", State/Country: " << current2->data.state_or_country
                     << ", Population: " << current2->data.population << ", Year: " << current2->data.yearRecorded
                     << ", Mayor: " << current2->data.mayor << ", Address: " << current2->data.mayorAddress
                     << ", Short History: " << current2->data.shortHistory << ", Latitude: "
                     << current2->data.coords.latitude << ", Longitude: " << current2->data.coords.longitude << endl;
                cout << "-------------------------------------------\n";
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    if (!found)
    {
        cout << "No cities with the same name found in different states or countries.\n";
    }
}