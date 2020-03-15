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

void update ( int l, int r, int n ){
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) / 2, leftSon = n * 2, rightSon = leftSon + 1;
		if ( mid < Index ) // 1
			update ( mid + 1, r, rightSon );
		else // 2
			update ( l, mid, leftSon );
		seg[n] = max ( seg[leftSon], seg[rightSon] );
	}
}

/*

1:
l   mid   r
|____|____|
        ^

2:
l   mid   r
|____|____|
  ^

*/

int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int nowMid = ( nowL + nowR ) / 2, leftSon = n * 2, rightSon = leftSon + 1;
	if ( r <= nowMid ) // 1
		return query ( l, r, nowL, nowMid, leftSon );
	else if ( nowMid < l ) // 2
		return query ( l, r, nowMid + 1, nowR, rightSon );
	else // 3
		return max ( quert ( l, r, nowL, nowMid, leftSon ), query ( l, r, nowMid + 1, nowR, rightSon ) );
}
/*

1:
nowL   nowMid     nowR
|_________|_________|
  |___|
  l   r

2:
nowL   nowMid     nowR
|_________|_________|
            |___|
            l   r

3:
nowL   nowMid     nowR
|_________|_________|
    |___________|
    l           r

*/