// segment tree
#include<bits/stdc++.h>

using namespace std;

struct segmentTree{
	long long max, min;
} seg[100005 * 4];
long long basic[100005];

inline void build ( long long l, long long r, long long n );
inline long long query ( long long l, long long r, long long nowL, long long nowR, long long n );
inline long long queryMax ( long long l, long long r, long long nowL, long long nowR, long long n );
inline long long queryMin ( long long l, long long r, long long nowL, long long nowR, long long n );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	long long n, stop, l, r, q;
	cin >> n >> q;
	
	for ( long long i = 1 ; i <= n ; i++ )
		cin >> basic[i];

	build ( 1, n, 1 );

	while ( q-- ){
		cin >> l >> r;
		cout << queryMax ( l, r, 1, n, 1 ) - queryMin ( l, r, 1, n, 1 ) << '\n';
	}
}

inline void build ( long long l, long long r, long long n ){
	if ( l == r )
		seg[n].max = seg[n].min = basic[r];
	else{
		int leftSon = n << 1, rightSon = leftSon + 1, mid = ( l + r ) >> 1;
		build ( l, mid, leftSon );
		build ( mid + 1, r, rightSon );
		seg[n].max = max ( seg[leftSon].max, seg[rightSon].max );
		seg[n].min = min ( seg[leftSon].min, seg[rightSon].min );
	}
}

inline long long queryMax ( long long l, long long r, long long nowL, long long nowR, long long n ){
	if ( l <= nowL && nowR <= r )
		return seg[n].max;
	long long nowMid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon + 1;
	if ( r <= nowMid )
		return queryMax ( l, r, nowL, nowMid, leftSon );
	if ( nowMid < l )
		return queryMax ( l, r, nowMid + 1, nowR, rightSon );
	return max ( queryMax ( l, nowMid, nowL, nowMid, leftSon ), queryMax ( nowMid + 1, r, nowMid + 1, nowR, rightSon ) );
}

inline long long queryMin ( long long l, long long r, long long nowL, long long nowR, long long n ){
	// cout << l << ' ' << r << '\n';
	if ( l <= nowL && nowR <= r )
		return seg[n].min;
	long long nowMid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon + 1;
	if ( r <= nowMid )
		return queryMin ( l, r, nowL, nowMid, leftSon );
	if ( nowMid < l )
		return queryMin ( l, r, nowMid + 1, nowR, rightSon );
	return min ( queryMin ( l, nowMid, nowL, nowMid, leftSon ), queryMin ( nowMid + 1, r, nowMid + 1, nowR, rightSon ) );
}