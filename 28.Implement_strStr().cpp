/*
28. Implement strStr()
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		 int needle_size = needle.size(), haystack_size = haystack.size();
		 if (haystack == needle || needle_size == 0) return 0;
		 if (haystack_size < needle_size) return -1;
		 for (int i = 0; i < haystack_size - needle_size; i++) {
			 if (haystack.substr(i, needle_size) == needle) 
				 return i;
		 }
		 return -1;
    }
};
