/*
 * 3.longest-substring-without-repeating-characters.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *     Given a string, find the length of the longest substring without repeating characters.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>M(256,-1);
        int longest=0,start=0;
        for(int i=0;i<s.length();++i){
        	if(start<=M[s[i]]){
        		longest=max(longest,i-start);
        		start=M[s[i]]+1;
        	}
        	M[s[i]]=i;
        }
        return max((int)s.length()-start,longest);
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





