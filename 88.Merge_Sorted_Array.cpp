/*
88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0, j = n;
		for (int k = 0; k < nums1.size(); k++) nums2.push_back(nums1[k]);
		nums1.clear();
		while (i < n && j < m+n) {
			if (nums2[i] < nums2[j]) nums1.push_back(nums2[i]), ++i;
			else nums1.push_back(nums2[j]), ++j;
		}
		if (i == n)
			while (j < m+n) nums1.push_back(nums2[j]), ++j;
		else
			while (i < n) nums1.push_back(nums2[i]), ++i;
		nums2.erase(nums2.begin()+n, nums2.end());
    }
};
