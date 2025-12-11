#include "FloodSystem.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Helper to make adding roads easier/cleaner
void addRoad(unordered_map<int, vector<pair<int, int>>>& network, int u, int v, int dist) {
    network[u].push_back({v, dist});
    network[v].push_back({u, dist});
}
//function to load and the roads and distance
void FloodReliefSystem::loadRoads() {
    // =============================================================
    // STRATEGY 1: THE NATIONAL HIGHWAY (N5) & MOTORWAY BACKBONE
    // Connecting Major Hubs first to create the "Skeleton"
    // =============================================================
    
    // Rawalpindi (170) -> Jhelum (82) -> Gujrat (60) -> Gujranwala (59) -> Lahore (121)
    addRoad(roadNetwork, 170, 82, 120); // Rwp - Jhelum
    addRoad(roadNetwork, 82, 60, 60);   // Jhelum - Gujrat
    addRoad(roadNetwork, 60, 59, 50);   // Gujrat - Gujranwala
    addRoad(roadNetwork, 59, 121, 70);  // Gujranwala - Lahore

    // Lahore (121) -> Sahiwal (174) -> Multan (142) -> Bahawalpur (7) -> RYK (165)
    addRoad(roadNetwork, 121, 152, 130); // Lahore - Okara (152)
    addRoad(roadNetwork, 152, 174, 50);  // Okara - Sahiwal
    addRoad(roadNetwork, 174, 142, 170); // Sahiwal - Multan
    addRoad(roadNetwork, 142, 7, 100);   // Multan - Bahawalpur
    addRoad(roadNetwork, 7, 165, 200);   // Bahawalpur - RYK
    addRoad(roadNetwork, 165, 173, 28);  // RYK - Sadiqabad (173)

    // Motorway M2/M3/M4 Links (Faisalabad Hub)
    addRoad(roadNetwork, 121, 50, 150);  // Lahore - Faisalabad (50)
    addRoad(roadNetwork, 170, 50, 280);  // Rwp - Faisalabad
    addRoad(roadNetwork, 50, 142, 240);  // Faisalabad - Multan

    // =============================================================
    // STRATEGY 2: REGIONAL CLUSTERS (Connecting Towns to Hubs)
    // =============================================================

    // --- RAWALPINDI REGION (Hub: 170) ---
    // Attock(4), Wah(200), Hasan Abdal(65), Murree(144), Gujar Khan(58), Kahuta(85), Taxila(not listed? using nearby)
    vector<int> northCities = {4, 200, 65, 144, 58, 85, 177, 37, 23, 194, 202}; 
    for(int city : northCities) addRoad(roadNetwork, 170, city, 40 + (rand() % 60)); // Random dist 40-100km

    // --- LAHORE REGION (Hub: 121) ---
    // Muridke(143), Kasur(97), Sheikhupura(186), Raiwind(166), Pattoki(156), Nankana(147), Narang(148)
    vector<int> lahoreCities = {143, 97, 186, 166, 156, 147, 148, 185, 84, 113, 29, 93};
    for(int city : lahoreCities) addRoad(roadNetwork, 121, city, 30 + (rand() % 50));

    // --- FAISALABAD REGION (Hub: 50) ---
    // Jaranwala(76), Khurrianwala(107), Chiniot(26), Jhang(79), Gojra(57), Samundri(not listed), Chak Jhumra(19)
    vector<int> fsdCities = {76, 107, 26, 79, 57, 19, 196, 130, 42, 102};
    for(int city : fsdCities) addRoad(roadNetwork, 50, city, 25 + (rand() % 45));

    // --- GUJRANWALA & SIALKOT REGION (Hubs: 59 & 189) ---
    // Sialkot(189), Daska(35), Sambrial(175), Hafizabad(62), Wazirabad(202), Pasrur(155), Narowal(149)
    addRoad(roadNetwork, 59, 189, 50); // Gujranwala - Sialkot
    vector<int> gujCities = {35, 175, 62, 202, 155, 149, 163, 117, 24, 191};
    for(int city : gujCities) addRoad(roadNetwork, 59, city, 30 + (rand() % 40));

    // --- SARGODHA REGION (Hub: 180) ---
    // Khushab(108), Bhalwal(13), Mianwali(138), Kot Momin(112), Shahpur(182)
    vector<int> sargodhaCities = {108, 13, 138, 112, 182, 190, 61, 63};
    for(int city : sargodhaCities) addRoad(roadNetwork, 180, city, 40 + (rand() % 50));

    // --- MULTAN REGION (Hub: 142) ---
    // Khanewal(101), Muzaffargarh(146), Shujaabad(188), Lodhran(126), Vehari(199)
    vector<int> multanCities = {101, 146, 188, 126, 199, 72, 83, 136, 195};
    for(int city : multanCities) addRoad(roadNetwork, 142, city, 30 + (rand() % 60));

    // --- BAHAWALPUR & SOUTH (Hubs: 7 & 165) ---
    // Ahmedpur East(1), Yazman(203), Khanpur(104), Sadiqabad(173)
    vector<int> southCities = {1, 203, 99, 66, 39, 109};
    for(int city : southCities) addRoad(roadNetwork, 7, city, 40 + (rand() % 50));
    
    // RYK Neighbors
    addRoad(roadNetwork, 165, 104, 50); // RYK - Khanpur
    addRoad(roadNetwork, 165, 173, 25); // RYK - Sadiqabad

    // --- DG KHAN & WEST (Hub: 38) ---
    // Taunsa(197), Rajanpur(168), Jampur(73), Kot Addu(110)
    vector<int> westCities = {197, 168, 73, 110, 31, 116, 124, 103, 32};
    for(int city : westCities) addRoad(roadNetwork, 38, city, 50 + (rand() % 70));

    // =============================================================
    // STRATEGY 3: THE "VILLAGE LINK" SAFETY NET
    // Ensure ALL 204 cities are connected, even obscure ones.
    // Logic: Connect city[i] to city[i+1] with a "Local Road"
    // =============================================================
    
    int totalCities = 204;
    for (int i = 0; i < totalCities - 1; i++) {
        // Connect 'i' to 'i+1' with a high cost (e.g., 200km local bumpy road)
        // This guarantees the graph is fully connected (no islands).
        // Dijkstra will prefer the Highways (Strategy 1 & 2) but uses this if needed.
        addRoad(roadNetwork, i, i + 1, 150); 
    }

    // Connect the last city back to the first to close the loop? 
    // Not strictly necessary but helps.
    addRoad(roadNetwork, totalCities - 1, 0, 300);

    cout << "[Adil] Network Built: Backbone + Regional Clusters + Safety Loop." << endl;
    cout << "[Adil] Total Connections Created: " << totalCities * 2 << "+" << endl;

    // ==========================================
    // DEBUG: PRINT SAMPLE CONNECTIONS
    // ==========================================
    cout << "\n=== [Adil] VERIFYING MAJOR CONNECTIONS ===\n";
    vector<int> testHubs = {121, 170, 50, 142}; // Check Lahore, Rwp, Fsd, Multan
    
    for (int hubID : testHubs) {
        string hubName = cityDatabase[hubID].name;
        cout << "Hub: " << hubName << " (" << hubID << ") connects to: " << endl;
        
        for (auto const& edge : roadNetwork[hubID]) {
             // Basic bounds check to prevent crash if ID is invalid
            if (cityDatabase.find(edge.first) != cityDatabase.end()) {
                cout << "   -> " << cityDatabase[edge.first].name << " (" << edge.second << " km)" << endl;
            }
        }
        cout << "-----------------------" << endl;
    }
}