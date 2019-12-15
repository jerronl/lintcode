/*
 * 41.first-missing-positive.cpp
 *
 *  Created on: Dec 13, 2019
 *      Author: jerron

 *      https://leetcode.com/problems/first-missing-positive//
 *      Given an unsorted integer array, find the smallest missing positive integer.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	int firstMissingPositive(vector<int> nums) {
		int s = nums.size(), i = 0, t = s, tmp = 0;
		for (; i < s; ++i) {
			while ((tmp = nums[i] - 1) != i) {
				auto j = tmp;
				if (j >= s)
					j = --s;
				else if (j < i || nums[j] == tmp + 1)
					--t, j = --s;
				if (i >= s)
					return i + 1;
				swap(nums[i], nums[j]);
			}
		}
		return 1 + (i < (int) nums.size() && nums[i] == i + 1 ? t : i);
	}
};

int test() {
	Solution s;
	assert(s.firstMissingPositive( { 2147483647, 2147483646, 2147483645, 3, 2,
			1, -1, 0, -2147483648 }) == 4);
	assert(s.firstMissingPositive( { -1, 4, 2, 1, 9, 10 }) == 3);
	assert(s.firstMissingPositive( { 2, 2, 2, 2, 2, 2 }) == 1);
	assert(s.firstMissingPositive( { 0, 1, 2 }) == 3);
	assert(s.firstMissingPositive( { 2, 1 }) == 3);
	assert(s.firstMissingPositive( { }) == 1);
	assert(s.firstMissingPositive( { 1 }) == 2);
	assert(s.firstMissingPositive( { 1, 2, 0 }) == 3);
	assert(s.firstMissingPositive( { 3, 4, -1, 1 }) == 2);
	assert(s.firstMissingPositive( { 7, 8, 9, 11, 12 }) == 1);
	cout << "first-missing-positive/ passed.\n";
	return 0;
}

#endif










