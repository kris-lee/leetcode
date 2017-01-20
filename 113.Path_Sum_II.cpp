/*
113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:Given the below binary tree and sum = 22,
		   5
		  / \
		 4   8
		/   / \
	   11  13  4
	  /  \    / \
	 7    2  5   1
return[[5,4,11,2],[5,8,4,5]]
*/
class Solution{
public:
	void path_sum(TreeNode* root, int sum, vector<vector<int>> &allPath, vector<int> singlePath) {
		if (root) {
			singlePath.push_back(root->val);
			if (root->left == NULL && root->right == NULL) {
				if (root->val == sum) allPath.push_back(singlePath);
				singlePath.pop_back();
			}
			else {
				path_sum(root->left, sum - root->val, allPath, singlePath);
				path_sum(root->right, sum - root->val, allPath, singlePath);
			}
		}
	}
	vector<vector<int>> pathSumII(TreeNode* root, int sum) {
		vector<vector<int>> allPath;
		vector<int> singlePath;
		path_sum(root, sum, allPath, singlePath);
		return allPath;
    }
};
