/*
461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:0 ¡Ü x, y < 231.
Example: Input: x = 1, y = 4	Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
		¡ü   ¡ü
The above arrows point to positions where the corresponding bits are different.
*/
class Solution {
public:
	int hammingDistance(int x, int y) {
        int z = x ^ y, count = 0;
		while (z != 0) {
			if (z % 2 == 1) ++count;
			z = z/2;
		}
		return count;
    }
};