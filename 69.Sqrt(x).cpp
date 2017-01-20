/*
69. Sqrt(x)
mplement int sqrt(int x).
Compute and return the square root of x.
*/
class Solution{
public:
	int mySqrt(int x) {
		//Solution 1
		if (x <= 0) return 0;
		int front = 0, back = x, middle, middle_back, limit = 46340;
		while (front <= back) {
			middle = front + (back - front)/2, middle_back = middle + 1;
			if (middle > limit) back = limit;
			else {
				int midle_result = middle * middle, middle_back_result = middle_back * middle_back;
				if (midle_result > x) back = middle;
				else if (middle_back_result <= x) front = middle + 1;
				else break;
			}
		}
		return middle;

		//Solution 2
		if (x <= 0) return 0;
		int front = 1, back = x, middle;
		while (front <= back) {
			middle = front + (back - front)/2;
			if (x / middle < middle) back = middle;
			else if (x / (middle+1) >= (middle+1)) front = middle + 1;
			else break;
		}
		return middle;
    }
};
