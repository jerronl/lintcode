/*
 * 95.validate-binary-search-tree.cpp
 *
 *  Created on: Jul 23, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/validate-binary-search-tree/description
 *      Given a binary tree, determine if it is a valid binary search tree (BST).
 */
#define __DEBUG
#include "../../utils/utils.h"

class Solution {
private:
    TreeNode *last = nullptr;
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if(!root)return true;
        if(!isValidBST(root->left))return false;
        if(last && last != root && last->val >= root->val)return false;
        last = root;
        if (!isValidBST(root->right))return false;
        return true;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode *tests[]{nullptr,new TreeNode{2,1,4,INT_MIN,INT_MIN,3},new TreeNode{5,1,4,INT_MIN,INT_MIN,3}};
	for(auto i=0u;i<countof(tests);++i){
		assert(s.isValidBST(tests[i])==TreeNode::isBST(tests[i]));
		if(tests[i])
			tests[i]->del();
		delete tests[i];
	}
	cout<<"validate-binary-search-tree passed.\n";
	return 0;
}

