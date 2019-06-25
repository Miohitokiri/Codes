// by. MiohitoKiri5474
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<cstring>

using namespace std;

#define maxN 1000005
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
#define F first
#define S second
typedef pair < int, int > pii;

vector < pii > edges[maxN];
long long ma[maxN];

bool inQ[maxN];

struct node{
	int u, v, w;
} ed[maxN];

inline void spfa ( void ){
	deque < int > q;
	q.pb ( 1 );
	inQ[1] = true;
	ma[1] = 0;
	int now, to;
	while ( !q.empty() ){
		now = q.front();
		q.pop_front();
		inQ[now] = false;
		for ( int i = 0 ; i < edges[now].size() ; i++ ){
			to = edges[now][i].F;
			if ( ma[now] + edges[now][i].S < ma[to] ){
				ma[to] = ma[now] + edges[now][i].S;
				if ( !inQ[to] ){
					inQ[to] = true;
					if ( ma[to] < ma[q.front()] )
						q.push_front ( to );
					else
						q.pb ( to );
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n, m, u, v, w;
	long long ans;
	for ( int i = 1 ; i < maxN ; i++ )
		edges[i].reserve ( maxN );
	cin >> t;
	while ( t-- ){
		cin >> n >> m;
		for ( int i = 1 ; i <= n ; i++ )
			edges[i].clear();
		memset ( ma, INF, sizeof ma );
		ans = 0;
		for ( int i = 0 ; i < m ; i++ ){
			cin >> u >> v >> w;
			ed[i] = node{ u, v, w };
			edges[u].pb ( pii ( v, w ) );
		}
		spfa();
		for ( int i = 1 ; i <= n ; i++ )
			ans += ma[i];

		for ( int i = 2 ; i <= n ; i++ )
			edges[i].clear();
		memset ( ma, INF, sizeof ma );
		for ( int i = 0 ; i < m ; i++ )
			edges[ed[i].v].pb ( pii ( ed[i].u, ed[i].w ) );
		spfa();
		for ( int i = 2 ; i <= n ; i++ )
			ans += ma[i];

		cout << ans << '\n';
	}
}