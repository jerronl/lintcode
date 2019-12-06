/*
 * 2.add-two-numbers.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: jerron
 *      https://leetcode.com/problems/add-two-numbers/
 *      Given a binary tree, find its maximum depth.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* res,** e=&res;
    	for(int c=0;l1||l2||c;){
    		if(l1){
    			c+=l1->val;
    			l1=l1->next;
    		}
    		if(l2){
    			c+=l2->val;
    			l2=l2->next;
    		}
    		*e=new ListNode(c % 10);
    		c/=10;
    		e=&((*e)->next);
    	}
    	return res;
    }
};

int test(){
	Solution s;
	ListNode l1{2,4,3},l2{5,6,4},l3{7,0,8};
	assertl(s.addTwoNumbers(&l1,&l2),&l3);
	cout<<"add-two-numbers passed.\n";
	return 0;
}


#endif




