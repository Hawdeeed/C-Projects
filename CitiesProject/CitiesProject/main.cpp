#include <iostream>
#include "CityManager.h"
using namespace std;

int main()
{
    CityManager manager;
    // Load data from file at the start
    manager.loadFromFile();
    string command;
    cout << "City Manager Program\n";
    cout << "------------------------------------------------------------------\n";
    cout << "Available commands:\n";
    cout << "1. add <name>, <state_or_country>, <population>, <year>, <mayor>, <mayor_address>, <short_history>, <latitude>, <longitude>\n";
    cout << "2. delete <name>, <state_or_country>\n";
    cout << "3. display\n";
    cout << "4. modify <city_name>, <state_or_country>\n";
    cout << "5. distance <name_city1>, <state_or_country_1>, <name_city2>, <state_or_country_2>\n";
    cout << "6. sort_by_year\n";
    cout << "7. search <country/state> (It will show all the cities in a country/state) \n";
    cout << "8. duplicate (it will show all cities with same names but in different countries)\n";
    cout << "9. save\n";
    cout << "10. quit\n";
    cout << "------------------------------------------------------------------\n";
    while (true)
    {
        cout << "\nEnter command: ";
        getline(cin, command);
        istringstream input(command);
        string action;
        input >> action;
        if (action == "add")
        {
            string name, state_or_country, mayor, mayor_address, short_history;
            int population = 0, year = 0;
            double latitude = 0.0, longitude = 0.0;
            try
            {
                // Parse and validate each field
                getline(input, name, ',');
                if (trim(name).empty())
                    throw invalid_argument("City name cannot be empty.");
                getline(input, state_or_country, ',');
                if (trim(state_or_country).empty())
                    throw invalid_argument("State or country cannot be empty.");
                if (!(input >> population) || population <= 0)
                    throw invalid_argument("Population must be a positive integer.");
                input.ignore(); // Ignore comma
                if (!(input >> year) || year <= 0)
                    throw invalid_argument("Year must be a positive integer.");
                input.ignore(); // Ignore comma
                getline(input, mayor, ',');
                if (trim(mayor).empty())
                    throw invalid_argument("Mayor cannot be empty.");
                getline(input, mayor_address, ',');
                if (trim(mayor_address).empty())
                    throw invalid_argument("Mayor address cannot be empty.");
                getline(input, short_history, ',');
                if (trim(short_history).empty())
                    throw invalid_argument("Short history cannot be empty.");
                if (!(input >> latitude) || latitude < -90.0 || latitude > 90.0)
                    throw invalid_argument("Latitude must be between -90 and 90 degrees.");
                input.ignore(); // Ignore comma
                if (!(input >> longitude) || longitude < -180.0 || longitude > 180.0)
                    throw invalid_argument("Longitude must be between -180 and 180 degrees.");
                // If all fields are valid, create the City object and add it
                City city(trim(name), trim(state_or_country), population, year, trim(mayor), trim(mayor_address), trim(short_history), Coordinates(latitude, longitude));
                manager.addCity(city);
            }
            // Catch any validation errors and notify the user
            catch (const exception &e)
            {
                cout << "Error adding city: " << e.what() << "\n";
            }
        }
        else if (action == "delete")
        {
            string name, state_or_country;
            getline(input, name, ',');
            getline(input, state_or_country, ',');
            manager.deleteCity(trim(name), trim(state_or_country));
        }
        else if (action == "display")
        {
            manager.displayAll(); // Default: Read from memory
        }
        else if (action == "modify")
        {
            string name, state_or_country;
            getline(input, name, ',');
            getline(input, state_or_country, ',');
            manager.modifyCity(trim(name), trim(state_or_country));
        }
        else if (action == "distance")
        {
            string name1, state1, name2, state2;
            // Read the parameters separated by commas
            getline(input, name1, ',');
            getline(input, state1, ',');
            getline(input, name2, ',');
            getline(input, state2, ',');
            // Pass trimmed values to the calculateDistance method
            manager.calculateDistance(trim(name1), trim(state1), trim(name2), trim(state2));
        }
        else if (action == "search")
        {
            string state_or_country;
            getline(input, state_or_country);          // Get the rest of the input after "search"
            state_or_country = trim(state_or_country); // Trim spaces around the input
            // If the state or country is provided, display cities in that state or country
            if (!state_or_country.empty())
            {
                manager.displayCitiesByStateOrCountry(state_or_country); // Display cities in the state or country
            }
            else
            {
                cout << "Invalid format. Please use the format: search <state/country>\n";
            }
        }
        else if (action == "duplicate")
        {
            manager.displayCitiesWithSameNameDifferentCountries();
        }

        else if (action == "sort_by_year")
        {
            manager.sortCitiesByYear(true); // Sort cities by year in ascending order
        }
        else if (action == "save")
        {
            manager.saveToFile();
        }
        else if (action == "quit")
        {
            manager.saveToFile();
            cout << "Exiting the program. Goodbye!\n";
            break;
        }
        else
        {
            cout << "Unknown command. Please try again.\n";
        }
    }
    return 0;
}