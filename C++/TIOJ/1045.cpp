#include<bits/stdc++.h>
using namespace std;
int data[10005][10005], basic[10005][10005];
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n = 0, ans, left, right, bottom, top;
	for ( int i = 0 ; i < 10005 ; i++ )
		for ( int j = 0 ; j < 10005 ; j++ )
			basic[i][j] = 1;
	while ( cin >> n ){
		if ( !n )
			break;

		// memset
		ans = 100000000;
		memcpy ( basic, data, sizeof ( int ) * 10005 * 10005 );
		for ( int times = 0 ; times < n ; times++ ){
			cin >> left >> top >> right >> bottom;
			for ( int i = left ; i != right ; i++ )
				for ( int j = top ; j != bottom ; j++ ){
					ans += data[i][j];
					data[i][j] *= 2;
				}
		}

		cout << ans << '\n';
	}
}