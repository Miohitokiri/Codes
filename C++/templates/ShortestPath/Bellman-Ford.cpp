// Bellman-Ford
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back
typedef pair < int, int > pii;

vector < pii > edges[maxN];
int dis[maxN];

inline void BellmanFord ( int start ){
	memset ( dis, 0x3f3f3f, sizeof dis );
	queue < int > q;
	dis[start] = 0;
	q.push ( start );
	while ( !q.empty() ){
		int now = q.front();
		q.pop();
		for ( auto i: edges[now] ){
			if ( dis[i.first] > dis[now] + i.second ){ // 檢查是否能更新
				q.push ( i.first );
				dis[i.first] = dis[now] + i.second;
			}
		}
	}
}