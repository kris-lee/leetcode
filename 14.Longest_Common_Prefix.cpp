/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result, sTemp;
		if (strs.size() == 0) return result;
		result = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			if (result.size() == 0) break;
			for (int j = 0; j < min(result.size(), strs[i].size()); j++) {
				if (strs[i][j] == result[j]) sTemp.push_back(result[j]);
				else break;
			}
			result = sTemp, sTemp.clear();
		}
		return result;
    }
};
