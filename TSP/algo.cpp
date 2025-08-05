
#include "city.h"
#include "TSP.h"

int main() {
    TSP tsp(5);

    tsp.addCity("City1");
    tsp.addCity("City2");
    tsp.addCity("City3");
    tsp.addCity("City4");
    tsp.addCity("City5"); //add cities to the list

    tsp.setDistance("City1", "City2", 800);
    tsp.setDistance("City1", "City3", 1000);
    tsp.setDistance("City1", "City4", 1200);
    tsp.setDistance("City2", "City3", 600);
    tsp.setDistance("City2", "City4", 900);
    tsp.setDistance("City3", "City4", 700);
    tsp.setDistance("City1", "City5", 1200);
    tsp.setDistance("City2", "City5", 1100);
    tsp.setDistance("City3", "City5", 900);
    tsp.setDistance("City4", "City5", 1800); //dumb code directly assigning distances (testing purposes). Method for distance reading from file is located in TCP.h file.


    tsp.loadCitiesFromFile("../temp/cities.txt"); 


    tsp.solve(); //find optimal solution


    return 0;
}