#ifndef FLOOD_SYSTEM_H
#define FLOOD_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>   // For Priority Queue & BFS
#include <stack>   // For Supplies
#include <map>     // For HashMap
#include <climits> // For INT_MAX (Infinity)
#include <cmath>   // For simple math

using namespace std;

// ==========================================
// SHARED DATA STRUCTURE: THE CITY
// ==========================================
struct City {
    int id;
    string name;
    int injuredCount = 0;       // Casualties (Set by Randomizer)
    bool isFlooded = false;     // True if flood reached here
    bool hasReceivedAid = false; // True if truck arrived
    int priorityScore = 0;      // Logic: injuredCount * severity
    
    // For Dijkstra (Adil)
    int minDistance = INT_MAX;  // "Infinity" initially
    int previousCityID = -1;    // To track the path back
};

// Comparator for Priority Queue (Max-Heap based on Injured Count)
struct ComparePriority {
    bool operator()(City const& p1, City const& p2) {
        // Returns true if p1 is LESS critical than p2
        return p1.injuredCount < p2.injuredCount;
    }
};

// ==========================================
// MAIN SYSTEM CLASS
// ==========================================
class FloodReliefSystem {
private:
    // --- DATA STRUCTURES ---
    
    // [Ahmed] HashMap: Fast lookup of City Details by ID
    map<int, City> cityDatabase;

    // [Adil] Graph: Adjacency List for Roads (pairs: neighborID, distance)
    map<int, vector<pair<int, int>>> roadNetwork;

    // [Ehsaan] Priority Queue: Critical Areas Management
    priority_queue<City, vector<City>, ComparePriority> emergencyQueue;

    // [Ehsaan] Stacks: Inventory Management
    stack<string> stockIslamabad;
    stack<string> stockLahore;

public:
    // Constructor
    FloodReliefSystem() {
        loadCities(); // Ahmed's setup
        loadRoads();  // Adil's setup
        loadStock();  // Ehsaan's setup
    }

    // ==========================================
    // PART 1: AHMED (Data & State)
    // ==========================================
    void loadCities();                 // Populate cityDatabase
    void updateCityStatus(int id);     // Mark city as 'Safe' or 'Helped'
    void evaporateFlood();             // Simulate flood receding (reduce casualties slightly)
    City getCity(int id);              // Helper to get city details

    // ==========================================
    // PART 2: EHSAAN (Events & Inventory)
    // ==========================================
    void loadStock();                  // Push items to stacks
    void simulateFloodSpread(int startCityID); // BFS Algorithm (The Flood)
    bool hasSupplies(string warehouse); // Check if stack is empty
    void dispatchSupply(string warehouse); // Pop from stack

    // ==========================================
    // PART 3: ADIL (Graph & Navigation)
    // ==========================================
    void loadRoads();                  // Build the Graph connections
    void runDijkstra(int startID);     // The Algorithm logic
    void visualizePath(int startID, int endID); // Print: "ISL -> Jhelum -> Gujrat"
    
    // The "Brain" that decides ISL vs LHR
    void processNextEmergency();       
};

#endif