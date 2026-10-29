#include <iostream>
#include <vector>
#include <string>
#include "game.h"
using namespace std;

void showStatus(int day, int cash, const vector<string>& inventory, const vector<int>& counts) {
    cout << "\n===============================" << endl;
    cout << "【第 " << day << " 天】 现金: $" << cash << endl;
    cout << "--- 个人背包仓库 ---" << endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << "  * " << inventory[i] << ": " << counts[i] << " 件" << endl;
    }
    cout << "===============================" << endl;
}

void marketScene(int& cash, const vector<string>& marketItems, const vector<int>& marketPrices, vector<int>& playerCounts) {
    cout << "\n[交易模式] 输入商品编号进行买卖 (例如: 1为芯片), 输入其他退出交易: ";
    int itemIdx;
    cin >> itemIdx;
    itemIdx--; // 转为 vector 的索引 (0, 1, 2)

    if (itemIdx >= 0 && itemIdx < static_cast<int>(marketItems.size())) {
        cout << "你想 [1] 购买 还是 [2] 出售 " << marketItems[itemIdx] << "？ ";
        int action;
        cin >> action;
        
        cout << "请输入数量: ";
        int amount;
        cin >> amount;

        if (action == 1) { // 购买
            int cost = marketPrices[itemIdx] * amount;
            if (cash >= cost) {
                cash -= cost;
                playerCounts[itemIdx] += amount;
                cout << "交易成功！" << endl;
            } else {
                cout << "资金不足！" << endl;
            }
        } else if (action == 2) { // 出售
            if (playerCounts[itemIdx] >= amount) {
                cash += marketPrices[itemIdx] * amount;
                playerCounts[itemIdx] -= amount;
                cout << "交易成功！" << endl;
            } else {
                cout << "你没有那么多货物！" << endl;
            }
        }
    }
}