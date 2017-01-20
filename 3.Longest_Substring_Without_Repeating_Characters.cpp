/*
3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> charMap;
		int maxLength = 0, i = 0, j= 0;
		while (i < s.size()-maxLength && j < s.size()) {
			j = i;
			while (j < s.size() && charMap.count(s[j]) == 0) 
				charMap[s[j]] = j++;
			maxLength = max(maxLength, int(charMap.size()));
			i = charMap[s[j]]+1, charMap.clear();
		}
		return maxLength;
    }
};
