/*
 * 11.container-with-most-water.cpp
 *
 *  Created on: Dec 19, 2019
 *      Author: jerron

 *      https://leetcode.com/problems/container-with-most-water/
 *      Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	int maxArea(const vector<int>& height) {
		int res = 0;
		for (int i = 0, j = height.size() - 1, h = 0; i < j;)
			if (height[i] <= h)
				++i;
			else {
				for (; height[j] <= h && i < j; --j)
					;
				h = min(height[i], height[j]);
				res = max(res, h * (j - i));
		}
		return res;
	}
};

int test() {
	Solution s;
	assert(s.maxArea( { 1, 8, 6, 2, 5, 4, 8, 3, 7 }) == 49);

	cout << "container-with-most-water passed.\n";
	return 0;
}

#endif
