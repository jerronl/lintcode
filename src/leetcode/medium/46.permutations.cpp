/*
 * 46.permutations.cpp
 *
 *  Created on: Jan 2, 2020
 *      Author: jerron

 *      https://leetcode.com/problems/permutations/
 *      Given a collection of distinct integers, return all possible permutations.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	vector<vector<int>> permute(const vector<int>& nums) {
		vector<vector<int>> result;
		int sz = nums.size();
		vector<int> status(sz + 1, -1);
		vector<bool> used(sz + 1, false);
		for (auto i = 0; i >= 0;) {
			if (i >= sz) {
				result.push_back(vector<int>(sz));
				for (auto j = 0; j < sz; ++j)
					result.back()[j] = nums[status[j]];
				used[status[sz - 1]] = false;
				i -= 2;
			} else {
				if (status[i] >= 0)
					used[status[i]] = false;
				while (used[++status[i]])
					;
				if (status[i] >= sz)
					--i;
				else {
					used[status[i]] = true;
					status[++i] = -1;
				}
			}
		}
		return result;
	}
};

int test() {
	Solution s;
	assertv(s.permute( { 1, 2, 3 }), { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, {
			2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } });

	cout << "permutations passed.\n";
	return 0;
}

#endif





