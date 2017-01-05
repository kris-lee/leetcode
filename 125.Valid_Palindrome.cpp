/*
125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example, "A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note: Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
	bool isPalindrome(string s) {
		//Solution 1
		for (int i=0, j=s.size()-1;i < j;i++,j--) {
			while( !((s[i]-'0'>=0 && s[i]-'0'<=9) || (tolower(s[i])-'a'>=0 && tolower(s[i])-'a'<=25))) ++i;
			while( !((s[j]-'0'>=0 && s[j]-'0'<=9) || (tolower(s[j])-'a'>=0 && tolower(s[j])-'a'<=25))) --j;
			if (i<j && tolower(s[i])!=tolower(s[j])) return false;
		}
		return true;

		//Solution 2
		for (int i=0, j=s.size()-1;i < j;i++,j--) {
			while( isalnum(s[i]) == false) ++i;
			while( isalnum(s[j]) == false) --j;
			if (i<j && tolower(s[i])!=tolower(s[j])) return false;
		}
		return true;
    }
};
