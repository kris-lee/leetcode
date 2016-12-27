	/*
	119. Pascal's Triangle II
	Given an index k, return the kth row of the Pascal's triangle.
	For example, given k = 3, Return [1,3,3,1].
	*/
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> temp;
		if (rowIndex < 0) return temp;
		vector<int> result(1,1);
		for (int i = 0; i < rowIndex; i++) {
			temp.push_back(1);
			for (int j = 1; j <= i; j++)
				temp.push_back(result[j] + result[j-1]);
			temp.push_back(1);
			result = temp;
			temp.clear();
		}
		return result;
    }
};
