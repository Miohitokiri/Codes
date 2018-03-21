#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *l, *r;
	node ( int d ): data ( d ), l ( nullptr ), r ( nullptr ){}
	inline void up ( void ){
		if ( !l )
			data = r -> data;
		else if ( !r )
			data = l -> data;
		else
			data = l -> data + r -> data;
	}
} *root;

int value, Index;

inline node *build ( int l, int r ){
	node *o = new node ( 0 );
	if ( l != r ){
		int mid = ( l + r ) >> 1;
		o -> l = build ( l, mid );
		o -> r = build ( mid + 1, r );
	}
	return o;
}

inline void XOR ( int l, int r, int nowL, int nowR, node *o ){
	if ( nowL <= l && r <= nowR ){
		if ( seg[n] < value )
			return;
		if ( nowL == nowR ){
			o -> data ^= value;
			return;
		}
	}

	int nowMid = ( nowL + nowR ) >> 1;
	if ( r <= nowMid )
		mod ( l, r, nowL, nowMid, o -> l );
	else if ( nowMid < l )
		mod ( l, r, nowMid + 1, nowR, o -> r );
	else{
		mod ( l, r, nowMid + 1, nowR, o -> r );
		mod ( l, r, nowL, nowMid, o -> l );
	}

	o -> up();
}

inline int query ( int l, int r, int nowL, int nowR, node *o ){
	if ( !o )
		return 0;
	if ( l <= nowL && nowR <= r )
		return o -> data;
	int nowMid = ( nowL + nowR ) >> 1;
	if ( nowMid < l )
		return query ( l, r, nowMid + 1, nowR, o -> r );
	else if ( r <= nowMid )
		return query ( l, r, nowL, nowMid, o -> l );
	else
		return query ( l, nowMid, nowL, nowMid, o -> l ) + query ( nowMid + 1, r, nowMid + 1, nowR, o -> r );
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( NULL );

	int n, q, l, r, type, v;
	vector < node* > version;
	node *now;
	cin >> n;
	n--;
	root = build ( 0, n );

	version.push_back ( root );

	cin >> q;
	while ( q-- ){
		cin >> type;
		if ( type == 1 ){
			cin >> l >> r;
			now = new node ( 0 );
			root = *( version.end() - 1 );
			now -> l = root -> l;
			now -> r = root -> r;
			now -> data = root -> data;
			XOR ( l, r, nowL, nowR, now );
			version.push_back ( now );
		}
		else{
			cin >> v >> l >> r;
			now = version[v];

			cout << query ( l, r, 0, n, now ) << '\n';
		}
	}
}