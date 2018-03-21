#include<bits/stdc++.h>

using namespace std;

int seg[105 * 4], Index, value;
inline void update ( int l, int r, int n );
inline int query ( int l, int r, int nowL, int nowR, int n );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );	

	int n, l, r, q;
	cin >> n >> q;
	n--;
	
	while ( Index <= n ){
		cin >> value;
		update ( 0, n, 1 );
		Index++;
	}

	while ( q-- ){
		cin >> l >> r;
		cout << query ( l, r, 0, n, 1 ) << '\n';
	}
}

inline void update ( int l, int r, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1;
		int rightSon = leftSon + 1;
		if ( mid < Index )
			update ( mid + 1, r, rightSon );
		else
			update ( l, mid, leftSon );
		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

inline int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int nowMid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon + 1;
	if ( r <= nowMid )
		return query ( l, r, nowL, nowMid, leftSon );
	else if ( nowMid < l )
		return query ( l, r, nowMid + 1, nowR, rightSon );
	else
		return max ( query ( l, r, nowL, nowMid, leftSon ), query ( l, r, nowMid + 1, nowR, rightSon ) );
}