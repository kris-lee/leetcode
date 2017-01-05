//104. Maximum Depth of Binary Tree
//Given a binary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
class Solution {
public:
	int maxDepth(TreeNode* root) {
		//Solution 1
		if (root == NULL) return 0;
		int leftCount = maxDepth(root->left);
		int rightCount = maxDepth(root->right);
		return leftCount>rightCount?leftCount+1:rightCount+1;

		//Solution 2
		if (root == NULL) return 0;
		queue<TreeNode*> nodeQueue;
		int count = 0, front = 0, back =0, row = 1;
		nodeQueue.push(root);
		while (!nodeQueue.empty())
		{
			TreeNode *temp = nodeQueue.front();
			nodeQueue.pop();
			++front;
			if (temp->left) nodeQueue.push(temp->left), ++back;
			if (temp->right) nodeQueue.push(temp->right), ++back;
			if (front == row) ++count, row = back;
		}
		return count;
	}
};
