#include<bits/stdc++.h>
#define maxN 100005
#define leftSon n * 2
#define rightSon leftSon + 1

using namespace std;

int Index = 1, s;
vector < int > seg[maxN * 4], stop;

void build ( int l, int r, int k );
void query ( int l, int r, int nowL, int nowR, int n );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, l, r, k;
	cin >> n >> m;

	for ( int i = 1 ; i <= n ; i++ ){
		Index = i;
		cin >> s;
		build ( 1, n, 1 );
	}

	while ( m-- ){
		cin >> l >> r >> k;
		stop.clear();
		// stop.resize ( r - l );
		query ( l, r, 1, n, 1 );
		sort ( stop.begin(), stop.end() );
		cout << stop[k - 1] << '\n';
	}
}

void build ( int l, int r, int n ){
	if ( l == r )
		seg[n].push_back ( s );
	else{
		int mid = ( l + r ) / 2, ls = leftSon, rs = rightSon;
		if ( Index <= mid )
			build ( l, mid, ls );
		else
			build ( mid + 1, r, rs );

		seg[n].resize ( r - l + 1 );
		merge ( seg[ls].begin(), seg[ls].end(), seg[rs].begin(), seg[rs].end(), seg[n].begin() );
	}
}

void query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r ){
		for ( auto i: seg[n] )
			stop.push_back ( i );
	}
	else{
		int nowMid = ( nowL + nowR ) / 2, ls = leftSon, rs = rightSon;
		if ( r <= nowMid )
			query ( l, r, nowL, nowMid, ls );
		else if ( nowMid < l )
			query ( l, r, nowMid + 1, nowR, rs );
		else{
			query ( l, nowMid, nowL, nowMid, ls );
			query ( nowMid + 1, r, nowMid + 1, nowR, rs );
		}
	}
}