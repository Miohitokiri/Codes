// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 105

struct node1{
	int seg[maxN << 2];

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
			return query ( l, r, mid + 1, nowR, rightSon );

		return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
	}
};

inline void merge ( node1 &res, node1 a, node1 b, int l, int r, int n ){
	res.seg[n] = max ( a.seg[n], b.seg[n] );
	if ( l == r )
		return;
	int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	merge ( res, a, b, l, mid, leftSon );
	merge ( res, a, b, mid + 1, r, rightSon );
}

struct node2{
	node1 seg[maxN << 2];
	int len;

	void update ( int u, int d, int x, int y, int value, int n ){
		if ( u == d )
			seg[n].update ( 1, len, y, value, 1 );
		else{
			int mid = ( u + d ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
			if ( x <= mid )
				update ( u, mid, x, y, value, leftSon );
			else
				update ( mid + 1, d, x, y, value, rightSon );

			merge ( seg[n], seg[leftSon], seg[rightSon], 1, len, 1 );
		}
	}

	int query ( int u, int d, int nowU, int nowD, int l, int r, int n ){
		if ( u <= nowU && nowD <= d )
			return seg[n].query ( l, r, 1, len, 1 );
		int mid = ( nowU + nowD ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( d <= mid )
			return query ( u, d, nowU, mid, l, r, leftSon );
		if ( mid < u )
			return query ( u, d, mid + 1, nowD, l, r, rightSon );

		return max ( query ( u, d, nowU, mid, l, r, leftSon ), query ( u, d, mid + 1, nowD, l, r, rightSon ) );
	}
};