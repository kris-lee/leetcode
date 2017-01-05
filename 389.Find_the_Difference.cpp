//389. Find the Difference
//Given two strings s and t which consist of only lowercase letters.
//String t is generated by random shuffling string s and then add one more letter at a random position.
//Find the letter that was added in t.
class Solution {
public:
	char findTheDifference(string s, string t) {
		map<char, int> store;
		for (int i = 0; i < s.size(); i++) {
			map<char, int>::iterator find_it = store.find(s[i]);
			if (find_it != store.end()) ++store[s[i]];
			else store[s[i]] = 1;
		}
		char result;
		for (int i = 0; i < t.size(); i++) {
			map<char, int>::iterator check_it = store.find(t[i]);
			if (check_it != store.end() && store[t[i]] >= 1)
				--store[t[i]];
			else {
				result = t[i];
				break;
			}
		}
		return result;
    }
};
