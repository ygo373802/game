#include <iostream>
#include <vector>
#include <string>
#include "game.h"
using namespace std;

int main() {
    // 基础属性：天数与初始资金
    int currentDay = 1;
    int maxDays = 30; // 游戏目标：生存30天并赚尽可能多的钱
    int playerCash = 500;

    // 商品列表 (使用 vector 存储名称)
    vector<string> itemNames = {"Chips", "HardDrives", "Nodes"};
    
    // 玩家背包 (记录对应商品的持有数量，初始全为 0)
    vector<int> playerInventory = {0, 0, 0};

    // 今日市场价格 (会随着天数随机波动)
    vector<int> currentPrices = {50, 120, 300};

    cout << "=== welcome to shop (Alpha v0.1) ===" << endl;

    // 核心游戏循环 (Game Loop)
    while (currentDay <= maxDays) {
        // 1. 展示当前玩家状态与背包
        showStatus(currentDay, playerCash, itemNames, playerInventory);

        // 2. 打印市场黑市价格
        cout << "\n--- today's price ---" << endl;
        for (size_t i = 0; i < itemNames.size(); ++i) {
            cout << i + 1 << ". " << itemNames[i] << " : $" << currentPrices[i] << endl;
        }

        // 3. 玩家决策菜单
        cout << "\naction: [1] shopping  [2] rest  [0] retreat: ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "you dissappear with your money" << endl;
            break;
        } else if (choice == 1) {
            marketScene(playerCash, itemNames, currentPrices, playerInventory);
        } else if (choice == 2) {
            cout << "a safe night, and price are changed" << endl;
            currentDay++;
            // 价格随机波动逻辑（后续通过 rand() 扩充）
            currentPrices[0] = 40 + rand() % 31;  // 40~70
            currentPrices[1] = 90 + rand() % 61;  // 90~150
            currentPrices[2] = 200 + rand() % 201; // 200~400
        }
    }

    cout << "game over!final money: $" << playerCash << endl;
    return 0;
}
    