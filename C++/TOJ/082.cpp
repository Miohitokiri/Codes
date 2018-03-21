#include<bits/stdc++.h>
#define maxN 200005
#define INF 0x1f1f1f1f

#pragma GCC optimize ("O3")

using namespace std;

vector < int > edge[maxN];
bool color[maxN];

inline int dfs ( int n, int p ){
	int s = INF;
	for ( auto i: edge[n] ){
		if ( i == p )
			continue;
		if ( color[i] )
			return 0;
		s = min ( s, dfs ( i, n ) + 1 );
	}

	return s;
}

int main(){
	int n, type, x, s;
	scanf ( "%d", &n );
	n--;
	while ( n-- ){
		scanf ( "%d%d", &type, &x );
		edge[type].push_back ( x );
		edge[x].push_back ( type );
	}

	scanf ( "%d", &n );
	while ( n-- ){
		scanf ( "%d%d", &type, &x );
		if ( !type )
			color[x] = !color[x];
		else{
			if ( color[x] )
				puts ( "0" );
			else{
				s = dfs ( x, -1 ) + 1;
				if ( s >= INF )
					puts ( "-1" );
				else
					printf ( "%d\n", s );
			}
		}
	}
}