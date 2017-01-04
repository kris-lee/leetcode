/*
400. Nth Digit
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:n is positive and will fit within the range of a 32-bit signed integer (n < 231).
Example 1:Input:3	Output:3
Example 2:Input:11	Output:0
Explanation:The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, 
which is part of the number 10.
*/
class Solution {
public:
	int findNthDigit(int n) {
		int count = 1;
		while (n > count*9*pow(10, count-1)) n -= pow(10, count-1)*9*count++ ;
		int true_number = pow(10, count-1) + (n-1)/count, divide_count =count - (n-1)%count;
		while (divide_count != 1) true_number /= 10, --divide_count;
		return true_number%10;
	}
};
