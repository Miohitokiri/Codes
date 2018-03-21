#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k, r, c, times = 0, max = 1, mas, ans;
	bool test;
	while ( cin >> n >> k ){
		if ( n == 0 && k == 0 )
			break;
		else{
			ans = 0;
			times++;
			bool data[n][n];
			int data1[n], data2[n],data3[2 * n];
			memset ( data, 0, sizeof ( data ) );
			memset ( data, 0, sizeof ( data1 ) );
			memset ( data, 0, sizeof ( data2 ) );
			for ( int i = 0 ; i < k ; i++ ){
				cin >> r >> c;
				r--;
				c--;
				data[r][c] = true;
				data1[r]++;
				data2[c]++;
			}
			while ( true ){
				for ( int i = 0 ; i < n ; i++ ){
					data3[i] = data1[i];
					data3[i + n] = data2[i];
				}
				max = 0;
				mas = 0;
				for ( int i = 0 ; i < 2 * n ; i++ )
					if ( max < data3[i] ){
						max = data3[i];
						mas = i;
					}
				if ( max == 0 )
					break;
				data3[mas] = 0;
				ans++;
				if ( mas >= n ){
					test = true;
					data2[mas - n] = 0;
				}
				for ( int i = 0 ; i < n ; i++ )
					if ( test )
						data[i][mas - n] = false;
					else
						data[mas][i] = false;
			}
			cout << "Case #" << times << ':' << ans << endl;
		}
	}
}