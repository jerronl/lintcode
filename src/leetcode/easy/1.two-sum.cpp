#if 0
/*
 * 1.two sum.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/two-sum/
 *      Given a binary tree, find its maximum depth.
 */
#include "../../utils/utils.h"

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int,int> M;
        int i=0;
        for(auto n:nums)
        	if(M.count(target-n))
        		return {M[target-n],i};
        	else
        		M[n]=i++;
        return {};
    }
};

int test(){
	Solution s;
	assertv(s.twoSum({2,7,11,15},9),{0,1});
	cout<<"two-sum passed.\n";
	return 0;
}


#endif
