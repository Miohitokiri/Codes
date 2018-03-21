#include<bits/stdc++.h>
#define maxN 1005

using namespace std;

typedef pair < int, int > pii;

struct disjoinSet{
	int dis[maxN], rank[maxN];

	inline void Init ( int n ){
		for ( int i = 0 ; i <= n ; i++ ){
			dis[i] = i;
			rank[i] = 1;
		}
	}

	inline int find ( int n ){
		return dis[n] == n ? n : dis[n] = find ( dis[n] );
	}

	inline void Union ( int a, int b ){
		a = find ( a ), b = find ( b );
		dis[a] = b;
		rank[b] += rank[a];
	}

	inline bool same ( int a, int b ){
		return find ( a ) == find ( b );
	}

	inline int getLider ( void ){
		return rank[find ( 0 )];
	}
} dis;

struct edgeData{
	int u, v, w;
	edgeData ( int a, int b, int c ): u ( a ), v ( b ), w ( c ){}
};

vector < edgeData > edge;
int mstValue;

inline bool cmp ( edgeData a, edgeData b ){
	return a.w < b.w;
}

inline void Dijsktra ( void ){
	sort ( edge.begin(), edge.end(), cmp );
	for ( auto i: edge ){
		if ( dis.same ( i.u, i.v ) )
			continue;
		dis.Union ( i.u, i.v );
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
		edge.push_back ( edgeData ( u, v, w ) );
	}

	dis.Init ( k );
	Dijsktra();

	cout << ( dis.getLider() == k ? mstValue : -1 ) << '\n';
}