/*
98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
	  2
	 / \
	1   3
Binary tree [2,1,3], return true.
Example 2:
	  1
	 / \
	2   3
Binary tree [1,2,3], return false.
*/
class Solution {
public:
	void addVector(TreeNode* node, vector<int> &nums) {
		if (node) {
			addVector(node->left, nums);
			nums.push_back(node->val);
			addVector(node->right, nums);
		}
	}
	bool isValidBST(TreeNode* root) {
		//Solution 1
		vector<int> nums;
		addVector(root, nums);
		for (int i = 1; i < nums.size(); i++)
			if (nums[i] <= nums[i-1]) return false;
		return true;

		//Solution 2
		vector<int> nums;
		stack<TreeNode*> sTree;
		while(!sTree.empty() || root) {
			if (root) {
				sTree.push(root);
				root = root->left;
			}
			else {
				root = sTree.top();
				nums.push_back(root->val);
				sTree.pop();
				root = root->right;
			}
		}
		for (int i = 1; i < nums.size(); i++)
			if (nums[i] <= nums[i-1]) return false;
		return true;
    }
};
