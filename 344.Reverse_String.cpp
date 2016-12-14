//344. Reverse String
//Write a function that takes a string as input and returns the string reversed.

class Solution {
public:
	string reverseString(string s) {
		if (s.size() <= 1) return s;
		for (int i = 0, j = s.size()-1; i < j; i++, j--)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
		return s;
    }
}