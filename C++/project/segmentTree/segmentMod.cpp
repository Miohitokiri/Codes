#include<bits/stdc++.h>
#define maxN 200005

using namespace std;

int seg[maxN * 4], Index, value;

inline void update ( int n, int l, int r ){
	if ( l == r )
		seg[n] += value;
	else{
		int mid = ( l + r ) >> 1, leftSon = ( n << 1 ) + 1, rightSon = leftSon + 1;
		if ( mid < Index )
			update ( rightSon, mid + 1, r );
		else
			update ( leftSon, l, mid );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

inline void mod ( int n, int l, int r, int nowL, int nowR ){
	if ( nowL <= l && r <= nowR ){
		if ( seg[n] < value )
			return;
		if ( nowL == nowR ){
			seg[n] %= value;
			return;
		}
	}

	int nowMid = ( nowL + nowR ) >> 1, leftSon = ( n << 1 ) + 1, rightSon = leftSon + 1;
	if ( r <= nowMid )
		mod ( leftSon, l, r, nowL, nowMid );
	else if ( nowMid < l )
		mod ( rightSon, l, r, nowMid + 1, nowR );
	else{
		mod ( leftSon, l, nowMid, nowL, nowMid );
		mod ( rightSon, nowMid + 1, r, nowMid + 1, nowR );
	}

	seg[n] = max ( seg[leftSon], seg[rightSon] );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, m, k, l, r;

	cin >> n, n--;
	for ( int i = 0 ; i <= n ; i++ ){
		cin >> value;
		update ( 0, 0, n );
		Index++;
	}

	cin >> m;
	while ( m-- ){
		cin >> k;
		if ( k == 1 ){
			cin >> value >> Index;
			update ( 0, 0, n );
		}
		else if ( k == 3 )
			cout << seg[0] << '\n';
		else{
			cin >> l >> r >> value;
			mod ( 0, l, r, 0, n );
		}
	}
}