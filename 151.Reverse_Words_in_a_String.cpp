/*
151. Reverse Words in a String
Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Update (2015-02-12):	For C programmers: Try to solve it in-place in O(1) space.
*/
class Solution {
public:
	void reverseWords(string &s) {
		int originSize = s.size(), index = originSize - 1;
		for (int i = index; i >= 0; i--) {
			if (s[i] != ' ') {
				int iTemp = i;
				while (iTemp >=0 && s[iTemp] != ' ') --iTemp;
				s += (s.substr(iTemp+1, i-iTemp) + ' ');
				i = iTemp;
			}
		}
		s = s.substr(originSize, s.size()-originSize-1);
    }
};
