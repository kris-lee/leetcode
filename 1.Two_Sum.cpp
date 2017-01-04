/*
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
Example:Given nums = [2, 7, 11, 15], target = 9, Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//Solution 1
		map<int, int> match;
		vector<int> indices;
		for (int i = 0; i < nums.size(); i++) match[nums[i]] = i;
		for (int i = 0; i < nums.size(); i++) {
			int leftValue = target-nums[i];
			if (match.count(leftValue) && match[leftValue] != i) {
				indices.push_back(i), indices.push_back(match[leftValue]);
				break;
			}
		}
		return indices;


		//Solution 2
		map<int, int> match;
		vector<int> indices;
		for (int i = 0; i < nums.size(); i++) match[i] = nums[i];
		sort(nums.begin(), nums.end());
		int i = 0 ,j = nums.size()-1;
		while (i < j) {
			int sum = nums[i] + nums[j];
			if (sum == target) break;
			else if (sum < target) ++i;
			else --j;
		}
		bool flag[] = {true, true};
		for (map<int, int>::iterator it = match.begin(); it != match.end(); ++it) {
			if (flag[0] == false && flag[1] == false) break;
			if (it->second == nums[i] && flag[0] == true) indices.push_back(it->first), flag[0] = false;
			else if (it->second == nums[j] && flag[1] == true) indices.push_back(it->first), flag[1] = false;
		}
		return indices;
    }
};