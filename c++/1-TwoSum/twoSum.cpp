#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> appearedMap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (appearedMap.count(complement)) 
                return {i, appearedMap[complement]};
            appearedMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums{3, 3};
    int target = 6;

    vector<int> ans = Solution().twoSum(nums, target);
    for (auto element : ans) 
        cout << element << " ";
    cout << endl;
    return 0;
}
