/*
 * 8.string-to-integer-atoi.cpp
 *
 *  Created on: Dec 10, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/string-to-integer-atoi/
 *      Implement atoi which converts a string to an integer.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
    int myAtoi(string str) {
        int base=10,sign=1,i=-1;
        unsigned res=0,c;
    	for(auto cont=true;cont&&++i<(int)str.length();)
    		switch (str[i]){
    		case ' ':
    			break;
    		case '-':
    			sign=-1; // @suppress("No break at end of case")
    		case '+':
    			++i; 	// @suppress("No break at end of case")
    		default:
    			cont=false;
    		}
    	for(auto cont=true;cont&&i<(int)str.length();++i)
    		switch (str[i]){
    		case '0':
    		case '1':
    		case '2':
    		case '3':
    		case '4':
    		case '5':
    		case '6':
    		case '7':
    		case '8':
    		case '9':
    			c=str[i]-'0';
    			if(res>INT_MAX/base||(res*=base)>INT_MAX-c)
    				return sign<0?INT_MIN:INT_MAX;
    			res+=c;
    			break;
    		default:
    			cont=false;
    		}
    	return sign*res;
    }
};

int test(){
	Solution s;
	assert(s.myAtoi("2147483646")==2147483646) ;
	assert(s.myAtoi("+42")==42) ;
	assert(s.myAtoi("42")==42) ;
	assert(s.myAtoi("     -42 with word")==-42) ;
	cout<<"string-to-integer-atoi passed.\n";
	return 0;
}


#endif




