	/*
	5. Longest Palindromic Substring
	Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
	Example:	Input: "babad"	Output: "bab"
	Note: "aba" is also a valid answer.
	Example:	Input: "cbbd"	Output: "bb"
	*/
class Solution {
public:
	bool isStringPalindrome(string s, int front, int rear) {
		while (front < rear)
			if (s[front++] != s[rear--]) return false;
		return true;
	}
	string longestPalindrome(string s) {
        string result;
		int length = 0;
		for (int i = 0; i < s.size()-length; i++) {
			for (int j = s.size(); j >= i+length ; j--) {
				if (s[i] == s[j] && isStringPalindrome(s,i,j) && (j-i+1)>length)
					length = j-i+1, result = s.substr(i,j-i+1);
			}
		}
		return result; 
    }
};
