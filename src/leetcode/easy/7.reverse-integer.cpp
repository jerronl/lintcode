/*
 * 7.reverse-integer.cpp
 *
 *  Created on: Dec 10, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/reverse-integer/
 *      Given a 32-bit signed integer, reverse digits of an integer.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	int reverse(int x) {
        if(x==INT_MIN)
                return 0;
		int sign=x<0?-1:1,res=0,base=10;
		unsigned ux=x*sign;
		for(;ux!=0;ux/=base){
			if(res>INT_MAX/base)
				return 0;
			auto tmp=ux%base;
			if(res>INT_MAX-tmp)
				return 0;
			res*=base;
			res+=tmp;
		}
		return res*sign;
    }
};

int test(){
	Solution s;
	assert(s.reverse(-123)==-321) ;
	assert(s.reverse(-2147483648)==0) ;
	assert(s.reverse(123)==321) ;
	assert(s.reverse(120)==21) ;
	cout<<"reverse-integer passed.\n";
	return 0;
}


#endif
