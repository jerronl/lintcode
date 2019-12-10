#if 0
/*
 *
 *
 *  Created on: Dec 6, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/add-two-numbers/
 *      given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
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
