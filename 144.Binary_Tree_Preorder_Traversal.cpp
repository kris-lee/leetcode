/*
144. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.
For example:Given binary tree {1,#,2,3},
		1
		\
		 2
		/
		3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> sTree;
		vector<int> nums;
		while(!sTree.empty() || root) {
			if (root) {
				nums.push_back(root->val);
				sTree.push(root);
				root = root->left;
			}
			else {
				root = sTree.top()->right;
				sTree.pop();
			}
		}
		return nums;
    }
};