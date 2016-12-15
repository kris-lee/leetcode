	/*
	169. Majority Element
	Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
	You may assume that the array is non-empty and the majority element always exist in the array.
	*/
class Solution{
	int majorityElement(vector<int>& nums) {
		//Solution 1:
		map<int, int> calculate;
		for (int i = 0; i < nums.size(); i++) {
			if(calculate.count(nums[i]) != 0) ++calculate[nums[i]];
			else calculate[nums[i]] = 1;
		}
		int result = 0;
		for (map<int,int>::iterator it = calculate.begin(); it != calculate.end(); it++) {
			if(it->second > (nums.size()/2)) {
				result = it->first;
				break;
			}
		}
		return result;

		//Solution 2:
		int index;
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0) count = 1,index = nums[i]; 
			else {
				if(nums[i] == index) ++count;
				else --count;
			}
		}
		return index;
    }
}