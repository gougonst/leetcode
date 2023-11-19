#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
        if (!root || (!root->left && !root->right))
			return root;
		
		TreeNode* tmp = root->right;
		root->right = root->left;
		root->left = tmp;

		root->left = invertTree(root->left);
		root->right = invertTree(root->right);

		return root;
    }
};

int main() {
	Solution sol = Solution();
	/* write test case here */
	return 0;
}
    