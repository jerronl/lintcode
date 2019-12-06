/*
 * 3.longest-substring-without-repeating-characters.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *      Given a binary tree, find its maximum depth.
 */
#if 1
#include "../../utils/utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,unsigned>M;
        unsigned longest=0,length=0;
        for(unsigned i=0;i<s.length();++i){
        	if(M.count(s[i])){
        		longest=max(longest,length);
        		length=min(i-M[s[i]],length+1);
        	}
        	else
        		++length;
        	M[s[i]]=i;
        }
        return max(length,longest);
    }
};

int test(){
	Solution s;
	assert(s.lengthOfLongestSubstring("abba")==2);
	assert(s.lengthOfLongestSubstring("abcabcbb")==3);
	assert(s.lengthOfLongestSubstring("bbbbb")==1);
	assert(s.lengthOfLongestSubstring("pwwkew")==3);
	cout<<"longest-substring-without-repeating-characters passed.\n";
	return 0;
}


#endif





