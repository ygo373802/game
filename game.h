#ifndef GAME_H
#define GAME_H

#include<vector>
#include<string>

void showStatus(int day, int cash,const std::vector<std::string>& inventory, const std::vector<int>& counts);
void marketScene(int& cash, const std::vector<std::string>& marketItems, const std::vector<int>& marketPrices, std::vector<int>& playerCounts);

#endif