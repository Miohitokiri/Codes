#pragma GCC optimize ("O3")

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, stop, q, l, r, sum[200005] = { 0 };
	cin >> n;
	for  ( int i = 1 ; i <= n ; i++ ){
		cin >> stop;
		sum[i] = sum[i - 1] + stop;
	}
	cin >> q;
	while ( q-- ){
		cin >> l >> r;
		if  ( l > r )
			swap ( l, r );
		cout << sum[r] - sum[l - 1] << '\n';
	}
}