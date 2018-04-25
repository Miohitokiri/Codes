// Dijkstra
#include<bits/stdc++.h>

using namespace std;

#define maxN 10005
#define pb push_back
typedef pair < int, int > pii;

vector < pii > edges[maxN];
int dis[maxN];

inline void dijkstra ( int start ){
	memset ( dis, 0x3f3f3f, sizeof dis );
	priority_queue < pii, vector < pii >, greater < pii > > pq;
	pq.push ( pii ( 0, start ) );
	while ( !pq.empty() ){
		int d = pq.top().first, node = pq.top().second;
		pq.pop();
		if ( dis[node] < d ) // 如果目前的路徑長比丟入pq時的路徑長還要短，直接忽略不處理
			continue;
		for ( auto i: edges[node] ){ // 跑過所有可以被node連結到的點
			if ( dis[i.first] > d + i.second ){ // 如果有更新，丟入當前路徑長以及點編號進入pq中
				dis[i.second] = d + i.second;
				pq.push ( pii ( dis[i.second], i.second ) );
			}
		}
	}
}
