#include<bits/stdc++.h>
#define maxN 5005

using namespace std;

#define int short

vector < int > edge[maxN];
int go[maxN], p[maxN];

inline void dfs ( int n, int cnt ){
	go[n] = cnt;
	for ( auto i: edge[n] )
		if ( go[i] == -1 )
			dfs ( i, cnt );
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	#define int short

	int n, m, u, v, cnt = 0, ans = 0;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v;
		edge[u].push_back ( v );
		edge[v].push_back ( u );
	}

	memset ( go, -1, sizeof ( go ) );

	for ( int i = 0 ; i < n ; i++ )
		if ( go[i] != -1 )
			dfs ( i, cnt++ );

	for ( int i = 0 ; i < n ; i++ )
		if ( edge[i].size() & 1 )
			ans++, p[go[i]]++;

	ans /= 2;
	if ( cnt != 1 )
		for ( int i = 0 ; i < cnt ; i++ )
			if ( p[i] == 0 )
				ans++;

	cout << ans << '\n';
}