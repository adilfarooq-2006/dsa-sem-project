#ifndef FLOOD_SYSTEM_H
#define FLOOD_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> // <--- CHANGED: Uses Hash Table logic
#include <climits>       // For INT_MAX

// --- CUSTOM MODULES ---
#include "City.h"
#include "InventorySystem.h"     // Ehsaan's Custom Stack
#include "PriorityQueueSystem.h" // Ehsaan's Custom Heap

using namespace std;

class FloodReliefSystem {
public:
    // --- DATA STRUCTURES ---

    // 1. Database (Ahmed)
    // REPLACED: std::map (BST) with std::unordered_map (Hash Table)
    // Complexity: O(1) Average Case for Lookup
    unordered_map<int, City> cityDatabase;

    // 2. Graph (Adil)
    // RoadNetwork[CityID] -> List of {NeighborID, Distance}
    // REPLACED: std::map with std::unordered_map
    unordered_map<int, vector<pair<int, int>>> roadNetwork;

    // 3. Emergency Queue (Ehsaan) -> USING YOUR CUSTOM CLASS
    PriorityQueueSystem emergencyQueue;

    // 4. Warehouses (Ehsaan) -> USING YOUR CUSTOM CLASS
    InventorySystem stockIslamabad;
    InventorySystem stockLahore;

    // --- CONSTRUCTOR ---
    FloodReliefSystem();

    // --- FUNCTION PROTOTYPES ---

    // Ahmed's Functions (Data)
    void loadCities();
    void updateCityStatus(int id);
    void evaporateFlood();
    City getCity(int id);

    // Ehsaan's Functions (Events)
    void loadStock();
    void simulateFloodSpread(int startCityID);

    // Check if supplies exist (bool is safer/cleaner than string comparison)
    bool hasSupplies(string warehouse);
    void dispatchSupply(string warehouse);

    // Adil's Functions (Pathfinding)
    void loadRoads();
    void runDijkstra(int startID);
    void visualizePath(int startID, int endID);
    void processNextEmergency();
};

#endif