#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

		while (left <= right) {
			int middle = (left + right) / 2;
			if (nums[middle] > target) 
				right = middle - 1;
			else if (nums[middle] < target) 
				left = middle + 1;
			else 
				return middle;
		}

		return -1;
    }
};

int main() {
	Solution sol = Solution();
	vector<int> nums = {};
	cout << sol.search(nums, -1) << endl;
	return 0;
}
    