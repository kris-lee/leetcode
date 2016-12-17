	/*
	387. First Unique Character in a String
	Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
	Examples: s = "leetcode" return 0.
		s = "loveleetcode",	return 2.
	*/
class Solution{
	int firstUniqChar(string s) {
		map<char, int> r;
		for (int i = 0; i < s.size(); i++) {
			if (r.count(s[i]) == 0) r[s[i]] = 1;
			else ++r[s[i]];
		}
		int index = -1;
		for (int i = 0; i < s.size(); i++)
			if(r[s[i]] == 1) {
				index = i;
				break;
			}
			return index;
	}
}
