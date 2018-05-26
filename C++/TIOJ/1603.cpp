#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
typedef long long LL;
typedef pair < LL, LL > pii;
#define F first
#define S second

#define int LL

pii seg[maxN << 2];
int basic[maxN];

inline void build ( int l, int r, int n ){
	if ( l == r )
		seg[n] = pii ( basic[l], basic[l] );
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		build ( l, mid, leftSon );
		build ( mid + 1, r, rightSon );

		seg[n].F = max ( seg[leftSon].F, seg[rightSon].F );
		seg[n].S = min ( seg[leftSon].S, seg[rightSon].S );
	}
}

inline int queryMa ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n].F;
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return queryMa ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return queryMa ( l, r, mid + 1, nowR, rightSon );
	return max ( queryMa ( l, mid, nowL, mid, leftSon ), queryMa ( mid + 1, r, mid + 1, nowR, rightSon ) );
}

inline int queryMi ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n].S;
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return queryMi ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return queryMi ( l, r, mid + 1, nowR, rightSon );
	return min ( queryMi ( l, mid, nowL, mid, leftSon ), queryMi ( mid + 1, r, mid + 1, nowR, rightSon ) );
}

#undef int

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	// cout.tie ( 0 );
	#define int LL

	int n, m, in, l, r;
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> basic[i];
	build ( 1, n, 1 );

	while ( m-- ){
		cin >> l >> r;
		cout << queryMa ( l, r, 1, n, 1 ) - queryMi ( l, r, 1, n, 1 ) << '\n';
	}
}