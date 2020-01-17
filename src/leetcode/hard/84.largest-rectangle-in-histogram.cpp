/*
 * 84.largest-rectangle-in-histogram.cpp
 *
 *  Created on: Jan 16, 2020
 *      Author: jerron

 *      https://leetcode.com/problems/largest-rectangle-in-histogram/
 *      Given a non-empty string containing only digits, determine the total number of ways to decode it.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	int largestRectangleArea(const vector<int> &heights) {
		int res = 0;
		auto height(heights);
		height.push_back(0);
		stack<int> st;
		for (int i = 0; i < (int) height.size();) {
			if (st.empty() || height[i] > height[st.top()]) {
				st.push(i++);
			} else {
				int top = st.top();
				st.pop();
				int width = st.empty() ? i : (i - 1 - st.top());
				res = max(res, height[top] * width);
			}
		}
		return res;
	}
};

int test() {
	Solution s;
	assert(
			s.largestRectangleArea(
					{ 1, 1, 1, 0, 2, 2, 1, 0, 1, 3, 2, 1, 2, 1 })
					== 6);
	assert(s.largestRectangleArea( { 2, 1, 2 }) == 3);
	assert(s.largestRectangleArea( {2, 1, 5, 6, 2, 3}) == 10); cout << "largest-rectangle-in-histogram passed.\n";
	return 0;
}

#endif





