#include<bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

set < long long > w;

int main(){
	long long n, q, data[100005];
	scanf ( "%lld", &n );
	for ( int i = 0 ; i < n ; i++){
		scanf ( "%lld", data + i );
		for ( int j = 0 ; j <= i ; j++ )
			w.insert ( data[i] + data[j] );
	}

	scanf ( "%lld", &q );
	while ( q-- ){
		cin >> n;
		puts ( w.find ( n ) != w.end() ? "yes" : "no" );
	}
}