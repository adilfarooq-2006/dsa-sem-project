// #ifndef FLOOD_SYSTEM_H
// #define FLOOD_SYSTEM_H

// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>   // For Priority Queue & BFS
// #include <stack>   // For Supplies
// #include <map>     // <--- REQUIRED for your Ahmed_Data.cpp
// #include <climits> // For INT_MAX

// using namespace std; // <--- This fixes the "string does not name a type" errors

// // 1. Define the City Structure
// struct City {
//     int id;
//     string name;
//     int injuredCount;
//     bool isFlooded;
//     bool hasReceivedAid;
//     int priorityScore;
//     int minDistance;
//     int previousCityID;
// };

// // Comparator for Priority Queue (Needed for Ehsaan)
// struct ComparePriority {
//     bool operator()(City const& p1, City const& p2) {
//         return p1.injuredCount < p2.injuredCount;
//     }
// };

// // 2. Define the Class
// class FloodReliefSystem {
// public:
//     // IMPORTANT: Changed from Array [25] to Map for your code to work
//     map<int, City> cityDatabase;

//     // Graph storage (Adil's part)
//     // Uses a Map now for consistency: RoadNetwork[CityID] -> List of Neighbors
//     map<int, vector<pair<int, int>>> roadNetwork;

//     // Warehouses (Ehsaan's part)
//     // Queue for emergency alerts
//     priority_queue<City, vector<City>, ComparePriority> emergencyQueue;

//     // Stacks for stock
//     stack<string> stockIslamabad;
//     stack<string> stockLahore;

//     // --- FUNCTION PROTOTYPES ---

//     // Constructor
//     FloodReliefSystem();

//     // Ahmed's Functions
//     void loadCities();
//     void updateCityStatus(int id);
//     void evaporateFlood();
//     City getCity(int id);

//     // Ehsaan's Functions
//     void loadStock();
//     void simulateFloodSpread(int startCityID);
//     bool hasSupplies(string warehouse);
//     void dispatchSupply(string warehouse);

//     // Adil's Functions
//     void loadRoads();
//     void runDijkstra(int startID);
//     void visualizePath(int startID, int endID);
//     void processNextEmergency();
// };

// #endif