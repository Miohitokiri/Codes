// Dijkstra
#include<bits/stdc++.h>

using namespace std;

#define maxN 10005
#define pb push_back
typedef pair < int, int > pii;

vector < int > edges[maxN];
int dis[maxN];

inline void dijkstra ( int start ){
	memset ( dis, 0x3f3f3f, sizeof dis );
	priority_queue < pii, vector < pii >, greater < pii > > pq;
	pq.push ( pii ( 0, start ) );
	while ( !pq.empty() ){
		int d = pq.top().first, node = pq.top().second;
		pq.pop();
		if ( dis[node] < d )
			continue;
		for ( auto i: edge[node] ){
			if ( dis[i.first] > d + i.second ){
				dis[i.second] = d + i.second;
				pq.push ( pii ( dis[i.second], i.second ) );
			}
		}
	}
}
