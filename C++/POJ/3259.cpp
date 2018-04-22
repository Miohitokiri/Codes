#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

#define maxN 100005
#define INF 0x3f3f3f
typedef pair < int, int > pii;

vector < pii > edges[maxN];
int dis[maxN], cnt[maxN];

inline void Init ( int n ){
	for ( int i = 1 ; i <= n ; i++ ){
		edges[i].clear();
		dis[i] = INF;
		cnt[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, w, u, v, p, t, now;
	bool ans;
	set < int > inQueue;
	cin >> t;
	while ( t-- ){
		cin >> n >> m >> w;
		Init ( n );
		while ( m-- ){
			cin >> u >> v >> p;
			edges[u].push_back ( pii ( v, p ) );
			edges[v].push_back ( pii ( u, p ) );
		}

		while ( w-- ){
			cin >> u >> v >> p;
			p *= -1;
			edges[u].push_back ( pii ( v, p ) );
		}

		ans = false;
		queue < int > q;
		dis[1] = 0;
		q.push ( 1 );
		inQueue.clear();
		inQueue.insert ( 1 );
		while ( !q.empty() ){
			now = q.front();
			q.pop();
			inQueue.erase ( now );
			for ( int j = 0 ; j < edges[now].size() ; j++ ){
				pii i = edges[now][j];
				if ( dis[i.first] > dis[now] + i.second ){
					dis[i.first] = dis[now] + i.second;
					cnt[i.first]++;
					if ( cnt[i.first] >= n ){
						ans = true;
						break;
					}
					if ( inQueue.find ( i.first ) == inQueue.end() ){
						inQueue.insert ( i.first );
						q.push ( i.first );
					}
				}
			}

			if ( ans )
				break;
		}


		cout << ( ans ? "YES" : "NO" ) << '\n';
	}
}