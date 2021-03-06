/*
 * 42.trapping-rain-water.cpp
 *
 *  Created on: Dec 14, 2019
 *      Author: jerron

 *      https://leetcode.com/problems/trapping-rain-water/
 *      Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	int trap(const vector<int>& height) {
		auto res = 0;
		for (int l = 0, r = height.size() - 1, low = 0, high = 0; l < r;) {
			low = height[l] > height[r] ? r-- : l++;
			high = max(high, height[low]);
			res += high - height[low];
		}
		return res;
	}
};

int test() {
	Solution s;
	assert(s.trap( { }) == 0);
	assert(s.trap( { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }) == 6);
	cout << "trapping-rain-water passed.\n";
	return 0;
}

#endif










