	/*
	242. Valid Anagram
	Given two strings s and t, write a function to determine if t is an anagram of s.
	For example,s = "anagram", t = "nagaram", return true. s = "rat", t = "car", return false.
	Note: You may assume the string contains only lowercase alphabets.
	*/
class Solution{
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		map<char,int> m;
		for (int i = 0; i < s.size(); i++) {
			if(m.count(s[i]) == 0) m[s[i]] = 1;
			else ++m[s[i]];
		}
		for (int i = 0; i < t.size(); i++) {
			if(m.count(t[i]) == 0) return false;
			else {
				--m[t[i]];
				if (m[t[i]] == 0) m.erase(t[i]);
			}
		}
		return true;
    }
}
