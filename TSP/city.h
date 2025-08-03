//THis is a city class header file

#pragma once
#include <iostream>
#include <vector>
#include <string>

/*
class City {
private:
    double x_coord;
    double y_coord;

public:
    // Constructor
    City(double x, double y) : x_coord(x), y_coord(y) {}

    // Getter methods for coordinates
    double getX() const {
        return x_coord;
    }

    double getY() const {
        return y_coord;
    }

    // Method to calculate distance to another city
    double calculateDistance(const City& other_city) const
};

*/


class City {
private:
    std::string name;
    int index;

public:
    City(const std::string& name_, int index_) : name(name_), index(index_) {}
    std::string getName() const { return name; }
    int getIndex() const { return index; }
};
