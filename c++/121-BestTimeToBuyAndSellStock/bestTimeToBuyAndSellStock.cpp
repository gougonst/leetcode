#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length <= 1)
            return 0;

        int minPrice = prices[0];
        int profit = 0;
        for (int i = 0; i < length; i++) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }

        return profit;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(1);
    int profit = sol.maxProfit(prices);
    cout << profit << endl;
    return 0;
}
    