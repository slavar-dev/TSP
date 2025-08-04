//THis is a city class header file

#pragma once
#include <iostream>
#include <vector>
#include <string>



class City {
private:
    std::string name;
    int index;
   /*
    // Constructor
    City(double x, double y) : x_coord(x), y_coord(y) {}

   double x_coord;
    double y_coord;
    Coordinates are commented out just for testing purposes - temporary used direct distance setting between cities
       // Method to calculate distance to another city
    double calculateDistance(const City& other_city) const
};
    */


public:
    City(const std::string& name_, int index_) : name(name_), index(index_) {} // Constructor
    std::string getName() const { return name; }
    int getIndex() const { return index; }
};
