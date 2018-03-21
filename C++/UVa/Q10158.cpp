// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define maxN 10005

int dis[maxN << 1], Rank[maxN << 1];

inline void Init ( void ){
	REPP ( i, 0, maxN << 1 ){
		dis[i] = i;
		Rank[i] = 1;
	}
}

inline int find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	a = find ( a ), b = find ( b );
	if ( Rank[a] < Rank[b] )
		swap ( a, b );
	dis[b] = a;
	Rank[a]++;
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, type, u, v, vn, un;
	cin >> n;
	Init();
	while ( cin >> type >> u >> v ){
		if ( !type && !u && !v )
			break;

		vn = v + n, un = u + n;

		if ( type == 1 ){
			if ( same ( u, vn ) )
				cout << -1 << '\n';
			else{
				Union ( u, v );
				Union ( vn, un );
			}
		}
		else if ( type == 2 ){
			if ( same ( u, v ) )
				cout << -1 << '\n';
			else{
				Union ( u, vn );
				Union ( un, v );
			}
		}
		else if ( type == 3 )
			cout << same ( u, v ) << '\n';
		else
			cout << same ( u, vn ) << '\n';
	}
}