/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		if (root->left != NULL && root->right != NULL) return 1 + min(minDepth(root->left), minDepth(root->right));
		if (root->left && root->right) return 1;
		return root->left == NULL? 1+minDepth(root->right):1+minDepth(root->left);
    }
};