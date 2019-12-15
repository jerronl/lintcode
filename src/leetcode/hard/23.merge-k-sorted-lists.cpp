/*
 * 23.merge-k-sorted-lists.cpp
 *
 *  Created on: Dec 13, 2019
 *      Author: jerron

 *      https://leetcode.com/problems/merge-k-sorted-lists/
 *      Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	std::remove_reference< decltype(lists)>::type q;
    	for(auto p:lists)
    		if(p)
    			q.push_back(p);
        auto list_comp=[](ListNode*l1,ListNode* l2){
        	return l1->val>l2->val;
        };
        make_heap(q.begin(),q.end(),list_comp);
    	ListNode* res=nullptr,**next=&res;
    	while(!q.empty()){
    		auto p=q.front();
    		pop_heap(q.begin(),q.end(),list_comp);
    		q.pop_back();
    		if(p->next){
    			q.push_back(p->next);
    			push_heap(q.begin(),q.end(),list_comp);
    		}
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
