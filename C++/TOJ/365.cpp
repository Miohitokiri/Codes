// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

#define maxN 100005

struct piece{
	int f, s, sz;
};

inline bool same ( piece a, piece b ){
	return a.f == b.f && a.s == b.s;
}

struct node{
	piece fro, bck, ma;
} seg[maxN << 2];

int basic[maxN];

inline node up ( node L, node R ){
	node res;
	res.fro = L.fro, res.bck = R.bck, res.ma = ( L.ma.sz > R.ma.sz ? L.ma : R.ma );

	if ( basic[L.bck.s] + 1 == basic[R.fro.f] ){
		piece stop = piece { L.bck.f, R.fro.s, R.fro.s - L.bck.f + 1 };

		if ( same ( L.fro, L.bck ) )
			res.fro = stop;
		if ( same ( R.fro, R.bck ) )
			res.bck = stop;

		res.ma = ( stop.sz > res.ma.sz ? stop : res.ma );
	}

	return res;
}

void build ( int l, int r, int n ){
	if ( l == r )
		seg[n].fro = seg[n].bck = seg[n].ma = piece { l, r, 1 };
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		build ( l, mid, leftSon );
		build ( mid + 1, r, rightSon );

		seg[n] = up ( seg[leftSon], seg[rightSon] );
	}
}

void update ( int l, int r, int Index, int n ){
	if ( l == r )
		return;
	int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( Index <= mid )
		update ( l, mid, Index, leftSon );
	else
		update ( mid + 1, r, Index, rightSon );

	seg[n] = up ( seg[leftSon], seg[rightSon] );
}

node query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );
	return up ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, q, l, r, type;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ )
		cin >> basic[i];
	build ( 1, n, 1 );

	cin >> q;
	while ( q-- ){
		cin >> type >> l >> r;
		if ( type == 1 ){
			basic[l] = r;
			update ( 1, n, l, 1 );
		}
		else
			cout << query ( l, r, 1, n, 1 ).ma.sz << '\n';
	}
}