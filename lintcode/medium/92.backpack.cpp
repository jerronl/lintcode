/*
 * 92.backpack.cpp
 *
 *  Created on: Sep 16, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/backpack/description
 *      Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?
 *
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
	/**
	 * @param m: An integer m denotes the size of a backpack
	 * @param A: Given n items with size A[i]
	 * @return: The maximum size
	 */
	int backPack(int m, vector<int> A) {
		// write your code here
		sort(A.begin(), A.end());
		auto B { A };
		for (int i = B.size() - 2; i >= 0; --i)
			B[i] += B[i + 1];
		function<int(int, unsigned int)> dfs =
				[&dfs,&A,&B](int m,unsigned int start)->int {
					if (m == 0 || start >= A.size()|| m < A[start])
						return 0;
					if (m > B[start])
						return B[start];
					if (A[start] == m || B[start] == m)
						return m;
					auto tmp=m - A[start], res=dfs(tmp, start + 1);
					if(tmp==res)
						return tmp+ A[start];
					res=max(res+ A[start],dfs(m,start + 1));
					return res;
				};
		return dfs(m, 0);
	}
};

/*
 #pragma GCC diagnostic ignored "-Wunused-function"
 static//*/
int test() { // @suppress("Unused static function")
	Solution s;
	assert(s.backPack(10, { 3, 4, 8, 5 }) == 9);
	assert(s.backPack(12, { 2, 3, 5, 7 }) == 12);
	cout << "backpack passed.\n";
	return 0;
}

