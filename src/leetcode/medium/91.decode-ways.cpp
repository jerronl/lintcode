/*
 * 91.decode-ways.cpp
 *
 *  Created on: Jan 16, 2020
 *      Author: jerron

 *      https://leetcode.com/problems/decode-ways/
 *      Given a non-empty string containing only digits, determine the total number of ways to decode it.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] < '1')
			return 0;
		int last = 100, res = 1, prev = 0;
		for (auto c : s) {
			c -= '0';
			if (!c) {
				if (last < 27) {
				res = prev;
				prev = 0;
				} else
					return 0;
			} else if (c + last < 27) {
				res += prev;
				prev = res - prev;
			} else
				prev = res;
			last = c * 10;
		}
		return res;
	}
};

int test() {
	Solution s;
	assert(s.numDecodings("230") == 0);
	assert(s.numDecodings("00") == 0);
	assert(s.numDecodings("12") == 2);
	assert(s.numDecodings("10") == 1);
	assert(s.numDecodings("110") == 1);
	assert(s.numDecodings("1105") == 1);
	assert(s.numDecodings("226") == 3);
	cout << "decode-ways passed.\n";
	return 0;
}

#endif
