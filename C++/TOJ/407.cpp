// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define pb push_back

#define maxN 200005

vector < int > edges[maxN];
int match[maxN], visit[maxN], turn;

inline bool dfs ( int n ){
	visit[n] = turn;
	for ( auto i: edges[n] ){
		if ( match[i] == -1 || ( visit[match[i]] != turn && dfs ( match[i] ) ) ){
			match[i] = n;
			match[n] = i;
			return true;
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, m, u, v, p, q, ans;
	cin >> t;
	while ( t-- ){
		ans = 0;
		memset ( match, -1, sizeof match );
		for ( auto &i: edges )
			i.clear();
		cin >> p >> q >> m;
		while ( m-- ){
			cin >> u >> v;
			v += p;
			edges[u].pb ( v );
			edges[v].pb ( u );
		}

		p += q;
		for ( int i = 0 ; i <= p ; i++ ){
			if ( match[i] == -1 ){
				turn++; // 省去每次 dfs 都要 memset 一次整個 used 陣列的時間
				if ( dfs ( i ) )
					ans++; // 如果可以找到新的配對就 ans++
			}
		}

		cout << ans << '\n';
	}
}

inline void dfs ( int n, int p ){
	REPALL ( i, edges[n] ){
		if ( i == p ){
			continue;
		}
		dfs ( i, n );
	}
}

void update ( int l, int r, int index, int value, int n ){
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

int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSonn );
	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSonn ) );
}