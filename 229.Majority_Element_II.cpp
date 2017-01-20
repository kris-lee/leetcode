/*
229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.
*/
class Solution{
public:
	vector<int> majorityElementII(vector<int>& nums) {
		map<int,int> match;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) match[nums[i]]++;
		for (map<int,int>::iterator it = match.begin(); it != match.end(); it++)
			if (it->second > nums.size()/3) result.push_back(it->second);
		return result;	
		}
};
