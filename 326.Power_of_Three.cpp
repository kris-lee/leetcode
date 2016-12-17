	/*
	326. Power of Three
	Given an integer, write a function to determine if it is a power of three.
	*/
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;
		if (n == 1) return true;
		return isPowerOfThree(n/3) && (n % 3 == 0?true:false);

		if (n <= 0) return false; 
		while (n != 1) {
			if (n % 3 != 0) return false;
			n /= 3;
		}
		return true;
    }
}