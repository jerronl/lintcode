/*
 * 4.median-of-two-sorted-arrays.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/median-of-two-sorted-arrays/
 *      Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    	function<pair<int,int>(int,int,int,int,int)> findNth=
    			[&findNth,&nums1,&nums2](int nth,int start1,int end1,int start2,int end2)->pair<int,int>{
    		if(start1>=end1)
    			return make_pair(nums2[start2+nth],nums2[min(start2+nth+1,(int)nums2.size()-1)]);
    		else if(start2>=end2)
    			return make_pair(nums1[start1+nth],nums1[min(start1+nth+1,(int)nums1.size()-1)]);
    		if(nth==0){
    			auto result=(nums2[start2]>nums1[start1])?
    					make_pair(nums1[start1],nums2[start2]):make_pair(nums2[start2],nums1[start1]);
    			if (start1+1<(int)nums1.size() && result.second>nums1[start1+1])
    				result.second=nums1[start1+1];
    			if (start2+1<(int)nums2.size() && result.second>nums2[start2+1])
    				result.second=nums2[start2+1];
    			return result;
    		}
    		auto t1=nth*(end1-start1)/(end1-start1+end2-start2),t2=max(0,nth-t1-1);
    		if(nums1[t1+start1]<nums2[t2+start2])
    			return findNth(nth-t1-1,t1+1+start1,min(end1,nth+start1+1),start2,t2+start2+1);
    		return findNth(nth-t2-1,start1,t1+start1+1,t2+1+start2,min(end2,nth+start2+1));
    	};
    	auto size=nums1.size()+nums2.size();
    	auto result=findNth((size-1)/2,0,nums1.size(),0,nums2.size());
    	return (size%2)?result.first:(result.first+result.second)/2.;
    }
};

int test(){
	Solution s;
	assert(s.findMedianSortedArrays({1},{2,3,4})==2.5);
	assert(s.findMedianSortedArrays({1,2},{-1,3})==1.5);
	assert(s.findMedianSortedArrays({},{1,2,3,4})==2.5);
	assert(s.findMedianSortedArrays({3,4},{1,2})==2.5);
	assert(s.findMedianSortedArrays({1,3},{2})==2);
	assert(s.findMedianSortedArrays({1,2},{3,4})==2.5);
	assert(s.findMedianSortedArrays({1,2,5,7,9,13,15},{3,4,6})==5.5);
	assert(s.findMedianSortedArrays({3,4,6},{1,2,5,7,9,13,15})==5.5);
	assert(s.findMedianSortedArrays({3,4,6},{1,2,5,7,8,9,13,15})==6);
	assert(s.findMedianSortedArrays({1,2,5,7,9,13,15},{3,4,6,8})==6);
	cout<<"median-of-two-sorted-arrays passed.\n";
	return 0;
}


#endif







