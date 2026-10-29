#include <iostream>
#include <vector>
#include <string>
#include "game.h"
using namespace std;

void showStatus(int day, int cash, const vector<string>& inventory, const vector<int>& counts) {
    cout << "\n===============================" << endl;
    cout << "[ " << day << " day] money: $" << cash << endl;
    cout << "--- personal storage ---" << endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << "  * " << inventory[i] << ": " << counts[i] << endl;
    }
    cout << "===============================" << endl;
}

void marketScene(int& cash, const vector<string>& marketItems, const vector<int>& marketPrices, vector<int>& playerCounts) {
    cout << "\n[shopping pattern] input number to market (example: 1 is chip), enter others to quit: ";
    int itemIdx;
    cin >> itemIdx;
    itemIdx--; // 转为 vector 的索引 (0, 1, 2)

    if (itemIdx >= 0 && itemIdx < static_cast<int>(marketItems.size())) {
        cout << "you want [1] buy or [2] sell " << marketItems[itemIdx] << "? ";
        int action;
        cin >> action;
        
        cout << "please enter the number of objects: ";
        int amount;
        cin >> amount;

        if (action == 1) { // 购买
            int cost = marketPrices[itemIdx] * amount;
            if (cash >= cost) {
                cash -= cost;
                playerCounts[itemIdx] += amount;
                cout << "deal successfully!" << endl;
            } else {
                cout << "money not enough!" << endl;
            }
        } else if (action == 2) { // 出售
            if (playerCounts[itemIdx] >= amount) {
                cash += marketPrices[itemIdx] * amount;
                playerCounts[itemIdx] -= amount;
                cout << "successful deal!" << endl;
            } else {
                cout << "you don't have enough stuff!" << endl;
            }
        }
    }
}