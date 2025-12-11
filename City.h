#ifndef CITY_H
#define CITY_H

#include <string>
#include <climits> // For INT_MAX

using namespace std;

struct City {
    // --- BASIC IDENTITY ---
    int id;
    string name;

    // --- FLOOD & TRIAGE STATUS ---
    int injuredCount;       // Number of casualties
    bool isFlooded;         // True if flood reached here
    bool hasReceivedAid;    // True if truck arrived
    int priorityScore;      // Score for Priority Queue

    // --- NAVIGATION DATA (Dijkstra) ---
    int minDistance;        // Shortest time found so far
    int previousCityID;     // Path reconstruction tracker

    // --- CONSTRUCTOR 1: The "Old Format" (Accepts Everything) ---
    // This allows initialization like: {0, "Lahore", 10, true, false, 50, INT_MAX, -1}
    City(int _id, string _name, int _inj, bool _flood, bool _aid, int _prio, int _dist, int _prev) {
        id = _id;
        name = _name;
        injuredCount = _inj;
        isFlooded = _flood;
        hasReceivedAid = _aid;
        priorityScore = _prio;
        minDistance = _dist;
        previousCityID = _prev;
    }

    // --- CONSTRUCTOR 2: Default Constructor ---
    // Required by Maps and Arrays to create empty slots before data is filled
    City() {
        id = -1;
        name = "";
        injuredCount = 0;
        isFlooded = false;
        hasReceivedAid = false;
        priorityScore = 0;
        minDistance = INT_MAX;
        previousCityID = -1;
    }
};

#endif