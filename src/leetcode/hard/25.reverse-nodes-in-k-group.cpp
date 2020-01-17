/*
 * 25.reverse-nodes-in-k-group.cpp
 *
 *  Created on: Jan 4, 2020
 *      Author: jerron

 *      https://leetcode.com/problems/reverse-nodes-in-k-group/
 *      Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 */
#if 0
#include "../../utils/utils.h"

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode*h = head;
		for (auto i = 0; i < k; ++i, h = h->next)
			if (!h)
				return head;
		ListNode *next = head->next, **ph = &head, **tail = &head->next;
		for (auto i = 1; i < k; ++i) {
			*tail = next->next;
			next->next = *ph;
			*ph = next;
			next = *tail;
		}
		*tail = reverseKGroup(h, k);
		return head;
	}
};

int test() {
	Solution s;
	ListNode test2 { 1, 2, 3, 4, 5 }, test3 { 1, 2, 3, 4, 5 }, expected3 { 3, 2,
			1, 4, 5 }, expected2 { 2, 1, 4, 3, 5 };
	assertl(s.reverseKGroup(&test2, 2), &expected2);
	assertl(s.reverseKGroup(&test3, 3), &expected3);

	cout << "reverse-nodes-in-k-group passed.\n";
	return 0;
}

#endif









