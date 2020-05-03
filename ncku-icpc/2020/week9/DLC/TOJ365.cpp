// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005

struct piece{
	int l, r, sz;

	// 檢查兩個 piece 是否相同
	bool operator == ( const piece b ){
		return l == b.l && r == b.r;
	}
};

// 不想寫 operator（或是覺得太麻煩）可以這樣寫
inline bool same ( piece a, piece b ){
	return a.l == b.l && a.r == b.r;
}

struct node{
	piece front, back, ma;
} seg[maxN << 2];

int basic[maxN];

inline node merge ( node L, node R ){
    node res;
	res.front = L.front, res.back = R.back, res.ma = ( L.ma.sz > R.ma.sz ? L.ma : R.ma );

	if ( basic[L.back.r] + 1 == basic[R.front.l] ){
		piece swp = piece { L.back.l, R.front.r, R.front.r - L.back.l + 1 };

		if ( L.front == L.back )
			res.front = swp;
		if ( R.front == R.back )
			res.back = swp;

		res.ma = ( swp.sz > res.ma.sz ? swp : res.ma );
	}

	return res;
}

void update ( int l, int r, int index, int value, int n ){
	if ( l == r )
		seg[n].front = seg[n].back = seg[n].ma = piece { l, l, 1 };
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		if ( index <= mid )
			update ( l, mid, index, value, leftSon );
		else
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = merge ( seg[leftSon], seg[rightSon] );
	}
}

node query ( int l, int r, int nowL, int nowR, int n ){
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid )
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l )
		return query ( l, r, mid + 1, nowR, rightSon );

	return merge ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, type, l, r;
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ){
		cin >> basic[i];
		update ( 1, n, i, basic[i], 1 );
	}

	cin >> m;
	while ( m-- ){
		cin >> type >> l >> r;
		if ( type == 1 ){
			basic[l] = r;
			update ( 1, n, l, r, 1 );
		}
		else
			cout << query ( l, r, 1, n, 1 ).ma.sz << '\n';
	}
}