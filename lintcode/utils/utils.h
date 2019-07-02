/*
 * util.h
 *
 *  Created on: Apr 12, 2019
 *      Author: jerron
 */

#ifndef UTIL_H_
#define UTIL_H_


#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>
#include <set>
#include <queue>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cassert>
#include <initializer_list>

using namespace std;


#ifdef __DEBUG
#define LOGGER(x) cout<<x
#else
#define LOGGER(x)
#endif

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode():val(INT_MIN),next(nullptr){}
    explicit ListNode(int val):val(val),next(nullptr) {}
    explicit ListNode(const initializer_list<int>& l):val(*l.begin()),next(nullptr) {
    	auto prev=&next;
    	for(auto i=l.begin();++i!=l.end();prev=&(*prev)->next)
    		*prev=new ListNode(*i);
    }
    bool del(){
    	if(val==INT_MIN){
    		LOGGER("Probably trying to delete pointer already deleted!!!!!"<<endl);
    		return false;
    	}
		if(next&&next->del())
			delete next;
		val=INT_MIN;
		return true;
    }
};
inline void assertl(ListNode*l1,ListNode*l2){
	if(l1){
		assert(l2);
		assert(l1->val==l2->val);
		assertl(l1->next,l2->next);
	}
	else
		assert(!l2);
}

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode() :val(INT_MIN),left(nullptr),right(nullptr){};
    explicit TreeNode(int val) :val(val),left(nullptr),right(nullptr){};
};

template<class T>
void enumerate(T&& dfs){
	int i=0;
	for (;dfs.next();++i)
		cout << dfs.getResult()<<" : " <<i<< endl;
}

using intVec=vector<int>;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& source){
	for(auto i:source)
		os<<i<<" ";
	return os;
}
template<class T>
void assertv(const vector<T>&v1,const vector<T>&v2){
	assert(v1.size()==v2.size());
	for(auto i1=v1.begin(),i2=v2.begin();i1!=v1.end();++i1,++i2)
		assert(*i1==*i2);
}
template<class T>
void del(vector<T*>v){
	for(auto i:v)
		i->del();
}

#endif /* UTIL_H_ */
