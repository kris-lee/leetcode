/*
448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), 
some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.
Example: Input:[4,3,2,7,8,2,3,1]  Output:[5,6]
*/
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (int i = 1; i <= nums.size(); i++) result.push_back(i);
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] == result[nums[i]-1] || result[nums[i]-1] == 0) result[nums[i]-1] = 0;
		for (vector<int>::iterator it = result.begin(); it != result.end();)
			if (*it == 0) it = result.erase(it);
			else ++it;
		return result;
	}
};
