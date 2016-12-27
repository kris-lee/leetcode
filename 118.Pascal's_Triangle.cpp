	/*
	118. Pascal's Triangle
	Given numRows, generate the first numRows of Pascal's triangle.
	*/
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		for (int i = 1; i <= numRows; i++) {
			vector<int> layVector(i,1);
			for (int j = 1; j < i - 1; j++)
				layVector[j] = result[i-2][j-1] + result[i-2][j];
			result.push_back(layVector);
			layVector.clear();
		}
		return result;
    }
};
