/*
 * 23.merge-k-sorted-lists.cpp
 *
 *  Created on: Dec 13, 2019
 *      Author: jerron

 *      https://leetcode.com/problems/merge-k-sorted-lists/
 *      Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
#if 1
#include "../../utils/utils.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto list_comp=[](ListNode*l1,ListNode* l2){
        	return l1->val>l2->val;
        };
    	priority_queue<ListNode*,vector<ListNode*>,decltype(list_comp)> q(list_comp);
    	ListNode* res=nullptr,**next=&res;
    	for(auto p:lists)
    		if(p)
    			q.push(p);
    	while(!q.empty()){
    		auto p=q.top();
    		q.pop();
    		if(p->next)
    			q.push(p->next);
    		*next=p;
    		p->next=nullptr;
    		next=&p->next;
    	}
    	return res;
    }
};
int test(){
	Solution s;
	ListNode t1{1,4,5},t2{1,3,4},t3{2,6},expected{1,1,2,3,4,4,5,6};
	vector<ListNode*> lists{&t1,&t2,&t3};
	assertl(s.mergeKLists(lists),&expected);
	cout<<"merge-k-sorted-lists passed.\n";
	return 0;
}


#endif








