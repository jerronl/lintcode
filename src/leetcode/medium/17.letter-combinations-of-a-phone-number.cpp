/*
 * letter-combinations-of-a-phone-number.cpp
 *
 *  Created on: Jan 16, 2020
 *      Author: jerron

 *      https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *      Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 */
#if 1
#include "../../utils/utils.h"

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		static vector<string> dmap { " ", "", "abc", "def", "ghi", "jkl", "mno",
				"pqrs", "tuv", "wxyz" };
		if (digits.empty())
			return {};
		vector<string> res = letterCombinations(digits.substr(1)), ret { };
		if (res.empty())
			for (auto c : dmap[digits[0] - '0'])
				ret.push_back(string(1, c));
		else
			for (auto r : res)
			for (auto c : dmap[digits[0] - '0'])
				ret.push_back(string(1, c) + r);
		return ret;
	}
};

int test() {
	Solution s;
	asserteqv(s.letterCombinations("23"), { "ad", "ae", "af", "bd", "be", "bf",
			"cd", "ce", "cf" });
	cout << "letter-combinations-of-a-phone-number passed.\n";
	return 0;
}

#endif





