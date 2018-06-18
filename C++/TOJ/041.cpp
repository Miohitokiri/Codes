#include<bits/stdc++.h>
#define maxN 1005

using namespace std;

typedef pair < int, int > pii;

int dis[maxN], rk[maxN];

inline void init ( void ){
	for ( int i = 0 ; i < maxN ; i++ ){
		dis[i] = i;
		rk[i] = 1;
	}
}

int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	a = find ( a ), b = find ( b );
	dis[a] = b;
	rk[b] += rk[a];
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline int getLider ( void ){
	return rk[find ( 0 )];
}

struct edgeData{
	int u, v, w;
};

vector < edgeData > edge;
int mstValue;

inline bool cmp ( edgeData a, edgeData b ){
	return a.w < b.w;
}

inline void Dijsktra ( void ){
	init();
	sort ( edge.begin(), edge.end(), cmp );
	for ( auto i: edge ){
		if ( same ( i.u, i.v ) )
			continue;
		Union ( i.u, i.v );
		mstValue += i.w;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int k, r, u, v, w;
	cin >> k >> r;
	while ( r-- ){
		cin >> u >> v >> w;
		edge.push_back ( edgeData { u, v, w } );
	}

	Dijsktra();

	cout << ( getLider() == k ? mstValue : -1 ) << '\n';
}
