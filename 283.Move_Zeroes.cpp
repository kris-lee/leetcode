//283. Move Zeroes
//Given an array nums, write a function to move all 0's to the end of it 
//while maintaining the relative order of the non-zero elements.
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
class Solution {
public:
	void swap(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;
	}
	void moveZeroes(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				int j = i + 1;
				while (j < nums.size() && nums[j] == 0) ++j;
				if (j != nums.size()) swap(nums[i], nums[j]);
				else break;
			}
		}
    }
};
