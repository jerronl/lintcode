/*
 * 29.divide-two-integers.cpp
 *
 *  Created on: Jan 14, 2020
 *      Author: jerron

 *      https://leetcode.com/problems/divide-two-integers/
 *      Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	int divide(int dividend, int divisor) {
		function<pair<long long, long long>(long long, long long)> helper =
				[&helper](long long dividend,long long divisor)->pair<long long,long long> {
					if(dividend<divisor)
					return make_pair(0,dividend);
					auto ndivi=dividend>>1,residual=dividend-(ndivi<<1);
					auto result=helper(ndivi,divisor);
					result.first<<=1;
					result.second=(result.second<<1)+residual;
					if(result.second>=divisor)
					return make_pair(result.first+1,result.second-divisor);
					return result;
				};
		long long ld = dividend, res, lds = divisor;
		if (dividend < 0) {
			if (divisor < 0)
				res = helper(-ld, -lds).first;
			else
				res = -helper(-ld, lds).first;
		} else if (divisor < 0)
			res = -helper(ld, -lds).first;
		else
			res = helper(ld, lds).first;
		return min((long long) INT_MAX, res);
	}
};

int test() {
	Solution s;
	assert(s.divide(7, 3) == 2);
	assert(s.divide(2147483647, 3) == 715827882);
	assert(s.divide(-2147483648, 1) == -2147483648);
	assert(s.divide(-2147483648, -1) == 2147483647);
	assert(s.divide(10, 3) == 3);
	assert(s.divide(7, -3) == -2);
	cout << "divide-two-integers passed.\n";
	return 0;
}

#endif














