#include<bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;

int seg[100005 * 4], Index, value;

inline void update ( int l, int r, int n ){
	if ( l == r )
		seg[n] += value;
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
		return max ( query ( l, nowMid, nowL, nowMid, leftSon ), query ( nowMid + 1, r, nowMid + 1, nowR, rightSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );	

	int n, l, r, q, type;
	while ( cin >> n >> q ){
		memset ( seg, 0, sizeof seg );
		Index = 1;
		
		while ( Index <= n ){
			cin >> value;
			update ( 1, n, 1 );
			Index++;
		}

		while ( q-- ){
			cin >> type;
			if ( type == 1 ){
				cin >> l >> r;
				cout << query ( l, r, 1, n, 1 ) << '\n';
			}
			else if ( type == 2 ){
				cin >> Index >> value;
				update ( 1, n, 1 );
			}
		}
	}
}