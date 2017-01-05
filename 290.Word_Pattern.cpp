/*
290. Word Pattern
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Examples:
1.pattern = "abba", str = "dog cat cat dog" should return true.
2.pattern = "abba", str = "dog cat cat fish" should return false.
3.pattern = "aaaa", str = "dog cat cat dog" should return false.
4.pattern = "abba", str = "dog dog dog dog" should return false.
Notes:You may assume pattern contains only lowercase letters
and str contains lowercase letters separated by a single space.
*/
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> pMatch;
		map<string, char>sMatch;
		vector<string> stringVector;
		string sTemp;
		for (int i = 0; i <= str.size(); i++) {
			if (str[i] == ' ' || i == str.size()) stringVector.push_back(sTemp),sTemp.clear();
			else sTemp += str[i];
		}
		if (pattern.size() != stringVector.size()) return false;
		for (int i = 0; i < pattern.size(); i++) {
			if(pMatch.count(pattern[i]) == 0) pMatch[pattern[i]] = stringVector[i];
			else if (pMatch[pattern[i]] != stringVector[i]) return false;
			if(sMatch.count(stringVector[i]) == 0) sMatch[stringVector[i]] = pattern[i];
			else if (sMatch[stringVector[i]] != pattern[i]) return false;
		}
		return true;
    }
};