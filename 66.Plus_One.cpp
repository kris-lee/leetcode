	/*
	66. Plus One
	Given a non-negative number represented as an array of digits, plus one to the number.
	The digits are stored such that the most significant digit is at the head of the list.
	*/
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0) {
			digits.push_back(1); 
			return digits;
		}
		reverse(digits.begin(), digits.end());
		int count = 0;
		for (int i = 0; i < digits.size(); i++) {
			if (i == 0) digits[i] += 1;
			int temp = (digits[i] + count) % 10;
			count = (digits[i] + count) / 10;
			digits[i] = temp;
		}
		if (count == 1) digits.push_back(count);
		reverse(digits.begin(), digits.end());
		return digits;
    }
};
