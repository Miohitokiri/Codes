#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a[100005] = {0};   // 数组a记录整数序列
	// count记录负数个数
	// max 最大和  max_f 最大和最前端 max_l最大和最后端
	int n, i, j, s, count, max, max_f, max_l; 

	// 以输入作为循环条件实现多组数据的输入 
	while(cin>>n) {
		count = 0;
		for( i = 0; i < n; ++i ) {
			cin>>a[i];
			if( a[i] < 0 ) count++;	 //记录负数个数 
		}

		if(count == n) {
			max = 0;
			max_f = a[0];
			max_l = a[n-1];
		}
		// 大多数情况的操作
		else {
			max = a[0];max_f = a[0];max_l = a[0];
			for( i = 0; i < n; ++i ) {
				//从a[0]开始计算各情况
				s = a[i];
				// 算法 可草稿推演
				for( j = i+1; j < n; ++j ) {
					s += a[j];
					//寻找最大 
					if(s>max) {
						max = s; 
						max_f = a[i];
						max_l = a[j];
					}
				}
			}
		}
		// 输出结果
		cout << max << '\n';
	}
	return 0;
}