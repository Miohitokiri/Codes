// Floyd-Warshall
// by. MiohitoKiri5474
#include<bits/stdc++.h>
#define maxN 5005
typedef long long LL;

using namespace std;

LL graph[maxN][maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, w, q;
	cin >> n >> m;

	memset ( graph, 0x3f3f3f, sizeof graph );
	while ( m-- ){
		cin >> u >> v >> w;
		graph[u][v] = graph[v][u] = w;
	}

	for ( int i = 0 ; i < n ; i++ )
		graph[1][1] = 0;

	for ( int k = 0 ; k < n ; k++ )
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < n ; j++ )
				if ( graph[i][j] > graph[i][k] + graph[k][j] )
					graph[i][j] = graph[i][k] + graph[k][j];

	cin >> q;
	while ( q-- ){
		cin >> u >> v;
		cout << graph[u][v] << '\n';
	}
}