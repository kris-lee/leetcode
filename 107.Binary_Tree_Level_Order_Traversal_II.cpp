	/*
	107. Binary Tree Level Order Traversal II
	Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
	For example: Given binary tree [3,9,20,null,null,15,7],
			3
		   / \
		  9  20
			/  \
		   15   7
	return its bottom-up level order traversal as: [[15,7],[9,20],[3]]
	*/
class Solution{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL) return result;
		vector<int> layerVector;
		queue<TreeNode*> queueNode;
		queueNode.push(root);
		int front = 0, back = 1, level = 1;
		while (!queueNode.empty()) {
			TreeNode *pTemp = queueNode.front();
			queueNode.pop();
			layerVector.push_back(pTemp->val);
			++front;
			if (pTemp->left != NULL) queueNode.push(pTemp->left), ++back;
			if (pTemp->right != NULL) queueNode.push(pTemp->right), ++back;
			if (front == level) {
				result.push_back(layerVector);
				layerVector.clear();
				level = back;
			}
		}
		reverse(result.begin(), result.end());
		return result;
    }
}