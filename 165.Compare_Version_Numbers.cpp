/*
165. Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering: 0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
	vector<int> strTovector(string s) {
		vector<int> result;
		int index = 0;
		for (int i = 0; i < s.size(); i++) {
			if (!isalnum(s[i])) {
				if (i-1 < index) result.push_back(0);
				else result.push_back(atoi(s.substr(index, i-index).c_str()));
				index = i+1;
			}
		}
		if (isalnum(s[s.size()-1])) result.push_back(atoi(s.substr(index, s.size()-index).c_str()));
		for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
		cout <<endl;
		return result;
	}
	int compareVersion(string version1, string version2) {
		vector<int> ver1,ver2;
		ver1 = strTovector(version1), ver2 = strTovector(version2);
		int diff = abs(int(ver1.size()-ver2.size()));
		if (ver1.size() < ver2.size())
			for (int i = 0; i < diff; i++) ver1.push_back(0);
		else for (int i = 0; i < diff; i++) ver2.push_back(0);
		for (int i = 0; i < ver1.size(); i++) {
			if (ver1[i] > ver2[i]) return 1;
			else if (ver1[i] < ver2[i]) return -1;
		}
		return 0;
    }
};
