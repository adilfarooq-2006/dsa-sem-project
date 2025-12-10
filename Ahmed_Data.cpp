#include "Flood_System.h" // Matches your new header name
#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

void FloodReliefSystem::loadCities() {
    // Syntax for Maps: cityDatabase[ID] = { ...data... };
    // We explicitly set INT_MAX and -1 for the last two fields (Dijkstra)
    
    cityDatabase[0]  = {0,  "Lahore",         10, true,  false, 50, INT_MAX, -1};
    cityDatabase[1]  = {1,  "Faisalabad",     5,  false, false, 20, INT_MAX, -1};
    cityDatabase[2]  = {2,  "Rawalpindi",     0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[3]  = {3,  "Gujranwala",     15, true,  false, 60, INT_MAX, -1};
    cityDatabase[4]  = {4,  "Multan",         8,  false, false, 25, INT_MAX, -1};
    cityDatabase[5]  = {5,  "Sialkot",        20, true,  false, 70, INT_MAX, -1};
    cityDatabase[6]  = {6,  "Bahawalpur",     3,  false, false, 10, INT_MAX, -1};
    cityDatabase[7]  = {7,  "Sargodha",       0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[8]  = {8,  "Jhang",          12, true,  false, 55, INT_MAX, -1};
    cityDatabase[9]  = {9,  "Pakpattan",      0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[10] = {10, "DG Khan",        25, true,  false, 90, INT_MAX, -1};
    cityDatabase[11] = {11, "Chiniot",        0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[12] = {12, "Mianwali",       7,  true,  false, 30, INT_MAX, -1};
    cityDatabase[13] = {13, "Khushab",        0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[14] = {14, "Attock",         2,  false, false, 5,  INT_MAX, -1};
    cityDatabase[15] = {15, "Jhelum",         10, true,  false, 50, INT_MAX, -1};
    cityDatabase[16] = {16, "Gujrat",         5,  false, false, 20, INT_MAX, -1};
    cityDatabase[17] = {17, "Rahim Yar Khan", 18, true,  false, 65, INT_MAX, -1};
    cityDatabase[18] = {18, "Vehari",         0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[19] = {19, "Okara",          3,  false, false, 10, INT_MAX, -1};
    cityDatabase[20] = {20, "Hafizabad",      0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[21] = {21, "Nankana Sahib",  0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[22] = {22, "Kasur",          8,  true,  false, 40, INT_MAX, -1};
    cityDatabase[23] = {23, "Sahiwal",        0,  false, false, 0,  INT_MAX, -1};
    cityDatabase[24] = {24, "Toba Tek Singh", 0,  false, false, 0,  INT_MAX, -1};

    cout << "[Ahmed] Data: 25 Cities Loaded into HashMap." << endl;
}

void FloodReliefSystem::updateCityStatus(int id) {
    // Check if city exists in map
    if (cityDatabase.find(id) != cityDatabase.end()) {
        cityDatabase[id].hasReceivedAid = true;
        cityDatabase[id].isFlooded = false;
        cityDatabase[id].injuredCount = 0;
        cityDatabase[id].priorityScore = 0;
        cout << "[Update] " << cityDatabase[id].name << " is now SAFE." << endl;
    } else {
        cout << "[Error] City ID not found!" << endl;
    }
}

void FloodReliefSystem::evaporateFlood() {
    cout << "[Nature] Flood waters are receding..." << endl;
    // Iterator loop for Map
    for (auto& entry : cityDatabase) {
        // entry.second refers to the City object
        if (entry.second.isFlooded && entry.second.injuredCount > 0) {
            entry.second.injuredCount--; // Reduce casualties naturally
        }
    }
}

City FloodReliefSystem::getCity(int id) {
    return cityDatabase[id];
}