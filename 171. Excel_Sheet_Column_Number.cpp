	/*
	171. Excel Sheet Column Number
	Given a column title as appear in an Excel sheet, return its corresponding column number.
	For example:
    A -> 1 B -> 2 C -> 3 ... Z -> 26 AA -> 27 AB -> 28 
	*/
class Solution{
	int titleToNumber(string s) {
		int sum = 0;
		for (int i = s.size()-1; i >= 0; i--)
			sum = sum + pow(26,s.size()-1-i)*(int(s[i])-int('A') + 1);
		return sum;
    }
}
