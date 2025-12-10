#ifndef FLOOD_SYSTEM_H
#define FLOOD_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>  // 🔥 REPLACED map with HASHMAP
#include <climits>
#include <cmath>

using namespace std;

// ==========================================
// SHARED DATA STRUCTURE: THE CITY
// ==========================================
struct City {
    int id;
    string name;
    int injuredCount = 0;
    bool isFlooded = false;
    bool hasReceivedAid = false;
    int priorityScore = 0;

    int minDistance = INT_MAX;
    int previousCityID = -1;
};

// Comparator for Priority Queue
struct ComparePriority {
    bool operator()(City const& p1, City const& p2) {
        return p1.injuredCount < p2.injuredCount;
    }
};

// ==========================================
// MAIN SYSTEM CLASS
// ==========================================
class FloodReliefSystem {
private:

    // 🔥 HASHMAP instead of map
    unordered_map<int, City> cityDatabase;

    // Graph: still okay as unordered_map (Used by ADIL)
    unordered_map<int, vector<pair<int,int>>> roadNetwork;

    priority_queue<City, vector<City>, ComparePriority> emergencyQueue;

    stack<string> stockIslamabad;
    stack<string> stockLahore;

public:
    FloodReliefSystem() {
        loadCities();
        loadRoads();
        loadStock();
    }

    // --- AHMED ---
    void loadCities();
    void updateCityStatus(int id);
    void evaporateFlood();
    City getCity(int id);

    // --- EHSAAN ---
    void loadStock();
    void simulateFloodSpread(int startCityID);
    bool hasSupplies(string warehouse);
    void dispatchSupply(string warehouse);

    // --- ADIL ---
    void loadRoads();
    void runDijkstra(int startID);
    void visualizePath(int startID, int endID);

    void processNextEmergency();
};

#endif
