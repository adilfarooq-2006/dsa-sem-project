#include "FloodSystem.h" // Links to all your classes
#include <iostream>
#include <ctime>         // For random number generation
#include <limits>        // For input validation

using namespace std;

int main() {
    // 1. Seed the Random Number Generator
    // This ensures every time you run the flood simulation, the casualties are different.
    srand(time(0));

    // 2. Initialize the System
    // This automatically calls the Constructor:
    // -> loadCities() [Ahmed]
    // -> loadRoads()  [Adil]
    // -> loadStock()  [Ehsaan]
    cout << "=================================================\n";
    cout << "   SMART FLOOD RELIEF MANAGEMENT SYSTEM (PUNJAB)\n";
    cout << "=================================================\n";
    cout << "Initializing System Modules...\n";

    FloodReliefSystem sys; // The Master Object

    cout << " - City Database: Loaded (203 Cities)\n";
    cout << " - Road Network:  Connected (Graph Built)\n";
    cout << " - Logistics:     Warehouses Stocked (Stacks Ready)\n\n";

    // 3. The Main Loop (Console Menu)
    int choice;
    while (true) {
        cout << "\n-------------------------------------------------\n";
        cout << "               MAIN CONTROL PANEL\n";
        cout << "-------------------------------------------------\n";
        cout << "1. [SIMULATION] Start New Flood Wave (BFS)\n";
        cout << "2. [MONITOR]    View Active Flood Status\n";
        cout << "3. [ACTION]     Dispatch Aid (Dijkstra + Heap)\n";
        cout << "4. [INVENTORY]  Check Warehouse Stock Levels\n";
        cout << "5. [LOGISTICS]  Manual Restock\n";
        cout << "0. Exit System\n";
        cout << "-------------------------------------------------\n";
        cout << "Select Option: ";
        cin >> choice;

        // Input Validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ">>> Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            int startNode;
            cout << "\n--- SELECT FLOOD ORIGIN ---\n";
            cout << "Suggested IDs: 15 (Bhera), 38 (DG Khan), 138 (Mianwali), 97 (Kasur)\n";
            cout << "Enter City ID: ";
            cin >> startNode;

            if (sys.cityDatabase.find(startNode) != sys.cityDatabase.end()) {
                sys.simulateFloodSpread(startNode);
            } else {
                cout << ">>> [Error] Invalid City ID.\n";
            }
            break;
        }

        case 2: {
            cout << "\n[CURRENT FLOOD STATUS REPORT]\n";
            bool anyFlooded = false;
            for (auto& entry : sys.cityDatabase) {
                City& c = entry.second;
                if (c.isFlooded) {
                    cout << " - " << c.name 
                         << " | Injured: " << c.injuredCount 
                         << " | Priority: " << c.priorityScore;
                    if (c.priorityScore > 500) cout << " [CRITICAL]";
                    cout << endl;
                    anyFlooded = true;
                }
            }
            if (!anyFlooded) cout << " >> All areas are currently safe.\n";
            break;
        }

        case 3:
            // The Brain Function (Adil_Graph.cpp)
            sys.processNextEmergency();
            break;

        case 4:
            cout << "\n[WAREHOUSE: RAWALPINDI (North Hub)]\n";
            sys.stockRawalpindi.displayStock();

            cout << "\n[WAREHOUSE: LAHORE (Central Hub)]\n";
            sys.stockLahore.displayStock();
            break;

        case 5:
            sys.manualRestock();
            break;

        case 0:
            cout << "Shutting down system. Stay Safe.\n";
            return 0;

        default:
            cout << ">>> Invalid Option. Try again.\n";
        }
    }
    return 0;
}