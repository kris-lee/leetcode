/*
100. Same Tree
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL ^ q == NULL) return false;
		if (p == NULL && q == NULL) return true;
		else {
			if(p->val != q->val) return false;
			else return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
		}
    }
}
