#include <iostream>
#include <vector>
#include <string>
#include "game.h"

int main() {
    // 基础属性：天数与初始资金
    int currentDay = 1;
    int maxDays = 30; // 游戏目标：生存30天并赚尽可能多的钱
    int playerCash = 500;

    // 商品列表 (使用 vector 存储名称)
    std::vector<std::string> itemNames = {"芯片(Chips)", "数据硬盘(HardDrives)", "违禁算力(Nodes)"};
    
    // 玩家背包 (记录对应商品的持有数量，初始全为 0)
    std::vector<int> playerInventory = {0, 0, 0};

    // 今日市场价格 (会随着天数随机波动)
    std::vector<int> currentPrices = {50, 120, 300};

    std::cout << "=== 欢迎来到黑客商行大亨 (Alpha v0.1) ===" << std::endl;

    // 核心游戏循环 (Game Loop)
    while (currentDay <= maxDays) {
        // 1. 展示当前玩家状态与背包
        showStatus(currentDay, playerCash, itemNames, playerInventory);

        // 2. 打印市场黑市价格
        std::cout << "\n--- 今日黑市价格 ---" << std::endl;
        for (size_t i = 0; i < itemNames.size(); ++i) {
            std::cout << i + 1 << ". " << itemNames[i] << " : $" << currentPrices[i] << std::endl;
        }

        // 3. 玩家决策菜单
        std::cout << "\n请选择行动: [1] 进入黑市买卖  [2] 结束今天休息  [0] 跑路退出: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "你带着残余的资金人间蒸发了..." << std::endl;
            break;
        } else if (choice == 1) {
            marketScene(playerCash, itemNames, currentPrices, playerInventory);
        } else if (choice == 2) {
            std::cout << "安全度过了一夜，市场价格发生了变动..." << std::endl;
            currentDay++;
            // 价格随机波动逻辑（后续通过 rand() 扩充）
            currentPrices[0] = 40 + rand() % 31;  // 40~70
            currentPrices[1] = 90 + rand() % 61;  // 90~150
            currentPrices[2] = 200 + rand() % 201; // 200~400
        }
    }

    std::cout << "游戏结束！最终资产: $" << playerCash << std::endl;
    return 0;
}
    