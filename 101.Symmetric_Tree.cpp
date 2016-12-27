	/*
	101. Symmetric Tree
	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
	For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
	But the following [1,2,2,null,3,null,3] is not:
		1
	   / \
	  2   2
	   \   \
	   3    3
	*/
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		vector<int> nums1,nums2;
		TreeNode* node1 = root;
		TreeNode* node2 = root;
		inOrder(node1, nums1);
		for (int i = 0, j = nums1.size()-1; i < j; i++, j--)
			if (nums1[i] != nums1[j]) return false;
		return breadth_check(node2);
    }
	void inOrder(TreeNode* node, vector<int> &nums) {
		if (node != NULL) {
			inOrder(node->left, nums);
			nums.push_back(node->val);
			inOrder(node->right, nums);
		}
	}
	bool breadth_check(TreeNode* node) {
		queue<TreeNode*> queueNode;
		map<int,int> mapValue;
		int front = 0, level = 1, rear = 1, back;
		queueNode.push(node), mapValue[rear] = node->val;
		while (!queueNode.empty()) {
			TreeNode *pTemp = queueNode.front();
			queueNode.pop(), ++front;
			if (pTemp->left != NULL) 
				queueNode.push(pTemp->left), ++rear, mapValue[rear] = pTemp->left->val;
			if (pTemp->right != NULL) queueNode.push(pTemp->right), ++rear, mapValue[rear] = pTemp->right->val;
			if (front == level) level = rear, back = rear; 
			else if (front < back) {
				if (mapValue[front] != mapValue[back]) return false;
				else --back;
			}
		}
		return true;
	}
};