#include <iostream>

using namespace std;


// 递归的特点与性质：1.逻辑方法不变 2.规模不断变小 3.注意一个终止条件

// 编程求 {1,2,3,...,n} 的全排列
void fullPermutation(int arra[], int n, int k){			// arra[]:代表要排列的内容用数组存放。
														// n：表示要排列几个数。
														// k：表示当前排列的状态排列到第几个数。

	if (k == n-1) {		// 递归终止条件，因为是交换所以到n-1步的时候就等于排好了全部了
		for (int i = 0; i < n; ++i)
			cout << arra[i] << " ";

		cout << endl;
	}
	else {
		for (int i = k; i < n; ++i) {

			// 交换元素的步骤
			int temp = arra[i];
			arra[i] = arra[k];
			arra[k] = temp;
			// 递归调用，对后续元素的全排列在递归调用中完成
			fullPermutation(arra, n, k + 1);
			
			// 调用结束后，要将元素放回原来的位置
			temp = arra[i];						// 注意这一步不可少，因为temp中的值在递归调用后变化，要将arra[i]的值重新赋给temp;
			arra[i] = arra[k];
			arra[k] = temp;

		}
	}
}

int main(){
	int arra[6] = {1,2,3,4,5,6};
	fullPermutation(arra, 5, 0);

	system("pause");

}


