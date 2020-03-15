// disjoint set
#include<bits/stdc++.h>

using namespace std;

#define maxN 10005
int dis[maxN], sz[maxN];
inline void init ( void ){
	for ( int i = 0 ; i < maxN ; i++ ){
		dis[i] = i;
		sz[i] = 1;
	}
}

int find ( int n ){
	if ( dis[n] == n )
		return n;
	return dis[n] = find ( dis[n] );
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