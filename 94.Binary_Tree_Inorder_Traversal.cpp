/*
94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree [1,null,2,3],
	1
	\
		2
	/
	3
return [1,3,2].
*/
class Solution {
public:
	//Solution 1
	void inorder_traversal(TreeNode* root, vector<int> &nums) {
		if (root) {
			inorder_traversal(root->left, nums);
			nums.push_back(root->val);
			inorder_traversal(root->right);
		}
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nums;
		inorder_traversal(root, nums);
		return nums;
	}

	//Solution 2
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nums;
		stack<TreeNode*> sTree;
		map<TreeNode*, bool> isVisited;
		if (root == NULL) return nums;
		sTree.push(root);
		while (!sTree.empty()) {
			TreeNode* pTemp = sTree.top();
			if (pTemp->left && isVisited[pTemp->left] != true) sTree.push(pTemp->left);
			else {
				nums.push_back(pTemp->val);
				isVisited[pTemp] = true;
				sTree.pop();
				if (pTemp->right && isVisited[pTemp->right] != true) sTree.push(pTemp->right);
			}
		}
		return nums;
	}

	//Solution 3
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> sTree;
		vector<int> nums;
		while (!sTree.empty() || root) {
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
		return nums;
	}
};
