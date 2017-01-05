//226. Invert Binary Tree
//Google: 90% of our engineers use the software you wrote (Homebrew),
//but you can¡¯t invert a binary tree on a whiteboard so fuck off.
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return NULL;
		TreeNode* temp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(temp);
		return root;
	}
};
