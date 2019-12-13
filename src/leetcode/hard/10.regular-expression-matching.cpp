/*
 * 10.regular-expression-matching.cpp
 *
 *  Created on: Dec 12, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/regular-expression-matching/
 *      Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 */
#if 0
#include "../../utils/utils.h"

class Solution {

public:
    bool isMatch(string s, string p) {
    	auto ls=s.length(),lp=p.length();
    	vector<bool> DP(lp+1,false);
    	for (auto i=ls-ls;i<=ls;++i){
    		bool pre=DP[0];
    		DP[0]=!i;
    	for (auto j=lp-lp+1;j<=lp;++j){
    		auto temp=DP[j];
    		if(p[j-1]=='*')
    			DP[j]=DP[j-2]||(i&&DP[j]&&(p[j-2]=='.'||p[j-2]==s[i-1]));
    		else
    			DP[j]=pre&&i&&(p[j-1]=='.'||p[j-1]==s[i-1]);
    		pre=temp;
    		}
    	}
    	return DP[lp];
    }
};
int test(){
	Solution s;
	assert(s.isMatch("aab","c*a*b"));
	assert(!s.isMatch("aa","a"));
	assert(s.isMatch("a","ab*"));
	assert(s.isMatch("","c*a*"));
	assert(!s.isMatch("a",".*..a*"));
	assert(s.isMatch("aa","a*"));
	assert(s.isMatch("aa",".*"));
	assert(!s.isMatch("mississippi","mis*is*p*."));
	assert(s.isMatch("aabc","c*a*b*abc"));
	assert(s.isMatch("abc","c*a*b*abc"));
	cout<<"regular-expression-matching passed.\n";
	return 0;
}


#endif








