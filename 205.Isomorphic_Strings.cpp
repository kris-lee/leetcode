/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.
For example, Given "egg", "add", return true. Given "foo", "bar", return false. Given "paper", "title", return true.
Note:You may assume both s and t have the same length.
*/
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, char> sMatch,tMatch;
		for (int i = 0; i < s.size(); i++) {
			if (sMatch.count(s[i]) == 0) sMatch[s[i]] = t[i];
			else if (sMatch[s[i]] != t[i]) return false;
			if (tMatch.count(t[i]) == 0) tMatch[t[i]] = s[i];
			else if (tMatch[t[i]] != s[i]) return false;		
		}
		return true;
    }
};