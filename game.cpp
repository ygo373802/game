#include <iostream>
#include <vector>
#include <string>
#include "game.h"

void showStatus(int day, int cash, const std::vector<std::string>& inventory, const std::vector<int>& counts) {
    std::cout << "\n===============================" << std::endl;
    std::cout << "【第 " << day << " 天】 现金: $" << cash << std::endl;
    std::cout << "--- 个人背包仓库 ---" << std::endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << "  * " << inventory[i] << ": " << counts[i] << " 件" << std::endl;
    }
    std::cout << "===============================" << std::endl;
}

void marketScene(int& cash, const std::vector<std::string>& marketItems, const std::vector<int>& marketPrices, std::vector<int>& playerCounts) {
    std::cout << "\n[交易模式] 输入商品编号进行买卖 (例如: 1为芯片), 输入其他退出交易: ";
    int itemIdx;
    std::cin >> itemIdx;
    itemIdx--; // 转为 vector 的索引 (0, 1, 2)

    if (itemIdx >= 0 && itemIdx < static_cast<int>(marketItems.size())) {
        std::cout << "你想 [1] 购买 还是 [2] 出售 " << marketItems[itemIdx] << "？ ";
        int action;
        std::cin >> action;
        
        std::cout << "请输入数量: ";
        int amount;
        std::cin >> amount;

        if (action == 1) { // 购买
            int cost = marketPrices[itemIdx] * amount;
            if (cash >= cost) {
                cash -= cost;
                playerCounts[itemIdx] += amount;
                std::cout << "交易成功！" << std::endl;
            } else {
                std::cout << "资金不足！" << std::endl;
            }
        } else if (action == 2) { // 出售
            if (playerCounts[itemIdx] >= amount) {
                cash += marketPrices[itemIdx] * amount;
                playerCounts[itemIdx] -= amount;
                std::cout << "交易成功！" << std::endl;
            } else {
                std::cout << "你没有那么多货物！" << std::endl;
            }
        }
    }
}