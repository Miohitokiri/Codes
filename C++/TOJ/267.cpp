#include<bits/stdc++.h>

using namespace std;

#define int long long

int cnt;

vector < int > edge[500005];

inline int dfs ( int n, int p ){
	int re = 0;
	for ( auto i: edge[n] ){
		if ( i == p )
			continue;
		re = max ( re, dfs ( i, n ) + 1 );
	}

	return re;
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int long long

	int n, u, v, ans;
	cin >> n;
	n--;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> u >> v;
		edge[u].push_back ( v );
		edge[v].push_back ( u );
	}

	ans = dfs ( 1, -1 );

	for ( int i = 2 ; i <= n ; i++ )
		ans ^= dfs ( i, -1 );

	cout << ans << '\n';
}