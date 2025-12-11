#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H

#include <iostream>
#include <string>
using namespace std;

// Node structure to hold a single supply item
struct SupplyNode {
    string itemType;
    SupplyNode* next;

    SupplyNode(string val) {
        itemType = val;
        next = nullptr;
    }
};

class InventorySystem {
private:
    SupplyNode* top; // Pointer to the top of the stack
    int count;

public:
    InventorySystem() {
        top = nullptr;
        count = 0;
    }

    // Add supplies (Push operation)
    void addSupply(string item) {
        SupplyNode* newNode = new SupplyNode(item);
        newNode->next = top;
        top = newNode;
        count++;
    }

    // Dispatch supplies (Pop operation)
    string dispatchSupply() {
        if (isEmpty()) {
            cout << "[Error] Inventory is empty! Cannot dispatch." << endl;
            return "";
        }

        SupplyNode* temp = top;
        string dispatchedItem = temp->itemType;

        // Memory Management: Delete the node
        top = top->next;
        delete temp;

        count--;
        return dispatchedItem;
    }

    string peek() {
        if (isEmpty()) return "None";
        return top->itemType;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getStockCount() {
        return count;
    }

    void displayStock() {
        if (isEmpty()) {
            cout << "Stock Status: Empty" << endl;
            return;
        }
        cout << "Current Stock (" << count << " items):" << endl;
        SupplyNode* current = top;
        while (current != nullptr) {
            cout << " - " << current->itemType << endl;
            current = current->next;
        }
    }

    ~InventorySystem() {
        while (!isEmpty()) {
            dispatchSupply();
        }
    }
};

#endif