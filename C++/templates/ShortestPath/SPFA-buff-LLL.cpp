// SPFA
// LLL
// basic on Bellman-Ford
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back
typedef pair < int, int > pii;

vector < pii > edges[maxN];
int dis[maxN], sum;
bool inQueue[maxN]; // 紀錄是否已經在queue中

inline void SPFA ( int start ){
	memset ( dis, 0x3f3f3f, sizeof dis );
	queue < int > q;
	q.push ( start );
	dis[start] = 0;
	inQueue[start] = true;
	while ( !q.empty() ){
		// LLL 優化，因為一定有一個點的長度小於平均值，所以就一路往後丟
		while ( dis[q.front()] * q.size() > sum ){
			q.push ( q.front() );
			q.pop();
		}
		int now = q.front();
		q.pop();
		sum -= dis[now];
		inQueue[now] = false; // 紀錄已經取出
		random_shuffle ( edges[now].begin(), edges[now].end() );
		for ( auto i: edges[now] ){ // 跑過所有可以被now連結到的點
			if ( dis[i.first] > dis[now] + i.second ){
				dis[i.first] = dis[now] + i.second;
				if ( !inQueue[i.first] ){
					// 如果點沒有在queue中，再加入queue，並記錄已經在queue中
					inQueue[i.first] = true;
					q.push ( i.first );
					sum += dis[i.first]; // 記得把數值加上
				}
			}
		}
	}
}