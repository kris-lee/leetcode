	/*
	172. Factorial Trailing Zeroes
	Given an integer n, return the number of trailing zeroes in n!.
	Note: Your solution should be in logarithmic time complexity.
	*/
class Solution {
public:
	int trailingZeroes(int n) {
        if(n<1) return 0;   
        int c = 0;   
        while(n/5 != 0) {    
            n /= 5;   
            c += n;   
        }   
        return c;   
    }
};
