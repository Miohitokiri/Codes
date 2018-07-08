#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	#define int long long

	int n, k, ans = 2;
	cin >> n >> k;
	k <<= 1;
	vector < int > data ( n );
	for ( auto &i: data )
		cin >> i;

	for ( int i = 1 ; i < n ; i++ ){
		if ( data[i] - data[i - 1] > k )
			ans += 2;
		else if ( data[i] - data[i - 1] == k )
			ans++;
	}

	cout << ans << '\n';
}