// by. MiohitoKiri5474
// #include<bits/stdc++.h>
#include<set>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

typedef pair < int, int > pii;

#define INF 0x3f3f3f3f
#define maxN 100005

vector < pii > edges[maxN];
int dis[maxN];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, w, now;
	set < int > inQueue;
	cin >> m >> n;
	while ( m-- ){
		cin >> u >> v >> w;
		edges[u].push_back ( pii ( v, w ) );
		edges[v].push_back ( pii ( u, w ) );
	}

	for ( int i = 0 ; i <= n ; i++ )
		dis[i] = INF;
	dis[n] = 0;
	queue < int > q;
	q.push ( n );
	inQueue.insert ( n );
	while ( !q.empty() ){
		now = q.front();
		q.pop();
		inQueue.erase ( now );
		for ( int j = 0 ; j < edges[now].size() ; j++ ){
			pii i = edges[now][j];
			if ( dis[i.first] <= dis[now] + i.second )
				continue;
			dis[i.first] = dis[now] + i.second;
			if ( inQueue.find ( i.first ) == inQueue.end() ){
				inQueue.insert ( i.first );
				q.push ( i.first );
				if ( q.find ( i.first ) == q.end() )
					q.erase ( i.first );
			}
		}
	}

	cout << dis[1] << '\n';
}