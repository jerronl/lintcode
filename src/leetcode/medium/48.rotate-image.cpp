/*
 * 48.rotate-image.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: jerron

 *      https://leetcode.com/problems/rotate-image/
 *      Rotate the image by 90 degrees (clockwise).
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		for (auto n = matrix.size(), i = n - n; i <= n / 2; ++i)
			for (auto j = i; j < n - i - 1; ++j)
				for (auto x = i, y = j, nx = x, ny = y;
						((nx = n - y - 1) != i) + ((ny = x) != j) != 0;
						x = nx, y = ny)
					swap(matrix[x][y], matrix[nx][ny]);
	}
};

int test() {
	Solution s;
	vector<vector<int>> test1 { vector<int> { 1, 2, 3 },
			vector<int> { 4, 5, 6 }, vector<int> { 7, 8, 9 } }, expected1 {
			vector<int> { 7, 4, 1 }, vector<int> { 8, 5, 2 }, vector<int> { 9,
					6, 3 } }, test2 { vector<int> { 5, 1, 9, 11 }, vector<int> {
			2, 4, 8, 10 }, vector<int> { 13, 3, 6, 7 }, vector<int> { 15, 14,
			12, 16 } }, expected2 { vector<int> { 15, 13, 2, 5 }, vector<int> {
			14, 3, 4, 1 }, vector<int> { 12, 6, 8, 9 }, vector<int> { 16, 7, 10,
			11 } };
	s.rotate(test1);
	s.rotate(test2);
	assertv(test1, expected1);
	assertv(test2, expected2);
	cout << "rotate-image passed.\n";
	return 0;
}

#endif










