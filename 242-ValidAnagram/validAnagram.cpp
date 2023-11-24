#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
        unordered_map<char, int> counter;

		for (auto& c: s) 
			counter[c]++;

		for (auto& c: t)
			counter[c]--;

		for (auto& pair: counter) {
			if (pair.second != 0)
				return false;
		}

		return true;
    }
};

int main() {
	Solution sol = Solution();
	/* write test case here */
	return 0;
}
    