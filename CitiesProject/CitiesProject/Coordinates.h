#ifndef COORDINATES_H
#define COORDINATES_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// Coordinates structure to store latitude and longitude
struct Coordinates
{
    double latitude;
    double longitude;
    // Constructor with default values
    Coordinates(double lat = 0.0, double lon = 0.0);
    // Calculate the distance between two coordinates (Haversine formula)
};

#endif // COORDINATES_H