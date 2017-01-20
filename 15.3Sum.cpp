/*
15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:	[[-1, 0, 1],[-1, -1, 2]]
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		//Solution 1
		vector<vector<int>> allResult;
		if (nums.size() < 3) return allResult;
		vector<int> singleResult;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if (nums[i] > 0) break;
			if (i >= 1 && nums[i] == nums[i-1]) continue;
			for (int j = nums.size()-1; j > i+1; j--) {
				if (j < nums.size()-1 && nums[j] == nums[j+1]) continue;
				for (int k = i+1; k < nums.size()-1 && k < j; k++) {
					int sum = nums[i] + nums[j] + nums[k];
					if (sum == 0) {
						singleResult.push_back(nums[i]),singleResult.push_back(nums[k]),singleResult.push_back(nums[j]);
						allResult.push_back(singleResult),singleResult.clear();
						break;
					}
				}
			}
		}
		return allResult;

		//Solution 2
		vector<vector<int>> allResult;
		if (nums.size() < 3) return allResult;
		vector<int> singleResult;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if (nums[i] > 0) break;
			if (i >= 1 && nums[i] == nums[i-1]) continue;
			int j = i+1, k = nums.size()-1;
			while (j < k) {
				while (j > i+1 && j < k && nums[j] == nums[j-1]) ++j;
				while (k < nums.size()-1 && j < k && nums[k] == nums[k+1]) --k;
				if (j >= k) break;
				if (nums[i] + nums[j] + nums[k] == 0) {
					singleResult.push_back(nums[i]),singleResult.push_back(nums[j++]),singleResult.push_back(nums[k--]);
					allResult.push_back(singleResult),singleResult.clear();
				}
				else if (nums[i] + nums[j] + nums[k] > 0) --k;
				else if (nums[i] + nums[j] + nums[k] < 0) ++j;
			}
		}
		return allResult;
    }
};
