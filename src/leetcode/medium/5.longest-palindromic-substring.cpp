/*
 * 5.longest-palindromic-substring.cpp
 *
 *  Created on: Dec 7, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/longest-palindromic-substring/
 *      Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int length=s.length(),start=0,longest=1;
        if(length<2)
        	return s;
        vector<int> cnt(length);
        cnt[0]=1;
        for(auto i=1;i<length;++i){
        	auto j=i-1-cnt[i-1];
        	if(j>=0&&s[i]==s[j])
        		cnt[i]=cnt[i-1]+2;
        	else{
        		cnt[i]=1;
        		for(j=max(0,j);j<i;++j)
        			if(s[i]==s[j]){
        				auto k=j+1,l=i-1;
        				for(;k<l;++k,--l)
        					if(s[k]!=s[l])
        						break;
        				if(k>=l){
        					cnt[i]=i-j+1;
        					break;
        				}
        			}
        	}
        	if(cnt[i]>longest){
        		longest=cnt[i];
        		start=i+1-cnt[i];
        	}
        }
        return s.substr(start,longest);
    }
};

int test(){
	Solution s;
	assert(s.longestPalindrome("")=="") ;
	assert(s.longestPalindrome("abcabababacaa")=="cabababac") ;
	auto tmp=s.longestPalindrome("babad");
	assert(tmp=="bab"||tmp=="aba");
	assert(s.longestPalindrome("cbbd")=="bb") ;
	cout<<"longest-palindromic-substring passed.\n";
	return 0;
}


#endif








