/*
7. Reverse Integer
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
*/
class Solution {
public:
	int reverseInt(int x) {
		if(x>INT_MAX || x<INT_MIN) return 0;
		stack<int> s;
		long long  count = 0, value = 0;
		while (x != 0) s.push(x%10), x/=10;
		while (!s.empty()) value += s.top()*pow(10,count++), s.pop();
		return (value>INT_MAX || value<INT_MIN)?0 : value;
    }
};