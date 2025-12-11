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

    cout << " - City Database: Loaded (25 Cities)\n";
    cout << " - Road Network:  Connected (Graph Built)\n";
    cout << " - Logistics:     Warehouses Stocked (Stacks Ready)\n\n";

    // 3. The Main Loop (Console Menu)
    int choice;
    while (true) {
        cout << "\n-------------------------------------------------\n";
        cout << "               MAIN CONTROL PANEL\n";
        cout << "-------------------------------------------------\n";
        cout << "1. [SIMULATION] Start New Flood Wave (Uses BFS)\n";
        cout << "2. [MONITOR]    View Active Flood Status\n";
        cout << "3. [ACTION]     Dispatch Aid to Critical Area (Uses Dijkstra + Heap)\n";
        cout << "4. [INVENTORY]  Check Warehouse Stock Levels\n";
        cout << "5. [LOGISTICS]  Manual Restock (Add Supplies)\n";
        cout << "0. Exit System\n";
        cout << "-------------------------------------------------\n";
        cout << "Select Option: ";
        cin >> choice;

        // Input Validation (Prevents crash if user enters text)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ">>> Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            // Case 1: Triggers the BFS Algorithm
            int startNode;
            cout << "\n--- SELECT FLOOD ORIGIN ---\n";
            cout << "Suggested IDs: 15 (Jhelum), 10 (DG Khan), 12 (Mianwali), 22 (Kasur)\n";
            cout << "Enter City ID to start flood: ";
            cin >> startNode;

            // Check if ID exists in the map
            if (sys.cityDatabase.find(startNode) != sys.cityDatabase.end()) {
                sys.simulateFloodSpread(startNode);
            }
            else {
                cout << ">>> [Error] Invalid City ID. Please check the list.\n";
            }
            break;
        }

        case 2: {
            // Case 2: Iterates through the HashMap to show status
            cout << "\n[CURRENT FLOOD STATUS REPORT]\n";
            bool anyFlooded = false;
            for (auto& entry : sys.cityDatabase) {
                City& c = entry.second;
                if (c.isFlooded) {
                    cout << " - " << c.name
                        << " | Injured: " << c.injuredCount
                        << " | Priority Score: " << c.priorityScore;

                    if (c.priorityScore > 500) cout << " [CRITICAL]";
                    cout << endl;
                    anyFlooded = true;
                }
            }
            if (!anyFlooded) cout << " >> All areas are currently safe.\n";
            break;
        }

        case 3:
            // Case 3: Triggers Priority Queue (Heap) & Shortest Path (Dijkstra)
            // This is the most complex function in your project
            sys.processNextEmergency();
            break;

        case 4:
            // Case 4: Peeks inside the Stacks
            cout << "\n[WAREHOUSE: RAWALPINDI (North Hub)]\n";
            sys.stockRawalpindi.displayStock();

            cout << "\n[WAREHOUSE: LAHORE (Central Hub)]\n";
            sys.stockLahore.displayStock();
            break;

        case 5:
            // Case 5: Calls the manual restock function you added
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