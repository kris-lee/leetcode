	/*
	437. Path Sum III
	You are given a binary tree in which each node contains an integer value.
	Find the number of paths that sum to a given value.
	The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
	The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000
	root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
	Example:
			  10
			 /  \
			5   -3
		   / \    \
		  3   2   11
		 / \   \
		3  -2   1

	Return 3. The paths that sum to 8 are:
		1.  5 -> 3
		2.  5 -> 2 -> 1
		3. -3 -> 11
	*/
class Solution{
public:
	int pathSum(TreeNode* root, int sum) {
		int count = 0;
		queue<TreeNode*> queueNode;
		queueNode.push(root);
		while (!queueNode.empty()) {
			TreeNode* pTemp = queueNode.front();
			queueNode.pop();
			if(pTemp->left != NULL) queueNode.push(pTemp->left);
			if(pTemp->right != NULL) queueNode.push(pTemp->right);
			count += countAvailable(pTemp, sum);
		}
		return count;
    }
	int countAvailable(TreeNode* root, int sum) {
		if (root == NULL) 
			return 0;
		else {
			if (root->val == sum)
				return 1 + countAvailable(root->left,sum - root->val) + countAvailable(root->right, sum - root->val);
			else
				return countAvailable(root->left,sum - root->val) + countAvailable(root->right, sum - root->val);
		}
	}
}