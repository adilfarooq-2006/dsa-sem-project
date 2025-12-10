#ifndef FLOOD_SYSTEM_H
#define FLOOD_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map> // <--- Correct Library for Hash Map
#include <climits>

using namespace std;

struct City {
    int id;
    string name;
    int injuredCount;
    bool isFlooded;
    bool hasReceivedAid;
    int priorityScore;
    int minDistance;
    int previousCityID;
};

struct ComparePriority {
    bool operator()(City const& p1, City const& p2) {
        return p1.injuredCount < p2.injuredCount;
    }
};

class FloodReliefSystem {
public:
    // FIX 1: Change 'map' to 'unordered_map'
    unordered_map<int, City> cityDatabase;

    // FIX 2: Change 'map' to 'unordered_map' here too
    unordered_map<int, vector<pair<int, int>>> roadNetwork;

    priority_queue<City, vector<City>, ComparePriority> emergencyQueue;
    stack<string> stockIslamabad;
    stack<string> stockLahore;

    FloodReliefSystem(); // Constructor

    // Ahmed's Functions
    void loadCities();
    void updateCityStatus(int id);
    void evaporateFlood();
    City getCity(int id);

    // Ehsaan's Functions
    void loadStock();
    void simulateFloodSpread(int startCityID);
    bool hasSupplies(string warehouse);
    void dispatchSupply(string warehouse);

    // Adil's Functions
    void loadRoads();
    void runDijkstra(int startID);
    void visualizePath(int startID, int endID);
    void processNextEmergency();
};

#endif