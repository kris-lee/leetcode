	/*
	168. Excel Sheet Column Title
	Given a positive integer, return its corresponding column title as appear in an Excel sheet.
	For example: 1 -> A 2 -> B 3 -> C ... 26 -> Z 27 -> AA 28 -> AB 
	*/
class Solution{
	string convertToTitle(int n) {
		string result;
		while (n != 0){
			if (n % 26 != 0){
				result.push_back(char(n%26 +64));
				n /= 26;
			}
			else {
				result.push_back('Z');
				n = n/26 - 1;
			}
		}
		reverse(result.begin(), result.end());
		return result;
    }
}
