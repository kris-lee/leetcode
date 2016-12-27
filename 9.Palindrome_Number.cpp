	/*
	9. Palindrome Number
	Determine whether an integer is a palindrome. Do this without extra space.
	*/
class Solution {
public:
	bool isPalindrome(int x) {
		int max = x;  
        int min = 0;  
        while(max >0){  
            min *= 10;  
            min+= max %10;  
            max /=10;  
        }  
        return min==x; 

		if (x < 0) return false;
		vector<int> nums;
		while (x != 0) {
			nums.push_back(x%10);
			x /= 10;
		}
		for (int i = 0, j = nums.size()-1; i < j; i++, j--)
			if (nums[i] != nums[j]) return false;
		return true;
    }
};
