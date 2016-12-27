	/*
	110. Balanced Binary Tree
	Given a binary tree, determine if it is height-balanced.
	For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
	*/
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL) return false;
		if (root->left == NULL && root->right == NULL) return true;
		int leftValue = isBalanced(root->left);
		int rightValue = isBalanced(root->right);
    }
};
