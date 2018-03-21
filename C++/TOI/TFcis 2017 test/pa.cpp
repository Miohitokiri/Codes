#include<bits/stdc++.h>
using namespace std;
long long pow3 ( long long a, long long b ){
	long long re = 1, base = a;
	while ( b != 0 ){
		if ( b & 1 ){
			re *= base;
			re %= 1000000007;
		}
		base *= base;
		base %= 1000000007;
		b >>= 1;
	}
	return re;
}
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	long long ans = 0, n, stop = 1;
	cin >> n;
	long long data[n];
	for ( int i = 0 ; i < n ; i++ ){
		cin >> data[i];
		data[i] %= 1000000007;
	}
	sort ( data, data + n );
	for ( int i = n - 1 ; i >= 0 ; i-- ){
		stop = 1;
		stop *= pow3 ( 987, i );
		stop %= 1000000007;
		stop *= data[n - i - 1];
		stop %= 1000000007;
		ans += stop;
		ans %= 1000000007;
	}
	cin >> n;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < 4 ; j++ )
			cin >> stop;
	cout << ans << endl;
}