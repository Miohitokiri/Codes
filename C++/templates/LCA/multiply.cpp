// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

const int maxLog = 20, maxN = 100005;

vector < int > edges[maxN];
int dp[maxN][maxLog], D[maxN], n;

void dfs ( int d, int p, int dep ){
	D[d] = dep++;
	dp[d][0] = p;
	for ( auto i: edges[d] )
		if ( i != p )
			dfs ( i, d, dep );
}

inline void buildLCA ( void ){
	memset ( dp, -1, sizeof dp );
	dfs ( 0, -1, 0 );
	for ( int k = 1 ; k < maxLog ; k++ )
		for ( int i = 0 ; i < n ; i++ )
			if ( dp[i][k - 1] != -1 )
				dp[i][k] = dp[dp[i][k - 1]][k - 1];
}

inline int findLCA ( int x, int y ){
	if ( D[x] < D[y] )
		swap ( x, y );

	for ( int i = maxLog - 1 ; i >= 0 ; i-- )
		if ( dp[x][i] != -1 && D[dp[x][i]] >= D[y] )
			x = dp[x][i];

	if ( x == y )
		return x;

	for ( int i = maxLog - 1 ; i >= 0 ; i-- )
		if ( dp[x][i] != dp[y][i] )
			x = dp[x][i], y = dp[y][i];

	return dp[x][0];
}