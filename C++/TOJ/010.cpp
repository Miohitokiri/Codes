// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define pb push_back
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 200010

vector < int > edges[maxN];
int where[maxN], value[maxN], link[maxN], pa[maxN], D[maxN], cnt, seg[maxN << 2], siz[maxN], maxSon[maxN];

inline void init ( void ){
	for ( auto &i: edges )
		i.clear();
	memset ( where, -1, sizeof where );
	memset ( value, NEG_INF, sizeof value );
	memset ( D, 0, sizeof D );
	memset ( maxSon, -1, sizeof maxSon );
	cnt = 0;
}

inline void findMaxSon ( int u ){
	siz[u] = 1;
	maxSon[u] = -1;
	for ( auto i: edges[u] ){
		if ( i == pa[u] )
			continue;
		pa[i] = u;
		D[i] = D[u] + 1;
		findMaxSon ( i );
		if ( maxSon[u] == -1 || siz[i] > siz[maxSon[u]] )
			maxSon[u] = i;
		siz[u] += siz[i];
	}
}

inline void dfs ( int n, int p ){
	link[n] = p;
	where[n] = ++cnt;
	if ( maxSon[n] == -1 )
		return;
	dfs ( maxSon[n], p );
	for ( auto i: edges[n] ){
		if ( i == maxSon[n] || i == pa[n] )
			continue;
		dfs ( i, i );
	}
}

inline void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

inline int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return max ( query ( l, r, mid + 1, nowR, rightSon ), query ( l, r, nowL, mid, leftSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, n, u, v, uPa, vPa, ma, N;
	string type;
	cin >> t;
	while ( t-- ){
		cin >> n;
		N = n << 1;
		N--;
		init();
		for ( int i = 1 ; i < n ; i++ ){
			cin >> u >> v >> value[n + i];
			edges[u].pb ( n + i );
			edges[n + i].pb ( u );
			edges[n + i].pb ( v );
			edges[v].pb ( n + i );
		}

		pa[1] = 1;
		findMaxSon ( 1 );
		dfs ( 1, 1 );
		for ( int i = 1 ; i < ( n << 1 ) ; i++ )
			update ( 1, N, where[i], value[i], 1 );
		while ( cin >> type ){
			if ( type == "DONE" )
				break;
			cin >> u >> v;
			if ( type == "QUERY" ){
				uPa = u, vPa = v;
				ma = -1;
				int ccc = 0;

				while ( link[vPa] != link[uPa] ){
					if ( D[link[vPa]] > D[link[uPa]] ){
						ma = max ( ma, query ( where[link[vPa]], where[vPa], 1, N, 1 ) );
						vPa = pa[link[vPa]];
					}
					else{
						ma = max ( ma, query ( where[link[uPa]], where[uPa], 1, N, 1 ) );
						uPa = pa[link[uPa]];
					}
				}

				if ( D[uPa] > D[vPa] )
					swap ( uPa, vPa );
				cout << max ( ma, query ( where[uPa], where[vPa], 1, N, 1 ) ) << '\n';
			}
			else
				update ( 1, N, where[n + u], v, 1 );
		}
	}
}
