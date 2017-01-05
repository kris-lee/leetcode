/*
38. Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
*/
class Solution {
public:
	string countAndSay(int n) {
		string result;
		if (n <= 0) return result;
		result = "1";
		string sTemp;
		for (int i = 1; i < n; i++) {
			int count = 1;
			for (int j = 1; j <= result.size(); j++) {
				if (result[j] == result[j-1]) ++count;
				else {
					sTemp = sTemp + to_string(count) + result[j-1];
					count = 1;
				}
			}
			result = sTemp,sTemp.clear();
		}
		return result;
    }
};
