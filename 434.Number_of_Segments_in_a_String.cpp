	/*
	434. Number of Segments in a String
	Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
	Please note that the string does not contain any non-printable characters.
	Example: Input: "Hello, my name is John" Output: 5
	*/
class Solution {
public:
	int countSegments(string s) {
		if (s.size() == 0) return 0;
		int count = 0;
		for (int i = 0; i < s.size()-1; i++)
			if (s[i] != ' ' && s[i+1] == ' ') ++count;
		if (s[s.size()-1] != ' ') ++count;
		return count;
    }
}