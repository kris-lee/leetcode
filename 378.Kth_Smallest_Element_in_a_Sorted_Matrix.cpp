/*
378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Example:matrix = [
		[ 1,  5,  9],
		[10, 11, 13],
		[12, 13, 15] ],
k = 8,
return 13.
Note: You may assume k is always valid, 1 ¡Ü k ¡Ü n2.
*/
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		//Solution 1
		vector<int> nums;
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[i].size(); j++) nums.push_back(matrix[i][j]);
		sort(nums.begin(), nums.end());
		return nums[k-1];

		//Solution 2
		priority_queue<int> nums_que;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				nums_que.push(matrix[i][j]);
				if (nums_que.size() > k) nums_que.pop();
			}
		}
		return nums_que.top();
	}
};