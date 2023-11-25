#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val == root->val || q->val == root->val) 
			return root;

    	if (p->val < root->val && q->val > root->val || p->val > root->val && q->val < root->val) 
			return root;
		else 
			root = (p->val < root->val) ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q);
		return root;
    }
};

int main() {
	Solution sol = Solution();
	/* write test case here */
	return 0;
}
    