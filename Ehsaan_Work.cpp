#include "FloodSystem.h" 
#include <iostream>
#include <queue>         // Used ONLY for the BFS frontier queue
#include <cstdlib>       // For rand()
#include <ctime>         // For random seed

using namespace std;

// ==========================================
// CONSTRUCTOR
// ==========================================
// FloodReliefSystem::FloodReliefSystem() {
//     // The Master Sequence:
//     loadCities();  // 1. Load the empty city shells (Ahmed)
//     loadRoads();   // 2. Connect them with roads (Adil)
//     loadStock();   // 3. Fill the warehouses (Ehsaan)
// }

// ==========================================
// LOGISTICS: LOAD REALISTIC STOCK (STACKS)
// ==========================================
void FloodReliefSystem::loadStock() {
    // REALISM: In Pakistan floods, standard aid includes "Ration Bags" (Flour/Rice/Oil),
    // "Medical Kits" (ORS/Panadol), "Tents", and "Mosquito Nets".

    // We add 100 items to each warehouse to ensure the simulation doesn't crash 
    // from running out of supplies too quickly.

    // --- ISLAMABAD WAREHOUSE (Medical & Specialized Focus) ---
    for (int i = 0; i < 50; i++) {
        // Updated Variable Name:
        stockRawalpindi.addSupply("Medical Kit (ORS, Bandages, Panadol)");
        stockRawalpindi.addSupply("Clean Water (19L Bottle)");
        stockRawalpindi.addSupply("Mosquito Net");
    }

    // --- LAHORE WAREHOUSE (Food & Shelter Focus) ---
    for (int i = 0; i < 50; i++) {
        stockLahore.addSupply("Ration Bag (20kg Flour, Rice, Oil)");
        stockLahore.addSupply("Waterproof Tent (Family Size)");
        stockLahore.addSupply("Dry Food Pack (Biscuits, Dates)");
    }

    cout << "[Ehsaan] Logistics: Warehouses fully stocked with 300+ relief items." << endl;
}

// ==========================================
// SIMULATION: FLOOD SPREAD (BFS ALGORITHM)
// ==========================================
void FloodReliefSystem::simulateFloodSpread(int startCityID) {
    // 1. Setup BFS Frontier Queue (Standard Queue)
    queue<int> bfsQ;

    // 2. Initialize the Disaster Point
    bfsQ.push(startCityID);
    cityDatabase[startCityID].isFlooded = true;
    cityDatabase[startCityID].injuredCount = (rand() % 50) + 10; // Initial Impact
    cityDatabase[startCityID].priorityScore = cityDatabase[startCityID].injuredCount * 10;

    // Add start node to Priority Queue immediately
    emergencyQueue.enqueue(cityDatabase[startCityID]);

    cout << "\n>>> DISASTER ALERT: Flood waters reported in " << cityDatabase[startCityID].name << "!" << endl;

    // 3. The BFS Loop (Spreading Layer by Layer)
    int impactRadius = 0;
    while (!bfsQ.empty() && impactRadius < 15) { // Limit iterations to prevent instant total destruction
        int currentID = bfsQ.front();
        bfsQ.pop();

        // Check all connected neighbors (Roads act as flood channels)
        vector<pair<int, int>> neighbors = roadNetwork[currentID];

        for (auto& edge : neighbors) {
            int neighborID = edge.first;

            // If the city is dry, the flood hits it now
            if (!cityDatabase[neighborID].isFlooded) {

                // A. Update Status
                cityDatabase[neighborID].isFlooded = true;
                cityDatabase[neighborID].hasReceivedAid = false; // Needs help

                // B. Random Casualty Generation (Realism: 10 to 100 injured)
                int casualties = (rand() % 90) + 10;
                cityDatabase[neighborID].injuredCount = casualties;

                // C. Calculate Priority Score (Casualties * Severity)
                // We give higher priority to high-casualty zones
                cityDatabase[neighborID].priorityScore = casualties * 10;

                // D. CRITICAL: Add to Custom Priority Queue
                emergencyQueue.enqueue(cityDatabase[neighborID]);

                // E. Add to BFS Queue to spread further next cycle
                bfsQ.push(neighborID);

                cout << "   [SPREAD] Flood hit " << cityDatabase[neighborID].name
                    << " | Casualties: " << casualties
                    << " | Priority Score: " << cityDatabase[neighborID].priorityScore << endl;
            }
        }
        impactRadius++;
    }
    cout << ">>> SIMULATION PAUSED: Flood wave has stabilized.\n" << endl;
}

