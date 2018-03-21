#include<bits/stdc++.h>
#define maxN 100005

using namespace std;

int low[maxN], dep[maxN], cnt, value[maxN], total[maxN];
vector < int > edge[maxN];

inline void dfs ( int n ){
	low[n] = dep[n] = ++cnt;
	total[n] = value[n];

	for ( auto i: edge[n] )
		if ( !dep[i] ){
			dfs ( i );

			low[n] = min ( low[n], low[i] );

			if ( low[i] >= dep[n] )
				total[n] += total[i];
		}
		else
			low[n] = min ( low[n], dep[i] );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, u, v, ma = 0, ans = -1;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> value[i];

	while ( m-- ){
		cin >> u >> v;
		edge[u].push_back ( v );
		edge[v].push_back ( u );
	}

	dfs ( 0 );

	for ( int i = 1 ; i <= n ; i++ )
		if ( ma < total[i] )
			ma = total[i], ans = i;

	cout << ans << '\n';
}