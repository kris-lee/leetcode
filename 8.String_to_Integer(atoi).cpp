/*
8. String to Integer (atoi)
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/
class Solution {
public:
	int myAtoi(string str) {
		//Solution 1
		int index = 0, sigh = 1;
		long long value = 0;
		bool flag = true;
		while (index<str.size() && str[index] == ' ') ++index;
		if (str[index] == '-' || str[index] == '+' && flag == true)
			if (str[index++] == '-') sigh = -1, flag = false;
		while (index<str.size() && isdigit(str[index])) {
			if (value>INT_MAX) break;
			value = 10*value + str[index] - '0';
			index++;
		}
		if (value*sigh>INT_MAX || value*sigh<INT_MIN) {
			if (sigh == -1) return INT_MIN;
			else return INT_MAX;
		}
		return value*sigh;

		//Solution 2
		int index = 0, sigh = 1;
		long value = 0;
		bool flag = true;
		while (index<str.size() && str[index] == ' ') ++index;
		if (str[index] == '-' || str[index] == '+' && flag == true)
			if (str[index++] == '-') sigh = -1, flag = false;
		while (index<str.size() && isdigit(str[index])) {
			value = 10*value + (str[index++] - '0');
			if (value*sigh>=INT_MAX)  return INT_MAX;
			if (value*sigh<=INT_MIN)  return INT_MIN;
		}
		return value*sigh;
	}
};