#include<bits/stdc++.h>
#define maxN 100005
#define x first
#define y second

using namespace std;

typedef pair < int, int > pii;

vector < pii > edge[maxN];
long long maxdep = -1;

inline void dfs ( int n, int p, long long dep ){
	maxdep = max ( dep, maxdep );
	for ( auto i: edge[n] ){
		if ( i.x == p )
			continue;
		dfs ( i.x, n, dep + i.y );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, u, v, w;
	long long res = 0;
	cin >> n;
	n--;
	while ( n-- ){
		cin >> u >> v >> w;
		edge[u].push_back ( pii ( v, w ) );
		edge[v].push_back ( pii ( u, w ) );
		res += w;
	}

	res <<= 1;

	dfs ( 1, -1, 0 );

	cout << res - maxdep << '\n';
}