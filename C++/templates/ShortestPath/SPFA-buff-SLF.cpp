// SPFA
// SLF
// basic on Bellman-Ford
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back
typedef pair < int, int > pii;

vector < pii > edges[maxN];
int dis[maxN];
bool inQueue[maxN]; // 紀錄是否已經在queue中

inline void SPFA ( int start ){
	memset ( dis, 0x3f3f3f, sizeof dis );
	deque < int > q; // 因為要支援雙向操作，所以用deque
	q.push_back ( start );
	dis[start] = 0;
	inQueue[start] = true;
	while ( !q.empty() ){
		int now = q.front();
		q.pop_front();
		inQueue[now] = false; // 紀錄已經取出
		random_shuffle ( edges[now].begin(), edges[now].end() );
		for ( auto i: edges[now] ){ // 跑過所有可以被now連結到的點
			if ( dis[i.first] > dis[now] + i.second ){
				dis[i.first] = dis[now] + i.second;
				if ( !inQueue[i.first] ){
					// 如果點沒有在queue中，再加入queue，並記錄已經在queue中
					inQueue[i.first] = true;
					// SLF 加速
					dis[i.first] < dis[q.front()] ? q.push_front ( i.first ) : q.push_back ( i.first );
				}
			}
		}
	}
}