// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

// rV -> 反圖
vector < int > edges[maxN], rV[maxN];
bool used[maxN];
int scc[n], deg[maxN];
vector < int > st;

void dfs ( vector < int > *dV, int n, int k = -1 ){
	used[n] = true;
	scc[n] = -1;
	for ( auto i: dV[n] ){
		if ( !used[n] )
			dfs ( i );
		else if ( scc[n] != scc[i] )
			deg[scc[n]]++;
	}
	if ( dV == edges )
		st.push ( n );
}

inline int kosaraju ( int n ){ // 回傳 SCC 數量
	memset ( used, 0, sizeof used );
	int id = 0;
	st.clear();
	for ( int i = 1 ; i <= n ; i++ )
		if ( !used[i] )
			dfs ( edges, i );
	memset ( used, 0, sizeof used );
	memset ( deg, 0, sizeof deg );
	for ( int i = n - 1 ; i >= 0 ; i-- ){
		if ( !used[st[i]] )
			dfs ( rV, st[i], id++ );
	}
	return id;
}