	/*
	350. Intersection of Two Arrays II
	Example: Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
	Note:1.Each element in the result should appear as many times as it shows in both arrays.
		2.The result can be in any order.
	*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
		map<int,int> s;
		for (int i = 0; i < nums1.size(); i++)
			if (s.count(nums1[i]) == 0) s[nums1[i]] = 1;
			else ++s[nums1[i]];
		for (int i = 0; i < nums2.size(); i++)
			if (s.count(nums2[i]) && s[nums2[i]] > 0) result.push_back(nums2[i]), --s[nums2[i]];
		return result;
    }
}