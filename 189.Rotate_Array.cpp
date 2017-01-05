/*
189. Rotate Array
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/
class Solution {
public:
	void Rotate(vector<int>& nums, int k) {
		//Solution 1
		if (nums.size() == 0) return;
		k = k%nums.size();
		queue<int> q;
		for (int i = 0; i < nums.size() - k; i++) q.push(nums[i]);
		nums.erase(nums.begin(),nums.begin()+nums.size()-k);
		while (!q.empty()) nums.push_back(q.front()),q.pop();

		//Solution 2
		if (nums.size() == 0) return;
		int front = k % nums.size(), nums_size = nums.size();
		for (int i = 0; i < nums_size - front; ++i) nums.push_back(nums[i]);
		nums.erase(nums.begin(), nums.begin()+nums_size-front);
    }
};
