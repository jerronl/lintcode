/*
 * 44.wildcard-matching.cpp
 *
 *  Created on: Dec 21, 2019
 *      Author: jerron

 *      https://leetcode.com/problems/wildcard-matching/
 *      Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	bool isMatch(const string &s, const string & p) {
		auto ss = -1, ps = -1;
		for (auto ls = s.length(), lp = p.length(), i = ls - ls, j = i;;)
			if (j < lp && p[j] == '*') {
				ss = i;
				ps = ++j;
			} else if (j < lp && i < ls && (p[j] == s[i] || p[j] == '?')) {
				++i;
				++j;
			} else if (j >= lp && i >= ls)
				return true;
			else if (ps > 0 && ss < (int) ls) {
				j = ps;
				i = ++ss;
			} else
				return false;
		return true;
	}
};

int test() {
	Solution s;
	assert(!s.isMatch("acdcb", "a*c?b"));
	assert(s.isMatch("aa", "*"));
	assert(!s.isMatch("aa", "a"));
	assert(!s.isMatch("cb", "?a"));
	assert(s.isMatch("adceb", "*a*b"));

	cout << "wildcard-matching passed.\n";
	return 0;
}

#endif

