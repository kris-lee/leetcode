	/*
	345. Reverse Vowels of a String
	Write a function that takes a string as input and reverse only the vowels of a string.
	Given s = "hello", return "holle".  Given s = "leetcode", return "leotcede". 
	The vowels does not include the letter "y".
	*/
class Solution{
public:
	string reverseVowels(string s) {
		//Solution 1
		string a = "AaEeIiOoUu";
		for (int i = 0, j = s.size()-1; i < j; i++, j--) {
			while (a.find(s[i]) == a.npos) ++i;
			while (a.find(s[j]) == a.npos) --j;
			if (i < j) {
				char temp = s[i];
				s[i] = s[j], s[j] = temp;
			}
		}
		return s;

		//Solution 2
		string a = "AaEeIiOoUu";
		stack<char> v;
		for (int i = 0; i < s.size(); i++)
			if (a.find(s[i]) != a.npos) v.push(s[i]);
		for (int i = 0; i < s.size(); i++) {
			if(a.find(s[i]) != a.npos) {
				s[i] = v.top();
				v.pop();
			}
		}
		return s;  
    }
}