/*
357. Count Numbers with Unique Digits
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10n.
Example: Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ¡Ü x < 100, 
excluding [11,22,33,44,55,66,77,88,99])
*/
class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		int sum = 1;
		for (int i = 10; i > 10 - n; i--) sum *= i;
		for (int j = n-1; j > 0; j--) {
			int temp = j;
			for (int k = 9; k > 10 - j; k--) temp *= k;
			sum += temp;
		}
		return sum;
    }
};
