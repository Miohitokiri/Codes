#include<bits/stdc++.h>
#define maxN 105
using namespace std;
int n, basicData[maxN][maxN], d[maxN], parent[maxN];
bool visit[maxN];
inline void dijkstra ( int );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int a, b, ma, flag, t = 0, e;
	while ( cin >> n ){
		if ( !n )
			break;

		cin >> flag;
		t++;
		memset ( basicData, 0, sizeof ( basicData ) );
		while ( cin >> a >> b ){
			if ( !a && !b )
				break;

			basicData[a][b] = 1;
		}

		dijkstra ( flag );
		for ( int i = 0 ; i < n ; i++ )
			if ( d[i] > ma ){
				ma = d[i];
				e = parent[i];
			}

		cout << "Case " << t << ": The logst path from " << flag << " has length " << ma << ", finishing at " << e << ".\n";
	}
}

inline void dijkstra ( int source ){
	memset ( visit, 0, sizeof ( visit ) );
	memset ( d, 0, sizeof ( d ) );

	d[source] = 0;
	parent[source ] = source;

	int a, b, max, stop;
	for ( int k = 0 ; k < n ; k++ ){
		a = -1, b = -1, max = -1;
		for ( int i = 0 ; i < n ; i++ )
			if ( !visit[i] && d[i] > max ){
				a = i;
				max = d[i];
			}


		if ( a == -1 )
			break;
		visit[a] = true;

		for ( b = 0 ; b < n ; b++ ){
			stop = d[a] + basicData[a][b];
			if ( !visit[b] && stop > d[b] ){
				d[b] = stop;
				parent[b] = a;
			}
		}
	}
}