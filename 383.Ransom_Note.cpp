//383. Ransom Note
//Given an arbitrary ransom note string and another string containing letters from all the magazines, 
//write a function that will return true if the ransom note can be constructed from the magazines;
//otherwise, it will return false.
//Each letter in the magazine string can only be used once in your ransom note.
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map<char, int> store;
		for (int i = 0; i < magazine.size(); i++) {
			map<char, int>::iterator find_it = store.find(magazine[i]);
			if (find_it != store.end()) ++store[magazine[i]];
			else store[magazine[i]] = 1;
		}
		bool result = true;
		for (int i = 0; i < ransomNote.size(); i++) {
			map<char, int>::iterator check_it = store.find(ransomNote[i]);
			if (check_it != store.end() && store[ransomNote[i]] >= 1) --store[ransomNote[i]];
			else {
				result = false;
				break;
			}
		}
		return result;
    }
};
