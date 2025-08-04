#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include "city.h"

class TSP {
private:
    int n; // total number of cities
    std::vector<City> cities;
    std::vector<std::vector<int>> dist;

    //  dp[mask][i] - minimum route cost, while visiting cityies from "mask", i - is the last city in the set
    std::vector<std::vector<int>> dp;
    // recover route
    std::vector<std::vector<int>> parent;

public:
    //TSP class constructor
    TSP(int n_) : n(n_) {
        dist.resize(n, std::vector<int>(n, 0));
        dp.resize(1 << n, std::vector<int>(n, -1));
        parent.resize(1 << n, std::vector<int>(n, -1));
    }


    /*all of these method functions will be moved to TSP.cpp file to maintain OOP architecture (class description and method functions should be in different fiules*/
    void addCity(const std::string& name) {
        cities.emplace_back(name, cities.size()); //placing new city object at the end of <city> vector, without copying and memory over-usage
    }

    void setDistance(const std::string& cityName1, const std::string& cityName2, int d) /*this code should be extended with the code from city.h(calculate distance using city coords - 
        Pythagoras theorem. Code now sets distances directly for testing purposes
        */
    {
        int i = -1, j = -1;
        for (int k = 0; k < cities.size(); ++k) {
            if (cities[k].getName() == cityName1) i = k;
            if (cities[k].getName() == cityName2) j = k; //pretty dumb code for filling <dist> vector
        }
        if (i != -1 && j != -1) {  
            dist[i][j] = d;
            dist[j][i] = d; // route cost is the same in both directions
        }
        else {
            std::cerr << "Unknown city!\n";
        }
    }

    int tsp(int mask, int pos) {
        if (mask == (1 << n) - 1) {
            // all cities are visited, returning to starting point (0)
            return dist[pos][0];
        }

        if (dp[mask][pos] != -1)
            return dp[mask][pos];

        int ans = INT_MAX;
        for (int city = 0; city < n; ++city) {
            if (!(mask & (1 << city))) { // åif the city is not visited
                int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
                if (newAns < ans) {
                    ans = newAns;
                    parent[mask][pos] = city; // save the route (remember the way)
                }
            }
        }
        dp[mask][pos] = ans;
        return ans;
    }

    void solve() {
        int minCost = tsp(1, 0); // starting at city  0
        // recovering route
        std::vector<int> route;
        route.push_back(0);
        int mask = 1;
        int pos = 0;

        while (true) {
            int nextCity = parent[mask][pos];
            if (nextCity == -1)
                break;
            route.push_back(nextCity);
            mask |= (1 << nextCity);
            pos = nextCity;
            if (mask == (1 << n) - 1)
                break;
        }
        route.push_back(0); // return to starting point

        // print to console
        std::cout << "Shortest route:\n";
        for (int idx : route) {
            std::cout << cities[idx].getName() << " -> ";
        }
        std::cout << "END\nTotal route cost: " << minCost << "\n";
    }
}; 
