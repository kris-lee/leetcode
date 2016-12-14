/*
	349. Intersection of Two Arrays
	Given two arrays, write a function to compute their intersection.
	Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
	Note: 1.Each element in the result must be unique.
		2.The result can be in any order.
*/

class Solution {
public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		set<int> s;
		for (int i = 0; i < nums1.size(); i++)
			if (s.count(nums1[i]) == 0) s.insert(nums1[i]);
		for (int i = 0; i < nums2.size(); i++)
			if (s.count(nums2[i])) result.push_back(nums2[i]), s.erase(nums2[i]);
		return result;
    }
}