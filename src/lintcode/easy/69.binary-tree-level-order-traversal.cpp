/*
 * 69.binary-tree-level-order-traversal.cpp
 *
 *  Created on: Jul 14, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/binary-tree-level-order-traversal/description
 *      Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */
#include "../../utils/utils.h"

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if(root){
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            result.push_back({});
            for(auto count=Q.size();count>0;--count){
                auto n=Q.front();
                Q.pop();
                result.back().push_back(n->val);
                if(n->left)
                    Q.push(n->left);
                if(n->right)
                    Q.push(n->right);
        }}}
        return result;
    }
};
//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode test[]{{1,2,3},{1,INT_MIN,2,3}};
	vector<vector<int>> expected[]{{{1},{2,3}},{{1},{2},{3}}};
	for(auto i=0u;i<countof(test);++i){
		assertv(s.levelOrder(&test[i]),expected[i]);
		test[i].del();
	}
	cout<<"binary-tree-level-order-traversal passed.\n";
	return 0;
}