// ==========================================
// WAREHOUSE MANAGEMENT
// ==========================================
bool FloodReliefSystem::hasSupplies(string warehouse) {
    // Now we only check for "Rawalpindi" because that matches the City Name in the Database
    if (warehouse == "Rawalpindi") {
        return !stockRawalpindi.isEmpty(); // Using new variable
    }
    else if (warehouse == "Lahore") {
        return !stockLahore.isEmpty();
    }
    return false;
}

void FloodReliefSystem::dispatchSupply(string warehouse) {
    string item = "";
    int remainingStock = 0;
    const int WARNING_THRESHOLD = 10; // Logic: Warn if stock drops below this

    // 1. Dispatch & Check Count based on Warehouse
    if (warehouse == "Rawalpindi") {
        item = stockRawalpindi.dispatchSupply();     // Send the item
        remainingStock = stockRawalpindi.getStockCount(); // Check what's left
    }
    else {
        item = stockLahore.dispatchSupply();         // Send the item
        remainingStock = stockLahore.getStockCount();     // Check what's left
    }

    // 2. Logistics Report & Warnings
    if (item != "") {
        cout << "   [Logistics] Truck dispatched from " << warehouse << " loaded with: " << item << endl;

        // --- NEW: LOW STOCK WARNING LOGIC ---
        if (remainingStock == 0) {
            cout << "   >>> [CRITICAL] " << warehouse << " WAREHOUSE IS NOW EMPTY!" << endl;
        }
        else if (remainingStock < WARNING_THRESHOLD) {
            cout << "   >>> [WARNING] LOW STOCK ALERT: " << warehouse
                << " only has " << remainingStock << " items left! Please Restock." << endl;
        }
    }
    else {
        cout << "   [Logistics] CRITICAL FAILURE: " << warehouse << " Warehouse is Empty!" << endl;
    }
}
// ==========================================
// 4. DYNAMIC RESTOCKING (NEW FEATURE)
// ==========================================
void FloodReliefSystem::manualRestock() {
    int choice, quantity;
    cout << "\n=== WAREHOUSE RESTOCKING PANEL ===" << endl;
    cout << "1. Rawalpindi (Medical/Water)" << endl;
    cout << "2. Lahore (Food/Shelter)" << endl;
    cout << "Select Warehouse to restock (1-2): ";
    cin >> choice;

    cout << "Enter quantity to add: ";
    cin >> quantity;

    if (choice == 1) {
        for (int i = 0; i < quantity; i++) {
            // Refilling with standard North supplies
            stockRawalpindi.addSupply("Medical Kit (Refilled)");
            stockRawalpindi.addSupply("Clean Water (Refilled)");
        }
        cout << ">>> SUCCESS: Added " << (quantity * 2) << " items to Rawalpindi." << endl;
    }
    else if (choice == 2) {
        for (int i = 0; i < quantity; i++) {
            // Refilling with standard Central supplies
            stockLahore.addSupply("Ration Bag (Refilled)");
            stockLahore.addSupply("Tent (Refilled)");
        }
        cout << ">>> SUCCESS: Added " << (quantity * 2) << " items to Lahore." << endl;
    }
    else {
        cout << ">>> Invalid Selection." << endl;
    }

    // Show new totals
    cout << "   [Status] Rawalpindi Level: " << stockRawalpindi.getStockCount() << endl;
    cout << "   [Status] Lahore Level:     " << stockLahore.getStockCount() << endl;
}