/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).
For example,a = "11", b = "1", Return "100".
*/
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		if (a.size() < b.size()) {string sTemp=b;b=a;a=sTemp;}
		int count = 0, sum = 0; 
		for (int i = 0; i < a.size(); i++) {
			if (i < b.size()) sum = a[a.size()-1-i] - '0' + b[b.size()-1-i] - '0' + count;
			else sum = a[a.size()-1-i] - '0' + count;
			result.push_back(char(sum%2 + '0'));
			if (sum >= 2) count = 1;
			else count = 0;
			sum = 0;
		}
		if (count == 1) result.push_back('1');
		reverse(result.begin(), result.end());
		return result;
	}
};
