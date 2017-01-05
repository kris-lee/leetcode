//371. Sum of Two Integers
//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
class Solution {
public:
	int getSum(int a, int b) {
		while (b){
			int c = a ^ b;
			b = (a & b) << 1;
			a = c;
        }
        return a;
    }
};