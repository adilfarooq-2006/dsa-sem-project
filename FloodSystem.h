#ifndef FLOOD_SYSTEM_H
#define FLOOD_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> 
#include <climits>       

// --- CUSTOM MODULES  ---
#include "City.h"
#include "InventorySystem.h"     
#include "PriorityQueueSystem.h" 

using namespace std;

class FloodReliefSystem {
public:
    // --- DATA STRUCTURES ---
    unordered_map<int, City> cityDatabase;
    unordered_map<int, vector<pair<int, int>>> roadNetwork;

    PriorityQueueSystem emergencyQueue; // Your Custom Heap
    InventorySystem stockRawalpindi;     // Your Custom Stack
    InventorySystem stockLahore;        // Your Custom Stack

    // --- CONSTRUCTOR ---
    FloodReliefSystem();

    // --- AHMED'S WORK ---
    void loadCities();
    void updateCityStatus(int id);
    void evaporateFlood();
    City getCity(int id);

    // --- EHSAAN'S WORK (You) ---
    void loadStock();
    void simulateFloodSpread(int startCityID);
    bool hasSupplies(string warehouse);
    void dispatchSupply(string warehouse);
    void manualRestock();

    // --- ADIL'S WORK ---
    void loadRoads();
    void runDijkstra(int startID);
    void visualizePath(int startID, int endID);
    void processNextEmergency();
};

#endif