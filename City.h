#ifndef CITY_H
#define CITY_H

#include <string>
#include <climits> // Needed for INT_MAX (Infinity)

using namespace std;

struct City {
    // --- BASIC IDENTITY ---
    int id;
    string name;

    // --- FLOOD & TRIAGE STATUS (For Ehsaan's Logic) ---
    int injuredCount;       // Number of casualties (higher = more critical)
    bool isFlooded;         // True if the flood simulation reached here
    int priorityScore;      // Calculated score for the Priority Queue
    bool isSafe;            // True if supplies have been delivered

    // --- NAVIGATION DATA (For Adil's Dijkstra Logic) ---
    int minDistance;        // The shortest time found so far (initially Infinity)
    int previousCityID;     // The city we came from (to reconstruct the path)

    // --- CONSTRUCTOR ---
    City(int _id = -1, string _name = "") {
        id = _id;
        name = _name;

        // Default Simulation Values
        injuredCount = 0;
        priorityScore = 0;
        isFlooded = false;
        isSafe = true;      // Safe until proven otherwise

        // Default Dijkstra Values
        minDistance = INT_MAX; // Represents "Unknown/Unreachable" initially
        previousCityID = -1;
    }
};

#endif