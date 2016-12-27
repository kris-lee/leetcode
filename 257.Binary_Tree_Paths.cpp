	/*
	257. Binary Tree Paths
	Given a binary tree, return all root-to-leaf paths.
	For example, given the following binary tree:
	   1
	 /   \
	2     3
	 \
	  5
	All root-to-leaf paths are:["1->2->5", "1->3"]
	*/
class Solution {
public:
	void initBinaryVisit(map<TreeNode*,bool> mapVector, TreeNode* root) {
		if (root != NULL) {
			initBinaryVisit(mapVector, root->left);
			mapVector[root] = false;
			initBinaryVisit(mapVector, root->right);
		}
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (root == NULL) return result;
		map<TreeNode*,bool> mapVector;
		initBinaryVisit(mapVector, root);
		vector<TreeNode*> nodeVector;
		nodeVector.push_back(root);
		mapVector[root] = true;
		while (!nodeVector.empty()) {
			TreeNode* pTemp = nodeVector.back();
			if(pTemp->left != NULL && mapVector[pTemp->left] == false) {
				nodeVector.push_back(pTemp->left);
				mapVector[pTemp->left] = true;
			}
			else {
				if (pTemp->right != NULL && mapVector[pTemp->right] == false) {
					nodeVector.push_back(pTemp->right);
					mapVector[pTemp->right] = true;
				}
				else if (pTemp->left == NULL && pTemp->right == NULL) {
					string s = "";
					for (int i = 0; i < nodeVector.size()-1; i++)
						s = s + to_string(nodeVector[i]->val) + "->";
					s = s + to_string(nodeVector.back()->val);
					result.push_back(s);
					nodeVector.pop_back();
				}
				else
					nodeVector.pop_back();
			}
		}
		return result;
    }
};
