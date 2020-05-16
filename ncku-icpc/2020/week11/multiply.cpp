// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define maxLog 17

vector < int > edges[maxN];
int parent[maxN], D[maxN], dp[maxN][maxLog], n;

void dfs ( int n, int p, int dep ){
	D[n] = dep++;
	dp[n][0] = p;
	for ( auto i: edges[n] )
		if ( i != p )
			dfs ( i, n, dep );
}

inline void build ( void ){
	memset ( dp, -1, sizeof dp );
	dfs ( 0, -1, 0 );
	for ( int k = 1 ; k < maxLog ; k++ )
		for ( int i = 0 ; i < n ; i++ )
			if ( dp[i][k - 1] != -1 )
				dp[i][k] = dp[dp[i][k - 1]][k - 1];
}

inline int findLCA ( int u, int v ){
	if ( D[u] < D[v] )
		swap ( u, v );

	for ( int i = maxLog - 1 ; i >= 0 ; i-- )
		if ( dp[u][i] != -1 && D[dp[u][i]] >= D[v] )
			u = dp[u][i];

	if ( u == v )
		return u;

	for ( int i = maxLog - 1 ; i >= 0 ; i-- )
		if ( dp[u][i] != dp[v][i] )
			u = dp[u][i], v = dp[v][i];

	return dp[u][0];
}