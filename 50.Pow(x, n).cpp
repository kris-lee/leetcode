/*
50. Pow(x, n)
Implement pow(x, n).
*/
class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1) return 1;
		if (x == -1) return n%2==0?1:-1;
		#define DBL_MAX         1.7976931348623158e+308
		double result = 1;
		for (int i = 0; i < abs(double(n)); i++) {
			result *= x;
			if (result == 0 || result >= DBL_MAX) 
				break;
		}
		if (n < 0) result = 1/result;
		return result;
    }
};
