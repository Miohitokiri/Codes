#include<bits/stdc++.h>

#pragma GCC optimize ("O3")

#define maxN 1000005

using namespace std;

// BIT
int n;
long long bit[maxN];

inline void add ( int x ){
	while ( x <= n ){
		bit[x]++;
		x += x & -x;
	}
}

inline long long sum ( int x ){
	long long res = 0;
	while ( x ){
		res += bit[x];
		x -= x & -x;
	}
	return res;
}

int main(){
	ios::sync_with_stdio ( 0 );
	cin.tie ( 0 );

	long long ans = 0, stop;
	int cnt = 0;
	vector < int > basic, data;

	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		basic.push_back ( stop );
	}

	// 離散化
	data = basic;
	sort ( data.begin(), data.end() );
	for ( int i = 0 ; i < n ; i++ )
		basic[i] = lower_bound ( data.begin(), data.end(), basic[i] ) - data.begin() + 1;

	for ( int i = 0 ; i < n ; i++ ){
		data[i] = i - sum ( basic[i] );
		add ( basic[i] );
	}

	memset ( bit, 0, sizeof bit );
	reverse ( basic.begin(), basic.end() );
	reverse ( data.begin(), data.end() );
	for ( int i = 0 ; i < n ; i++ ){
		stop = sum ( basic[i] );
		ans += ( long long ) stop * data[i];
		add ( basic[i] );
	}

	cout << ans << '\n';
}