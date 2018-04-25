// disjoint set
#include<bits/stdc++.h>

using namespace std;

int dis[maxN], sz[maxN];

inline void init ( void ){
	for ( int i = 0 ; i < n ; i++ ){
		dis[i] = i;
		sz[i] = 1;
	}
}

inline int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	a = find ( a ), b = find ( b );
	if ( sz[a] > sz[b] )
		swap ( a, b );
	dis[a] = b;
	sz[b] += sz[a];
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}