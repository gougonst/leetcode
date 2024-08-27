#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& image, int r, int c, int originColor, int newColor) {
		if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] == newColor ||image[r][c] != originColor)
			return;

		image[r][c] = newColor;
		dfs(image, r - 1, c, originColor, newColor);
		dfs(image, r + 1, c, originColor, newColor);
		dfs(image, r, c - 1, originColor, newColor);
		dfs(image, r, c + 1, originColor, newColor);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		int originColor = image[sr][sc];
		dfs(image, sr, sc, originColor, color);
		return image;
    }
};

int main() {
	Solution sol = Solution();
	vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
	image = sol.floodFill(image, 1, 1, 2);
	for (int n = 0; n < image.size(); n++) {
		for (int m = 0; m < image[0].size(); m++) {
			cout << image[n][m] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
    