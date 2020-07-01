// by. Miohitokiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define F first
#define S second
typedef pair < int, int > pii;

pii seg[maxN << 2];

void push ( int n ){
	if ( seg[n].S ){
		int leftSon = n << 1, rightSon = n << 1 | 1, value = seg[n].S;
		seg[n].S = 0;
		seg[leftSon].F += value, seg[rightSon].F += value;
		seg[leftSon].S += value, seg[rightSon].S += value;
	}
}

void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n].F = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		push ( n ); // lazy tag
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n].F = max ( seg[leftSon].F, seg[rightSon].F );
	}
}

int query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n].F;
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	push ( n ); // lazy tag
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

void modify ( int l, int r, int nowL, int nowR, int value, int n ){
	if ( l <= nowL && nowR <= r )
		seg[n].F += value, seg[n].S += value;
	else{
		int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		push ( n ); // lazy tag
		if ( r <= mid )
			modify ( l, r, nowL, mid, value, leftSon );
		else if ( mid < l )
			modify ( l, r, mid + 1, nowR, value, rightSon );
		else{
			modify ( l, r, nowL, mid, value, leftSon );
			modify ( l, r, mid + 1, nowR, value, rightSon );
		}
		seg[n].F = max ( seg[leftSon].F, seg[rightSon].F );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, l, r, in, type;
	cin >> n >> m;

	// build
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> in;
		update ( 1, n, i, in, 1 );
	}

	while ( m-- ){
		// type 1: 單點修改
		// type 2: 區間查詢
		// type 3: 區間修改
		cin >> type >> l >> r;
		if ( type == 1 ){
			update ( 1, n, l, r, 1 );
		}
		else if ( type == 2 )
			cout << query ( l, r, 1, n, 1 ) << '\n';
		else{
			cin >> in;
			modify ( l, r, 1, n, in, 1 );
		}
	}
}